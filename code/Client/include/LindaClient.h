/**
 * @file LindaClient.h
 *
 * @date 29-04-2013
 *
 * @author Opasiak Krzysztof, Markiewicz Mikołaj, Klara Mateusz, Sosnowski Jacek
 *
 * @brief Implementation of the Class UXP1A_project::Client::LindaClient
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#if !defined(EA_BBD5C16D_5176_4930_BA02_6131DB72415B__INCLUDED_)
#define EA_BBD5C16D_5176_4930_BA02_6131DB72415B__INCLUDED_

#include "ServerCommunication.h"
#include <QVariant>
#include <QString>

namespace UXP1A_project {
namespace Client {

/**
 * @brief Client's interface
 */
class LindaClient
{

public:
    /**
     * @brief Constructor.
     *
     * @details You may create object of this class for more convenient
     *          usage of static methods of this class.
     */
    LindaClient();

    /**
     * @brief Destructor
     */
    virtual ~LindaClient();

    /**
     * @brief Execute preview command in Linda Client application.
     *        This method doesn't cause tuple deletion from server.
     *
     * @param[in]   pattern which returned tuple should fulfill.
     * @param[in]   timeout is max time in milliseconds which server will wait for tuple
     *              since begin of serving this command, before it sends timeout message
     *
     * @return  QVariantList which contains required tuple
     *          or empty QVariantList which means that there is no such tuple and timeout occurs.
     *
     * @details This method send preview request to server and wait for answer ( until timeout ).
     *          First calling of this method opens client's FIFO which is use to receive tuples from server
     *          in this method and pull() also. FIFO is opening only one per client - only if it is necessary
     *          (after first use of preview() or pull() method).
     *
     * @throws Shared::ParserException if pattern is incorrect
     * @throws Shared::NumericLimitException if some numeric values exceeds integer or float limits
     * @throws ServerFifoException if function was unable to open server's FIFO
     * @throws ClientFifoException if function was unable to create or open client's FIFO
     */
    static QVariantList preview(const QString& pattern, long timeout = -1);

    /**
     * @brief Execute pull command in Linda Client application.
     * This method DELETES tuple from server!
     *
     * @param[in]   pattern which returned tuple should fulfill. This is not parsed pattern.
     * @param[in]   timeout is max time in milliseconds which server will wait for tuple
     *              since begin of serving this command, before it sends timeout message
     *
     * @return QVariantList which contains required tuple
     *         or empty QVariantList which means that there is no such tuple and timeout occurs.
     *
     * @details This method send pull request to server and wait for answer ( until timeout ).
     *          First calling of this method opens client's FIFO which is use to receive tuples from server
     *          in this method and preview() also. FIFO is opening only one per client - only if it is necessary
     *          (after first use of preview() or pull() method).
     *
     * @note Returned tuple won't be available on the server any more.
     *
     * @throws Shared::ParserException if pattern is incorrect
     * @throws Shared::NumericLimitException if some numeric values exceeds integer or float limits
     * @throws ServerFifoException if function was unable to open server's FIFO
     * @throws ClientFifoException if function was unable to create or open client's FIFO
     */
    static QVariantList pull(const QString& pattern, long timeout = -1);

    /**
     * @brief Execute push command in Linda Client application.
     * This method will send record to the Linda Server via its FIFO.
     *
     * @param[in]   record to be sent. This record will be send and store in Server only
     *              if types of each QVariant will be one from the list below:
     *              string, int or float
     *
     * @details To push record Client application should prepare tuple - QList of QVariant (QVariantList typedef)
     *          and call this method which should return immediately after write this tuple to Server FIFO.
     *
     * @throws Shared::ParserException if record consist of from types diferen than integer, float, string
     * @throws ServerFifoException if function was unable to open server's FIFO
     * @throws ClientFifoException if function was unable to create or open client's FIFO
     */
    static void push(const QVariantList& record);

private:
    /**
     * @brief Object used to communicate with Linda Server.
     */
    static ServerCommunication m_ServerCommunication;
};

} //namespace Client
} //namespace UXP1A_project

#endif // !defined(EA_BBD5C16D_5176_4930_BA02_6131DB72415B__INCLUDED_)
