#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Cryptography
		{
			class Base64EncodeDecodeUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( Base64EncodeDecodeUnitTests );
				CPPUNIT_TEST( Test_Base64EncodeDecodeA );
                CPPUNIT_TEST( Test_Base64EncodeDecodeW );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_Base64EncodeDecodeW();
				void Test_Base64EncodeDecodeA();
				void Test_EntryPoints();
			};
        }
	}
}
