#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Cryptography
		{
			class EncodeDecodeUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( EncodeDecodeUnitTests );
				CPPUNIT_TEST( Test_HexEncodeDecodeA );
                CPPUNIT_TEST( Test_HexEncodeDecodeW );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_HexEncodeDecodeW();
				void Test_HexEncodeDecodeA();
				void Test_EntryPoints();
			};
        }
	}
}
