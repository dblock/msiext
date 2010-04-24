#include "StdAfx.h"

using namespace AppSecInc::Crypt;

std::string CryptoPPImpl::Base64Encode(const std::string& input)
{
    std::string output;
    if (input.size() > 0)
    {
	    output.resize(input.size() * 2);
        Base64Encoder encoder;
        encoder.PutMessageEnd(reinterpret_cast<const byte *>(input.c_str()), input.size()); 
        encoder.Get(reinterpret_cast<LPBYTE>(& * output.begin()), output.size()); 
    }
    return output;
}

std::string CryptoPPImpl::Base64Decode(const std::string& input)
{
    std::string output;
    if (input.length() > 0)
    {
	    // input is a string and the output is bytes
	    output.resize(input.length() * 3 / 2);
        Base64Decoder decoder;
        decoder.PutMessageEnd(reinterpret_cast<const byte *>(input.c_str()), input.length()); 
        decoder.Get(reinterpret_cast<LPBYTE>(& * output.begin()), output.size()); 
    }
    return output;
}

std::string CryptoPPImpl::DESEDE3Encrypt(const std::string& input, const std::string& key )
{
	// only 24 bytes of the key are used, otherwise it's padded
    std::string key_pad = key;
	if (key_pad.length() < 24) key_pad.resize(24);

    std::string input_pad;
    int nBlocks = 0;
	Pad(input, 8, input_pad, nBlocks);
    std::string output;
	output.resize(input_pad.size());

	DES_EDE3_Encryption des_encryptor(reinterpret_cast<const byte *>(& * key_pad.begin()), key_pad.size());

	for (int block_num = 0; block_num < nBlocks; block_num ++)
	{
		des_encryptor.ProcessBlock(reinterpret_cast<const byte *>(input.c_str()) + block_num * 8, 
			reinterpret_cast<LPBYTE>(& * output.begin()) + block_num * 8);
	}

    return output;
}

std::string CryptoPPImpl::DESEDE3Decrypt(const std::string& input, const std::string& key )
{	
	// only 24 bytes of the key are used, otherwise it's padded
    std::string key_pad = key;
	if (key_pad.length() < 24) key_pad.resize(24);
	
    std::string input_pad;
	int nBlocks;
    Pad(input, 8, input_pad, nBlocks);
    std::string output;
	output.resize(input.size());

	DES_EDE3_Decryption des_decryptor(
		reinterpret_cast<const byte *>(& * key_pad.begin()), 
		key_pad.size());

	for (int block_num = 0; block_num < nBlocks; block_num ++)
	{
		des_decryptor.ProcessBlock(
			reinterpret_cast<const byte *>(input.c_str()) + block_num * 8, 
			reinterpret_cast<LPBYTE>(& * output.begin()) + block_num * 8);
	}

	// TODO: this only works for strings, need a way to pad with a sequence which will always 
	//       clearly identify where the string ends
	output.resize(strlen(output.c_str()));
    return output;
}

std::string CryptoPPImpl::HexDecode(const std::string& data)
{
    std::string output;
    if (data.length() > 0)
    {
	    ULONG len = data.length() / 2;

	    HexDecoder hexDecoder;
        hexDecoder.Put(reinterpret_cast<const byte *>(data.c_str()), data.length());
        hexDecoder.MessageEnd();
        
	    output.resize(len);    
        hexDecoder.Get(reinterpret_cast<LPBYTE>(& * output.begin()), len);
    }
    return output;
}

std::string CryptoPPImpl::HexEncode(const std::string& data)
{
    std::string output;
    if (data.length() > 0)
    {
        HexEncoder hexEncoder;
	    hexEncoder.Put(reinterpret_cast<const byte *>(data.c_str()), data.length());
	    hexEncoder.MessageEnd();

	    output.resize(data.length() * 2);
	    hexEncoder.Get(reinterpret_cast<LPBYTE>(& * output.begin()), output.size());
    }
    return output;
}

std::wstring CryptoPPImpl::HexDecode(const std::wstring& data)
{
    std::wstring output;
    if (data.length() > 0)
    {
        std::string data_a = AppSecInc::StringUtils::wc2mb(data);

        HexDecoder hexDecoder;
        hexDecoder.Put(reinterpret_cast<const byte *>(data_a.c_str()), data_a.length());
        hexDecoder.MessageEnd();
        
        ULONG len = data_a.length() / 4;
	    output.resize(len);
        hexDecoder.Get(reinterpret_cast<LPBYTE>(& * output.begin()), len * sizeof(wchar_t));
    }
    return output;
}

std::wstring CryptoPPImpl::HexEncode(const std::wstring& data)
{
    std::string output;
    if (data.length() > 0)
    {
        HexEncoder hexEncoder;
	    hexEncoder.Put(reinterpret_cast<const byte *>(data.c_str()), data.length() * sizeof(wchar_t));
	    hexEncoder.MessageEnd();

	    output.resize(data.length() * 4);
	    hexEncoder.Get(reinterpret_cast<LPBYTE>(& * output.begin()), output.size());
    }
    return AppSecInc::StringUtils::mb2wc(output);
}

std::string CryptoPPImpl::DESEDE3GenerateKey()
{
	RandomPool pool;
    std::string key;
    key.resize(24);
	pool.GenerateBlock(reinterpret_cast<LPBYTE>(& * key.begin()), key.size());
    return key;
}

std::string CryptoPPImpl::Pad(const std::string& input, int size)
{
    int nBlocks = 0;
    std::string output;
    Pad(input, size, output, nBlocks);
    return output;
}

void CryptoPPImpl::Pad(const std::string& input, int size, std::string& output, int& nBlocks)
{
	int nSize = input.size() + 1;
	nBlocks = nSize / size;
	
	if (nSize % size != 0)
		nBlocks ++;

	output.resize(nBlocks * size, 0);
	memcpy(reinterpret_cast<LPBYTE>(& * output.begin()), 
		reinterpret_cast<const byte *>(input.c_str()), input.size());	
}

std::vector<BYTE> CryptoPPImpl::GenerateRandom(long size)
{
	RandomPool pool;
	std::vector<BYTE> data;
	data.resize(size);
	pool.GenerateBlock(reinterpret_cast<LPBYTE>(& * data.begin()), data.size());
    return data;
}
