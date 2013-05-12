///////////////////////////////////////////////////////////
//  ClientCommunication.cpp
//  Implementation of the Class ClientCommunication
//  Created on:      24-kwi-2013 11:07:18
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "ClientCommunication.h"

namespace UXP1A_project {
namespace Server {

ClientCommunication::ClientCommunication(const QString& clientFifoPath)
        : m_clientPath(clientFifoPath), m_fifo(0)
{
    // store state of open operation
    m_fifoState = openFifo();
}

ClientCommunication::~ClientCommunication()
{
    if (m_fifoState)
        close(m_fifo);
}

void ClientCommunication::sendRecord(const QString& pattern,
        const QVariantList& data)
{
    using Shared::Configuration;

    if (!m_fifoState) // if server can't open client FIFO
        return;
    qDebug() << "To " << m_clientPath << " sending record " << data;
    qDebug(); // TOD del

    // PREPARING DATA
    QByteArray data_array;
    for (int i = 0; i < data.size(); ++i) {
        qDebug() << "In CC sending data...";        // TODO
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
    for (int i = 0; i < MAX_BUF; ++i)
        buf[i] = 0;        // TODO del this

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

    Shared::Configuration::displayBuffer(buf, MAX_BUF);
    write(m_fifo, buf, ptr);

//    qDebug() << "Send structure: ";                                         // TODO delete line
//    Configuration::displayBuffer(buf, ptr);
}

void ClientCommunication::sendTimeoutInfo()
{
    using Shared::Configuration;

    if (!m_fifoState) // if server can't open client FIFO
        return;

    qDebug() << "To " << m_clientPath << " sending Timeout";
    qDebug();   // TODO del

    char timeoutCode[2];
    timeoutCode[0] = Configuration::getMesCode(Configuration::TIME);
    timeoutCode[1] = '\0';
    write(m_fifo, timeoutCode, 2);
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
