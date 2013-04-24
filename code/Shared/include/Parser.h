///////////////////////////////////////////////////////////
//  Parser.h
//  Implementation of the Class Parser
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_)
#define EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_

#include "SearchPattern.h"

class Parser
{

public:
    Parser();
    virtual ~Parser();

    static bool checkCondition(QString conditions);
    static SearchPattern parseConditions(QString conditions);
    static QString parseStruct(QString pattern);

};
#endif // !defined(EA_A4407334_679E_4e12_ACA8_9238EB2FF7E2__INCLUDED_)
