#include <gtest/gtest.h>
#include <limits>
#include <QString>
#include "ParserTest.h"
#include "ParserException.h"
#include "NumericLimitException.h"
#include "Configuration.h"
#include "ConfigurationTest.h"
#include "ComparisonFactory.h"
#include "ComparisonFactoryTest.h"
#include "SearchPattern.h"
#include "SearchPatternTest.h"

using namespace UXP1A_project::Shared;
using namespace UXP1A_project::Shared::GTest;

TEST_F(ParserTest, CheckConditionSingleInt)
{
    for (int i = 0; i < 100; ++i) {
        QString str;

        foreach (QString op, Parser::INT_OPERATORS){
        str = generateInt(op.toStdString().c_str());

        EXPECT_TRUE(Parser::checkCondition(str))<<str.toStdString();
    }
}
}

TEST_F(ParserTest, CheckConditionSingleFloat)
{
    for (int i = 0; i < 100; ++i) {
        QString str;

        foreach (QString op, Parser::FLOAT_OPERATORS){
        str = generateFloat(op.toStdString().c_str());

        EXPECT_TRUE(Parser::checkCondition(str))<<str.toStdString();
    }
}
}

TEST_F(ParserTest, CheckConditionSingleString)
{
    for (int i = 0; i < 100; ++i) {
        QString str;

        foreach (QString op, Parser::STRING_OPERATORS){
        str = generateString(op.toStdString().c_str());

        EXPECT_TRUE(Parser::checkCondition(str))<<str.toStdString();
    }
}
}

TEST_F(ParserTest, CheckConditionMultipleMixed)
{
    int op;

    for (int i = 0; i < 100; ++i) {
        QString str;

        for (int j = randInt(1, 10); j > 0; --j) {
            switch (randInt(0, 2)) {
                case 0:
                    op = randInt(0, Parser::INT_OPERATORS.size() - 1);
                    str.append(
                            generateInt(
                                    Parser::INT_OPERATORS.at(op).toStdString()
                                            .c_str()));
                    break;
                case 1:
                    op = randInt(0, Parser::FLOAT_OPERATORS.size() - 1);
                    str.append(
                            generateFloat(
                                    Parser::FLOAT_OPERATORS.at(op).toStdString()
                                            .c_str()));
                    break;
                case 2:
                    op = randInt(0, Parser::STRING_OPERATORS.size() - 1);
                    str.append(
                            generateString(
                                    Parser::STRING_OPERATORS.at(op).toStdString()
                                            .c_str()));
                    break;
            }

            if (j > 1)
                str.append(", ");
        }

        EXPECT_TRUE(Parser::checkCondition(str)) << str.toStdString();
    }

}

TEST_F(ParserTest, CheckConditionSampleBadInputs)
{
    EXPECT_FALSE(Parser::checkCondition("float:2"));
    EXPECT_FALSE(Parser::checkCondition("float:-4"));
    EXPECT_FALSE(Parser::checkCondition("float:0"));
    EXPECT_FALSE(Parser::checkCondition("string:\"\"\""));
    EXPECT_FALSE(Parser::checkCondition("ints:*"));
    EXPECT_FALSE(Parser::checkCondition("Int:*"));
    EXPECT_FALSE(Parser::checkCondition("flaot:*"));
    EXPECT_FALSE(Parser::checkCondition("floaT:*"));
    EXPECT_FALSE(Parser::checkCondition("strong:*"));
    EXPECT_FALSE(Parser::checkCondition("String:*"));
    EXPECT_FALSE(Parser::checkCondition("int:*,"));
    EXPECT_FALSE(Parser::checkCondition("int:* "));
    EXPECT_FALSE(Parser::checkCondition("int:*, "));

    for (int i = 0; i < 100; ++i) {
        EXPECT_FALSE(Parser::checkCondition(randString(randInt(0, 255))));
    }
}

TEST_F(ParserTest, CheckConditionOutOfLimitExceptions)
{
    long l;
    double d;

    l = std::numeric_limits<int>::max();
    ++l;

    ASSERT_THROW(Parser::checkCondition(QString("int:>") + QString::number(l)),
            NumericLimitException);

    l = std::numeric_limits<int>::min();
    --l;

    ASSERT_THROW(Parser::checkCondition(QString("int:<") + QString::number(l)),
            NumericLimitException);

    d = std::numeric_limits<float>::max();
    d *= 2;

    ASSERT_THROW(
            Parser::checkCondition(QString("float:>") + QString::number(d)),
            NumericLimitException);

    d = std::numeric_limits<float>::max();
    d *= -2;

    ASSERT_THROW(
            Parser::checkCondition(QString("float:<") + QString::number(d)),
            NumericLimitException);
}

