///////////////////////////////////////////////////////////
//  ToServerPipe.h
//  Implementation of the Class ToServerPipe
//  Created on:      24-kwi-2013 11:04:00
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_)
#define EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_

class ToServerPipe
{

public:
	ToServerPipe();
	virtual ~ToServerPipe();

	void writePreviewMessage(QString pattern, long timeout);
	void writePullDataMessage(QString condition, long timeout);
	void writePushDataMessage(QString pattern, QVariantList data);

};
#endif // !defined(EA_61525155_5086_42f4_A1F9_AB47015C5EA5__INCLUDED_)
