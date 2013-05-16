/**
 * @file ServerCommunication.cpp
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

#include "ServerCommunication.h"

namespace UXP1A_project {
namespace Client {

ServerCommunication::ServerCommunication()
{

}

ServerCommunication::~ServerCommunication()
{

}

QVariantList ServerCommunication::sendPreview(const QString& pattern,
        long timeout)
{
    if(!m_ToServerPipe)
        m_ToServerPipe = boost::shared_ptr<ToServerPipe>(
                        new ToServerPipe());
    // find out if FIFO for receive data from server is created
    if (!m_FromServerPipe)
        m_FromServerPipe = boost::shared_ptr<FromServerPipe>(
                new FromServerPipe());
    // send PREV request
    m_ToServerPipe->writePreviewMessage(pattern, timeout);

    return m_FromServerPipe->waitForMessage(Shared::Parser::parseStruct(pattern));
}

QVariantList ServerCommunication::sendPullData(const QString& pattern,
        long timeout)
{
    if(!m_ToServerPipe)
            m_ToServerPipe = boost::shared_ptr<ToServerPipe>(
                            new ToServerPipe());
    // find out if FIFO for receive data from server is created
    if (!m_FromServerPipe)
        m_FromServerPipe = boost::shared_ptr<FromServerPipe>(
                new FromServerPipe());
    // send PULL request
    m_ToServerPipe->writePullDataMessage(pattern, timeout);

    return m_FromServerPipe->waitForMessage(Shared::Parser::parseStruct(pattern));
}

void ServerCommunication::sendPushData(const QString& pattern,
        const QVariantList& data)
{
    if(!m_ToServerPipe)
            m_ToServerPipe = boost::shared_ptr<ToServerPipe>(
                            new ToServerPipe());
    m_ToServerPipe->writePushDataMessage(pattern, data);
}

} //namespace Client
} //namespace UXP1A_project
