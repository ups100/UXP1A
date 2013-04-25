///////////////////////////////////////////////////////////
//  ServerCommunication.h
//  Implementation of the Class ServerCommunication
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_CB6AB119_B8C2_46c4_ABFA_E406179A4D60__INCLUDED_)
#define EA_CB6AB119_B8C2_46c4_ABFA_E406179A4D60__INCLUDED_

#include "ToServerPipe.h"
#include "FromServerPipe.h"

class ServerCommunication
{

public:
    ServerCommunication();
    virtual ~ServerCommunication();
    ToServerPipe *m_ToServerPipe;
    FromServerPipe *m_FromServerPipe;

    QVariantList sendPreview(QString pattern, long timeout);
    QVariantList sendPullData(QString pattern, long timeout);
    void sendPushData(QString pattern, QVariantLis data);

};
#endif // !defined(EA_CB6AB119_B8C2_46c4_ABFA_E406179A4D60__INCLUDED_)
