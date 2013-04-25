///////////////////////////////////////////////////////////
//  LindaClient.h
//  Implementation of the Class LindaClient
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_BBD5C16D_5176_4930_BA02_6131DB72415B__INCLUDED_)
#define EA_BBD5C16D_5176_4930_BA02_6131DB72415B__INCLUDED_

#include "ServerCommunication.h"
#include <QVariant>
#include <QString>

namespace UXP1A_project {
namespace Client {

class LindaClient
{

public:
    LindaClient();
    virtual ~LindaClient();

    static QVariantList preview(const QString& pattern, long timeout);
    static QVariantList pull(const QString& pattern, long timeout);
    static void push(const QVariantList& record);

private:
    static ServerCommunication m_ServerCommunication;
};

}//namespace Client
}//namespace UXP1A_project

#endif // !defined(EA_BBD5C16D_5176_4930_BA02_6131DB72415B__INCLUDED_)
