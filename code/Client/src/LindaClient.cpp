/**
 * @file LindaClient.cpp
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
