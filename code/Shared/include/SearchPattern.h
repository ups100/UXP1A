///////////////////////////////////////////////////////////
//  SearchPattern.h
//  Implementation of the Class SearchPattern
//  Created on:      24-kwi-2013 11:08:35
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_CB41E0A0_6E76_4c34_90D8_0BD01E7DFAB7__INCLUDED_)
#define EA_CB41E0A0_6E76_4c34_90D8_0BD01E7DFAB7__INCLUDED_

#include "Condition.h"

class SearchPattern
{

public:
	SearchPattern();
	virtual ~SearchPattern();
	Condition *m_Condition;

	bool check(QVariantList other);
	QString getTypesPattern();

private:
	QString m_typePattern;

};
#endif // !defined(EA_CB41E0A0_6E76_4c34_90D8_0BD01E7DFAB7__INCLUDED_)
