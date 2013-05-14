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
#include <QString>

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

    /**
     * @brief Random generator
     */
    RandomNumberGenerator m_generator;

    /**
     * @brief Int generator
     */
    IntGenerator m_intGenerator;

    /**
     * @brief Float generator
     */
    FloatGenerator m_floatGenerator;

protected:

    /**
     * @brief C-tor
     */
    ParserTest();

    /**
     * @brief Generate int pattern condition
     * <br />Example:
     * @code
     *     int:>123 or int:* or int:41 etc.
     * @endcode
     *
     * @param[in] op Operator to use in generation, random amount ommit it for ANYTHING example
     *
     * @return Generated pattern condition
     */
    QString generateInt(const char* op);

    /**
     * @brief Generate float pattern condition
     * <br />Example:
     * @code
     *     float:>123 or float:* or not float:41 etc.
     * @endcode
     *
     * @param[in] op Operator to use in generation, random amount ommit it for ANYTHING example
     *
     * @return Generated pattern condition
     */
    QString generateFloat(const char* op);

    /**
     * @brief Generate string pattern condition
     * <br />Example:
     * @code
     *     string:>"asdsdg wet w!$412" or string:* or string:"41" etc.
     * @endcode
     *
     * @param[in] op Operator to use in generation, random amount ommit it for ANYTHING example
     *
     * @return Generated pattern condition
     */
    QString generateString(const char* op);

    /**
     * @brief Generate random amount of spaces
     *
     * @return String with random amount of spaces inside
     */
    QString generateRandSpaces();

    /**
     * @brief Generate next random int value from given interval
     *
     * @note rangeMin < rangeMax
     *
     * @param[in] rangeMin Left side of interval
     *
     * @param[in] rangeMax Right side of interval
     *
     * @return Random int from given interval
     */
    int randInt(int rangeMin = std::numeric_limits<int>::min(), int rangeMax =
            std::numeric_limits<int>::max());

    /**
     * @brief Generate next random float value from given interval
     *
     * @note rangeMin < rangeMax
     *
     * @param[in] rangeMin Left side of interval
     *
     * @param[in] rangeMax Right side of interval
     *
     * @return Random float from given interval
     */
    float randFloat(float rangeMin = std::numeric_limits<float>::min(),
            float rangeMax = std::numeric_limits<float>::max());

    /**
     * @brief Generate random boolean value
     *
     * @param[in] falseProbability From 0 to 100, probability of generate false value
     *
     * @return Random bool with given probability
     */
    bool randBool(int falseProbability = 50);

    /**
     * @brief Generate random string with given length from ASCII characters from collection { -~}\{"}
     *
     * @param[in] length Length of string
     *
     * @return Random sequence of characters with given length
     */
    QString randString(int length);

};

} //namespace GTest
} //namespace Shared
} //namespace UXP1A_project

#endif // !defined(PARSER_TEST__INCLUDED_)
