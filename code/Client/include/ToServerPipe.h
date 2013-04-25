///////////////////////////////////////////////////////////
//  ToServerPipe.h
//  Implementation of the Class ToServerPipe
//  Created on:      24-kwi-2013 11:04:00
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_)
#define EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_

#include <QString>
#include <QVariant>

namespace UXP1A_project {
namespace Client {

class ToServerPipe
{

public:
    ToServerPipe();
    virtual ~ToServerPipe();

    void writePreviewMessage(const QString& pattern, long timeout);
    void writePullDataMessage(const QString& condition, long timeout);
    void writePushDataMessage(const QString& pattern, const QVariantList& data);

};

}//namespace Client
}//namespace UXP1A_project

#endif // !defined(EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_)
