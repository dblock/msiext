#include <StdAfxUnitTests.h>
#include <CppUnitTests\CppUnitTests.h>

int main( int argc, char* argv[] )
{
	AppSecInc::Com::CCoInitialize coinit;
	CppUnitTestRunner runner;
	return runner.Run(argc, argv);
}
