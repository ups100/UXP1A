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
{
    using Shared::Configuration;
    // find server fifo file
    std::string fifo = Configuration::getServerFifoDir();
    ;
    fifo.append(Configuration::getServerFifoName());

    m_fifo = open(fifo.c_str(), O_WRONLY);

    if (m_fifo <= 0)
        qDebug() << "No server found!!! ps Error in opening FIFO";

}

ToServerPipe::~ToServerPipe()
{
    close(m_fifo);
}

void ToServerPipe::writePreviewMessage(const QString& pattern, long timeout)
{
    using Shared::Configuration;

    writeToFifo(Configuration::getMesCode(Configuration::PREV), pattern, timeout);
}

void ToServerPipe::writePullDataMessage(const QString& condition, long timeout)
{
    using Shared::Configuration;

    writeToFifo(Configuration::getMesCode(Configuration::PULL), condition, timeout);
}

void ToServerPipe::writePushDataMessage(const QString& pattern,
        const QVariantList& data)
/**
 * KOD \0 LENGTH \0 PID \0 PATTERN \0 data[0] \0 data[1] \0 ... data[n] \0
 */
{

}

QByteArray ToServerPipe::getPid() const
{
    pid_t p = getpid();
    QString pid = QString::number(p);
    return pid.toAscii();
}

void ToServerPipe::writeToFifo(char code, const QString& pattern,
        const long timeout) const
/**
 * KOD \0 LENGTH \0 PID \0 PATTERN \0 TIME \0
 */
{
    //^^^^^^^^^^^^^^^^^^^^  Preparing data
    QByteArray pid = getPid();
    QByteArray patt = pattern.toAscii();

    QString t_s = QString::number(timeout);
    QByteArray tim = t_s.toAscii();

    int length = pid.size() + patt.size() + tim.size();
    length += 3; // add number of separation sign '\0'
    QVariant l(length);
    QByteArray len = l.toByteArray();

    //^^^^^^^^^^^^^^^^^^^^ Preparing buffer
    // create sending buffer
    const int MAX_BUF = 7 + len.size() + pid.size() + tim.size()
            + pattern.size();   // +7 because of separators number
    char buf[MAX_BUF];   // = { 0 };
    // Operation preview CODE
    buf[0] = code;
    buf[1] = 0;
    int ptr = 2;        // pointer to free space in buffer buf
    int currLen = 0;  // auxiliary variable - current data length (while memcpy)

    //^^^^^^^^^^^^^^^^^^^^  Copy data to the buffer
    // copy all message LENGTH
    currLen = len.size();
    memcpy(buf + ptr, len.constData(), currLen);
    ptr += currLen; // move pointer to first free space cell
    buf[ptr++] = 0; // separator

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

    // copy TIMER value
    currLen = tim.size();
    memcpy(buf + ptr, tim.constData(), currLen);
    ptr += currLen;
    buf[ptr++] = 0;

    if (ptr != length + len.size() + 3)
        qDebug() << "    Cos NIE tak z dlugosciami w writePreview"; // TODO delete this line

    write(m_fifo, buf, ptr);

    qDebug() << "Wyslano: " << length;
    Shared::Configuration::displayBuffer(buf, ptr);
}

}     //namespace Client
}     //namespace UXP1A_project
