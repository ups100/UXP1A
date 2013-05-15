/**
 * @file ServerFifoException.h
 *
 * @date 11-05-2013
 *
 * @author Jacek Sosnowski
 *
 * @brief Definition of exception interface.
 *
 * @details This exception will be throw after problems with server's FIFO file.
 * For example after bad open server FIFO - when no server is running.
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(SERVERFIFOEXCEPTION_H_)
#define SERVERFIFOEXCEPTION_H_

#include "ClientException.h"

namespace UXP1A_project {
namespace Client {

/**
 * @brief Class represents exception during 'parsing'
 */
class ServerFifoException : public virtual ClientException
{
public:
    /**
     * @brief C-tor, calls runtime_error c-tor with proper param
     *
     * @details This exception class covers communication with server errors.
     *
     * @param[in] message Exception message
     */
    ServerFifoException(const char* message)
            : ClientException(message)
    {

    }
    ServerFifoException(std::string& message)
            : ClientException(message.c_str())
    {

    }

};

} //namespace Client
} //namesoace UXP1A_project

#endif /* SERVERFIFOEXCEPTION_H_ */
