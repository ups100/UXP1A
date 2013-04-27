/**
 * @file Parser.cpp
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

#include "Parser.h"
#include <QRegExp>

#include <QList>
namespace UXP1A_project {
namespace Shared {

const char *Parser::INT = "int", *Parser::INT_LESS = "<",
        *Parser::INT_LESS_EQUAL = "<=", *Parser::INT_GREATER = ">",
        *Parser::INT_GREATER_EQUAL = ">=";
const char *Parser::FLOAT = "float", *Parser::FLOAT_LESS = "<",
        *Parser::FLOAT_LESS_EQUAL = "<=", *Parser::FLOAT_GREATER = ">",
        *Parser::FLOAT_GREATER_EQUAL = ">=";
const char *Parser::STRING = "string", *Parser::STRING_LESS = "<",
        *Parser::STRING_LESS_EQUAL = "<=", *Parser::STRING_GREATER = ">",
        *Parser::STRING_GREATER_EQUAL = ">=";

const QStringList Parser::TYPES = QStringList() << Parser::INT << Parser::FLOAT
        << Parser::STRING;
const QStringList Parser::INT_OPERATORS = QStringList() << Parser::INT_LESS
        << Parser::INT_LESS_EQUAL << Parser::INT_GREATER
        << Parser::INT_GREATER_EQUAL;
const QStringList Parser::FLOAT_OPERATORS = QStringList() << Parser::FLOAT_LESS
        << Parser::FLOAT_LESS_EQUAL << Parser::FLOAT_GREATER
        << Parser::FLOAT_GREATER_EQUAL;
const QStringList Parser::STRING_OPERATORS = QStringList()
        << Parser::STRING_LESS << Parser::STRING_LESS_EQUAL
        << Parser::STRING_GREATER << Parser::STRING_GREATER_EQUAL;

Parser::Parser()
{

}

Parser::~Parser()
{

}

/**
 * @note operators whether value is equal "*", will be ignored
 */
bool Parser::checkCondition(const QString& conditions)
{
    QString pattern = "((";
    pattern += QString("(") + INT + ":\\s?(" + INT_OPERATORS.join("|") + ")?(\\d+|\\*))";
    pattern += "|";
    pattern += QString("(") + FLOAT + ":\\s?(" + FLOAT_OPERATORS.join("|") + ")?((\\d+\\.?\\d*)|\\*))";
    pattern += "|";
    pattern += QString("(") + STRING + ":\\s?(" + STRING_OPERATORS.join("|") + ")?(\".*\"|\\*))";
    pattern += "),?\\s?)+";

    QRegExp r(pattern);

    return r.exactMatch(conditions);
}

SearchPattern Parser::parseConditions(const QString& conditions)
{

    return SearchPattern();
}

QString Parser::parseStruct(const QString& pattern)
{
    QString shorter;
    int pos = 0;

    QRegExp r(TYPES.join("|"));

    while ((pos = r.indexIn(pattern, pos)) != -1) {
        shorter.append(r.cap(0)[0]);
        pos += r.matchedLength();
    }

    return shorter;
}

} //namespace Shared
} //namesoace UXP1A_project
