/**
 * @file ComparisonFactory.h
 *
 * @date 27-04-2013
 *
 * @author Mikolaj Markiewicz <kajo100@gmail.com>
 *
 * @brief Implementation of the Class UXP1A_project::Shared::ComparisonFactory
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on UXP1A lectures.
 */

#if !defined(EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_)
#define EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_

#include "Functor.h"
#include <QString>
#include <QMap>

namespace UXP1A_project {
namespace Shared {

/**
 * @author Mikolaj Markiewicz
 *
 * @brief Singleton Factory of functors to compare tuple's attributes
 */
class ComparisonFactory
{

public:

    /**
     * @brief Identifiers of available Functors.
     */
    enum CmpSymbol
    {
        INT_EQUAL, /* == */
        INT_LESS, /* < */
        INT_LESS_EQUAL, /* <= */
        INT_GREATER, /* > */
        INT_GREATER_EQUAL, /* >= */
        FLOAT_LESS, /* < */
        FLOAT_LESS_EQUAL, /* <= */
        FLOAT_GREATER, /* > */
        FLOAT_GREATER_EQUAL, /* >= */
        STRING_EQUAL, /* == */
        STRING_LESS, /* < */
        STRING_LESS_EQUAL, /* <= */
        STRING_GREATER, /* > */
        STRING_GREATER_EQUAL, /* >= */
        ANYTHING /* * */
    };

    /**
     * @brief D-tor
     */
    virtual ~ComparisonFactory();

    /**
     * @brief Get comparison functor identified by given CmpSymbol
     *
     * @note Throws const char* exception if not found given symbol in map
     *
     * @param Symbol identifying wanted functor
     *
     * @return Proper functor or throws const char* if not found
     */
    static Functor getCmpFunctor(CmpSymbol cmpSymbol);

private:

    /**
     * @brief Private C-tor to make it Singleton
     *        Defines several standard functors
     */
    ComparisonFactory();

    /**
     * @brief Private copying constructor
     *
     * @note Due to Singleton class, should not be called,
     *       If does, throws an exception as const char*
     *
     * @param Irrelevant
     *
     * @return Irrelevant
     */
    ComparisonFactory(const ComparisonFactory&);

    /**
     * @brief Private assign operator
     *
     * @note Due to Singleton class, should not be called,
     *       If does, throws an exception as const char*
     *
     * @param Irrelevant
     *
     * @return Irrelevant
     */
    ComparisonFactory& operator=(const ComparisonFactory&);

    /**
     * @brief Map of Functors set by CmpSymbol
     */
    QMap<CmpSymbol, Functor> m_functors;

    /**
     * @brief Template for creating Functors by binding standard function as
     *          functor passed as argument to compare QVariants with given Type
     *
     * @note Type has to be same as functor specialization type
     * @note Return Functor applies QVariant as both arguments
     *
     * @return Functor with binded function
     */
    template<class Type, class Func>
    Functor::PF stdFunction();
};

} //namespace Shared
} //namesoace UXP1A_project

#endif // !defined(EA_51FBBCB3_DBC3_4122_A5C4_FE817CB86CAC__INCLUDED_)
