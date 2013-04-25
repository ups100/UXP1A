///////////////////////////////////////////////////////////
//  LindaClient.cpp
//  Implementation of the Class LindaClient
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "LindaClient.h"

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

    return QVariantList();
}

QVariantList LindaClient::pull(const QString& pattern, long timeout)
{

    return QVariantList();
}

void LindaClient::push(const QVariantList& record)
{

}

}//namespace Client
}//namespace UXP1A_project
