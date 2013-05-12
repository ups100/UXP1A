/**
 * @file CommandQueue.h
 *
 * @date 27-04-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class UXP1A_project::Server::RecordTable
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#if !defined(EA_6F70F9D8_1D5A_4ea2_9FC3_CF3EB2298A5C__INCLUDED_)
#define EA_6F70F9D8_1D5A_4ea2_9FC3_CF3EB2298A5C__INCLUDED_

#include <QThread>
#include <QMutex>
#include <QDebug>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

namespace UXP1A_project {
namespace Server {

class CommandDispatcher;

/**
 * @brief This class is responsible for receiving commands from clients.
 */
class CommandQueue : public QObject
{
Q_OBJECT
    ;
public:
    /**
     * @brief This is friend class to execute some private cleaning up methods.
     */
    friend class CommandDispatcher;
    /**
     * @brief Constructor
     *
     * @throw Exception std::string when can't create path for fifo or FIFO file
     * @throw Exception std::string when FIFO file exist
     * - it means that one server is running.
     *
     * @param[in,out] commandDispatcher which will serve the commands.
     */
    CommandQueue(CommandDispatcher *commandDispatcher);

    /**
     * @brief Destructor
     */
    virtual ~CommandQueue();

    /**
     * @brief Starts additional thread for receiving demands from clients.
     */
    void exec();

private:
    /**
     * @brief Checks if directory specify by Configuration class exists in the system
     *
     * @return true - if all directory on path exists
     * false - otherwise
     */
    bool isDirExists() const;

    /**
     * @brief This method is use by constructor when
     * it notice that server directory for FIFO file is not create
     *
     * @throw Exception std::string when server can't create or open directory for his FIFO
     *
     * @return true if success; false otherwise
     */
    bool makeDir() const;

    /**
     * @brief Check if server FIFO object exists
     *
     * @details This could mean that some server still works.
     * Otherwise server must create their own FIFO file.
     *
     * @return true if FIFO file exists; false if doesn't - server must create new
     */
    bool isFifoExists() const;

    /**
     * @brief Create FIFO file in localization specify by Configuration class
     *
     * @throw Exception std::string When server can't create FIFO file.
     */
    bool makeFifoFile() const;

    /**
     * @brief Temporary here. Check errno variable.
     */
    void checkFifoErrors() const;

    /**
     * @brief Opens prepared before fifo file for read only.
     *
     * @details Save descriptor in m_fifo variable.
     *
     * @return true if success; false - otherwise
     */
    bool openFifo();

    /*
     * @brief Used by readTuple()
     */
    enum Action
    {
        DEL, NON_DEL
    };

    /**
     * @brief Reading and parsing function group
     */
    void readTuple(const char *buf, const int length, const char code) const;
    void anotherRead(int restBytes, char **in);

private slots:

    /**
     * @brief Waits for commands from client.
     *
     * @details Reads commands from named pipe.
     */
    void waitForCommands();

private:

    /**
     * @brief Terminates the additional thread and closes the pipe.
     *
     * @details Puts exit message to server's queue
     *
     * @note This function will be executed always in context of main thread.
     */
    void terminate();

    /**
     * @brief Closes the opened pipe.
     */
    void closePipe();

    /**
     * @brief Class which executes commands
     */
    CommandDispatcher *m_commandDispatcher;

    /**
     * @brief Additional thread for reading from pipe.
     */
    QThread m_additionalThread;

    /*************FOR TEST ONLY< REMOVE THIS JACEK*/
    //QMutex m_mutex;
    /**
     * @brief FIFO file descriptor
     */
    int m_fifo;

    /**
     * @brief Contains full path for FIFO file.
     * Of course after all checks - path is good.
     */
    std::string m_fifoPath;

    static const int MAX_BUF = 200;
    char m_buf[MAX_BUF];
};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_6F70F9D8_1D5A_4ea2_9FC3_CF3EB2298A5C__INCLUDED_)
