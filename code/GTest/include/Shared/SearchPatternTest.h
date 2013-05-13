/**
 * @file SearchPatternTest.h
 *
 * @date 13-05-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::SearchPatternTest
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(SEARCH_PATTERN_TEST__INCLUDED_)
#define SEARCH_PATTERN_TEST__INCLUDED_

#include <gtest/gtest.h>
#include "SearchPattern.h"
#include <QVariantList>

namespace UXP1A_project {
namespace Shared {
namespace GTest {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Test for SearchPattern class
 */
class SearchPatternTest : public ::testing::Test
{

protected:

    SearchPattern m_sp;
    QVariantList m_list;

};

} //namespace GTest
} //namespace Shared
} //namespace UXP1A_project

#endif // !defined(SEARCH_PATTERN_TEST__INCLUDED_)
