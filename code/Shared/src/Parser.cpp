///////////////////////////////////////////////////////////
//  Parser.cpp
//  Implementation of the Class Parser
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "Parser.h"

namespace UXP1A_project {
namespace Shared {

Parser::Parser()
{

}

Parser::~Parser()
{

}

bool Parser::checkCondition(const QString& conditions)
{

    return false;
}

SearchPattern* Parser::parseConditions(const QString& conditions)
{
    SearchPattern pattern;
    return &pattern;
}

/**
 * Makes a shorter pattern
 */
QString Parser::parseStruct(const QString& pattern)
{

    return QString();
}

}//namespace Shared
}//namesoace UXP1A_project
