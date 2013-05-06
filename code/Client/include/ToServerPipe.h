///////////////////////////////////////////////////////////
//  ToServerPipe.h
//  Implementation of the Class ToServerPipe
//  Created on:      24-kwi-2013 11:04:00
//  Original author: kopasiak
///////////////////////////////////////////////////////////

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
     * @throw std::string while couldn't open server FIFO file.
     */
    ToServerPipe();
    virtual ~ToServerPipe();

    void writePreviewMessage(const QString& pattern, long timeout);
    void writePullDataMessage(const QString& condition, long timeout);
    void writePushDataMessage(const QString& pattern, const QVariantList& data);

private:

    /**
     * @brief Write message to the FIFO. It is call by Preview or Pull only.
     * So it is method use be writePreviewMessage and writePullDataMessage only.
     * char code should be prepared before message code - here it is not modify - just send
     */
    void writeToFifo(char code, const QString& pattern, const long timeout); //const;                   // TODO repair

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
    int initialWriteToFifo(char code, const QByteArray& len,
            const QByteArray& pid, const QByteArray& patt, char *buf) const;

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

    int m_GID;          // TODO del this
};

} //namespace Client
} //namespace UXP1A_project

#endif // !defined(EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_)
