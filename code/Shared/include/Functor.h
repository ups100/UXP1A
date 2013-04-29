/**
 * @file Functor.h
 *
 * @date 27-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::Configuration
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(EA_B52C6882_AFD6_43c1_9F81_465D6615CA83__INCLUDED_)
#define EA_B52C6882_AFD6_43c1_9F81_465D6615CA83__INCLUDED_

#include <boost/function.hpp>
#include <QVariant>

namespace UXP1A_project {
namespace Shared {

class Functor
{

public:

    /**
     * @brief Short name for function type
     */
    typedef boost::function<bool(const QVariant&, const QVariant&)> PF;

    /**
     * @brief D-tor
     */
    virtual ~Functor();

    /**
     * @brief Default C-tor. Required by QMap ?
     */
    Functor();

    /**
     * @brief Proper C-tor
     *
     * @param cmpFunction Appropriate comparison function
     */
    Functor(PF cmpFunction);

    /**
     * @brief Invoke function passed to functor with given parameters
     * <br /> Example:
     * @code
     *      less(1,5) => true, greater(1,5) => false
     * @endcode
     *
     * @note In most cases asks for relation between first to second
     *
     * @param left First value
     *
     * @param right Second value
     *
     * @return true if specified function say so, false otherwise
     */
    bool operator()(const QVariant& left, const QVariant& right);

private:

    /**
     * @brief Functor handler
     */
    PF m_cmpFunction;
};

} //namespace Shared
} //namesoace UXP1A_project

#endif // !defined(EA_B52C6882_AFD6_43c1_9F81_465D6615CA83__INCLUDED_)
