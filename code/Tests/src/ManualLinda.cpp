/**
 * @file ManualLinda.cpp
 *
 * @date 13-05-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::ManualLinda
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#include "ManualLinda.h"
#include "Parser.h"
#include "LindaClient.h"
#include "ParserException.h"
#include "NumericLimitException.h"
#include <QRegExp>
#include <QMetaType>
#include <QTime>
#include <QDate>
#include <boost/lexical_cast.hpp>
#include <boost/thread/thread.hpp>
#include <QDebug>
#include <iostream>

namespace UXP1A_project {
namespace Tests {

using namespace std;
using namespace UXP1A_project::Shared;

ManualLinda::ManualLinda(bool testOutput, unsigned int testSleep,
        unsigned int testTimeout, unsigned int testAfterPulledSleep)
        : m_testOutput(testOutput), m_testSleep(testSleep),
                m_testTimeout(testTimeout),
                m_testAfterPulledSleep(testAfterPulledSleep),
                m_intGenerator(m_generator, IntNumberDistribution())
{
    m_generator.seed((uint) QTime::currentTime().msec());
}

QString ManualLinda::start()
{
    m_pushed.clear();
    m_pulled.clear();
    m_testChain = "";

    if (m_testOutput)
        cout.setstate(ios::failbit);

    cout << "\nHello! This is test of manual Linda use.";

    qPrintPidInfo("START");

    loop();

    qPrintPidInfo("END");

    if (!m_testOutput) {
        qDebug() << "\n\tPushed " << m_pushed.size() << " tuples:";
        foreach (QVariantList list, m_pushed){
        qDebug()<<list;
    }

        qDebug() << "\n\tPulled " << m_pulled.size() << " tuples:";
        foreach (QVariantList list, m_pulled){
        qDebug()<<list;
    }
}

    cout << "\n\nBye!\n\n";

    if (m_testOutput)
        cout.clear();

    return m_testChain;
}

void ManualLinda::loop()
{
    char c;
    showMenu();

    while ((c = getc(stdin)) != 'q') {
        while (getchar() != '\n') {
        }

        try {
            if (c == '1') {
                pushTuple();
                cout << "\nTuple successful pushed.";

                qPrintPidInfo("Successfully pushed!");

                m_testChain.append("1");
            } else if (c == '2') {
                const QVariantList list = pullTuple();

                if (list.size()) {
                    cout << "\nTuple successful pulled:\n";
                    cout << printTupleList(list).toStdString();

                    qPrintPidInfo("Successfully pulled!");

                    if (m_testAfterPulledSleep) {
                        int slp = randInt(m_testAfterPulledSleep);
                        qPrintPidInfo(
                                QString("Random ") + QString::number(slp)
                                        + " ms sleep after successful pull.");
                        boost::this_thread::sleep(
                                boost::posix_time::milliseconds(slp));
                    }

                    m_testChain.append("1");
                } else {
                    cout << "\nTimeout.";

                    qPrintPidInfo("Pull timeout!");

                    m_testChain.append("0");
                }
            } else if (c == '3') {
                const QVariantList list = previewTuple();

                if (list.size()) {
                    cout << "\nTuple preview successful:\n";
                    cout << printTupleList(list).toStdString();

                    qPrintPidInfo("Preview successful!");

                    m_testChain.append("1");
                } else {
                    cout << "\nTimeout.";

                    qPrintPidInfo("Preview timeout!");

                    m_testChain.append("0");
                }
            } else {
                cout << "\tMistake\n";
            }
        } catch (ParserException &e) {
            cout << "Bad pattern: " << e.what() << "\n";

            qPrintPidInfo("PattermException!");

            m_testChain.append("0");
        } catch (NumericLimitException &e) {
            cout << "Out of limit: " << e.what() << "\n";

            qPrintPidInfo("NumericLimitException!");

            m_testChain.append("0");
        } catch (...) {
            cout << "Unknown exception, probably server.\n";

            qPrintPidInfo("Unknown exception!");

            m_testChain.append("0");
        }

        if (m_testSleep) {
            int slp = randInt(m_testSleep);

            qPrintPidInfo(
                    QString("Sleep for ") + QString::number(slp)
                            + " ms after linda operation.");

            boost::this_thread::sleep(boost::posix_time::milliseconds(slp));
        }

        showMenu();
    }
}

void ManualLinda::pushTuple()
{
    char c;
    QString str;

    cout
            << "Type tuple format (push so: operators are useless, float need operator!):\n\t";

    while ((c = getchar()) != '\n') {
        str.append(c);
    }

    if (!Parser::checkCondition(str))
        throw ParserException(
                "Check condition failed.\nThere is no push from string in program so if float then it needs operator!");

    QVariantList list = Parser::parseValuesToList(str);

    if (list.contains(QVariant(QDate())))
        throw ParserException("Only int, float, string.");

    qPrintPidInfo(QString("Push:\t") + printTupleList(list));

    Client::LindaClient::push(list);

    m_pushed << list;
}

QVariantList ManualLinda::pullTuple()
{
    pair<QString, int> pr = getRequest();

    qPrintPidInfo(
            QString("Pull with timeout: ") + QString::number(pr.second)
                    + "\tPattern: \"" + pr.first + "\"");

    QVariantList list = Client::LindaClient::pull(pr.first, pr.second);

    if (list.size())
        m_pulled << list;

    return list;
}

QVariantList ManualLinda::previewTuple()
{
    pair<QString, int> pr = getRequest();

    qPrintPidInfo(
            QString("Preview with timeout: ") + QString::number(pr.second)
                    + "\tPattern: \"" + pr.first + "\"");

    QVariantList list = Client::LindaClient::preview(pr.first, pr.second);

    return list;
}

std::pair<QString, int> ManualLinda::getRequest()
{
    char c;
    int timeout;
    QString str;

    /*
     * Timeout
     */
    cout << "Type timeout (-1 | 0 | X msec.):\n\t";

    while ((c = getchar()) != '\n') {
        str.append(c);
    }

    if (m_testTimeout) {
        timeout = randInt(m_testTimeout);
    } else {

        try {
            timeout = boost::lexical_cast<int>(str.toStdString());
        } catch (boost::bad_lexical_cast &e) {
            cout << "\t0 has been choosen ;)\n";
            timeout = 0;
        }
    }
    str.clear();

    if (timeout < 0)
        timeout = -1;
