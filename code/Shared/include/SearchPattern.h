/**
 * @file SearchPattern.h
 *
 * @date 29-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::SerachPattern
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(EA_CB41E0A0_6E76_4c34_90D8_0BD01E7DFAB7__INCLUDED_)
#define EA_CB41E0A0_6E76_4c34_90D8_0BD01E7DFAB7__INCLUDED_

#include "Condition.h"
#include "CompareOperations.h"

namespace UXP1A_project {
namespace Shared {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Class represents pattern for searching appropriate tuple
 */
class SearchPattern
{

public:

    /**
     * @brief C-tor
     */
    SearchPattern();

    /**
     * @brief D-tor
     */
    virtual ~SearchPattern();

    /**
     * @brief Check whether tuple pass all search pattern conditions
     *
     * @param other Tuple to check
     *
     * @return True if all conditions are passed, false otherwise
     */
    bool check(const QVariantList& other);

    /**
     * @brief Add condition to search pattern
     *
     * @param type Type of tuple attribute
     *
     * @param op Enumeration defined symbol of compare operator
     *
     * @param value Value to compare tuples to it, if CompareOpeartions::ANYTHING then value is ignored
     */
    void addCondition(const QString& type, CompareOperations op,
            const QVariant& value);

    /**
     * @brief Get pattern describing searching tuple
     * <br /> Example:
     * @code
     *      string, int, float, int  =>  sifi
     * @endcode
     *
     * @return Pattern of tuple
     */
    const QString& getTypesPattern();

private:

    /**
     * @brief Pattern from first letters of types describing type of tuple
     */
    QString m_typePattern;

    /**
     * @brief List of conditions which are needed to be 'passed'
     */
    QList<Condition> m_conditions;
};

} //namespace Shared
} //namesoace UXP1A_project

#endif // !defined(EA_CB41E0A0_6E76_4c34_90D8_0BD01E7DFAB7__INCLUDED_)
