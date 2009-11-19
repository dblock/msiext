#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Crypt
		{
			class CryptoPPImplUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CryptoPPImplUnitTests );
				CPPUNIT_TEST( testPad );
				CPPUNIT_TEST( testPadEmpty );
				CPPUNIT_TEST( testBase64EncodeDecode );
				CPPUNIT_TEST( testHexEncodeDecode );
				CPPUNIT_TEST( testDESEDE3EncryptDecrypt );
				CPPUNIT_TEST( testDESEDE3EncryptDecryptWithBase64 );
				CPPUNIT_TEST( testDESEDE3EncryptDecryptWithHex );
				CPPUNIT_TEST( testDESEDE3GenerateKey );
				CPPUNIT_TEST_SUITE_END();

			public:
				void testPad(void);
				void testPadEmpty(void);
				void testBase64EncodeDecode(void);
				void testHexEncodeDecode(void);
				void testDESEDE3GenerateKey(void);
				void testDESEDE3EncryptDecrypt(void);
				void testDESEDE3EncryptDecryptWithBase64(void);
				void testDESEDE3EncryptDecryptWithHex(void);
			};
		}
	}
}