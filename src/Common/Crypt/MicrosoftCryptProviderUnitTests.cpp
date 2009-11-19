#include "StdAfxUnitTests.h"
#include "MicrosoftCryptProviderUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Crypt::MicrosoftCryptProviderUnitTests );

using namespace AppSecInc::UnitTests::Crypt;

void MicrosoftCryptProviderUnitTests::testInitialize(void)
{
	AppSecInc::Crypt::MicrosoftCryptProvider prov;
    prov.Initialize();
    try
    {
        prov.Initialize();
        throw "expected std::exception";
    }
    catch(std::exception& )
    {
    }

    prov.UnInitialize();
    try
    {
        prov.UnInitialize();
        throw "expected std::exception";
    }
    catch(std::exception& )
    {
    }
}

