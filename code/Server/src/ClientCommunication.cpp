/**
 * @file ClientCommunication.cpp
 *
 * @date 29-04-2013
 *
 * @author Sosnowski Jacek
 *
 * @brief Implementation of the Class UXP1A_project::Server::ClientCommunication
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#include "ClientCommunication.h"

namespace UXP1A_project {
namespace Server {

ClientCommunication::ClientCommunication(const QString& clientFifoPath)
        : m_clientPath(clientFifoPath), m_fifo(0)
{
    // store state of open operation
//    m_fifoState = openFifo();
}

ClientCommunication::~ClientCommunication()
{
    if (m_fifo > 0)
        close(m_fifo);
}

bool ClientCommunication::sendRecord(const QString& pattern,
        const QVariantList& data)
{
    using Shared::Configuration;

    if (!openFifo()) // if server can't open client FIFO
        return false;

    qDebug() << "To " << m_clientPath << " sending record " << data;
    qDebug();

    // PREPARING DATA
    QByteArray data_array;
    for (int i = 0; i < data.size(); ++i) {
        char dataType = pattern[i].toAscii();
        if (dataType == 's') {
            data_array.append(data[i].toByteArray());
            data_array.append('\0');
        }
        else if (dataType == 'i') {
            int dInt = data[i].toInt();
            char dBuf[sizeof(int)] = {0};
            memcpy(dBuf, &dInt, sizeof(int));
            data_array.append(dBuf, sizeof(int));
        }
        else if (dataType == 'f') {
            float dFloat = data[i].toFloat();
            char dBuf[sizeof(float)] = {0};
            memcpy(dBuf, &dFloat, sizeof(float));
            data_array.append(dBuf, sizeof(float));
        }
    }

    int length = data_array.size();
    QByteArray len = QVariant(length).toByteArray();

    // PREPARING BUFFER
    // create sending buffer
    const int MAX_BUF = 7 + length + len.size(); // +7 because of separators number
    char buf[MAX_BUF];

    // Operation preview CODE
    buf[0] = Configuration::getMesCode(Configuration::FOUND);
    buf[1] = 0;
    int ptr = 2;        // pointer to free space in buffer buf
    int currLen = 0;  // auxiliary variable - current data length (while memcpy)

    // Copy data to the buffer
    // copy all message LENGTH
    currLen = len.size();
    memcpy(buf + ptr, len.constData(), currLen);
    ptr += currLen; // move pointer to first free space cell
    buf[ptr++] = 0; // separator

    memcpy(buf + ptr, data_array.constData(), length);
    ptr += length;
    // no require to end with '\0' - because data_array include this sign

    write(m_fifo, buf, ptr);

    close(m_fifo);
    m_fifo = -1; //FIFO is closed

    return true;
}

void ClientCommunication::sendTimeoutInfo()
{
    using Shared::Configuration;

    if (!openFifo()) // if server can't open client FIFO
        return;

    qDebug() << "To " << m_clientPath << " sending Timeout";
    qDebug();

    char timeoutCode[2];
    timeoutCode[0] = Configuration::getMesCode(Configuration::TIME);
    timeoutCode[1] = '\0';
    write(m_fifo, timeoutCode, 2);

    close(m_fifo);
    m_fifo = -1; //FIFO is closed
}

bool ClientCommunication::openFifo()
{
    using Shared::Configuration;
    // now we can remember full path to fifo file
    std::string fifoPath = Configuration::getServerFifoDir();
    fifoPath.append(std::string(m_clientPath.toStdString()));

    m_fifo = open(fifoPath.c_str(), O_WRONLY);

    if (m_fifo <= 0) {
        qDebug() << "Error during open client FIFO. PID: " << m_clientPath;
        return false;
    }
    return true;
}

} //namespace Server
} //namespace UXP1A_project
