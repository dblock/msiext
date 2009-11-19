#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Cryptography
		{
			class CryptProtectDataHexUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CryptProtectDataHexUnitTests );
				CPPUNIT_TEST( Test_HexCryptProtectDataHex );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_HexCryptProtectDataHex();
				void Test_EntryPoints();
			};
        }
	}
}
