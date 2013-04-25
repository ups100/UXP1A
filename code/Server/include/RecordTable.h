///////////////////////////////////////////////////////////
//  RecordTable.h
//  Implementation of the Class RecordTable
//  Created on:      24-kwi-2013 11:07:19
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_EE4E919E_81D9_44ea_B28F_CBC84C61DC9D__INCLUDED_)
#define EA_EE4E919E_81D9_44ea_B28F_CBC84C61DC9D__INCLUDED_

#include "Demand.h"
#include <QList>
#include <QVariant>

namespace UXP1A_project {
namespace Server {

class RecordTable
{

public:
    RecordTable();
    virtual ~RecordTable();

    void addDemand(Demand* demand);
    void addRecord(QVariantList* record);
    void removeDemand(Demand* demand);

private:
    QList<QVariantList*> m_records;
    QList<Demand*> m_demands;
};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_EE4E919E_81D9_44ea_B28F_CBC84C61DC9D__INCLUDED_)
