/**
 * @file ServerCommunication.h
 *
 * @date 29-04-2013
 *
 * @author Sosnowski Jacek
 *
 * @brief Implementation of the Class UXP1A_project::Client::ServerCommunication
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures. Project was created to ensure interprocess communication
 * with Linda communication language.
 */

#if !defined(EA_CB6AB119_B8C2_46c4_ABFA_E406179A4D60__INCLUDED_)
#define EA_CB6AB119_B8C2_46c4_ABFA_E406179A4D60__INCLUDED_

#include "ToServerPipe.h"
#include "FromServerPipe.h"
#include "SearchPattern.h"
#include "Parser.h"

#include <memory>
#include <boost/shared_ptr.hpp>
#include <QString>
#include <QVariantList>

namespace UXP1A_project {
namespace Client {

class ServerCommunication
{

public:
    /**
     * @brief With this object is create also ToServerPipe
     * This opens server FIFO, so it could end with exception.
     *
     * @throw std::string from constructor of ToServerPipe when no server is running.
     */
    ServerCommunication();
    virtual ~ServerCommunication();

    /**
     * @brief Manage sending Preview request to server.
     * @details After send request this wait for reply.
     * If it is first use of sending request there is creating a client FIFO
     * file to receive answer from server
     * @throws std::exception when can not creating FIFO file.
     */
    QVariantList sendPreview(const QString& pattern, long timeout);
    QVariantList sendPullData(const QString& pattern, long timeout);
    //QVariantList processData(const QString& pattern, const QVariantList& qvl) const;
    void sendPushData(const QString& pattern, const QVariantList& data);

private:
    ToServerPipe m_ToServerPipe;
    boost::shared_ptr<FromServerPipe> m_FromServerPipe;

};

} //namespace Client
} //namespace UXP1A_project

#endif // !defined(EA_CB6AB119_B8C2_46c4_ABFA_E406179A4D60__INCLUDED_)
