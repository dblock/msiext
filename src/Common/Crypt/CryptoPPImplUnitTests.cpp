#include "StdAfxUnitTests.h"
#include "CryptoPPImplUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Crypt::CryptoPPImplUnitTests);

using namespace AppSecInc::UnitTests::Crypt;
			
void CryptoPPImplUnitTests::testPadEmpty()
{
    std::string input, output;
    int nBlocks = 0;
	AppSecInc::Crypt::CryptoPPImpl::Pad(input, 8, output, nBlocks);
	CPPUNIT_ASSERT(output.length() == 8);
}

void CryptoPPImplUnitTests::testPad()
{	
	int block = 8;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < block; j++)
		{
            std::string input;
			input.resize(i * block + j, 'x');
            std::string output = AppSecInc::Crypt::CryptoPPImpl::Pad(input, block);
			CPPUNIT_ASSERT(output.size() % block == 0);
		}
	}
}

void CryptoPPImplUnitTests::testDESEDE3GenerateKey()
{
    std::string key = AppSecInc::Crypt::CryptoPPImpl::DESEDE3GenerateKey();
	CPPUNIT_ASSERT(key.size() == 24);
    std::string key_hex = AppSecInc::Crypt::CryptoPPImpl::HexEncode(key);
	CPPUNIT_ASSERT(key_hex.size() == 48);
}

void CryptoPPImplUnitTests::testBase64EncodeDecode()
{
	char * testdata[] = 
	{
		"",
		"foo",
		"barbar",
	    "xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz",
	};

	for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
	{
        std::string encoded = AppSecInc::Crypt::CryptoPPImpl::Base64Encode(testdata[i]);
        std::string decoded = AppSecInc::Crypt::CryptoPPImpl::Base64Decode(encoded);
		CPPUNIT_ASSERT(strcmp(testdata[i], decoded.c_str()) == 0);
	}
}

void CryptoPPImplUnitTests::testHexEncodeDecode()
{
	char * testdata[] = 
	{
		"",
		"foo",
		"barbar",
	    "xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz",
	};

	for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
	{
        std::string encoded = AppSecInc::Crypt::CryptoPPImpl::HexEncode(testdata[i]);
        std::string decoded = AppSecInc::Crypt::CryptoPPImpl::HexDecode(encoded);
		// cout << endl << testdata[i] << "->" << encoded << "->" << decoded;
		CPPUNIT_ASSERT(strcmp(testdata[i], decoded.c_str()) == 0);
	}
}

void CryptoPPImplUnitTests::testDESEDE3EncryptDecrypt()
{
	char * testdata[] = 
	{
		"",
		"foo",
		"barbar",
		"88888888",
	    "xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz",
	};

	for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
	{
        std::string encrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Encrypt(testdata[i], "password");
        std::string decrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Decrypt(encrypted, "password");
		CPPUNIT_ASSERT(strlen(testdata[i]) == strlen(decrypted.c_str()));
		CPPUNIT_ASSERT(strcmp(testdata[i], decrypted.c_str()) == 0);
	}
}

void CryptoPPImplUnitTests::testDESEDE3EncryptDecryptWithBase64()
{
	char * testdata[] = 
	{
		"",
		"foo",
		"barbar",
		"88888888",
	    "xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz",
	};

	for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
	{
		//cout << endl << "testing: " << testdata[i] << endl;
        std::string encrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Encrypt(testdata[i], "password");
		//cout << "[encrypted:" << encrypted.size() << "]" << endl;
		std::string encoded = AppSecInc::Crypt::CryptoPPImpl::Base64Encode(encrypted);
		//cout << "[encoded:" << encoded << "][" << encoded.size() << "]" << endl;
		std::string decoded = AppSecInc::Crypt::CryptoPPImpl::Base64Decode(encoded);
		//cout << "[decoded:" << decoded.size() << "]" << endl;
		std::string decrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Decrypt(decoded, "password");
		//cout << "[decrypted:" << decrypted << "][" << decrypted.size() << "]" << endl;
		// CPPUNIT_ASSERT(strlen(testdata[i]) == decrypted.length());
		CPPUNIT_ASSERT(strcmp(testdata[i], decrypted.c_str()) == 0);
	}
}

void CryptoPPImplUnitTests::testDESEDE3EncryptDecryptWithHex()
{
	char * testdata[] = 
	{
		"",
		"foo",
		"barbar",
		"88888888",
	    "xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz",
	};

	for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
	{
		//cout << endl << "testing: " << testdata[i] << endl;
		std::string encrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Encrypt(testdata[i], "password");
		//cout << "[encrypted:" << encrypted.size() << "]" << endl;
		std::string encoded = AppSecInc::Crypt::CryptoPPImpl::HexEncode(encrypted);
		//cout << "[encoded:" << encoded << "][" << encoded.size() << "]" << endl;
		std::string decoded = AppSecInc::Crypt::CryptoPPImpl::HexDecode(encoded);
		//cout << "[decoded:" << decoded.size() << "]" << endl;
		std::string decrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Decrypt(decoded, "password");
		//cout << "[decrypted:" << decrypted << "][" << decrypted.size() << "]" << endl;
		// CPPUNIT_ASSERT(strlen(testdata[i]) == decrypted.length());
		CPPUNIT_ASSERT(strcmp(testdata[i], decrypted.c_str()) == 0);
	}
}

void CryptoPPImplUnitTests::testGenerateRandom()
{
	int size = 10;
	std::vector<BYTE> data = AppSecInc::Crypt::CryptoPPImpl::GenerateRandom(size);
	CPPUNIT_ASSERT(size == data.size());
	long total = 0;
	for(int i = 0; i < size - 1; i++) total += data[i];
	std::cout << std::endl << AppSecInc::Crypt::CryptoPPImpl::HexEncode(
		std::string(data.begin(), data.end()));
	CPPUNIT_ASSERT(total != 0);
}
