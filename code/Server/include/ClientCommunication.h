///////////////////////////////////////////////////////////
//  ClientCommunication.h
//  Implementation of the Class ClientCommunication
//  Created on:      24-kwi-2013 11:07:18
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_E5ED41B2_C079_426d_84A5_B5150BB1C442__INCLUDED_)
#define EA_E5ED41B2_C079_426d_84A5_B5150BB1C442__INCLUDED_

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
namespace Server {

class ClientCommunication
{

public:
    ClientCommunication(const QString& clientFifoPath);
    virtual ~ClientCommunication();

    /**
     * @brief Sending response for client request to client FIFO.
     * Response contains message code, length of data
     * and of course all data which client want.
     * Client doesn't obtain pattern of request and response.
     *
     * @details Client FIFO is recognized by Client PID number - obtain in constructor
     *
     * @returns True if server opens client FIFO and False otherwise
     */
    bool sendRecord(const QString& pattern, const QVariantList& data);

    /**
     * @brief Sending response to client with Timeout message only.
     *
     * @details It is only short 2 characters message: Code'\0'
     */
    void sendTimeoutInfo();

private:
    bool openFifo();

private:
    QString m_clientPath;

    /**
     * @brief FIFO file descriptor
     */
    int m_fifo;

    /**
     * @brief Store FIFO state after opening.
     *
     * @details If open client FIFO fail this is false
     * and all operation: sendRecord and sendTimeoutInfo are empty.
     */
    //bool m_fifoState;
};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_E5ED41B2_C079_426d_84A5_B5150BB1C442__INCLUDED_)
