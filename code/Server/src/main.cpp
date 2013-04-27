#include <QCoreApplication>
#include "CommandDispatcher.h"
#include "CommandQueue.h"

int main(int argc, char **argv)
{
    UXP1A_project::Server::CommandDispatcher dispatcher;
    UXP1A_project::Server::CommandQueue commandQueue(&dispatcher);
    QCoreApplication app(argc, argv);

    commandQueue.exec();
    return app.exec();
}
