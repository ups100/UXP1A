//#include "ManualLinda.h"
#include "LindaClient.h"
#include <QDebug>
using namespace UXP1A_project::Client;

//void testServerFifo();

int main(int argc, char **argv)
{
//    void testServerFifo();

//    UXP1A_project::Tests::ManualLinda m;
//    m.start();

    if (argc == 1) {
        // pull int:*
        QVariantList list;
        qDebug() << LindaClient::pull("int:*");
    } else if (argc == 2) {
        // push int:-1
        QVariantList list;
        list << -1;
        LindaClient::push(list);
    }

    return 0;
}
