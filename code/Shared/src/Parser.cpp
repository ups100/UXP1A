/**
 * @file Parser.cpp
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

SearchPattern Parser::parseConditions(const QString& conditions)
{

    return SearchPattern();
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
