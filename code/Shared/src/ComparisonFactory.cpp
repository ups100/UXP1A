///////////////////////////////////////////////////////////
//  ComparisonFactory.cpp
//  Implementation of the Class ComparisonFactory
//  Created on:      24-kwi-2013 11:08:34
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "ComparisonFactory.h"
#include <functional>
#include <boost/bind.hpp>
#include <boost/lambda/lambda.hpp>

namespace UXP1A_project {
namespace Shared {

int f(int x)
{
    return x * 2;
}

template<class Type, typename Func>
Functor::PF ComparisonFactory::stdFunction()
{
    return Functor(
            boost::bind(Func(), boost::bind(&QVariant::value<Type>, _1),
                    boost::bind(&QVariant::value<Type>, _2)));
}

ComparisonFactory::ComparisonFactory()
{
    m_functors[INT_EQUAL] = stdFunction<int, std::equal_to<int> >();
    m_functors[INT_LESS] = stdFunction<int, std::less<int> >();
    m_functors[INT_LESS_EQUAL] = stdFunction<int, std::less_equal<int> >();
    m_functors[INT_GREATER] = stdFunction<int, std::greater<int> >();
    m_functors[INT_GREATER_EQUAL] =
            stdFunction<int, std::greater_equal<int> >();

    m_functors[FLOAT_LESS] = stdFunction<float, std::less<float> >();
    m_functors[FLOAT_LESS_EQUAL] =
            stdFunction<float, std::less_equal<float> >();
    m_functors[FLOAT_GREATER] = stdFunction<float, std::greater<float> >();
    m_functors[FLOAT_GREATER_EQUAL] = stdFunction<float,
            std::greater_equal<float> >();

    m_functors[STRING_EQUAL] = stdFunction<QString, std::equal_to<QString> >();
    m_functors[STRING_LESS] = stdFunction<QString, std::less<QString> >();
    m_functors[STRING_LESS_EQUAL] = stdFunction<QString,
            std::less_equal<QString> >();
    m_functors[STRING_GREATER] = stdFunction<QString, std::greater<QString> >();
    m_functors[STRING_GREATER_EQUAL] = stdFunction<QString,
            std::greater_equal<QString> >();

    m_functors[ANYTHING] = Functor(boost::lambda::constant(true));
}

ComparisonFactory::ComparisonFactory(const ComparisonFactory&)
{
    throw "Singleton copying C-tor";
}

ComparisonFactory& ComparisonFactory::operator=(const ComparisonFactory&)
{
    throw "Singleton assign operator";
}

ComparisonFactory::~ComparisonFactory()
{

}

Functor ComparisonFactory::getCmpFunctor(CmpSymbol cmpSymbol)
{
    static ComparisonFactory instance;

    if (instance.m_functors.contains(cmpSymbol))
        return instance.m_functors[cmpSymbol];

    // Should not be here
    throw "No function";
}

} //namespace Shared
} //namesoace UXP1A_project
