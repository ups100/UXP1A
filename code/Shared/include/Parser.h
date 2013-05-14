/**
 * @file Parser.h
 *
 * @date 28-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::Parser
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

    /**
     * @brief RegExp pattern to get parts of tuples
     */
    static const QString CONDITIONS_PATTERN;

    /**
     * @brief RegExp pattern to parse single tuple part
     */
    static const QString PARSE_CONDITIONS_PATTERN;

public:

    /**
     * @brief int typename
     */
    static const char *INT;
    /**
     * @brief int operators
     */
    static const char *INT_EQUAL, *INT_LESS, *INT_LESS_EQUAL, *INT_GREATER,
            *INT_GREATER_EQUAL;

    /**
     * @brief float typename
     */
    static const char *FLOAT;
    /**
     * @brief float operators
     */
    static const char *FLOAT_LESS, *FLOAT_LESS_EQUAL, *FLOAT_GREATER,
            *FLOAT_GREATER_EQUAL;

    /**
     * @brief string typename
     */
    static const char *STRING;
    /**
     * @brief string operators
     */
    static const char *STRING_EQUAL, *STRING_LESS, *STRING_LESS_EQUAL,
            *STRING_GREATER, *STRING_GREATER_EQUAL;

    /**
     * @brief Anything character sequence => default '*'
     */
    static const char *ANYTHING;

    /**
     * @brief List of possible typenames in pattern
     */
    static const QStringList TYPES;
    /**
     * @brief List of available operators for each type
     */
    static const QStringList INT_OPERATORS, FLOAT_OPERATORS, STRING_OPERATORS;

    /**
     * @brief Available short format of types
     */
    static const char *SHORT_TYPE_INT, *SHORT_TYPE_FLOAT, *SHORT_TYPE_STRING;
    /**
     * @brief List of available short format of types
     */
    static const QStringList SHORT_TYPES;

    /**
     * @brief C-tor
     */
    Parser();

    /**
     * @brief D-tor
     */
    virtual ~Parser();

    /**
     * @brief Ch-ecks whtether given conditions are well formatted
     * <br /> Example:
     * @code
     *      string:*, int:>2, float:<=5.2, string:"ex", float:<4
     * @endcode
     *
     * @param conditions Stringified conditions to check
     *
     * @note There are available characters in string: in ASCII from ! to ~ without "
     *
     * @throws NumericLimitException if limit of int or float exceeded
     *
     * @return true if proper pattern, false otherwise
     */
    static bool checkCondition(const QString& conditions);

    /**
     * @brief Parse stringified conditions to the SearchPattern object
     * <br /> Example:
     * @code
     *      string:*, int:>2, float:<=5.2, string:"ex", float:<4
     * @endcode
     *
     *
     * @param conditions Stringified conditions
     *
     * @note There are available characters in string: in ASCII from ! to ~ without "
     *
     * @throws ParserException if bad conditions
     * @throws NumericLimitException if limit of int or float exceeded
     *
     * @return Created SearchPattern object pointer
     */
    static SearchPattern* parseConditions(const QString& conditions);

    /**
     * @brief Makes a shorter pattern (mostly first letters of types)
     *
     * @throws ParserException if bad pattern
     * @throws NumericLimitException if limit of int or float exceeded
     *
     * @return Shorter pattern
     */
    static QString parseStruct(const QString& pattern);

    /**
     * @brief Makes a short pattern of types of list values (mostly first letters of each type)
     *
     * @throws ParserException if not available values
     *
     * @note Available values are: int, float, string
     *
     * @return Short pattern
     */
    static QString parseStruct(const QVariantList& list);

};

} //namespace Shared
} //namesoace UXP1A_project

#endif // !defined(EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_)
