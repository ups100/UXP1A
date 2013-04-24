///////////////////////////////////////////////////////////
//  FromServerPipe.h
//  Implementation of the Class FromServerPipe
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_)
#define EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_

/**
 * Proxy on write
 */
class FromServerPipe
{

public:
	FromServerPipe();
	virtual ~FromServerPipe();

	QString getPipeName();
	QVariantList waitForMessage();

};
#endif // !defined(EA_20C0297F_C43E_42ec_B37A_3F47C0968D67__INCLUDED_)
