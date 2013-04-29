/**
 * @file Configuration.h
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

#if !defined(EA_5B26D2EF_5E9E_4623_A7EB_9A8732F16065__INCLUDED_)
#define EA_5B26D2EF_5E9E_4623_A7EB_9A8732F16065__INCLUDED_

#include <QString>

namespace UXP1A_project {
namespace Shared {

/**
 * @brief Class to store name (path) of pipe for app commands
 *
 * @note Assume that temporary (/tmp) directory exists
 *
 * @author Mikolaj Markiewicz
 */
class Configuration
{

public:

    /**
     * @brief Name (path) of pipe for commands
     */
    static const char *CONFIG_FILE_NAME;

    /**
     * @brief Get name (path) of pipe for commands
     *
     * @return Self defined const name (path) of pipe
     */
    static const QString getServerFifoPath();

};

} //namespace Shared
} //namesoace UXP1A_project

#endif // !defined(EA_5B26D2EF_5E9E_4623_A7EB_9A8732F16065__INCLUDED_)
