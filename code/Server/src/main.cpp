#include <QCoreApplication>
#include "CommandDispatcher.h"
#include "CommandQueue.h"
#include <signal.h>


using UXP1A_project::Server::CommandDispatcher;



void handler(int signal)
{
    CommandDispatcher::terminate();
}


int main(int argc, char **argv)
{
    CommandDispatcher *dispatcher = CommandDispatcher::getInstance(argc, argv) ;
    signal(SIGINT, handler);
    return dispatcher->exec();

}
