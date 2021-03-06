/**
 * @file FromServerPipe.h
 *
 * @date 29-04-2013
 *
 * @author Sosnowski Jacek
 *
 * @brief Implementation of the Class UXP1A_project::Client::FromServerPipe
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#if !defined(EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_)
#define EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_

#include <QString>
#include <QVariant>
#include <QDebug>
#include "Configuration.h"

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

namespace UXP1A_project {
namespace Client {

/**
 * Proxy on write
 */
class FromServerPipe
{

public:
    /**
     * @brief Create FIFO file and open it.
     * @throw std::exception while fail
     */
    FromServerPipe();
    virtual ~FromServerPipe();

    const QString getPipeName() const;
    QVariantList waitForMessage(const QString& pattern);

private:
    /**
     * @brief Create client FIFO file.
     * @details FIFO is create in the same folder where server has his own FIFO.
     * FIFO name is client process PID number
     * @returns true if operation succeed; exception otherwise
     *
     * @throw ClientFifoException with error message when can't make fifo file.
     * This exception will be catch end re-throw by constructor.
     */
    bool makeFifoFile() const;
    /**
     * @brief Checks state of errno variable.
     * @details It is call in makeFifoFile() when mkfifo fails.
     * NO exception throws - just returns text about fail.
     *
     * @return QString with all errors messages.
     */
    QString checkFifoErrors() const;
    /**
     * @brief Opening client FIFO file which is made before by makeFifoFile()
     * @details When fails for some reasons the exception is throw.
     * @returns true if operation successful; false - otherwise - throws exception
     * @throw ClientFifoException with error message.
     * This exception will be catch end re-throw by constructor.
     */
    bool openFifo();
    /**
     * @brief Checks and return current client process pid number.
     *
     * @returns QString object which contains client process pid number as a text.
     */
    QString getPid() const;
    /**
     * @brief This method is use when message does not fit into the buffer at all.
     * @details In the end of buffer there is some data, but we don't know
     * if this is full part of message. So we move this rest of data in the begin of buffer
     * and read more data from FIFO. After that we read again last part of message
     * now just from begin of buffer. That's why this method take pointer to total position
     * in the receiving buffer while reading (reading in waitForMessage() method) - because we must
     * change the value of this variable to 0 - rest of read (in waitForMessage() ) will be continued
     * from the begin of buffer.
     */
    void anotherRead(int *total);

    /**
     * @brief FIFO file descriptor
     */
    int m_fifo;

    /**
     * @brief Receive buffer max capacity.
     * @details Should be set to value more than max size of max component of one tuple.
     * So for this class, tuple could have almost infinity number of parts but each part length
     * should be less than MAX_BUF.
     */
    static const int MAX_BUF = 1000;
    /**
     * @brief Receive buffer.
     */
    char m_buf[MAX_BUF];

    /**
     * @brief Contains full path for FIFO file.
     * @details Especially used by destructor of this class for fast finding fifo file.
     */
    std::string m_fifoPath;

};

} //namespace Client
} //namespace UXP1A_project
#endif // !defined(EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_)
