/**
 * @file CommandQueue.cpp
 *
 * @date 27-04-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class UXP1A_project::Server::RecordTable
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#include "CommandQueue.h"
#include "Configuration.h"
#include <QDebug>

namespace UXP1A_project {
namespace Server {

CommandQueue::CommandQueue(CommandDispatcher *commandDispatcher)
        : m_commandDispatcher(commandDispatcher), m_fifo(0)
{
    if (!isDirExists())
        makeDir();      //throw exception

    if (!isFifoExists())
        makeFifoFile();
    else {
        qDebug() << "There is another instance of server running.";
        throw std::string("Stop: another instance of server is running.");
    }

//    for(int i=0; i<MAX_BUF; ++i)      // TODO del lines
//        m_buf[i] = 0;
}

CommandQueue::~CommandQueue()
{
// Przenies te dwie linijki gdzies dalej za terminate
    close(m_fifo);              // close descriptor
    unlink(m_fifoPath.c_str()); // delete fifo file
    // **********************
    if (m_additionalThread.isRunning()) {
        m_additionalThread.wait();
    }
}

void CommandQueue::exec()
{
    if (m_additionalThread.isRunning())
        return;

    this->moveToThread(&m_additionalThread);

    connect(&m_additionalThread, SIGNAL(started()), this,
            SLOT(waitForCommands()));
    connect(&m_additionalThread, SIGNAL(finished()),
            QCoreApplication::instance(), SLOT(quit()));
    m_additionalThread.start();
}

void CommandQueue::terminate()
{
    //write exit message to fifo but now only
    m_mutex.unlock();
    closePipe();
}

void CommandQueue::closePipe()
{
    qDebug() << "Jacek please implement me";
}

void CommandQueue::waitForCommands()
{
//   m_mutex.lock();
//    m_mutex.lock();
//    m_mutex.unlock();
//    qDebug()<<"papa";
//    QThread::currentThread()->quit();

    if ( !openFifo() )
        return;

    qDebug() << "Ready...";

    while (true) {
        int read_bytes = read(m_fifo, m_buf, MAX_BUF - 1);
        // for secure the byte after last read byte is set to zero:
        m_buf[read_bytes] = '\0';
        int rest_bytes = MAX_BUF; //number of sign to read
        //Shared::Configuration::displayBuffer(m_buf, MAX_BUF); //TODO del

        char *in = m_buf;
        while (in[0] != '\0') {
            char code = in[0]; //in[1] == '\0'
            // ptr - pointer to first sign no read yet in current message
            int ptr = 2;
            QByteArray length_q(in + ptr);
            ptr += length_q.size() + 1; // +1 because of separator '\0' after length
            long length_l = length_q.toLong(); // the value - length the rest of message

            rest_bytes -= ptr; // number of ptr signs already read
            if (rest_bytes <= 1 || rest_bytes < length_l) {
                //it means that we don't have all message in the buffer
                // so we move rest data and fill buffer with next data from FIFO
                anotherRead(rest_bytes+ptr, &in);
                rest_bytes = MAX_BUF;           // buffer is full again
                //Shared::Configuration::displayBuffer(m_buf, MAX_BUF);     // TODO del
                continue;
            }

            // qDebug() << "Kod: " << code; qDebug() << "Len: " << length_l;    // TODO del
            // continue reading the rest of message - using specific method
            readTuple(in + ptr, length_l, code);

            ptr += length_l; // not +1 because lenght_l includes separator sign '\0'
            rest_bytes -= length_l; // there is less bytes in buffer

            in = in + ptr; // points to next message
        }
    }
}

void dispDebug(QString pid, QString patt, QString tim) {
    qDebug() << "PID: " << pid;
    qDebug() << "Pat: " << patt;
    qDebug() << "Tim: " << tim;
}

void CommandQueue::readTuple(const char *buf, const int length, const char code) const
{
    using Shared::Configuration;

    QString pid_s = QString::fromAscii(buf);
    int ptr = pid_s.size() + 1; // +1 because of separator sign '\0'

    QString pattern(buf + ptr);
    ptr += pattern.size() + 1;

    // messages PULL and PUSH end with long timeout
    if (Configuration::getMes(code) == Configuration::PULL) {
        QString tim_s = QString::fromAscii(buf + ptr);
        long timeout = tim_s.toLong();
        m_commandDispatcher->dispatchPullCommand(pattern, pid_s, timeout);
//        dispDebug(pid_s, pattern, tim_s); qDebug() << "TIM(int): " << timeout ;     // TODO del
    }

    if (Configuration::getMes(code) == Configuration::PREV) {
        QString tim_s = QString::fromAscii(buf + ptr);
        long timeout = tim_s.toLong();
        m_commandDispatcher->dispatchPreviewCommand(pattern, pid_s, timeout);
//        dispDebug(pid_s, pattern, tim_s); qDebug() << "TIM(int): " << timeout ;     // TODO del
    }

    // message PUSH ends with QVariantList data
    if (Configuration::getMes(code) == Configuration::PUSH) {
        QVariantList data;
        for (int i=ptr; i<length; ) {
            QString qba(buf+i);
            QVariant qv(qba);
            i += qba.size() + 1;
            data.append(qv);
        }
        m_commandDispatcher->dispatchPushCommand(pattern, data);
//        qDebug() << "Pushuje taki pattern: " << pattern << "   i takie dane: " << data; // TODO del
//        qDebug();
//        dispDebug(pid_s, pattern, QString(""));  qDebug() << data;
    }

}

void CommandQueue::anotherRead(int restBytes, char **in)
{
    // The last byte in the buffer is always '/0' - so we omit him
    restBytes--;
    // move rest data from the end of buffer to the front of it
    memcpy(m_buf, *in, restBytes);
    *in = m_buf; // change 'in' pointer - it must still point to rest data

    // filling buffer free space with next data from FIFO
    int read_bytes = read(m_fifo, m_buf+restBytes, MAX_BUF - restBytes - 1);
    // for secure the byte after last read byte is set to zero:
    m_buf[restBytes+read_bytes] = '\0';
}

bool CommandQueue::isDirExists() const
{
    using Shared::Configuration;
    // checking if server fifo directory exist
    std::string dir = Configuration::getServerFifoDir();
    struct stat st;
    if (stat(dir.c_str(), &st) == 0)
        // below check if last inode on path is directory
        if (S_ISDIR(st.st_mode))
            return true;
        else
            return false;

    return false;
}

bool CommandQueue::makeDir() const
{
    using Shared::Configuration;
    // checking if server fifo directory exist
    std::string dir = Configuration::getServerFifoDir();

    int status = 0;
    status = mkdir(dir.c_str(), 0777);

    if (status < 0 && errno == EACCES) {
        qDebug()
                << "Server doesn't have privileges to make the FIFO directory.";
    }
    if (status < 0 && errno == EEXIST) {
        qDebug()
                << "Server can't make directory - there is some file with the same name - name collision.";
    }
    if (status < 0 && errno == EROFS) {
        qDebug()
                << "Server can't make directory. The parent directory resides on a read-only file system.";
    }
    if (status < 0)
        throw std::string("Error while creating server FIFO path. ");

    return true;
}

bool CommandQueue::isFifoExists() const
{
    using Shared::Configuration;
    // checking if server fifo file exist
    std::string file = Configuration::getServerFifoName();
    struct stat st;
    if (stat(file.c_str(), &st) == 0)
        // check if file which we find is exactly FIFO
        if (S_ISFIFO(st.st_mode))
            return true;
        else
            return false;

    return false;
}

bool CommandQueue::makeFifoFile() const
{
    using Shared::Configuration;
    bool retVal = true;

    std::string path = Configuration::getServerFifoDir();
    std::string file = Configuration::getServerFifoName();
    path.append(file);

    // disable umask for create fifo operation
    mode_t old_mask = umask(0);

    if (mkfifo(path.c_str(), S_IFIFO | 0777) < 0) {
        checkFifoErrors();
        retVal = false;
        throw std::string("Server error while creating server fifo file.");
    }

    umask(old_mask);
    return retVal;
}

void CommandQueue::checkFifoErrors() const
{
    qDebug() << "!!! Create server FIFO file error... ";

    if (errno == EACCES)
        qDebug() << "Permission deny";

    if (errno == EEXIST)
        qDebug() << "File already exist";

    if (errno == ENOENT)
        qDebug() << "File on path does not exist or dangling symbolic link";

    if (errno == ENOTDIR)
        qDebug() << "Using not directory in pathname.";

    if (errno == EROFS)
        qDebug() << "Pathname refers to a read-only file system";
}

bool CommandQueue::openFifo()
{
    using Shared::Configuration;
    // now we can remember full path to fifo file
    m_fifoPath = Configuration::getServerFifoDir();
    m_fifoPath.append(Configuration::getServerFifoName());

    // must be RDWR because in RDONLY function read() is non-blocking
    // when no clients are connect to FIFO
    m_fifo = open(m_fifoPath.c_str(), O_RDWR);

    if (m_fifo <= 0 && errno == EINTR)
        qDebug() << "A signal was caught during open() server FIFO";

    if (m_fifo <= 0) {
        qDebug() << "Server open FIFO error.";
        return false;
    }
    return true;
}

} //namespace Server
} //namespace UXP1A_project
