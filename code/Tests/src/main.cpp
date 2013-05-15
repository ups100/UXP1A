#include "ManualLinda.h"
#include <iostream>

//void testServerFifo();

int main(int argc, char **argv)
{
//    void testServerFifo();

    UXP1A_project::Tests::ManualLinda m;
    std::cout << m.start().toStdString();

    return 0;
}
