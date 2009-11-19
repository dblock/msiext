#include "StdAfx.h"

using namespace AppSecInc::Crypt;

CryptoPPCryptProvider::CryptoPPCryptProvider()
{
}

CryptoPPCryptProvider::~CryptoPPCryptProvider()
{
}

std::string CryptoPPCryptProvider::Protect(const std::string& input)
{ 
	return Encrypt(input, "magic");
} 

std::string CryptoPPCryptProvider::Unprotect(const std::string& input)
{ 
	return Decrypt(input, "magic");
}

std::string CryptoPPCryptProvider::GenerateKey()
{ 	
	return CryptoPPImpl::DESEDE3GenerateKey();
}

std::string CryptoPPCryptProvider::Encrypt(const std::string& input, const std::string& key)
{ 
	return CryptoPPImpl::DESEDE3Encrypt(input, key);
}

std::string CryptoPPCryptProvider::Decrypt(const std::string& input, const std::string& key)
{
	return CryptoPPImpl::DESEDE3Decrypt(input, key);
}

std::string CryptoPPCryptProvider::Encode(const std::string& input)
{ 
	return CryptoPPImpl::HexEncode(input);
}

std::string CryptoPPCryptProvider::Decode(const std::string& input)
{ 
	return CryptoPPImpl::HexDecode(input);
}

