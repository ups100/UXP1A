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
#include <QVariant>
#include <QString>
#include <QTimer>

namespace UXP1A_project {
namespace Server {

class Demand
{

public:
    Demand();
    virtual ~Demand();

    void checkRecord(const QVariantList& record);
    bool isPullDemand();
    void sendRecord(QVariantList *record);
    void startTimer();

private:
    Shared::SearchPattern m_SearchPattern;
    ClientCommunication m_ClientCommunication;
    bool m_finalized;
    bool m_isPullDemand;
    QString m_pattern;
    long m_timeout;
    QTimer m_timer;

};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_B91FCB49_E030_4c12_B60E_CB447A493D12__INCLUDED_)
