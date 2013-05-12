///////////////////////////////////////////////////////////
//  ServerCommunication.cpp
//  Implementation of the Class ServerCommunication
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "ServerCommunication.h"

namespace UXP1A_project {
namespace Client {

ServerCommunication::ServerCommunication()
{

}

ServerCommunication::~ServerCommunication()
{

}

/**
 * Empty list after timeout
 */
QVariantList ServerCommunication::sendPreview(const QString& pattern,
        long timeout)
{
    // find out if FIFO for receive data from server is created
    if (!m_FromServerPipe)
        m_FromServerPipe = boost::shared_ptr<FromServerPipe>(
                new FromServerPipe());
    // send PREV request
    m_ToServerPipe.writePreviewMessage(pattern, timeout);

    return m_FromServerPipe->waitForMessage(Shared::Parser::parseStruct(pattern));
}

/**
 * Empty list after timeout
 */
QVariantList ServerCommunication::sendPullData(const QString& pattern,
        long timeout)
{
    // find out if FIFO for receive data from server is created
    if (!m_FromServerPipe)
        m_FromServerPipe = boost::shared_ptr<FromServerPipe>(
                new FromServerPipe());
    // send PULL request
    m_ToServerPipe.writePullDataMessage(pattern, timeout);

    return m_FromServerPipe->waitForMessage(Shared::Parser::parseStruct(pattern));
}

void ServerCommunication::sendPushData(const QString& pattern,
        const QVariantList& data)
{
//    Shared::SearchPattern *searchPattern = Shared::Parser::parseConditions(
//            pattern);
//    m_ToServerPipe.writePushDataMessage(searchPattern->getTypesPattern(), data);
    // ostatecznie bedzie to tak wygladac
    m_ToServerPipe.writePushDataMessage(pattern, data);
}

} //namespace Client
} //namespace UXP1A_project
