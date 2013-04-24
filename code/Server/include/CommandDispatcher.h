///////////////////////////////////////////////////////////
//  CommandDispatcher.h
//  Implementation of the Class CommandDispatcher
//  Created on:      24-kwi-2013 11:07:18
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_)
#define EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_

#include "RecordTable.h"

class CommandDispatcher
{

public:
	CommandDispatcher();
	virtual ~CommandDispatcher();
	RecordTable *m_RecordTable;

	void dispatchPreviewCommand(QString conditions, long timeout);
	void dispatchPullCommand(QString condition, long timeout);
	void dispatchPushCommand(QString pattern, QVariantList data);

private:
	QMap<QString, RecordTable> m_tables;

};
#endif // !defined(EA_AAA1EB89_F26C_4e8e_80C9_ECB4A1B07793__INCLUDED_)
