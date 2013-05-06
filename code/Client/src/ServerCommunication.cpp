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

QVariantList ServerCommunication::sendPreview(const QString& pattern,
        long timeout)
{
    m_ToServerPipe.writePreviewMessage(pattern, timeout);
    return m_FromServerPipe.waitForMessage();
    //return QVariantList();
}

/**
 * Empty list after timeout
 */
QVariantList ServerCommunication::sendPullData(const QString& pattern,
        long timeout)
{
    m_ToServerPipe.writePullDataMessage(pattern, timeout);
    return m_FromServerPipe.waitForMessage();
    //return QVariantList();
}

void ServerCommunication::sendPushData(const QString& pattern,
        const QVariantList& data)
{
    Shared::SearchPattern *searchPattern = Shared::Parser::parseConditions(
            pattern);
    m_ToServerPipe.writePushDataMessage(searchPattern->getTypesPattern(), data);
}

} //namespace Client
} //namespace UXP1A_project
