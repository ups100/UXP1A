/**
 * @file Functor.cpp
 *
 * @date 27-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::Functor
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#include "Functor.h"

namespace UXP1A_project {
namespace Shared {

Functor::Functor()
{

}

Functor::Functor(PF cmpFunction)
        : m_cmpFunction(cmpFunction)
{

}

Functor::~Functor()
{

}

bool Functor::operator()(const QVariant& left, const QVariant& right)
{
    return m_cmpFunction(left, right);
}

} //namespace Shared
} //namesoace UXP1A_project
