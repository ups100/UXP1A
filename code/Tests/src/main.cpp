#include <iostream>
#include "Configuration.h"


int main(int argc, char **argv)
{

    UXP1A_project::Shared::Configuration c;
    std::cout<<UXP1A_project::Shared::Configuration::CONFIG_FILE_NAME<<"\n";
    std::cout<<UXP1A_project::Shared::Configuration::getServerFifoPath().toStdString().c_str()<<"\n";

    std::cout<<"\n";
    return 0;
}
