/**
 * @file ParserTest.cpp
 *
 * @date 13-05-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::GTest::ParserTest
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#include "ParserTest.h"
#include <QTime>
#include <QDebug>

namespace UXP1A_project {
namespace Shared {
namespace GTest {

ParserTest::ParserTest()
        : m_intGenerator(m_generator, IntNumberDistribution()),
                m_floatGenerator(m_generator, FloatNumberDistribution())
{
    m_generator.seed((uint) QTime::currentTime().msec());
}

int ParserTest::randInt(int rangeMin, int rangeMax)
{
    m_intGenerator.distribution().param(
            boost::uniform_int<>::param_type(rangeMin, rangeMax));

    return m_intGenerator();
}

float ParserTest::randFloat(float rangeMin, float rangeMax)
{
    m_floatGenerator.distribution().param(
            boost::uniform_real<float>::param_type(rangeMin, rangeMax));

    return m_floatGenerator();
}

bool ParserTest::randBool(int falseProbabitlity)
{
    if (randInt(0, 100) < falseProbabitlity)
        return false;

    return true;
}

QString ParserTest::randString(int length)
{
    QString str;
    int c;

    for (;;) {
        if (str.length() >= length)
            break;

        while ((c = randInt(32, 126)) == 34) // ASCRII 34 = "
        {
        }

        str.append(c);
    }

    return str;
}

QString ParserTest::generateInt(const char* op)
{
    if (!Parser::INT_OPERATORS.contains(op))
        throw "Bad int operator given";

    bool anything = randBool(80);

    QString str;
    str.append(Parser::INT);
    str.append(":");

    if (anything) {
        str.append(Parser::ANYTHING);
    } else {
        str.append(op);
        str.append(QString::number(randInt()));
    }

    return str;
}

QString ParserTest::generateFloat(const char* op)
{
    if (!Parser::FLOAT_OPERATORS.contains(op))
        throw "Bad float operator given";

    bool anything = randBool(80);

    QString str;
    str.append(Parser::FLOAT);
    str.append(":");

    if (anything) {
        str.append(Parser::ANYTHING);
    } else {
        str.append(op);
        str.append(QString::number(randFloat()));
    }

    return str;
}

QString ParserTest::generateString(const char* op)
{
    if (!Parser::STRING_OPERATORS.contains(op))
        throw "Bad string operator given";

    bool anything = randBool(80);

    QString str;
    str.append(Parser::STRING);
    str.append(":");

    if (anything) {
        str.append(Parser::ANYTHING);
    } else {
        str.append("\"");
        str.append(op);
        str.append(randString(randInt(0, 50)));
        str.append("\"");
    }

    return str;
}

} //namespace GTest
} //namespace Shared
} //namesoace UXP1A_project
