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

const char *Configuration::CONFIG_FILE_NAME = "/tmp/.UXP1A_commands";

const QString Configuration::getServerFifoPath()
{
    return QString(CONFIG_FILE_NAME);
}

} //namespace Shared
} //namesoace UXP1A_project
