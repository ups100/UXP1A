/**
 * @file CommandDispatcher.cpp
 *
 * @date 27-04-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class UXP1A_project::Server::CommandDispatcher
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#include "CommandDispatcher.h"
#include "Parser.h"
#include "Demand.h"
#include <QDebug>

namespace UXP1A_project {
namespace Server {

CommandDispatcher* CommandDispatcher::getInstance(int argc, char **argv)
{
    static CommandDispatcher instance(argc, argv);
    return &instance;
}

void CommandDispatcher::terminate()
{
    CommandDispatcher *disp = getInstance(0, 0L);

    if (QThread::currentThread() == disp->m_mainThread) {
        disp->m_commandQueue.terminate();
    } else {
        disp->m_commandQueue.closePipe();
        QThread::currentThread()->quit();
    }
}

CommandDispatcher::CommandDispatcher(int argc, char **argv)
        : m_commandQueue(this), m_eventLoop(argc, argv),
                m_mainThread(QThread::currentThread())
{

}

CommandDispatcher::~CommandDispatcher()
{

    foreach(QString key, this->m_tables.keys()) {
        delete m_tables[key];
    }
    m_tables.clear();
}

void CommandDispatcher::dispatchPreviewCommand(const QString& conditions,
        const QString& client, int timeout)
{
    QMetaObject::invokeMethod(this, "dispatchPreviewCommandSlot",
            Q_ARG(const QString &, conditions),
            Q_ARG(const QString &, client), Q_ARG(int, timeout));
}

void CommandDispatcher::dispatchPullCommand(const QString& conditions,
        const QString& client, int timeout)
{
    QMetaObject::invokeMethod(this, "dispatchPullCommandSlot",
            Q_ARG(const QString &, conditions),
            Q_ARG(const QString &, client), Q_ARG(int, timeout));
}

void CommandDispatcher::dispatchPushCommand(const QString& pattern,
        const QVariantList& data)
{
    QMetaObject::invokeMethod(this, "dispatchPushCommandSlot",
            Q_ARG(const QString &, pattern),
            Q_ARG(const QVariantList&, data));
}

void CommandDispatcher::dispatchPreviewCommandSlot(const QString& conditions,
        const QString& client, int timeout)
{
    Shared::SearchPattern *searchPattern = Shared::Parser::parseConditions(
            conditions);

    Demand *newDemand = new Demand(searchPattern, client, false, timeout);

    if (this->m_tables.contains(searchPattern->getTypesPattern())) {
        m_tables[searchPattern->getTypesPattern()]->addDemand(newDemand);
    } else {
        RecordTable *newRecordTable = new RecordTable();
        m_tables.insert(searchPattern->getTypesPattern(), newRecordTable);
        newRecordTable->addDemand(newDemand);
    }
}

void CommandDispatcher::dispatchPullCommandSlot(const QString& conditions,
        const QString& client, int timeout)
{
    Shared::SearchPattern *searchPattern = Shared::Parser::parseConditions(
            conditions);

    Demand *newDemand = new Demand(searchPattern, client, true, timeout);

    if (this->m_tables.contains(searchPattern->getTypesPattern())) {
        m_tables[searchPattern->getTypesPattern()]->addDemand(newDemand);
    } else {
        RecordTable *newRecordTable = new RecordTable();
        m_tables.insert(searchPattern->getTypesPattern(), newRecordTable);
        newRecordTable->addDemand(newDemand);
    }
}

void CommandDispatcher::dispatchPushCommandSlot(const QString& pattern,
        const QVariantList& data)
{
    if (this->m_tables.contains(pattern)) {
        m_tables[pattern]->addRecord(data);
    } else {
        RecordTable *newRecordTable = new RecordTable();
        m_tables.insert(pattern, newRecordTable);
        newRecordTable->addRecord(data);
    }
}

int CommandDispatcher::exec()
{
    m_commandQueue.exec();
    return m_eventLoop.exec();
}

} //namespace Server
} //namespace UXP1A_projec
