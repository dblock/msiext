#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Crypt
		{
			class CryptoPPCryptProviderUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CryptoPPCryptProviderUnitTests );
				CPPUNIT_TEST( testGenerateKey );
				CPPUNIT_TEST( testEncryptDecrypt );
				CPPUNIT_TEST( testProtectUnprotect );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testGenerateKey (void);
				void testEncryptDecrypt (void);
				void testProtectUnprotect (void);
			};
		}
	}
}