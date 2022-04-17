#include "Tests.h"
#include "gtest-all.cc"
#include "gtest_main.cc"

class DemoTestSuite : public ::testing::Test {};

TEST_F(DemoTestSuite, WillPass)
{
	ASSERT_TRUE(true);
}

TEST_F(DemoTestSuite, WillFail)
{
	ASSERT_FALSE(true);
}