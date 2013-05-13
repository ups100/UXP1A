/**
 * @file ParserTest.h
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

#if !defined(PARSER_TEST__INCLUDED_)
#define PARSER_TEST__INCLUDED_

#include <gtest/gtest.h>
#include "Parser.h"
#include <boost/random.hpp>
#include <limits>

namespace UXP1A_project {
namespace Shared {
namespace GTest {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Test for Parser class
 */
class ParserTest : public ::testing::Test
{
    typedef boost::uniform_int<> IntNumberDistribution;
    typedef boost::uniform_real<float> FloatNumberDistribution;
    typedef boost::mt19937 RandomNumberGenerator;
    typedef boost::variate_generator<RandomNumberGenerator&,
            IntNumberDistribution> IntGenerator;
    typedef boost::variate_generator<RandomNumberGenerator&,
            FloatNumberDistribution> FloatGenerator;

    RandomNumberGenerator m_generator;
    IntGenerator m_intGenerator;
    FloatGenerator m_floatGenerator;

protected:

    ParserTest();

    QString generateInt(const char* op);

    QString generateFloat(const char* op);

    QString generateString(const char* op);

    int randInt(int rangeMin = std::numeric_limits<int>::min(), int rangeMax =
            std::numeric_limits<int>::max());

    float randFloat(float rangeMin = std::numeric_limits<float>::min(),
            float rangeMax = std::numeric_limits<float>::max());

    bool randBool(int falseProbability = 50);

    QString randString(int length);

};

} //namespace GTest
} //namespace Shared
} //namespace UXP1A_project

#endif // !defined(PARSER_TEST__INCLUDED_)
