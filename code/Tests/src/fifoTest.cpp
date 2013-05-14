#include <QDebug>
#include <QString>

#include "ToServerPipe.h"
#include "CommandDispatcher.h"
#include "CommandQueue.h"
#include "LindaClient.h"

void testServerFifo()
{
    using namespace UXP1A_project;

    qDebug() << "Begin testServerFifo";
    qDebug();

    try {
        QVariantList qvl;
        qvl.append(QVariant("Tekst1"));
        qvl.append(QVariant("Tekst2"));
        qvl.append(QVariant(-34912));

        Client::LindaClient lc;

        //sc.sendPushData(QString("string:*, string:*, int:*"), qvl);
        lc.push(qvl);

        QVariantList reciv;
        reciv = lc.preview(QString("string:*, string:* int:*"), 1000);
        if (reciv.size() != 3 || !reciv[0].canConvert(QVariant::String)
                || !reciv[1].canConvert(QVariant::String)
                || !reciv[2].canConvert(QVariant::Int)) {
            qDebug() << "Error 1 in Preview with data: " << reciv << "\n";
        }
        if (reciv != qvl)
            qDebug() << "Error 1.5. \n";
        else
            qDebug() << "Receive correct.\n";

        reciv = lc.preview(QString("string:*, string:* int:>4"), 1000);
        if (!reciv.isEmpty())
            qDebug() << "Error 2 in Preview (should be TIMEOUT) with data: "
                    << reciv << "\n";
        else
            qDebug() << "Receive correct.\n";

        reciv = lc.pull(QString("string:*, string:* int:*"), 1000);
        if (reciv != qvl)
            qDebug() << "Error 3 after Pull" << reciv << "\n";
        else
            qDebug() << "Receive correct.\n";

        reciv = lc.preview(QString("string:*, string:* int:*"), 5000);
        if (!reciv.isEmpty())
            qDebug() << "Error 4 in Preview (should be TIMEOUT) with data: "
                    << reciv << "\n";
        else
            qDebug() << "Receive correct.\n";

        QVariantList test2;
        test2.append(QVariant(4.567f));
        test2.append(QVariant("Drugi test."));
        test2.append(QVariant(8));
        test2.append(QVariant(98.765f));

        lc.push(test2); // QString("float:*, string:*, int:*, float:*")
        lc.push(qvl);   // QString("string:*, string:*, int:*"),
        lc.push(test2); // QString("float:*, string:*, int:*, float:*")

        reciv = lc.pull(QString("string:*, string:* int:*"), 1000);
        if (reciv != qvl)
            qDebug() << "Error 20 \n";
        else
            qDebug() << "Receive correct. \n";

        reciv = lc.preview(QString("float:*, string:*, int:*, float:*"), 1000);
        if (reciv.size() != 4 || !reciv[0].canConvert(QVariant::Double)
                || !reciv[1].canConvert(QVariant::String)
                || !reciv[2].canConvert(QVariant::Int)
                || !reciv[0].canConvert(QVariant::Double)) {
            qDebug() << "Error 21 in Preview with data: " << reciv << "\n";
        }
        if (reciv != test2)
            qDebug() << "Error 21.5 \n" << reciv;
        else
            qDebug() << "Receive correct. \n";

//return;
        reciv = lc.preview(QString("string:*, string:* int:<=4"), 1000);
        if (!reciv.isEmpty())
            qDebug() << "Error 21.99 \n" << reciv;
        else
            qDebug() << "Receive correct. \n";

        reciv = lc.pull(QString("float:*, string:*, int:*, float:*"), 1000);
        if (reciv != test2)
            qDebug() << "Error 22 pull1 \n" << reciv;
        else
            qDebug() << "Receive correct. \n";

        reciv = lc.pull(QString("float:<1, string:*, int:*, float:*"), 1000);
        if (!reciv.isEmpty())
            qDebug() << "Error 23 pull2 \n" << reciv;
        else
            qDebug() << "Receive correct. \n";

        reciv = lc.pull(QString("float:*, string:*, int:*, float:*"), 1000);
        if (reciv != test2)
            qDebug() << "Error 24 pull3 \n" << reciv;
        else
            qDebug() << "Receive correct. \n";

        reciv = lc.pull(QString("float:*, string:*, int:*, float:*"), 1000);
        if (!reciv.isEmpty())
            qDebug() << "Error 25 Pull from empty \n" << reciv;
        else
            qDebug() << "Receive correct. \n";

    } catch (char const* e) {
        QString error(e);
        qDebug() << "Zlapano wyjatek: " << error;
    } catch (std::string &s) {
        QString error(s.c_str());
        qDebug() << "Zlapano wyjatek: " << error;
    } catch (...) {
        qDebug() << "Niewyspecyfikowany wyjatek";
    }

}

