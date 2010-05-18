#include "StdAfxUnitTests.h"
#include "CryptoPPImplUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Crypt::CryptoPPImplUnitTests);

using namespace AppSecInc::UnitTests::Crypt;
			
void CryptoPPImplUnitTests::testPadEmpty()
{
    std::vector<byte> input, output;
    int nBlocks = 0;
	AppSecInc::Crypt::CryptoPPImpl::Pad(input, 8, output, nBlocks);
	CPPUNIT_ASSERT(output.size() == 8);
}

void CryptoPPImplUnitTests::testPad()
{	
	int block = 8;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < block; j++)
		{
            std::vector<byte> input;
			input.resize(i * block + j, 'x');
            std::vector<byte> output = AppSecInc::Crypt::CryptoPPImpl::Pad(input, block);
			CPPUNIT_ASSERT(output.size() % block == 0);
		}
	}
}

void CryptoPPImplUnitTests::testDESEDE3GenerateKey()
{
    std::vector<byte> key = AppSecInc::Crypt::CryptoPPImpl::DESEDE3GenerateKey();
	CPPUNIT_ASSERT(key.size() == 24);
    std::string key_hex = AppSecInc::Crypt::CryptoPPImpl::HexEncode(key);
	CPPUNIT_ASSERT(key_hex.length() == 48);
}

void CryptoPPImplUnitTests::testBase64EncodeDecode()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::vector<byte> data;
		for (size_t j = 0; j < i; j++)
		{
			data.push_back(j);
		}

		std::string data_encoded = AppSecInc::Crypt::CryptoPPImpl::Base64Encode(data);
		CPPUNIT_ASSERT(data_encoded.length() >= i);
		CPPUNIT_ASSERT(strlen(data_encoded.c_str()) == data_encoded.length());
		std::vector<byte> data_decoded = AppSecInc::Crypt::CryptoPPImpl::Base64Decode(data_encoded);
		CPPUNIT_ASSERT(data_decoded.size() == i);
		CPPUNIT_ASSERT(data_decoded == data);
	}
}

void CryptoPPImplUnitTests::testHexEncodeDecode()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::vector<byte> data;
		for (size_t j = 0; j < i; j++)
		{
			data.push_back(j);
		}

		std::string data_encoded = AppSecInc::Crypt::CryptoPPImpl::HexEncode(data);
		CPPUNIT_ASSERT(data_encoded.length() == 2 * i);
		CPPUNIT_ASSERT(strlen(data_encoded.c_str()) == data_encoded.length());
		std::vector<byte> data_decoded = AppSecInc::Crypt::CryptoPPImpl::HexDecode(data_encoded);
		CPPUNIT_ASSERT(data_decoded.size() == i);
		CPPUNIT_ASSERT(data_decoded == data);
	}
}

void CryptoPPImplUnitTests::testDESEDE3EncryptDecrypt()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::vector<byte> data;
		for (size_t j = 0; j < i; j++)
		{
			data.push_back(j);
		}

		std::vector<byte> key = AppSecInc::Crypt::CryptoPPImpl::DESEDE3GenerateKey();
		std::vector<byte> encrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Encrypt(data, key);
		std::vector<byte> decrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Decrypt(encrypted, key);
		CPPUNIT_ASSERT(decrypted.size() == i);
		CPPUNIT_ASSERT(decrypted == data);
	}
}

void CryptoPPImplUnitTests::testDESEDE3EncryptDecryptWithBase64()
{
	std::string key = "password";
	std::vector<byte> key_bytes;
	key_bytes.insert(key_bytes.begin(), key.begin(), key.end());

	for (size_t i = 0; i < 10; i++)
	{
		std::vector<byte> data;
		for (size_t j = 0; j < i; j++)
		{
			data.push_back(j);
		}

		std::vector<byte> encrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Encrypt(data, key_bytes);
		std::string encoded = AppSecInc::Crypt::CryptoPPImpl::Base64Encode(encrypted);
		std::vector<byte> decoded = AppSecInc::Crypt::CryptoPPImpl::Base64Decode(encoded);
		CPPUNIT_ASSERT(decoded == encrypted);
		std::vector<byte> decrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Decrypt(decoded, key_bytes);
		CPPUNIT_ASSERT(decrypted.size() == i);
		CPPUNIT_ASSERT(decrypted == data);
	}
}

void CryptoPPImplUnitTests::testDESEDE3EncryptDecryptWithHex()
{
	std::string key = "password";
	std::vector<byte> key_bytes;
	key_bytes.insert(key_bytes.begin(), key.begin(), key.end());

	for (size_t i = 0; i < 10; i++)
	{
		std::vector<byte> data;
		for (size_t j = 0; j < i; j++)
		{
			data.push_back(j);
		}

		std::vector<byte> encrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Encrypt(data, key_bytes);
		std::string encoded = AppSecInc::Crypt::CryptoPPImpl::HexEncode(encrypted);
		std::vector<byte> decoded = AppSecInc::Crypt::CryptoPPImpl::HexDecode(encoded);
		CPPUNIT_ASSERT(decoded == encrypted);
		std::vector<byte> decrypted = AppSecInc::Crypt::CryptoPPImpl::DESEDE3Decrypt(decoded, key_bytes);
		CPPUNIT_ASSERT(decrypted.size() == i);
		CPPUNIT_ASSERT(decrypted == data);
	}
}

void CryptoPPImplUnitTests::testGenerateRandom()
{
	int size = 10;
	std::vector<BYTE> data = AppSecInc::Crypt::CryptoPPImpl::GenerateRandom(size);
	CPPUNIT_ASSERT(size == data.size());
	long total = 0;
	for(int i = 0; i < size - 1; i++) total += data[i];
	CPPUNIT_ASSERT(total != 0);
}
