///////////////////////////////////////////////////////////
//  CommandQueue.h
//  Implementation of the Class CommandQueue
//  Created on:      24-kwi-2013 11:07:18
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_6F70F9D8_1D5A_4ea2_9FC3_CF3EB2298A5C__INCLUDED_)
#define EA_6F70F9D8_1D5A_4ea2_9FC3_CF3EB2298A5C__INCLUDED_

#include "CommandDispatcher.h"

/**
 * ma qthreda, ciagle czyta o wysyla do dispatchera
 */
class CommandQueue
{

public:
	CommandQueue();
	virtual ~CommandQueue();
	CommandDispatcher *m_CommandDispatcher;

	void exec();

};
#endif // !defined(EA_6F70F9D8_1D5A_4ea2_9FC3_CF3EB2298A5C__INCLUDED_)
