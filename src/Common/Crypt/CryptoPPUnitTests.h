#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Crypt
		{
			class CryptoPPUnitTest :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CryptoPPUnitTest );
				CPPUNIT_TEST( testHexEncoder );
                CPPUNIT_TEST( testScramble41 );
                CPPUNIT_TEST( testSHA1 );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testHexEncoder(void);
                void testScramble41(void);
                void testSHA1(void);
			};
		}
	}
}