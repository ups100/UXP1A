/**
 * @file FromServerPipe.cpp
 *
 * @date 29-04-2013
 *
 * @author Sosnowski Jacek
 *
 * @brief Implementation of the Class UXP1A_project::Client::FromServerPipe
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#include "FromServerPipe.h"
#include "ClientFifoException.h"

namespace UXP1A_project {
namespace Client {

FromServerPipe::FromServerPipe()
        : m_fifo(0)
{
    try {
        makeFifoFile();
        openFifo();
    } catch (ClientFifoException& e) {
        throw e;
    }
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

QVariantList FromServerPipe::waitForMessage(const QString& pattern)
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
    QByteArray length_q(m_buf + total);
    total += length_q.size() + 1; // +1 because of separator '\0' after length
    long length_l = length_q.toLong(); // the value - length the rest of message

    QVariantList data;
    int pIter = 0; //Pattern Iterator
    for (int i = 0; i < length_l;) {
        char mesType = pattern[pIter++].toAscii();
        int recivLength = 0;   //below we set the receive data length
        QVariant qv;
        if (mesType == 's') {
            QString qstr(m_buf + total);
            recivLength = qstr.size() + 1; // +1 because \0 termination
            qv = QVariant(qstr);
        } else if (mesType == 'i') {
            int dInt;
            memcpy(&dInt, m_buf + total, sizeof(int));
            recivLength = sizeof(int);
            qv = QVariant(dInt);
        } else if (mesType == 'f') {
            float dFloat;
            memcpy(&dFloat, m_buf + total, sizeof(float));
            recivLength = sizeof(float);
            qv = QVariant(dFloat);
        }

        // if qba reach end of buffer - it require another read operation
        if (total + recivLength >= MAX_BUF - 1) {
            anotherRead(&total);
            pIter--; // we will read this part of data second time
            continue;
        }
        // move pointers of first no read yet sign
        i += recivLength;    // pointer in the all message
        total += recivLength; // pointer in the current buffer
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
        QString error = checkFifoErrors();
        throw ClientFifoException(error.toStdString());
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

    QString error;
    if (m_fifo <= 0 && errno == EINTR)
        error.append("A signal was caught during open() client FIFO. ");

    if (m_fifo <= 0) {
        error.append("Opening client FIFO error. ");
        throw ClientFifoException(error.toStdString());
    }
    return true;
}

QString FromServerPipe::checkFifoErrors() const
{
    QString error("Create client FIFO error... ");

    if (errno == EACCES)
        error.append("Permission deny. ");

    if (errno == EEXIST)
        error.append("File already exist. ");

    if (errno == ENOENT)
        error.append("File on path does not exist or dangling symbolic link. ");

    if (errno == ENOTDIR)
        error.append("Using not directory in pathname. ");

    if (errno == EROFS)
        error.append("Pathname refers to a read-only file system. ");

    return error;
}

QString FromServerPipe::getPid() const
{
    pid_t p = getpid();
    return QString::number(p);
}

void FromServerPipe::anotherRead(int *total)
{
    // we have some data in the end of buffer but we don't know if it full part of data
    // so we move that rest to the begin of buffer and read more data
    int rest_length = MAX_BUF - *total - 1; // -1 because last sign is always '\0'
    memcpy(m_buf, m_buf + *total, rest_length);

    int read_bytes = read(m_fifo, m_buf + rest_length,
            MAX_BUF - rest_length - 1);
    // for secure the byte after last read byte is set to zero:
    m_buf[rest_length + read_bytes] = '\0';

    // total points to first no read sign in the buffer so:
    *total = 0;
}

} //namespace Client
} //namespace UXP1A_project
