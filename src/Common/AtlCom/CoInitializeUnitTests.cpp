#include "StdAfxUnitTests.h"
#include "CoInitializeUnitTests.h"
#include <AtlCom/CoInitialize.h>

using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::AtlCom;

CPPUNIT_TEST_SUITE_REGISTRATION( 
	AppSecInc::UnitTests::AtlCom::CoInitializeUnitTest);

void CoInitializeUnitTest::testCCoInitialize()
{
	{
		AppSecInc::Com::CCoInitialize coinit;

		HRESULT hrCoInitEx = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
		std::cout << std::endl << "HR (CoInitializeEx): 0x" << std::hex << hrCoInitEx;
		CPPUNIT_ASSERT(hrCoInitEx == S_FALSE);
		::CoUninitialize();

		HRESULT hrCoInit = ::CoInitialize(NULL);
		std::cout << std::endl << "HR (CoInitialize): 0x" << std::hex << hrCoInit;
		CPPUNIT_ASSERT(hrCoInit == RPC_E_CHANGED_MODE);
	}
}