#ifdef UNITTEST
#include "gtest.h"
#include "../CoutLogger.h"
#include "../NullLogger.h"

namespace CoutLoggerTestNS {

void testAndCheckLog(string logString) {
	Logger* logger = new CoutLogger();
	testing::internal::CaptureStdout();
	logger->log(logString);
	std::string output = testing::internal::GetCapturedStdout();

	// append \n as we add newline to logged string
	EXPECT_EQ(logString.append("\n"), output);
	delete logger;
}

TEST(CoutLoggerTest, logString)
{
	string logString = "my test string";
	testAndCheckLog( logString);
}

TEST(CoutLoggerTest, logEmptyString)
{
	string logString = "";
	testAndCheckLog(logString);
}

// NULL throws a fault which we can't trap (no threads!!)
//TEST(CoutLoggerTest, logNullString)
//{
//	string logString = NULL;
//	testAndCheckLog(logString);
//}

void testAndCheckNullLoggerLog(string logString, string expected) {
	Logger* logger = new NullLogger();
	testing::internal::CaptureStdout();
	logger->log(logString);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(expected, output);
	delete logger;
}

TEST(NullLoggerTest, logString)
{
	Logger* logger = new CoutLogger();
	string logString = "my test string";
	testAndCheckNullLoggerLog( logString, "");
}

TEST(NullLoggerTest, logEmptyString)
{
	Logger* logger = new CoutLogger();
	string logString = "";
	testAndCheckNullLoggerLog( logString, "");
}


} // end namespace

#endif
