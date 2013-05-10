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
#include "CompareOperations.h"
#include <QRegExp>
#include <boost/lexical_cast.hpp>
#include <QMetaType>

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

Parser::Parser()
{

}

Parser::~Parser()
{

}

bool Parser::checkCondition(const QString& conditions)
{
    /*
     * Regex pattern:
     *      (((int:(((<|<=|>|>=)?(-?\d+))|(\*)))|(float:(((<|<=|>|>=){1}(-?\d+\.?\d*))|(\*)))|(string:(((<|<=|>|>=)?"[\s!#-~]*")|(\*)))),?\s?)+
     */

    QString pattern = "((";
    pattern += QString("(") + INT + ":(((" + INT_OPERATORS.join("|")
            + ")?(-?\\d+))|(\\" + ANYTHING + ")))";
    pattern += "|";
    pattern += QString("(") + FLOAT + ":(((" + FLOAT_OPERATORS.join("|")
            + "){1}(-?\\d+\\.?\\d*))|(\\" + ANYTHING + ")))";
    pattern += "|";
    pattern += QString("(") + STRING + ":(((" + STRING_OPERATORS.join("|")
            + ")?\"[\\s!#-~]*\")|(\\" + ANYTHING + ")))";
    pattern += "),?\\s?)+";

    QRegExp r(pattern);

    return r.exactMatch(conditions);
}

SearchPattern* Parser::parseConditions(const QString& conditions)
{
    if (!checkCondition(conditions))
        throw "Check conditions first man..";

    // Get separated conditions and gather them into list
    QString pattern = "(";
    pattern += QString("(") + INT + ":(((" + INT_OPERATORS.join("|")
            + ")?(\\d+))|(\\" + ANYTHING + ")))";
    pattern += "|";
    pattern += QString("(") + FLOAT + ":(((" + FLOAT_OPERATORS.join("|")
            + "){1}(\\d+\\.?\\d*))|(\\" + ANYTHING + ")))";
    pattern += "|";
    pattern += QString("(") + STRING + ":(((" + STRING_OPERATORS.join("|")
            + ")?\"[\\s!#-~]*\")|(\\" + ANYTHING + ")))";
    pattern += ")";

    QRegExp r(pattern);
    QStringList conds;

    int pos = 0;
    while ((pos = r.indexIn(conditions, pos)) != -1) {
        pos += r.matchedLength();
        conds << r.cap();
    }

    // Parse each condition
    pattern = "";
    pattern += QString("(") + INT + "|" + FLOAT + "|" + STRING + ")";
    pattern += QString(":");
    pattern += QString("(") + INT_OPERATORS.join("|") + ")?";
    pattern += QString("(") + ".+" + ")";

    r.setPattern(pattern);

    SearchPattern *sp = new SearchPattern();
    QString type, op, val;
    QVariant value;
    CompareOperations opr;

    foreach (QString s, conds){
    r.indexIn(s);

    type = r.cap(1);
    op = r.cap(2);
    val = r.cap(3);

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
    if (!checkCondition(pattern))
        throw "Check conditions first man..";

    QString shorter;
    int pos = 0;

    const QRegExp r(TYPES.join("|"));

    while ((pos = r.indexIn(pattern, pos)) != -1) {
        if (!SHORT_TYPES.contains(QString(r.cap()[0])))
            throw "How it happens, never should be there.";

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
        throw "Only int, float, string available.";
    }
}
    return shorter;
}

} //namespace Shared
} //namesoace UXP1A_project
