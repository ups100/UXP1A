/**
 * @file Configuration.cpp
 *
 * @date 27-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::Configuration
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#include "Configuration.h"

namespace UXP1A_project {
namespace Shared {

//TODO I remove dot from file name - after we can add it again
const char *Configuration::CONFIG_FILE_NAME = "UXP1A_commands";
// remember about slash after directory path below:
const char *Configuration::CONFIG_FILE_PATH = "/tmp/linda/"; //remember - end with '/'

const QString Configuration::getServerFifoPath()
{
    return QString(CONFIG_FILE_PATH) + QString(CONFIG_FILE_NAME);
}

const std::string Configuration::getServerFifoDir()
{
    return std::string(CONFIG_FILE_PATH);
}

const std::string Configuration::getServerFifoName()
{
    return std::string(CONFIG_FILE_NAME);
}

void Configuration::displayBuffer(const char *buff, const int length)
{
    for(int i=0; i<length; ++i) {
        if(buff[i] == '\0')
            std::cout.put('#');
        std::cout.put(buff[i]);
    }
    std::cout << std::endl;
}

char Configuration::getMesCode(Message mes)
{
    switch (mes) {
        case PUSH:
            return 'a';
        case PULL:
            return 'b';
        case PREV:
            return 'c';
        case FOUND:
            return 'd';
        case TIME:
            return 'e';
        case EXIT:
            return 'f';
    };
    // if a kind of error - return safe value '\0' - this is always ignore
    return '\0';
}

Configuration::Message Configuration::getMes(const char code)
{
    switch (code) {
        case 'a':
            return PUSH;
        case 'b':
            return PULL;
        case 'c':
            return PREV;
        case 'd':
            return FOUND;
        case 'e':
            return TIME;
        case 'f':
            return EXIT;
    }

}

} //namespace Shared
} //namesoace UXP1A_project
