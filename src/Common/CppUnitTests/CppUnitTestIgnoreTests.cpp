#include "StdAfxUnitTests.h"
#include "CppUnitTestIgnoreTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION( 
	AppSecInc::UnitTests::CppUnitTests::CppUnitTestIgnoreUnitTest);

using namespace AppSecInc::UnitTests::CppUnitTests;

void CppUnitTestIgnoreUnitTest::testIgnore()
{
	CPPUNIT_IGNORE(true);
	throw "this code cannot be reached";
}