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

} //namespace Shared
} //namesoace UXP1A_project
