///////////////////////////////////////////////////////////
//  Functor.h
//  Implementation of the Class Functor
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_B52C6882_AFD6_43c1_9F81_465D6615CA83__INCLUDED_)
#define EA_B52C6882_AFD6_43c1_9F81_465D6615CA83__INCLUDED_

#include <boost/function.hpp>
#include <QVariant>

namespace UXP1A_project {
namespace Shared {


class Functor
{

public:

    typedef boost::function<bool(const QVariant&, const QVariant&)> PF;

    Functor();
    virtual ~Functor();
    Functor(PF cmpFunction);
    bool operator()(const QVariant& left, const QVariant& right);

private:
    PF m_cmpFunction;
};

}//namespace Shared
}//namesoace UXP1A_project

#endif // !defined(EA_B52C6882_AFD6_43c1_9F81_465D6615CA83__INCLUDED_)
