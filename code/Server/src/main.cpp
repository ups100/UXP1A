#include <QCoreApplication>
#include "CommandDispatcher.h"
#include "CommandQueue.h"
#include <QDebug>
#include <QThread>
#include <signal.h>

UXP1A_project::Server::CommandQueue *cQ;

void signal_handler(int sig)
{
    qDebug() << "Signal handler2";

    QThread::currentThread()->exit(0);

    //QTimer::singleShot(0, cQ, SLOT(quit()));
}

int main(int argc, char **argv)
{
    UXP1A_project::Server::CommandDispatcher dispatcher;
    UXP1A_project::Server::CommandQueue commandQueue(&dispatcher);
    cQ = &commandQueue;
    signal(SIGINT, signal_handler);

    QCoreApplication app(argc, argv);

    commandQueue.exec();
    return app.exec();
}
