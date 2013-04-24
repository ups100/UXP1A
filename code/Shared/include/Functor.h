///////////////////////////////////////////////////////////
//  Functor.h
//  Implementation of the Class Functor
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_B52C6882_AFD6_43c1_9F81_465D6615CA83__INCLUDED_)
#define EA_B52C6882_AFD6_43c1_9F81_465D6615CA83__INCLUDED_

/**
 * dodac template constructor
 */
class Functor
{

public:
	Functor();
	virtual ~Functor();

	bool operator()(QVariant left, QVariant right);

};
#endif // !defined(EA_B52C6882_AFD6_43c1_9F81_465D6615CA83__INCLUDED_)
