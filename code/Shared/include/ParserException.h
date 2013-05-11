/**
 * @file ParserException.h
 *
 * @date 11-05-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::ParserException
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(PARSER_EXCEPTION__INCLUDED_)
#define PARSER_EXCEPTION__INCLUDED_

#include <string>

namespace UXP1A_project {
namespace Shared {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Class represents exception during 'parsing'
 */
class ParserException : public virtual std::runtime_error
{

public:

    /**
     * @brief C-tor, calls runtime_error c-tor with proper param
     *
     * @param[in] message Exception message
     */
    ParserException(const char* message)
            : runtime_error(std::string(message))
    {

    }

};

} //namespace Shared
} //namesoace UXP1A_project

#endif // !defined(PARSER_EXCEPTION__INCLUDED_)
