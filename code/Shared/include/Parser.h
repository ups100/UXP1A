///////////////////////////////////////////////////////////
//  Parser.h
//  Implementation of the Class Parser
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

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
    static SearchPattern* parseConditions(const QString& conditions);
    static QString parseStruct(const QString& pattern);

};

}//namespace Shared
}//namesoace UXP1A_project

#endif // !defined(EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_)
