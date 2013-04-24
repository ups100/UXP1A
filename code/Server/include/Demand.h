///////////////////////////////////////////////////////////
//  Demand.h
//  Implementation of the Class Demand
//  Created on:      24-kwi-2013 11:07:18
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_B91FCB49_E030_4c12_B60E_CB447A493D12__INCLUDED_)
#define EA_B91FCB49_E030_4c12_B60E_CB447A493D12__INCLUDED_

#include "ClientCommunication.h"
#include "SearchPattern.h"

class Demand
{

public:
	Demand();
	virtual ~Demand();
	ClientCommunication *m_ClientCommunication;
	SearchPattern *m_SearchPattern;

	void checkRecord(QVariant record);
	bool isPullDemand();
	void sendRecord(QVariant record);
	void startTimer();

private:
	bool m_finalized;
	bool m_isPullDemand;
	QString m_pattern;
	long m_timeout;
	QTimer m_timer;

};
#endif // !defined(EA_B91FCB49_E030_4c12_B60E_CB447A493D12__INCLUDED_)
