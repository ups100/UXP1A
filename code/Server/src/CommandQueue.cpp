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
#include <QDebug>
#include "CommandDispatcher.h"

namespace UXP1A_project {
namespace Server {

CommandQueue::CommandQueue(CommandDispatcher *commandDispatcher)
        : m_commandDispatcher(commandDispatcher)
{

}

CommandQueue::~CommandQueue()
{
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
    qDebug() << "I'm waiting for commands. Please implement me";
    m_mutex.lock();
    m_mutex.lock();
    m_mutex.unlock();
    qDebug()<<"papa";
    QThread::currentThread()->quit();
}

} //namespace Server
} //namespace UXP1A_project
