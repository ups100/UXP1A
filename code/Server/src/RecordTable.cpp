/**
 * @file RecordTable.h
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

#include "RecordTable.h"
#include "Demand.h"

namespace UXP1A_project {
namespace Server {

RecordTable::RecordTable()
{

}

RecordTable::~RecordTable()
{

}

void RecordTable::addDemand(Demand* demand)
{
    foreach(QVariantList *record, m_records)
    {
        if(demand->checkRecord(*record))
        {
            demand->sendRecord(*record);
            if(demand->isPullDemand())
            {
                m_records.removeOne(record);
                delete record;
            }

            delete demand;
            demand = 0L;
            break;
        }
    }

    //we was unable to satisfy the demand with any of current records, let's wait
    if(demand != 0L)
    {
        m_demands.append(demand);
        demand->setRecordTable(this);
    }
}

void RecordTable::addRecord(const QVariantList& record)
{
    bool addIt = true;
    foreach(Demand *demand, m_demands)
    {
        if(demand->checkRecord(record))
        {
            demand->sendRecord(record);
            if(demand->isPullDemand())
            {
                addIt = false;
            }

            m_demands.removeOne(demand);
            //schedule it for later deletion
            QMetaObject::invokeMethod(demand, SLOT(deleteLater()), Qt::QueuedConnection);
        }
    }

    if(addIt)
    {
        QVariantList *newRecord = new QVariantList(record);
        m_records.append(newRecord);
    }
}

void RecordTable::removeDemand(Demand* demand)
{
    if(m_demands.contains(demand))
    {
        m_demands.removeOne(demand);
        QMetaObject::invokeMethod(demand, SLOT(deleteLater()), Qt::QueuedConnection);
    }
}

} //namespace Server
} //namespace UXP1A_project
