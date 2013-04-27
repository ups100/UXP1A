/**
 * @file RecordTable.h
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

#if !defined(EA_EE4E919E_81D9_44ea_B28F_CBC84C61DC9D__INCLUDED_)
#define EA_EE4E919E_81D9_44ea_B28F_CBC84C61DC9D__INCLUDED_


#include <QList>
#include <QVariant>

namespace UXP1A_project {
namespace Server {

class Demand;

/**
 * @brief This class represents the table of record with specific types pattern.
 */
class RecordTable
{

public:
    /**
     * @brief Constructor
     */
    RecordTable();

    /**
     * @brief Destructor
     */
    virtual ~RecordTable();

    /**
     * @brief Adds a demand from client on this table.
     *
     * @details If demand may be satisfied from the list of records
     * it is done, otherwise it's added to list of pending demands.
     *
     * @param[in] demand to be satisfied. This function takes the ownership of
     *  passed parameter
     */
    void addDemand(Demand* demand);

    /**
     * @brief Adds record to this record table.
     *
     * @details If there are some pending demands on this table this
     *      function checks whether some of them may be satisfied with
     *      the new record and if so it is done. If there is no pending
     *      demands or the new record does not satisfied any of them it
     *      is just added to record table.
     *
     * @param[in] record to be added
     */
    void addRecord(const QVariantList& record);

private:

    /**
     * @brief Demand is a friend class to execute removeDemand method.
     */
    friend class Demand;

    /**
     * @brief Removes pending demand from list.
     *
     * @param[in] demand to be removed.
     */
    void removeDemand(Demand* demand);

    /**
     * @brief List of record in this table.
     */
    QList<QVariantList*> m_records;

    /**
     * @brief List of demands pending on this table.
     */
    QList<Demand*> m_demands;
};

} //namespace Server
} //namespace UXP1A_project
#endif // !defined(EA_EE4E919E_81D9_44ea_B28F_CBC84C61DC9D__INCLUDED_)
