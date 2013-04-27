/**
 * @file Demand.h
 *
 * @date 27-04-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class UXP1A_project::Server::Demand
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#if !defined(EA_B91FCB49_E030_4c12_B60E_CB447A493D12__INCLUDED_)
#define EA_B91FCB49_E030_4c12_B60E_CB447A493D12__INCLUDED_

#include "ClientCommunication.h"
#include "SearchPattern.h"
#include <QVariant>
#include <QString>
#include <QTimer>

namespace UXP1A_project {
namespace Server {

class RecordTable;

/**
 * @brief Client's demand.
 *
 * @details This class represents Clients demand for some record.
 */
class Demand: public QObject
{
Q_OBJECT;
public:
    /**
     * @brief Constructor
     *
     * @param[in] pattern search pattern,
     *              This function takes the ownership of this object
     *
     * @param[in] client FIFO
     *
     * @param[in] isPull true if this is pull demand
     *
     * @param[in] timeout number of seconds when this demand expires
     */
    Demand(Shared::SearchPattern* pattern, const QString& client,
            bool isPull, int timeout);

    /**
     * @brief Destructor
     */
    virtual ~Demand();

    /**
     * @brief Sets the record table to make this demand as pending
     *
     * @param[in,out] recordTable on which deman is pending
     */
    void setRecordTable(RecordTable *recordTable);

    /**
     * @brief Check if passed record is suitable for this demand
     *
     * @param[in] record to be checked
     *
     * @return true if @arg{record} is suitable, false otherwise
     */
    bool checkRecord(const QVariantList& record);

    /**
     * @brief Checks if this is pull demand.
     *
     * @return true if this is pull demand, false otherwise
     */
    bool isPullDemand();

    /**
     * @brief Sends passed record to the client
     *
     * @param[in] record to be sent
     */
    void sendRecord(const QVariantList& record);

private slots:

    /**
     * @brief Helper slot to inform about the timeout
     */
    void demandTimeout();

private:
    /**
     * @brief Search pattern for this demand
     */
    Shared::SearchPattern *m_searchPattern;

    /**
     * @brief Client - the owner of this demand
     */
    ClientCommunication m_clientCommunication;

    /**
     * @brief Informs if this demand has been satisfied
     */
    bool m_finalized;

    /**
     * @brief Informs if this is pull demand or not
     */
    bool m_isPullDemand;

    /**
     * @brief Informs about the timeout length
     */
    int m_timeout;

    /**
     * @brief Timer for this demand
     */
    QTimer m_timer;

    /**
     * @brief Record table with equal type pattern.
     */
    RecordTable *m_recordTable;

};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_B91FCB49_E030_4c12_B60E_CB447A493D12__INCLUDED_)
