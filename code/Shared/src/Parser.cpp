/**
 * @file Parser.cpp
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

#include "Parser.h"
#include "CompareOperations.h"
#include <QRegExp>
#include <boost/lexical_cast.hpp>
#include <QMetaType>
#include "ParserException.h"
#include "NumericLimitException.h"

namespace UXP1A_project {
namespace Shared {

const char *Parser::INT = "int", *Parser::INT_EQUAL = "", *Parser::INT_LESS =
        "<", *Parser::INT_LESS_EQUAL = "<=", *Parser::INT_GREATER = ">",
        *Parser::INT_GREATER_EQUAL = ">=";
const char *Parser::FLOAT = "float", *Parser::FLOAT_LESS = "<",
        *Parser::FLOAT_LESS_EQUAL = "<=", *Parser::FLOAT_GREATER = ">",
        *Parser::FLOAT_GREATER_EQUAL = ">=";
const char *Parser::STRING = "string", *Parser::STRING_EQUAL = "",
        *Parser::STRING_LESS = "<", *Parser::STRING_LESS_EQUAL = "<=",
        *Parser::STRING_GREATER = ">", *Parser::STRING_GREATER_EQUAL = ">=";
const char *Parser::ANYTHING = "*";

const QStringList Parser::TYPES = QStringList() << Parser::INT << Parser::FLOAT
        << Parser::STRING;
const QStringList Parser::INT_OPERATORS = QStringList() << Parser::INT_EQUAL
        << Parser::INT_LESS << Parser::INT_LESS_EQUAL << Parser::INT_GREATER
        << Parser::INT_GREATER_EQUAL;
const QStringList Parser::FLOAT_OPERATORS = QStringList() << Parser::FLOAT_LESS
        << Parser::FLOAT_LESS_EQUAL << Parser::FLOAT_GREATER
        << Parser::FLOAT_GREATER_EQUAL;
const QStringList Parser::STRING_OPERATORS = QStringList()
        << Parser::STRING_EQUAL << Parser::STRING_LESS
        << Parser::STRING_LESS_EQUAL << Parser::STRING_GREATER
        << Parser::STRING_GREATER_EQUAL;

const char *Parser::SHORT_TYPE_INT = "i", *Parser::SHORT_TYPE_FLOAT = "f",
        *Parser::SHORT_TYPE_STRING = "s";
const QStringList Parser::SHORT_TYPES = QStringList() << Parser::SHORT_TYPE_INT
        << Parser::SHORT_TYPE_FLOAT << Parser::SHORT_TYPE_STRING;

/*
 * Regex pattern:
 *      (((int\s*:\s*(((<|<=|>|>=)?\s*(-?\d+))|(\*)))|(float\s*:\s*(((<|<=|>|>=){1}\s*((-?\d\d*\.?\d*e[+-]\d+)|(-?\d+\.?\d*)))|(\*)))|(string\s*:\s*(((<|<=|>|>=)?\s*"[\s!#-~]*")|(\*))))\s*,?\s*)+
 */
const QString Parser::CONDITIONS_PATTERN = QString() + "(" + "(" + Parser::INT
        + "\\s*:\\s*(((" + Parser::INT_OPERATORS.join("|")
        + ")?\\s*(-?\\d+))|(\\" + ANYTHING + ")))" + "|" + "(" + Parser::FLOAT
        + "\\s*:\\s*(((" + Parser::FLOAT_OPERATORS.join("|")
        + "){1}\\s*((-?\\d\\d*\\.?\\d*e[+-]\\d+)|(-?\\d+\\.?\\d*)))|(\\"
        + ANYTHING + ")))" + "|" + "(" + Parser::STRING + "\\s*:\\s*((("
        + Parser::STRING_OPERATORS.join("|") + ")?\\s*\"[\\s!#-~]*\")|(\\"
        + Parser::ANYTHING + ")))"
                ")";

const QString Parser::PARSE_CONDITIONS_PATTERN = QString() + "(" + INT + "|"
        + FLOAT + "|" + STRING + ")\\s*:\\s*(" + INT_OPERATORS.join("|")
        + ")?\\s*(.+)";

Parser::Parser()
{

}

Parser::~Parser()
{

}

bool Parser::checkCondition(const QString& conditions)
{
    QString pattern = "(\\s*";
    pattern += CONDITIONS_PATTERN;
    pattern += "\\s*,?\\s*)+";

    QRegExp r(pattern);
    // To prevent last \\s*,?\\s* part as accept eg.: "int:2 , "
    QRegExp re("(\\s*,\\s*)$");

    if (!(r.exactMatch(conditions) && re.indexIn(conditions) == -1))
        return false;

    /*
     * Check numeric limits
     */
    parseValuesToList(conditions);

    return true;
}

