/**
 * @file CommandDispatcher.h
 *
 * @date 27-04-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class UXP1A_project::Server::CommandDispatcher
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#if !defined(EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_)
#define EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_

#include "RecordTable.h"
#include "CommandQueue.h"
#include <QCoreApplication>
#include <QString>
#include <QVariant>
#include <QMap>


namespace UXP1A_project {
namespace Server {

/**
 * @brief This is brain of server.
 *
 * @details All commands are served here.
 */
class CommandDispatcher : public QObject
{
Q_OBJECT
    ;
public:

    /**
     * @brief Gets the instance of this class.
     *
     * @details This is singleton class so this function is the only way to get the instance of it.
     *
     * @param[in] argc to be passed to QCoreApplication
     *
     * @param[in] argv to be passed to QCoreApplication
     *
     * @return Instance of this class
     *
     * @warning This function is not thread safe.
     */
    static CommandDispatcher *getInstance(int argc, char **argv);

    /**
     * @brief Ends the execution of main and additional event loop.
     */
    static void terminate();

    /**
     * @brief Destructor
     */
    virtual ~CommandDispatcher();

    /**
     * @brief Wraper function for Preview Command to change thread affinity
     *
     * @param[in] conditions of needed record
     *
     * @param[in] client FIFO path
     *
     * @param[in] timeout
     */
    void dispatchPreviewCommand(const QString& conditions,
            const QString& client, int timeout);

    /**
     * @brief Wraper function for Pull Command to change thread affinity
     *
     * @param[in] conditions of needed record
     *
     * @param[in] client FIFO path
     *
     * @param[in] timeout
     */
    void dispatchPullCommand(const QString& conditions, const QString& client,
            int timeout);

    /**
     * @brief Wraper function for Push Command to change thread affinity
     *
     * @param[in] pattern of record types
     *
     * @param[in] data of record
     */
    void dispatchPushCommand(const QString& pattern, const QVariantList& data);

    /**
     * @brief Starts the main and the helper event loop.
     *
     * @return The exit code from main event loop
     */
    int exec();

private slots:

    /**
     * @brief Serves the preview command
     *
     * @param[in] conditions of needed record
     *
     * @param[in] client FIFO path
     *
     * @param[in] timeout
     */
    void dispatchPreviewCommandSlot(const QString& conditions,
            const QString& client, int timeout);

    /**
     * @brief Serves the pull command
     *
     * @param[in] conditions of needed record
     *
     * @param[in] client FIFO path
     *
     * @param[in] timeout
     */
    void dispatchPullCommandSlot(const QString& conditions,
            const QString& client, int timeout);

    /**
     * @brief Serves the pull command
     *
     * @param[in] pattern of record types
     *
     * @param[in] data of record
     */
    void dispatchPushCommandSlot(const QString& pattern,
            const QVariantList& data);

private:

    /**
     * @brief Constructor
     *
     * @param[in] argc to be passed to QCoreApplication
     *
     * @param[in] argv to be passed to QCoreApplication
     */
    CommandDispatcher(int argc, char **argv);

    /**
     * @brief Tables created on server
     */
    QMap<QString, RecordTable*> m_tables;

    /**
     * @brief Command queue for receiving commands from clients.
     */
    CommandQueue m_commandQueue;

    /**
     * @brief Main event loop.
     */
    QCoreApplication m_eventLoop;

    /**
     * @brief Main thread of application
     */
    QThread *m_mainThread;
};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_)
