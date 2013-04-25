///////////////////////////////////////////////////////////
//  ComparsionFactory.h
//  Implementation of the Class ComparsionFactory
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_)
#define EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_

#include "Functor.h"
#include <QString>
#include <QMap>

namespace UXP1A_project {
namespace Shared {

//ma to byc singleton ukryty
class ComparsionFactory
{

public:
    virtual ~ComparsionFactory();

    static Functor getCmpFunctor(const QString& cmpSymbol);

private:
    ComparsionFactory();
    QMap<QString, Functor> m_functors;
};

}//namespace Shared
}//namesoace UXP1A_project

#endif // !defined(EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_)
