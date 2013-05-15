/**
 * @file ClientFifoException.h
 *
 * @date 11-05-2013
 *
 * @author Jacek Sosnowski
 *
 * @brief Definition of exception interface.
 *
 * @details This exception will be throw after problems with client's FIFO file.
 * For example after bad create or open operation.
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(CLIENTFIFOEXCEPTION_H_)
#define CLIENTFIFOEXCEPTION_H_

#include <stdexcept>
#include "ClientException.h"

namespace UXP1A_project {
namespace Client {

/**
 * @brief Class represents exception during 'parsing'
 */
class ClientFifoException : public virtual ClientException
{
public:
    /**
     * @brief C-tor, calls ClientException c-tor with proper param
     *
     * @details This class covers client's fifo operation errors.
     *
     * @param[in] message Exception message
     */
    ClientFifoException(const char* message)
            : ClientException(message)
    {

    }

    /**
     * @brief C-tor, calls ClientException c-tor with proper param
     *
     * @details This class covers client's fifo operation errors.
     *
     * @param[in] message Exception message
     */
    ClientFifoException(const std::string& message)
            : ClientException(message.c_str())
    {

    }

};

} //namespace Client
} //namesoace UXP1A_project

#endif /* CLIENTFIFOEXCEPTION_H_ */
