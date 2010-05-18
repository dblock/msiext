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
				CPPUNIT_TEST( testGenerateRandom );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testPad();
				void testPadEmpty();
				void testBase64EncodeDecode();
				void testHexEncodeDecode();
				void testDESEDE3GenerateKey();
				void testDESEDE3EncryptDecrypt();
				void testDESEDE3EncryptDecryptWithBase64();
				void testDESEDE3EncryptDecryptWithHex();
				void testGenerateRandom();
			};
		}
	}
}