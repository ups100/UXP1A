///////////////////////////////////////////////////////////
//  Configuration.h
//  Implementation of the Class Configuration
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_5B26D2EF_5E9E_4623_A7EB_9A8732F16065__INCLUDED_)
#define EA_5B26D2EF_5E9E_4623_A7EB_9A8732F16065__INCLUDED_

class Configuration
{

public:
	Configuration();
	virtual ~Configuration();

	static QString getServerFifoPath();

};
#endif // !defined(EA_5B26D2EF_5E9E_4623_A7EB_9A8732F16065__INCLUDED_)
