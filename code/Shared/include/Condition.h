///////////////////////////////////////////////////////////
//  Condition.h
//  Implementation of the Class Condition
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_A18CDE82_D1C3_4028_91EE_C28369DCB05F__INCLUDED_)
#define EA_A18CDE82_D1C3_4028_91EE_C28369DCB05F__INCLUDED_

#include "Functor.h"

namespace UXP1A_project {
namespace Shared {

class Condition
{

public:
    Condition();
    virtual ~Condition();

    Condition(Functor cmpFun, const QVariant& data);
    bool check(const QVariant& data);

private:
    QVariant m_value;
    Functor m_Functor;
};

}//namespace Shared
}//namesoace UXP1A_project

#endif // !defined(EA_A18CDE82_D1C3_4028_91EE_C28369DCB05F__INCLUDED_)
