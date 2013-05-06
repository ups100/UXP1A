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
#include "SearchPattern.h"
#include "Parser.h"

#include <QString>
#include <QVariantList>

namespace UXP1A_project {
namespace Client {

class ServerCommunication
{

public:
    ServerCommunication();
    virtual ~ServerCommunication();

    QVariantList sendPreview(const QString& pattern, long timeout);
    QVariantList sendPullData(const QString& pattern, long timeout);
    void sendPushData(const QString& pattern, const QVariantList& data);

private:
    ToServerPipe m_ToServerPipe;
    FromServerPipe m_FromServerPipe;

};

}//namespace Client
}//namespace UXP1A_project

#endif // !defined(EA_CB6AB119_B8C2_46c4_ABFA_E406179A4D60__INCLUDED_)
