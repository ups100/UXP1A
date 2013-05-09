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
    QMutex m_mutex;
};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_6F70F9D8_1D5A_4ea2_9FC3_CF3EB2298A5C__INCLUDED_)
