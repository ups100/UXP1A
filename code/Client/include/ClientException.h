/**
 * @file ClientException.h
 *
 * @date 11-05-2013
 *
 * @author Jacek Sosnowski
 *
 * @brief Definition of exception interface.
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(CLIENTEXCEPTION_H_)
#define CLIENTEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace UXP1A_project {
namespace Client {

/**
 * @brief Class represents exception during 'parsing'
 */
class ClientException : public std::runtime_error
{
public:
    /**
     * @brief C-tor, calls runtime_error c-tor with proper param
     *
     * @param[in] message Exception message
     */
    ClientException(const char* message)
            : runtime_error(std::string(message))
    {

    }

};

} //namespace Client
} //namesoace UXP1A_project

#endif /* CLIENTEXCEPTION_H_ */
