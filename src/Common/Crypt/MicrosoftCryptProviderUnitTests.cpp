#include "StdAfxUnitTests.h"
#include "MicrosoftCryptProviderUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Crypt::MicrosoftCryptProviderUnitTests );

using namespace AppSecInc::UnitTests::Crypt;

void MicrosoftCryptProviderUnitTests::testInitialize()
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

void MicrosoftCryptProviderUnitTests::testGenerateRandom()
{
	AppSecInc::Crypt::MicrosoftCryptProvider prov;
    prov.Initialize();
	int size = 10;
	std::vector<BYTE> data = prov.GenerateRandom(size);
	CPPUNIT_ASSERT(size == data.size());
	long total = 0;
	for(int i = 0; i < size - 1; i++) total += data[i];
	std::cout << std::endl << AppSecInc::Crypt::CryptoPPImpl::HexEncode(
		std::string(data.begin(), data.end()));
	CPPUNIT_ASSERT(total != 0);
	prov.UnInitialize();
}
