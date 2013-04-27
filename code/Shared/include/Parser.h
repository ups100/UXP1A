/**
 * @file Parser.h
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

#if !defined(EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_)
#define EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_

#include "SearchPattern.h"

namespace UXP1A_project {
namespace Shared {

class Parser
{

public:
    Parser();
    virtual ~Parser();

    static bool checkCondition(const QString& conditions);
    static SearchPattern parseConditions(const QString& conditions);
    static QString parseStruct(const QString& pattern);

};

}//namespace Shared
}//namesoace UXP1A_project

#endif // !defined(EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_)
