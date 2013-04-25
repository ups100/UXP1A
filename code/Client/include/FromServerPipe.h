///////////////////////////////////////////////////////////
//  FromServerPipe.h
//  Implementation of the Class FromServerPipe
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_)
#define EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_

#include <QString>
#include <QVariant>

namespace UXP1A_project {
namespace Client {

/**
 * Proxy on write
 */
class FromServerPipe
{

public:
    FromServerPipe();
    virtual ~FromServerPipe();

    const QString& getPipeName();
    QVariantList waitForMessage();

};

}//namespace Client
}//namespace UXP1A_project
#endif // !defined(EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_)
