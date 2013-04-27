///////////////////////////////////////////////////////////
//  Functor.cpp
//  Implementation of the Class Functor
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "Functor.h"

namespace UXP1A_project {
namespace Shared {

Functor::Functor()
{

}

Functor::Functor(PF cmpFunction): m_cmpFunction(cmpFunction)
{

}

Functor::~Functor()
{

}

bool Functor::operator()(const QVariant& left, const QVariant& right)
{
    return m_cmpFunction(left, right);
}

}//namespace Shared
}//namesoace UXP1A_project
