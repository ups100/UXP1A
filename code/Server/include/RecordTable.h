///////////////////////////////////////////////////////////
//  RecordTable.h
//  Implementation of the Class RecordTable
//  Created on:      24-kwi-2013 11:07:19
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_EE4E919E_81D9_44ea_B28F_CBC84C61DC9D__INCLUDED_)
#define EA_EE4E919E_81D9_44ea_B28F_CBC84C61DC9D__INCLUDED_

#include "Demand.h"

class RecordTable
{

public:
	RecordTable();
	virtual ~RecordTable();
	Demand *m_Demand;

	void addDemand(Demand * demand);
	void addRecord(QVariant record);
	void removeDemand(Demand* demand);

private:
	QList<QVariantList> m_records;

};
#endif // !defined(EA_EE4E919E_81D9_44ea_B28F_CBC84C61DC9D__INCLUDED_)
