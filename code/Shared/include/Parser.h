/**
 * @file Parser.h
 *
 * @date 28-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::Configuration
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_)
#define EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_

#include "SearchPattern.h"
#include <QStringList>

namespace UXP1A_project {
namespace Shared {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Class to parse and check given conditions and patterns of tuples
 */
class Parser
{

public:

    /**
     * @brief int typename
     */
    static const char *INT;
    static const char *INT_LESS, *INT_LESS_EQUAL, *INT_GREATER, *INT_GREATER_EQUAL;

    /**
     * @brief float typename
     */
    static const char *FLOAT;
    static const char *FLOAT_LESS, *FLOAT_LESS_EQUAL, *FLOAT_GREATER, *FLOAT_GREATER_EQUAL;

    /**
     * @brief string typename
     */
    static const char *STRING;
    static const char *STRING_LESS, *STRING_LESS_EQUAL, *STRING_GREATER, *STRING_GREATER_EQUAL;

    /**
     * @brief list of possible typenames in pattern
     */
    static const QStringList TYPES;
    static const QStringList INT_OPERATORS;
    static const QStringList FLOAT_OPERATORS;
    static const QStringList STRING_OPERATORS;

    /**
     * @breif C-tor
     */
    Parser();

    /**
     * @brief D-tor
     */
    virtual ~Parser();

    /**
     * @brief Checks whtether given conditions are well formatted
     *
     * @param conditions Stringified conditions to check
     *
     * @return true if proper pattern, false otherwise
     */
    static bool checkCondition(const QString& conditions);

    /**
     * @brief Parse stringified conditions to the SearchPattern object
     *
     * @param conditions Stringified conditions
     *
     * @example string:*, int:>2, float:<=5.2, string:"ex", float:<4
     *
     * @return Created SearchPattern object
     */
    static SearchPattern parseConditions(const QString& conditions);

    /**
     * @brief Makes a shorter pattern (first letters of types)
     *
     * @return Shorter pattern
     */
    static QString parseStruct(const QString& pattern);

};

}//namespace Shared
}//namesoace UXP1A_project

#endif // !defined(EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_)
