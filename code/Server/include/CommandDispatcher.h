///////////////////////////////////////////////////////////
//  CommandDispatcher.h
//  Implementation of the Class CommandDispatcher
//  Created on:      24-kwi-2013 11:07:18
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_)
#define EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_

#include "RecordTable.h"
#include <QString>
#include <QVariant>
#include <QMap>

namespace UXP1A_project {
namespace Server {

class CommandDispatcher
{

public:
    CommandDispatcher();
    virtual ~CommandDispatcher();

    void dispatchPreviewCommand(const QString& conditions, long timeout);
    void dispatchPullCommand(const QString& condition, long timeout);
    void dispatchPushCommand(const QString& pattern, const QVariantList& data);

private:
    QMap<QString, RecordTable> m_tables;

};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_)
