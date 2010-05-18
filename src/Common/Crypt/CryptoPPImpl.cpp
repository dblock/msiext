#include "StdAfx.h"

using namespace AppSecInc::Crypt;

std::string CryptoPPImpl::Base64Encode(const std::vector<byte>& input)
{
    std::string output;
    if (input.size() > 0)
    {
        Base64Encoder encoder;
        encoder.PutMessageEnd(& * input.begin(), input.size()); 
		output.resize(static_cast<size_t>(encoder.MaxRetrievable() - 1)); // seems to include the null terminator
		encoder.Get(reinterpret_cast<byte *>(& * output.begin()), output.size());
    }
    return output;
}

std::vector<byte> CryptoPPImpl::Base64Decode(const std::string& input)
{
    std::vector<byte> output;
    if (input.length() > 0)
    {
        Base64Decoder decoder;
        decoder.PutMessageEnd(reinterpret_cast<const byte *>(input.c_str()), input.length()); 
		output.resize(static_cast<size_t>(decoder.MaxRetrievable()));
        decoder.Get(& * output.begin(), output.size()); 
    }

    return output;
}

std::vector<byte> CryptoPPImpl::DESEDE3Encrypt(const std::vector<byte>& input, const std::vector<byte>& key )
{
	CHECK_BOOL(key.size() <= DES_EDE3::DEFAULT_KEYLENGTH,
		L"DESEDE3 key cannot exceed " << DES_EDE3::DEFAULT_KEYLENGTH << L" bytes");

	std::vector<byte> output;
	if (input.size() > 0)
	{
		std::vector<byte> iv;
		iv = Pad(iv, DES_EDE3::BLOCKSIZE);

		// keys are 24 bytes
		std::vector<byte> key_pad = (key.size() < DES_EDE3::DEFAULT_KEYLENGTH) 
			? Pad(key, DES_EDE3::DEFAULT_KEYLENGTH) : key;

		CBC_Mode<DES_EDE3>::Encryption ecbEncryption(& * key_pad.begin(), DES_EDE3::DEFAULT_KEYLENGTH, & * iv.begin());
		StreamTransformationFilter encryptor(ecbEncryption, NULL, StreamTransformationFilter::DEFAULT_PADDING);
		encryptor.Put(& * input.begin(), input.size());
		encryptor.MessageEnd();

		output.resize(static_cast<size_t>(encryptor.MaxRetrievable()));
		encryptor.Get(& * output.begin(), output.size());
	}
	return output;
}

std::vector<byte> CryptoPPImpl::DESEDE3Decrypt(const std::vector<byte>& input, const std::vector<byte>& key )
{
	CHECK_BOOL(key.size() <= DES_EDE3::DEFAULT_KEYLENGTH,
		L"DESEDE3 key cannot exceed " << DES_EDE3::DEFAULT_KEYLENGTH << L" bytes");

	std::vector<byte> output;
	if (input.size() > 0)
	{
		std::vector<byte> iv;
		iv = Pad(iv, DES_EDE3::BLOCKSIZE);

		// keys are 24 bytes
		std::vector<byte> key_pad = (key.size() < DES_EDE3::DEFAULT_KEYLENGTH) 
			? Pad(key, DES_EDE3::DEFAULT_KEYLENGTH) : key;

		CBC_Mode<DES_EDE3>::Decryption ecbDecryption(& * key_pad.begin(), DES_EDE3::DEFAULT_KEYLENGTH, & * iv.begin());
		StreamTransformationFilter decryptor(ecbDecryption, NULL, StreamTransformationFilter::DEFAULT_PADDING);
		decryptor.Put(& * input.begin(), input.size());
		decryptor.MessageEnd();

		output.resize(static_cast<size_t>(decryptor.MaxRetrievable()));
		decryptor.Get(& * output.begin(), output.size());
	}
	return output;
}

std::vector<byte> CryptoPPImpl::HexDecode(const std::string& data)
{
    std::vector<byte> output;
    if (data.length() > 0)
    {
	    HexDecoder decoder;
        decoder.Put(reinterpret_cast<const byte *>(data.c_str()), data.length());
        decoder.MessageEnd();
	    output.resize(static_cast<size_t>(decoder.MaxRetrievable()));
        decoder.Get(& * output.begin(), output.size());
    }
    return output;
}

std::string CryptoPPImpl::HexEncode(const std::vector<byte>& data)
{
    std::string output;
    if (data.size() > 0)
    {
        HexEncoder encoder;
	    encoder.Put(& * data.begin(), data.size());
	    encoder.MessageEnd();
	    output.resize(static_cast<size_t>(encoder.MaxRetrievable()));
	    encoder.Get(reinterpret_cast<byte *>(& * output.begin()), output.size());
    }
    return output;
}

std::vector<byte> CryptoPPImpl::DESEDE3GenerateKey()
{
	RandomPool pool;
    std::vector<byte> key;
    key.resize(24);
	pool.GenerateBlock(& * key.begin(), key.size());
    return key;
}

std::vector<byte> CryptoPPImpl::Pad(const std::vector<byte>& input, int size)
{
    int nBlocks = 0;
    std::vector<byte> output;
    Pad(input, size, output, nBlocks);
    return output;
}

void CryptoPPImpl::Pad(const std::vector<byte>& input, int size, std::vector<byte>& output, int& nBlocks)
{
	int nSize = input.size() + 1;
	nBlocks = nSize / size;
	
	if (nSize % size != 0)
		nBlocks ++;

	output.resize(nBlocks * size, 0);
	if (input.size() > 0)
	{
		memcpy_s(& * output.begin(), output.size(), & * input.begin(), input.size());
	}
}

std::vector<byte> CryptoPPImpl::GenerateRandom(long size)
{
	RandomPool pool;
	std::vector<byte> data;
	data.resize(size);
	pool.GenerateBlock(& * data.begin(), data.size());
    return data;
}
