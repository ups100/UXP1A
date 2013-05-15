/**
 * @file ToServerPipe.h
 *
 * @date 29-04-2013
 *
 * @author Sosnowski Jacek
 *
 * @brief Implementation of the Class UXP1A_project::Client::ToServerPipe
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#if !defined(EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_)
#define EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_

#include <QString>
#include <QVariant>
#include <QDebug>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

namespace UXP1A_project {
namespace Client {

class ToServerPipe
{

public:
    /**
     * @throw ServerFifoException while couldn't open server FIFO file.
     */
    ToServerPipe();
    virtual ~ToServerPipe();

    /**
     * @brief Manage with sending PREVIEW message to Server FIFO with given condition pattern and time for waiting.
     *
     * @param[in] pattern   Correctly parsed pattern in long form. This won't be check again in this method.
     * @param[in] timeout   Client process will be block for this time (in milliseconds)
     * in waiting for required tuple occurs.
     *
     * @throw ServerFifoException when any error of writing to server fifo occurs.
     * Usually when server doesn't response - for example when server process is manually finished.
     */
    void writePreviewMessage(const QString& pattern, long timeout);
    /**
     * @brief Manage with sending PULL message to Server FIFO with given condition pattern and time for waiting.
     *
     * @param[in] condition   Correctly parsed pattern in long form. This won't be check again in this method.
     * @param[in] timeout   Client process will be block for this time (in milliseconds)
     * in waiting for required tuple occurs.
     *
     * @throw ServerFifoException when any error of writing to server fifo occurs.
     * Usually when server doesn't response - for example when server process is manually finished.
     */
    void writePullDataMessage(const QString& condition, long timeout);
    /**
     * @brief Manage with sending PUSH message to Server FIFO with given pattern and list of data.
     *
     * @param[in] pattern   Correctly parsed pattern in short form. This won't be check again in this method.
     * @param[in] data      QVariantList with data related to pattern - type of data must be also correct
     * and it will be not check again.
     *
     * @throw ServerFifoException when any error of writing to server fifo occurs.
     * Usually when server doesn't response - for example when server process is manually finished.
     */
    void writePushDataMessage(const QString& pattern, const QVariantList& data);

private:

    /**
     * @brief Write message to the FIFO. It is call by Preview or Pull only.
     * So it is method use be writePreviewMessage and writePullDataMessage only.
     * char code should be prepared before message code - here it is not modify - just send
     */
    void writeToFifo(char code, const QString& pattern,
            const long timeout) const;

    /**
     * @brief It is first part of preparing buffer to send.
     * It is common part of message for Preview and Pull also.
     *
     * @details It response for copy to the buffer first part of message:
     * CODE # LENGTH # PID # PATTERN
     *
     * @returns Number of written bytes.
     * It is position of first free space in buffer. Counted from 0.
     */
    int initialWriteToFifo(char code, const long len, const QByteArray& pid,
            const QByteArray& patt, char *buf) const;

    /**
     * @brief Gets client process PID and prepare it into needed structure.
     *
     * @returns QByteArray which contain client PID number.
     */
    QByteArray getPid() const;

    /**
     * @brief Descriptor to the server fifo file.
     */
    int m_fifo;
};

} //namespace Client
} //namespace UXP1A_project

#endif // !defined(EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_)