//    else
//        timeout *= 1000;

    /*
     * Tuple pattern
     */
    cout << "Type tuple format:\n\t";

    while ((c = getchar()) != '\n') {
        str.append(c);
    }

    if (!Parser::checkCondition(str))
        throw ParserException("Check condition failed.");

    return make_pair(str, timeout);
}

QString ManualLinda::printTupleList(const QVariantList &list)
{
    QString str;
    int i = list.size();
    str.append("\t( ");

    foreach (QVariant l, list){
    switch (l.type()) {
        case QVariant::Int:
        str.append(QString::number(l.value<int>()));
        break;
        case QMetaType::Float:
        str.append(QString::number(l.value<float>()));
        break;
        case QVariant::String:
        str.append("\"");
        str.append(l.value<QString>());
        str.append("\"");
        break;
    }

    if (--i != 0)
    str.append(", ");
}
    str.append(" )");

    return str;
}

void ManualLinda::showMenu()
{
    cout << "\n";
    cout << "\n +-----------+";
    cout << "\n | 1 Push    |";
    cout << "\n | 2 Pull    |";
    cout << "\n | 3 Preview |";
    cout << "\n |           |";
    cout << "\n | q Quit    |";
    cout << "\n +-----------+";
    cout << "\n   $> ";
}

void ManualLinda::qPrintPidInfo(const QString &info)
{
    if (m_testOutput)
        qDebug() << getpid() << ": " << info;
}

int ManualLinda::randInt(int rangeMax, int rangeMin)
{
    m_intGenerator.distribution().param(
            boost::uniform_int<>::param_type(rangeMin, rangeMax));

    return m_intGenerator();
}

} //namespace Tests
} //namesoace UXP1A_project
