///////////////////////////////////////////////////////////
//  ToServerPipe.cpp
//  Implementation of the Class ToServerPipe
//  Created on:      24-kwi-2013 11:04:00
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "ToServerPipe.h"
#include "Configuration.h"
#include <QObject>
#include <iostream>

namespace UXP1A_project {
namespace Client {

ToServerPipe::ToServerPipe()
        : m_GID(0)
{
    using Shared::Configuration;
    // find server fifo file
    std::string fifo = Configuration::getServerFifoDir();
    ;
    fifo.append(Configuration::getServerFifoName());

    m_fifo = open(fifo.c_str(), O_WRONLY);

    if (m_fifo <= 0) {
        qDebug() << "No server found!!!";
        throw std::string("Error while opening server FIFO.");
    }

}

ToServerPipe::~ToServerPipe()
{
    close(m_fifo);
}

void ToServerPipe::writePreviewMessage(const QString& pattern, long timeout)
{
    using Shared::Configuration;

    writeToFifo(Configuration::getMesCode(Configuration::PREV), pattern,
            timeout);
}

void ToServerPipe::writePullDataMessage(const QString& condition, long timeout)
{
    using Shared::Configuration;

    writeToFifo(Configuration::getMesCode(Configuration::PULL), condition,
            timeout);
}

void ToServerPipe::writePushDataMessage(const QString& pattern,
        const QVariantList& data)
/**
 * KOD \0 LENGTH \0 PID \0 PATTERN \0 data[0] \0 data[1] \0 ... data[n] \0
 */
{
    using Shared::Configuration;
    // PREPARING DATA
    QByteArray pid = getPid();
    QByteArray patt = pattern.toAscii();

    // PREPARING DATA
    QByteArray data_array;
    for (int i = 0; i < data.size(); ++i) {
        qDebug() << "TSPipe sending...";
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

    int data_array_length = data_array.size();

    long length = pid.size() + patt.size() + data_array_length;
    length += 2; // add number of separation sign '\0'
    //QByteArray len = QVariant(length).toByteArray();

    // PREPARING BUFFER
    // create sending buffer
    const int MAX_BUF = 7 + length + sizeof(long); // +7 because of separators number
    char buf[MAX_BUF];

    char mesCode = Configuration::getMesCode(Configuration::PUSH);
    int writtenBytes = initialWriteToFifo(mesCode, length, pid, patt, buf);

    memcpy(buf + writtenBytes, data_array.constData(), data_array_length);
    // no require to end with '\0' - because data_array include this sign

    write(m_fifo, buf, writtenBytes + data_array_length);

    qDebug() << m_GID++ << " Wyslano zadanie PUSH";
    qDebug()
            << "code # length(fromfirst PID sign) # PID # ParsedPattern # Data# "; // TODO delete line
    Configuration::displayBuffer(buf, writtenBytes + data_array_length);
    qDebug();
}

QByteArray ToServerPipe::getPid() const
{
    pid_t p = getpid();
    QString pid = QString::number(p);
    return pid.toAscii();
}

void ToServerPipe::writeToFifo(char code, const QString& pattern,
        const long timeout) //const
/**
 * KOD \0 LENGTH \0 PID \0 PATTERN \0 TIME \0
 */
{
    using Shared::Configuration;
    //^^^^^^^^^^^^^^^^^^^^  Preparing data
    QByteArray pid = getPid();
    QByteArray patt = pattern.toAscii();

    QString t_s = QString::number(timeout);
    QByteArray tim = t_s.toAscii();

    long length = pid.size() + patt.size() + tim.size();
    length += 3; // add number of separation sign '\0'
//    QByteArray len = QVariant(length).toByteArray();

    //^^^^^^^^^^^^^^^^^^^^ Preparing buffer
    // create sending buffer
    const int MAX_BUF = 7 + length + sizeof(long); // +7 because of separators number
    char buf[MAX_BUF];

    // writes first part of message: KOD \0 LENGTH \0 PID \0 PATTERN
    int writtenBytes = initialWriteToFifo(code, length, pid, patt, buf);

    // copy TIMER value
    int currLen = tim.size();
    memcpy(buf + writtenBytes, tim.constData(), currLen);
    writtenBytes += currLen;
    buf[writtenBytes++] = 0;

    if (writtenBytes != length + sizeof(long) + 2)
        qDebug() << "    Cos NIE tak z dlugosciami w writePreview"; // TODO delete this line

    write(m_fifo, buf, writtenBytes);

    qDebug() << m_GID++ << " Wyslano zadanie "
            << ((Configuration::getMes(code) == Configuration::PREV) ?
                    "PREVIEW" : "PULL");
    qDebug()
            << "code # length(from first PID sign) # PID # NOTParsedPattern # Timeout# "; // TODO del
    Shared::Configuration::displayBuffer(buf, writtenBytes);
    qDebug();
}

int ToServerPipe::initialWriteToFifo(char code, const long length,
        const QByteArray& pid, const QByteArray& patt, char *buf) const
{
    // Operation preview CODE
    buf[0] = code;
    buf[1] = 0;
    int ptr = 2;        // pointer to free space in buffer buf
    int currLen = 0;  // auxiliary variable - current data length (while memcpy)

    // Copy data to the buffer
    // copy all message LENGTH
    qDebug() << "Dlugosc: " << length;
    memcpy(buf + ptr, &length, sizeof(long));
    int dl; memcpy(&dl, buf+ptr, sizeof(long)); qDebug() << "DlugoscTo: " << dl;
    ptr += sizeof(long); // move pointer to first free space cell
    //buf[ptr++] = 0; // separator

    // copy client PID
    currLen = pid.size();
    memcpy(buf + ptr, pid.constData(), currLen);
    ptr += currLen;
    buf[ptr++] = 0;

    // copy PATTERN data
    currLen = patt.size();
    memcpy(buf + ptr, patt.constData(), currLen);
    ptr += currLen;
    buf[ptr++] = 0;

    return ptr;
}

}     //namespace Client
}     //namespace UXP1A_project
