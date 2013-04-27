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
     * @brief Constructor
     */
    CommandDispatcher();

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
     * @brief Tables created on server
     */
    QMap<QString, RecordTable*> m_tables;

};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_)