QVariantList Parser::parseValuesToList(const QString& pattern)
{
    QVariantList list;

    // Get separated conditions and gather them into list
    QRegExp r(CONDITIONS_PATTERN);
    QStringList conds;

    int pos = 0;
    while ((pos = r.indexIn(pattern, pos)) != -1) {
        pos += r.matchedLength();
        conds << r.cap();
    }

    // Parse each condition
    r.setPattern(PARSE_CONDITIONS_PATTERN);

    QString type, val;

    foreach (QString s, conds){
    r.indexIn(s);

    type = r.cap(1);
    val = r.cap(3).trimmed();

    if (val == ANYTHING) {
        list << 0.;
    } else {
        try {
            if (type == INT) {
                list << boost::lexical_cast<int>(val.toStdString());
            } else if (type == FLOAT) {
                list << boost::lexical_cast<float>(val.toStdString());
            } else if (type == STRING) {
                list << val.remove(QRegExp("\"")); // Maybe length but for now it's not requested to check for limits
            }
        } catch (boost::bad_lexical_cast &e) {
            throw NumericLimitException((type + " number out of bound.").toStdString().c_str());
        }
    }
}

    return list;
}

SearchPattern* Parser::parseConditions(const QString& conditions)
{
    try {
        if (!checkCondition(conditions))
            throw ParserException("Check conditions first man..");
    } catch (NumericLimitException &e) {
        throw e;
    }

    // Get separated conditions and gather them into list
    QRegExp r(CONDITIONS_PATTERN);
    QStringList conds;

    int pos = 0;
    while ((pos = r.indexIn(conditions, pos)) != -1) {
        pos += r.matchedLength();
        conds << r.cap();
    }

    // Parse each condition
    r.setPattern(PARSE_CONDITIONS_PATTERN);

    SearchPattern *sp = new SearchPattern();
    QString type, op, val;
    QVariant value;
    CompareOperations opr;

    foreach (QString s, conds){
    r.indexIn(s);

    type = r.cap(1);
    op = r.cap(2);
    val = r.cap(3).trimmed();

    if (val == ANYTHING) {
        value.setValue(0L); // Unnecessary but better look and feel ;p in (q)debug
        sp->addCondition(type, UXP1A_project::Shared::ANYTHING, value);
    } else {
        if (type == INT) {
            value.setValue(boost::lexical_cast<int>(val.toStdString()));

            if (op == Parser::INT_EQUAL) {
                opr = UXP1A_project::Shared::INT_EQUAL;
            } else if (op == Parser::INT_LESS) {
                opr = UXP1A_project::Shared::INT_LESS;
            } else if (op == Parser::INT_LESS_EQUAL) {
                opr = UXP1A_project::Shared::INT_LESS_EQUAL;
            } else if (op == Parser::INT_GREATER) {
                opr = UXP1A_project::Shared::INT_GREATER;
            } else if (op == Parser::INT_GREATER_EQUAL) {
                opr = UXP1A_project::Shared::INT_GREATER_EQUAL;
            }
        } else if (type == FLOAT) {
            value.setValue(boost::lexical_cast<float>(val.toStdString()));

            if (op == Parser::FLOAT_LESS) {
                opr = UXP1A_project::Shared::FLOAT_LESS;
            } else if (op == Parser::FLOAT_LESS_EQUAL) {
                opr = UXP1A_project::Shared::FLOAT_LESS_EQUAL;
            } else if (op == Parser::FLOAT_GREATER) {
                opr = UXP1A_project::Shared::FLOAT_GREATER;
            } else if (op == Parser::FLOAT_GREATER_EQUAL) {
                opr = UXP1A_project::Shared::FLOAT_GREATER_EQUAL;
            }
        } else if (type == STRING) {
            val.remove(QRegExp("\""));
            value.setValue(val);

            if (op == Parser::STRING_EQUAL) {
                opr = UXP1A_project::Shared::STRING_EQUAL;
            } else if (op == Parser::STRING_LESS) {
                opr = UXP1A_project::Shared::STRING_LESS;
            } else if (op == Parser::STRING_LESS_EQUAL) {
                opr = UXP1A_project::Shared::STRING_LESS_EQUAL;
            } else if (op == Parser::STRING_GREATER) {
                opr = UXP1A_project::Shared::STRING_GREATER;
            } else if (op == Parser::STRING_GREATER_EQUAL) {
                opr = UXP1A_project::Shared::STRING_GREATER_EQUAL;
            }
        }

        sp->addCondition(type, opr, value);
    }
}

    return sp;
}

QString Parser::parseStruct(const QString& pattern)
{
    try {
        if (!checkCondition(pattern))
            throw ParserException("Check conditions first man..");
    } catch (NumericLimitException &e) {
        throw e;
    }

    QString shorter;
    int pos = 0;

    const QRegExp r(TYPES.join("|"));

    while ((pos = r.indexIn(pattern, pos)) != -1) {
        if (!SHORT_TYPES.contains(QString(r.cap()[0])))
            throw ParserException("How it happens, never should be there.");

        shorter.append(r.cap()[0]);
        pos += r.matchedLength();
    }

    return shorter;
}

QString Parser::parseStruct(const QVariantList& list)
{
    QString shorter;

    foreach (QVariant v, list){
    switch (v.type()) {
        case QVariant::Int:
        shorter.append(SHORT_TYPE_INT);
        break;
        case QMetaType::Float:
        shorter.append(SHORT_TYPE_FLOAT);
        break;
        case QVariant::String:
        shorter.append(SHORT_TYPE_STRING);
        break;
        default:
        throw ParserException("Only int, float, string available.");
    }
}
    return shorter;
}

} //namespace Shared
} //namesoace UXP1A_project
