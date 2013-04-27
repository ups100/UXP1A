///////////////////////////////////////////////////////////
//  ComparisonFactory.h
//  Implementation of the Class ComparisonFactory
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
class ComparisonFactory
{

public:
    enum CmpSymbol
    {
        INT_EQUAL,
        INT_LESS,
        INT_LESS_EQUAL,
        INT_GREATER,
        INT_GREATER_EQUAL,
        FLOAT_LESS,
        FLOAT_LESS_EQUAL,
        FLOAT_GREATER,
        FLOAT_GREATER_EQUAL,
        STRING_EQUAL,
        STRING_LESS,
        STRING_LESS_EQUAL,
        STRING_GREATER,
        STRING_GREATER_EQUAL,
        ANYTHING
    };

    virtual ~ComparisonFactory();

    static Functor getCmpFunctor(CmpSymbol cmpSymbol);

private:
    ComparisonFactory();
    ComparisonFactory(const ComparisonFactory&);
    ComparisonFactory& operator=(const ComparisonFactory&);

    QMap<CmpSymbol, Functor> m_functors;

    template<class Type, class Func>
    Functor::PF stdFunction();
};

} //namespace Shared
} //namesoace UXP1A_project

#endif // !defined(EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_)
