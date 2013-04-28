/**
 * @file SearchPattern.h
 *
 * @date 29-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::Configuration
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#include "SearchPattern.h"
#include "ComparisonFactory.h"

namespace UXP1A_project {
namespace Shared {

SearchPattern::SearchPattern()
{

}

SearchPattern::~SearchPattern()
{

}

void SearchPattern::addCondition(const QString& type, CompareOperations op,
        const QVariant& value)
{
    m_typePattern.append(type[0]);

    Condition condition(ComparisonFactory::getCmpFunctor(op), value);
    m_conditions.append(condition);
}

bool SearchPattern::check(const QVariantList& other)
{
    if (m_conditions.size() != other.size())
        return false;

    QList<Condition>::iterator cond_it = m_conditions.begin();
    QList<QVariant>::const_iterator data_it = other.begin();

    for (; cond_it != m_conditions.end(); ++cond_it, ++data_it) {
        if (!cond_it->check(*data_it))
            return false;
    }

    return true;
}

const QString& SearchPattern::getTypesPattern()
{
    return m_typePattern;
}

} //namespace Shared
} //namesoace UXP1A_project
