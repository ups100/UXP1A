/**
 * @file NumericLimitException.h
 *
 * @date 11-05-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::NumericLimitException
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(NUMERIC_LIMIT_EXCEPTION__INCLUDED_)
#define NUMERIC_LIMIT_EXCEPTION__INCLUDED_

#include <string>
#include <exception>

namespace UXP1A_project {
namespace Shared {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Class represents exception during 'parsing' as numeric limit exceed
 */
class NumericLimitException : public virtual std::runtime_error
{

public:

    /**
     * @brief C-tor, calls runtime_error c-tor with proper param
     *
     * @param[in] message Exception message
     */
    NumericLimitException(const char* message)
            : runtime_error(std::string(message))
    {

    }

};

} //namespace Shared
} //namesoace UXP1A_project

#endif // !defined(NUMERIC_LIMIT_EXCEPTION__INCLUDED_)
