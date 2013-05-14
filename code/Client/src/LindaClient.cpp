///////////////////////////////////////////////////////////
//  LindaClient.cpp
//  Implementation of the Class LindaClient
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "LindaClient.h"
#include "ParserException.h"
#include "NumericLimitException.h"

namespace UXP1A_project {
namespace Client {

ServerCommunication LindaClient::m_ServerCommunication;

LindaClient::LindaClient()
{

}

LindaClient::~LindaClient()
{

}

QVariantList LindaClient::preview(const QString& pattern, long timeout)
{
    // check given pattern structure
    try {
        Shared::Parser::checkCondition(pattern);
    } catch (Shared::ParserException &e) {
        throw e;
    } catch (Shared::NumericLimitException &e) {
        throw e;
    }

    return m_ServerCommunication.sendPreview(pattern, timeout);
}

QVariantList LindaClient::pull(const QString& pattern, long timeout)
{
    // check given pattern structure
    try {
        Shared::Parser::checkCondition(pattern);
    } catch (Shared::ParserException &e) {
        throw e;
    } catch (Shared::NumericLimitException &e) {
        throw e;
    }

    return m_ServerCommunication.sendPullData(pattern, timeout);
}

void LindaClient::push(const QVariantList& record)
{
    using Shared::Parser;

    QString shrt;

    try {
        shrt = Parser::parseStruct(record);
    } catch (Shared::ParserException &e) {
        throw e;
    } catch (Shared::NumericLimitException &e) {
        throw e;
    }

    m_ServerCommunication.sendPushData(shrt, record);
}

} //namespace Client
} //namespace UXP1A_project
