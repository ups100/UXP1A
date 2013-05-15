#include "ManualLinda.h"
#include <iostream>
#include <boost/lexical_cast.hpp>

//void testServerFifo();

int main(int argc, char **argv)
{
//    void testServerFifo();

    int ar[4];

    if (argc < 5) {
        ar[0] = 0;
        ar[1] = 0;
        ar[2] = 0;
        ar[3] = 0;
    } else {
        ar[0] = boost::lexical_cast<int>(argv[1]);
        ar[1] = boost::lexical_cast<unsigned int>(argv[2]);
        ar[2] = boost::lexical_cast<unsigned int>(argv[3]);
        ar[3] = boost::lexical_cast<unsigned int>(argv[4]);
    }

    UXP1A_project::Tests::ManualLinda m(ar[0], ar[1], ar[2], ar[3]);
    std::cout << m.start().toStdString();

    return 0;
}
