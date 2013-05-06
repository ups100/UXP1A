///////////////////////////////////////////////////////////
//  FromServerPipe.cpp
//  Implementation of the Class FromServerPipe
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "FromServerPipe.h"

namespace UXP1A_project {
namespace Client {

FromServerPipe::FromServerPipe(): m_fifo(0)
{
    makeFifoFile();
    openFifo();
}

FromServerPipe::~FromServerPipe()
{
    close(m_fifo);
    unlink(m_fifoPath.c_str());
}

const QString FromServerPipe::getPipeName() const
{
    using Shared::Configuration;
    QString path(Configuration::getServerFifoDir().c_str());
    path.append(getPid());

    return path;
}

/**
 * Pusta lista albo wyjatekjak po timeoucie
 */
QVariantList FromServerPipe::waitForMessage()
{
    using Shared::Configuration;
    int read_bytes = read(m_fifo, m_buf, MAX_BUF - 1);
    // for secure the byte after last read byte is set to zero:
    m_buf[read_bytes] = '\0';

    char code = m_buf[0];
    if (Configuration::getMes(code) == Configuration::TIME)
        return QVariantList();

    // total - pointer to first sign no read yet in current message
    int total = 2;
    QByteArray length_q(m_buf+total);
    total += length_q.size() + 1; // +1 because of separator '\0' after length
    long length_l = length_q.toLong(); // the value - length the rest of message

    QVariantList data;
    for (int i=0; i<length_l; ) {
        QString qba(m_buf+total);
        QVariant qv(qba);
        if (i+qba.size() >= MAX_BUF - 1)
            anotherRead(&total);
        // move pointers of first no read yet sign
        i += qba.size() + 1;    // pointer in the all message
        total += qba.size() + 1; // pointer in the current buffer
        data.append(qv);
    }

    return data;
}



bool FromServerPipe::makeFifoFile() const
{
    bool retVal = true;

    std::string path = getPipeName().toStdString();

    // disable umask for create fifo operation
    mode_t old_mask = umask(0);

    if (mkfifo(path.c_str(), S_IFIFO | 0777) < 0) {
        checkFifoErrors();
        retVal = false;
    }

    umask(old_mask);
    return retVal;
}

bool FromServerPipe::openFifo()
{
    using Shared::Configuration;
    // now we can remember full path to fifo file
    m_fifoPath = getPipeName().toStdString();

    // must be RDWR because in RDONLY function read() is non-blocking
    // when server is not connect to FIFO
    m_fifo = open(m_fifoPath.c_str(), O_RDWR);

    if (m_fifo <= 0 && errno == EINTR)
        qDebug() << "A signal was caught during open() client FIFO";

    if (m_fifo <= 0) {
        qDebug() << "Client open FIFO error.";
        return false;
    }
    return true;
}

void FromServerPipe::checkFifoErrors() const
{
    qDebug() << "FIFO error... //uzupelnic!!!";         //TODO uzupelnic
}

QString FromServerPipe::getPid() const
{
    pid_t p = getpid();
    return QString::number(p);
}

void FromServerPipe::anotherRead(int *total)
{

}

}//namespace Client
}//namespace UXP1A_project
