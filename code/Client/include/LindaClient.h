///////////////////////////////////////////////////////////
//  LindaClient.h
//  Implementation of the Class LindaClient
//  Created on:      24-kwi-2013 11:03:59
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_BBD5C16D_5176_4930_BA02_6131DB72415B__INCLUDED_)
#define EA_BBD5C16D_5176_4930_BA02_6131DB72415B__INCLUDED_

#include "ServerCommunication.h"

class LindaClient
{

public:
	LindaClient();
	virtual ~LindaClient();
	ServerCommunication *m_ServerCommunication;

	static QVariantList preview(QString pattern, long timeout);
	static QVariantList pull(QString pattern, long timeout);
	static void push(QVariant record);

};
#endif // !defined(EA_BBD5C16D_5176_4930_BA02_6131DB72415B__INCLUDED_)
