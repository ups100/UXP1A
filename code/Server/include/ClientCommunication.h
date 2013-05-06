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

    void sendRecord(const QString& pattern, const QVariantList& data);
    void sendTimeoutInfo();

private:
    bool openFifo();

private:
    QString m_clientPath;

    /**
     * @brief FIFO file descriptor
     */
    int m_fifo;

};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_E5ED41B2_C079_426d_84A5_B5150BB1C442__INCLUDED_)
