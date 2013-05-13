/**
 * @file Condition.cpp
 *
 * @date 27-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::Condition
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */
#include "Condition.h"

namespace UXP1A_project {
namespace Shared {

Condition::~Condition()
{

}

Condition::Condition(const Functor& cmpFun, const QVariant& data)
        : m_Functor(cmpFun), m_value(data)
{

}

bool Condition::check(const QVariant& data)
{
    return m_Functor(data, m_value);
}

} //namespace Shared
} //namesoace UXP1A_project
