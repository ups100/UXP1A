///////////////////////////////////////////////////////////
//  Configuration.h
//  Implementation of the Class Configuration
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_5B26D2EF_5E9E_4623_A7EB_9A8732F16065__INCLUDED_)
#define EA_5B26D2EF_5E9E_4623_A7EB_9A8732F16065__INCLUDED_

#include <QString>

namespace UXP1A_project {
namespace Shared {

//singleton albo qstring jako pole static
class Configuration
{

public:
    Configuration();
    virtual ~Configuration();

    static const QString& getServerFifoPath();

};

}//namespace Shared
}//namesoace UXP1A_project

#endif // !defined(EA_5B26D2EF_5E9E_4623_A7EB_9A8732F16065__INCLUDED_)
