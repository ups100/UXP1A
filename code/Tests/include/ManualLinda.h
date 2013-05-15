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

namespace UXP1A_project {
namespace Tests {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Test for Manual Linda client use
 */
class ManualLinda
{
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
     * @brief Whether do random sleeps after push/pull/preview
     */
    bool m_testSleep;

public:

    /**
     * @brief C-tor
     *
     * @param[in] testOutput Whether disable stdout while test is running
     *
     * @param[in] testSleep Whether enable random sleep after push/pull/preview
     */
    ManualLinda(bool testOutput = false, bool testSleep = false);

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
     * @brief Prints available QVariant's without opaque
     *
     * @param[in] list List to print values from
     */
    void printTupleList(const QVariantList &list);

    /**
     * @brief Get Timeout and tuple pattern from stdin
     *
     * @throws ParserException if bad pattern
     *
     * @return Pair with given pattern and timeout
     */
    std::pair<QString, int> getRequest();

};

} //namespace Tests
} //namespace UXP1A_project

#endif // !defined(MANUAL_LINDA__INCLUDED_)
