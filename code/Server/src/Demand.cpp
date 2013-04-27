/**
 * @file Demand.cpp
 *
 * @date 27-04-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class UXP1A_project::Server::Demand
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#include "Demand.h"
#include "RecordTable.h"

namespace UXP1A_project {
namespace Server {

Demand::Demand(Shared::SearchPattern* pattern, const QString& client,
        bool isPull, int timeout)
        : m_searchPattern(pattern), m_clientCommunication(client),
                m_finalized(false), m_isPullDemand(isPull), m_timeout(timeout),
                m_recordTable(0L)
{

}

Demand::~Demand()
{
    m_timer.stop();
    delete m_searchPattern;
}

void Demand::setRecordTable(RecordTable *recordTable)
{
    if (m_recordTable != 0L)
        return;

    m_recordTable = recordTable;

    if (m_timeout != -1) {
        m_timer.setInterval(m_timeout);
        m_timer.setSingleShot(true);
        connect(&m_timer, SIGNAL(timeout()), this, SLOT(demandTimeout()),
                Qt::QueuedConnection);
        m_timer.start();
    }
}

bool Demand::checkRecord(const QVariantList& record) const
{
    if (m_searchPattern != 0L) {
        return m_searchPattern->check(record);
    }
    return false;
}

bool Demand::isPullDemand() const
{

    return m_isPullDemand;
}

void Demand::sendRecord(const QVariantList& record)
{
    m_finalized = true;
    m_timer.stop();

    m_clientCommunication.sendRecord(m_searchPattern->getTypesPattern(), record);
}

int Demand::getTimeout() const
{
    return m_timeout;
}

void Demand::demandTimeout()
{
    if(m_finalized) return;

    m_clientCommunication.sendTimeoutInfo();

    if(m_recordTable != 0L) m_recordTable->removeDemand(this);
}

} //namespace Server
} //namespace UXP1A_project
