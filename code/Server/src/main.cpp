#include <QCoreApplication>
#include "CommandDispatcher.h"
#include "CommandQueue.h"
#include <signal.h>
#include <QString>

using UXP1A_project::Server::CommandDispatcher;



void handler(int signal)
{
    CommandDispatcher::terminate();
}


int main(int argc, char **argv)
{
    try {
    CommandDispatcher *dispatcher = CommandDispatcher::getInstance(argc, argv) ;
    signal(SIGINT, handler);
    return dispatcher->exec();
    } catch(std::string &e)
    {
        qDebug()<<"Unable to start server due to exception: ";
        qDebug()<<QString(e.c_str());
        return -1;
    }
}
