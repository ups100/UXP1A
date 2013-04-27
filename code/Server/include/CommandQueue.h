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

#include "CommandDispatcher.h"
#include <QThread>

namespace UXP1A_project {
namespace Server {

/**
 * @brief This class is responsible for receiving commands from clients.
 */
class CommandQueue: public QObject
{
Q_OBJECT;
public:
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

    void waitForCommands();

private:
    /**
     * @brief Class which executes commands
     */
    CommandDispatcher *m_commandDispatcher;

    /**
     * @brief Additional thread for reading from pipe.
     */
    QThread m_additionalThread;
};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_6F70F9D8_1D5A_4ea2_9FC3_CF3EB2298A5C__INCLUDED_)
