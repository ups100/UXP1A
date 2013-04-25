///////////////////////////////////////////////////////////
//  SearchPattern.h
//  Implementation of the Class SearchPattern
//  Created on:      24-kwi-2013 11:08:35
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_CB41E0A0_6E76_4c34_90D8_0BD01E7DFAB7__INCLUDED_)
#define EA_CB41E0A0_6E76_4c34_90D8_0BD01E7DFAB7__INCLUDED_

#include "Condition.h"

namespace UXP1A_project {
namespace Shared {

class SearchPattern
{

public:
    SearchPattern();
    virtual ~SearchPattern();

    bool check(const QVariantList& other);
    const QString& getTypesPattern();

private:
    QString m_typePattern;
    QList<Condition> m_conditions;
};

}//namespace Shared
}//namesoace UXP1A_project

#endif // !defined(EA_CB41E0A0_6E76_4c34_90D8_0BD01E7DFAB7__INCLUDED_)
