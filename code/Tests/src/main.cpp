#include "ManualLinda.h"
#include <iostream>
#include <boost/lexical_cast.hpp>

//void testServerFifo();

int main(int argc, char **argv)
{
//    void testServerFifo();

    if (argc < 5)
        exit(1);

    UXP1A_project::Tests::ManualLinda m(boost::lexical_cast<int>(argv[1]),
            boost::lexical_cast<unsigned int>(argv[2]),
            boost::lexical_cast<unsigned int>(argv[3]),
            boost::lexical_cast<unsigned int>(argv[4]));
    std::cout << m.start().toStdString();

    return 0;
}