TEST_F(ParserTest, ParseStringStructParserException)
{
    ASSERT_THROW(Parser::parseStruct("string:sdfs"), ParserException);
    ASSERT_THROW(Parser::parseStruct("fgsdio"), ParserException);
    ASSERT_THROW(Parser::parseStruct("string:*, float:43"), ParserException);
    ASSERT_THROW(Parser::parseStruct("ints: sdada"), ParserException);
    ASSERT_THROW(Parser::parseStruct("n sdfio nds"), ParserException);
    ASSERT_THROW(Parser::parseStruct("double:>2, int:5"), ParserException);

    for (int i = 0; i < 100; ++i) {
        EXPECT_THROW(Parser::parseStruct(randString(randInt(0, 255))),
                ParserException);
    }
}

/*
 * QString comparison, not const char* due to that -> EQ not STREQ
 */TEST_F(ParserTest, ParseStructStringPosNeg)
{
    int op;

    for (int i = 0; i < 100; ++i) {
        QString str;
        QString shrt;

        for (int j = randInt(1, 10); j > 0; --j) {
            switch (randInt(0, 2)) {
                case 0:
                    op = randInt(0, Parser::INT_OPERATORS.size() - 1);
                    str.append(
                            generateInt(
                                    Parser::INT_OPERATORS.at(op).toStdString()
                                            .c_str()));
                    shrt.append(Parser::SHORT_TYPE_INT);
                    break;
                case 1:
                    op = randInt(0, Parser::FLOAT_OPERATORS.size() - 1);
                    str.append(
                            generateFloat(
                                    Parser::FLOAT_OPERATORS.at(op).toStdString()
                                            .c_str()));
                    shrt.append(Parser::SHORT_TYPE_FLOAT);
                    break;
                case 2:
                    op = randInt(0, Parser::STRING_OPERATORS.size() - 1);
                    str.append(
                            generateString(
                                    Parser::STRING_OPERATORS.at(op).toStdString()
                                            .c_str()));
                    shrt.append(Parser::SHORT_TYPE_STRING);
                    break;
            }

            if (j > 1)
                str.append(", ");
        }

        ASSERT_EQ(shrt, Parser::parseStruct(str))<< (shrt + " != " + str).toStdString();
        ASSERT_NE(shrt + randString(1), Parser::parseStruct(str));
    }
}

TEST_F(ParserTest, ParseStructListPosNeg)
{
    QVariantList list;

    for (int i = 0; i < 100; ++i) {
        QString shrt;

        for (int j = randInt(1, 10); j > 0; --j) {
            switch (randInt(0, 2)) {
                case 0:
                    list << randInt();
                    shrt.append(Parser::SHORT_TYPE_INT);
                    break;
                case 1:
                    list << randFloat();
                    shrt.append(Parser::SHORT_TYPE_FLOAT);
                    break;
                case 2:
                    list << randString(randInt(0, 255));
                    shrt.append(Parser::SHORT_TYPE_STRING);
                    break;
            }
        }

        ASSERT_EQ(shrt, Parser::parseStruct(list))<< shrt.toStdString();
        ASSERT_NE(shrt + randString(1), Parser::parseStruct(list));

        list.clear();
    }
}

TEST_F(ConfigurationTest, StringsEquality)
{
    ASSERT_STREQ(Configuration::CONFIG_FILE_PATH,
            Configuration::getServerFifoDir().c_str());

    ASSERT_STREQ(Configuration::CONFIG_FILE_NAME,
            Configuration::getServerFifoName().c_str());

    ASSERT_EQ(
            QString(Configuration::CONFIG_FILE_PATH) + Configuration::CONFIG_FILE_NAME,
            Configuration::getServerFifoPath());
}

TEST_F(ComparisonFactoryTest, FunctorsFactory)
{
    int i;

    for (i = INT_EQUAL; i <= ANYTHING; ++i) {
        ASSERT_NO_THROW(ComparisonFactory::getCmpFunctor(CompareOperations(i)));
    }

    for (int j = i; j < i + 20; ++j) {
        ASSERT_THROW( ComparisonFactory::getCmpFunctor(CompareOperations(i)),
                const char*);
    }
}

TEST_F(SearchPatternTest, ExampleConstruction)
{
    ASSERT_TRUE(m_sp.check(m_list));

    m_sp.addCondition(Parser::STRING, ANYTHING, QVariant());

    ASSERT_FALSE(m_sp.check(m_list));
    ASSERT_EQ(Parser::SHORT_TYPE_STRING, m_sp.getTypesPattern());

    m_list << "any";

    ASSERT_TRUE(m_sp.check(m_list));

    m_sp.addCondition(Parser::INT, INT_GREATER_EQUAL, 3);

    ASSERT_FALSE(m_sp.check(m_list));

    m_list << 2;

    ASSERT_FALSE(m_sp.check(m_list));

    m_list.pop_front();
    m_list << 4;

    ASSERT_TRUE(m_sp.check(m_list));

    m_list << -24.f;

    ASSERT_FALSE(m_sp.check(m_list));

    m_sp.addCondition(Parser::FLOAT, FLOAT_LESS, -20);

    ASSERT_TRUE(m_sp.check(m_list));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
