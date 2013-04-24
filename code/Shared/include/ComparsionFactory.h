///////////////////////////////////////////////////////////
//  ComparsionFactory.h
//  Implementation of the Class ComparsionFactory
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_)
#define EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_

#include "Functor.h"

class ComparsionFactory
{

public:
    ComparsionFactory();
    virtual ~ComparsionFactory();
    Functor *m_Functor;

    static Functor getCmpFunctor(QString cmpSymbol);

};
#endif // !defined(EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_)
