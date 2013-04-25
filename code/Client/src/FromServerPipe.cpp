///////////////////////////////////////////////////////////
//  FromServerPipe.cpp
//  Implementation of the Class FromServerPipe
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "FromServerPipe.h"

namespace UXP1A_project {
namespace Client {

FromServerPipe::FromServerPipe()
{

}

FromServerPipe::~FromServerPipe()
{

}

const QString& FromServerPipe::getPipeName()
{

    return NULL;
}

/**
 * Pusta lista albo wyjatekjak po timeoucie
 */
QVariantList FromServerPipe::waitForMessage()
{

    return QVariantList();
}

}//namespace Client
}//namespace UXP1A_project
