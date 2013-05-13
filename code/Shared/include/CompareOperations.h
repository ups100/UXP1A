/**
 * @file CompareOperations.h
 *
 * @date 27-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::CompareOperations
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(EA_D98FAB1D_8F5D_47c9_B612_CD62769BFEFD__INCLUDED_)
#define EA_D98FAB1D_8F5D_47c9_B612_CD62769BFEFD__INCLUDED_

namespace UXP1A_project {
namespace Shared {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Identifiers of available functor's comparison methods.
 */
enum CompareOperations
{
    INT_EQUAL, /* == */
    INT_LESS, /* < */
    INT_LESS_EQUAL, /* <= */
    INT_GREATER, /* > */
    INT_GREATER_EQUAL, /* >= */
    FLOAT_LESS, /* < */
    FLOAT_LESS_EQUAL, /* <= */
    FLOAT_GREATER, /* > */
    FLOAT_GREATER_EQUAL, /* >= */
    STRING_EQUAL, /* == */
    STRING_LESS, /* < */
    STRING_LESS_EQUAL, /* <= */
    STRING_GREATER, /* > */
    STRING_GREATER_EQUAL, /* >= */
    ANYTHING /* * */
};

} //namespace Shared
} //namesoace UXP1A_project

#endif // !defined(EA_D98FAB1D_8F5D_47c9_B612_CD62769BFEFD__INCLUDED_)
