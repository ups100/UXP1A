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
    QList<QVariantList> m_pushed;
    QList<QVariantList> m_pulled;

public:

    void start();

private:

    void loop();

    void showMenu();

    void pushTuple();

    QVariantList pullTuple();

    QVariantList previewTuple();

    void printTupleList(const QVariantList &list);

    std::pair<QString, int> getRequest();

};

} //namespace Tests
} //namespace UXP1A_project

#endif // !defined(MANUAL_LINDA__INCLUDED_)
