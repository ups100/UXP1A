///////////////////////////////////////////////////////////
//  FromServerPipe.h
//  Implementation of the Class FromServerPipe
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

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
    FromServerPipe();
    virtual ~FromServerPipe();

    const QString getPipeName() const;
    QVariantList waitForMessage();

private:
    bool makeFifoFile() const;
    void checkFifoErrors() const;
    bool openFifo();
    QString getPid() const;
    void anotherRead(int *total);

    /**
     * @brief FIFO file descriptor
     */
    int m_fifo;

    static const int MAX_BUF = 200;
    char m_buf[MAX_BUF];

    /**
     * @brief Contains full path for FIFO file.
     */
    std::string m_fifoPath;

};

}//namespace Client
}//namespace UXP1A_project
#endif // !defined(EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_)
