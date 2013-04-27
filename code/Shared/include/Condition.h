/**
 * @file Condition.h
 *
 * @date 27-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::Configuration
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(EA_A18CDE82_D1C3_4028_91EE_C28369DCB05F__INCLUDED_)
#define EA_A18CDE82_D1C3_4028_91EE_C28369DCB05F__INCLUDED_

#include "Functor.h"

namespace UXP1A_project {
namespace Shared {

class Condition
{

public:

    /**
     * @brief D-tor
     */
    virtual ~Condition();

    /**
     * @brief C-tor
     *
     * @param cmpFun Functor to check values by it
     *
     * @param data Value to compare other values to it
     */
    Condition(const Functor& cmpFun, const QVariant& data);

    /**
     * @brief Check whether given data match condition
     *
     * @param data Value to compare
     *
     * @return true if given value passes test, false otherwise
     */
    bool check(const QVariant& data);

private:
    /**
     * @brief Value of condition
     */
    QVariant m_value;

    /**
     * @brief Functor to compare values by it
     */
    Functor m_Functor;
};

}//namespace Shared
}//namesoace UXP1A_project

#endif // !defined(EA_A18CDE82_D1C3_4028_91EE_C28369DCB05F__INCLUDED_)
