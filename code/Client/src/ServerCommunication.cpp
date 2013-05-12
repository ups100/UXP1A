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
    // find out if FIFO for receive data from server is created
    if (!m_FromServerPipe)
        m_FromServerPipe = boost::shared_ptr<FromServerPipe>(
                new FromServerPipe());
    // send PREV request
    m_ToServerPipe.writePreviewMessage(pattern, timeout);

    //QVariantList receivData = m_FromServerPipe->waitForMessage(Shared::Parser::parseStruct(pattern));
    //return processData(pattern, receivData);
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

//    QVariantList receivData = m_FromServerPipe->waitForMessage(Shared::Parser::parseStruct(pattern));
//    return processData(pattern, receivData);
    return m_FromServerPipe->waitForMessage(Shared::Parser::parseStruct(pattern));
}

/*
QVariantList ServerCommunication::processData(const QString& pattern, const QVariantList& qvl) const
{
    qDebug() << "Do processData takie dane: " << qvl;
    QString shortPattern(Shared::Parser::parseStruct(pattern));
    qDebug() << "Pattern: "<<shortPattern;
    QVariantList retData;
    int pIter = 0; //Pattern Iterator
    for (int i=0; i<qvl.size(); ++i) {
        char dataType = shortPattern[pIter++].toAscii();
        QVariant qv;
        if (dataType == 's') {
            qv = qvl[i];
        }
        else if (dataType == 'i') {
            int d;
            const char *sInt = qvl[i].toByteArray().constData();
            memcpy(&d, sInt, sizeof(int));
            qv = QVariant(d);
        }
        else if (dataType == 'f') {
            float f;
            const char *sFloat = qvl[i].toByteArray().constData();
            memcpy(&f, sFloat, sizeof(float));
            qv = QVariant(f);
        }
        retData.append(qv);
    }
    qDebug() << "Zwwracam takie dane: " <<retData;
    return retData;
}
*/

void ServerCommunication::sendPushData(const QString& pattern,
        const QVariantList& data)
{
    Shared::SearchPattern *searchPattern = Shared::Parser::parseConditions(
            pattern);
    m_ToServerPipe.writePushDataMessage(searchPattern->getTypesPattern(), data);
    // ostatecznie bedzie to tak wygladac
//    m_ToServerPipe.writePushDataMessage(pattern, data);
}

} //namespace Client
} //namespace UXP1A_project
