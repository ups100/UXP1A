/**
 * @file ManualLinda.h
 *
 * @date 14-05-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Tests::ManualLinda
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(MANUAL_LINDA__INCLUDED_)
#define MANUAL_LINDA__INCLUDED_

#include <QVariantList>
#include <QString>
#include <boost/random.hpp>

namespace UXP1A_project {
namespace Tests {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Test for Manual Linda client use
 */
class ManualLinda
{
    typedef boost::uniform_int<> IntNumberDistribution;
    typedef boost::mt19937 RandomNumberGenerator;
    typedef boost::variate_generator<RandomNumberGenerator&,
            IntNumberDistribution> IntGenerator;

    /**
     * @brief Random generator
     */
    RandomNumberGenerator m_generator;

    /**
     * @brief Int generator
     */
    IntGenerator m_intGenerator;

    /**
     * @brief Pushed tuples during test
     */
    QList<QVariantList> m_pushed;

    /**
     * @brief Pulled tuples during test
     */
    QList<QVariantList> m_pulled;

    /**
     * @brief Used in test to track push/pulls
     */
    QString m_testChain;

    /**
     * @brief Whether disable stdout anything during test
     */
    bool m_testOutput;

    /**
     * @brief Whether do random sleeps after push/pull/preview.
     *      Sleep random ms of set value.
     *      If set to 0, no sleep
     */
    unsigned int m_testSleep;

    /**
     * @brief Whether do random timeout instead of given one.
     *      Sleep random ms of set value.
     *      If set to 0, use given timeout
     */
    unsigned int m_testTimeout;

    /**
     * @brief Whether do random sleep after successful pull.
     *      Sleep random ms of set value.
     *      If set to 0, no sleep
     */
    unsigned int m_testAfterPulledSleep;

public:

    /**
     * @brief C-tor
     *
     * @param[in] testOutput Whether disable stdout while test is running
     *
     * @param[in] testSleep Whether enable random sleep after push/pull/preview in ms
     *
     * @param[in] testTimeout Whether enable random timeout instead of given one in ms
     *
     * @param[in] testAfterPulledSleep Whether enable random sleep after successful pull operation in ms
     */
    ManualLinda(bool testOutput = false, unsigned int testSleep = 0,
            unsigned int testTimeout = 0,
            unsigned int testAfterPulledSleep = 0);

    /**
     * @brief Start manual Linda test
     */
    QString start();

private:

    /**
     * @brief Main loop
     */
    void loop();

    /**
     * @brief Print menu on stdout
     */
    void showMenu();

    /**
     * @brief Push tuple to server
     *
     * @throws ParserException if bad pattern
     */
    void pushTuple();

    /**
     * @brief Pull tuple from server
     *
     * @throws ParserException if bad pattern
     *
     * @return Pulled tuple or empty list if timeout
     */
    QVariantList pullTuple();

    /**
     * @brief Preview tuple on server
     *
     * @throws ParserException if bad pattern
     *
     * @return Tuple preview or empty list if timeout
     */
    QVariantList previewTuple();

    /**
     * @brief Get print of available QVariant's without opaque
     *
     * @param[in] list List to print values from
     *
     * @return Printed list without opaque
     */
    QString printTupleList(const QVariantList &list);

    /**
     * @brief Get Timeout and tuple pattern from stdin
     *
     * @throws ParserException if bad pattern
     *
     * @return Pair with given pattern and timeout
     */
    std::pair<QString, int> getRequest();

    /**
     * @brief Print some info via qDebug if m_testOutput is enabled
     *
     * @param[in] info Info message
     */
    void qPrintPidInfo(const QString &info);

    /**
     * @brief Generate next random int value from given interval
     *
     * @note rangeMin < rangeMax
     *
     * @param[in] rangeMax Right side of interval
     *
     * @param[in] rangeMin Left side of interval
     *
     * @return Random int from given interval
     */
    int randInt(int rangeMax, int rangeMin = 0);

};

} //namespace Tests
} //namespace UXP1A_project

#endif // !defined(MANUAL_LINDA__INCLUDED_)
