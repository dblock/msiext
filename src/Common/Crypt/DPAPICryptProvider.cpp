#include "StdAfx.h"

using namespace AppSecInc::Crypt;

const std::string DPAPICryptProvider::DPAPI_ENCRYPTED_PREFIX = "L$AppSecInc!DpapiMachineKey53 ";

DPAPICryptProvider::DPAPICryptProvider()
{
}

DPAPICryptProvider::DPAPICryptProvider(const std::string& entropy)
	: m_Entropy(entropy)
{
}

DPAPICryptProvider::~DPAPICryptProvider()
{
}

void DPAPICryptProvider::SetEntropy(const std::string& entropy)
{
	m_Entropy = entropy;
}

const std::string& DPAPICryptProvider::GetEntropy() const
{
	return m_Entropy;
}

std::string DPAPICryptProvider::GenerateKey()
{
    throw std::exception("Not implemented");
}

std::string DPAPICryptProvider::Encrypt(const std::string& input, const std::string& key)
{
    throw std::exception("Not implemented");
}

std::string DPAPICryptProvider::Decrypt(const std::string& input, const std::string& key)
{
    throw std::exception("Not implemented");
}

std::string DPAPICryptProvider::Encode(const std::string& input)
{ 
	return CryptoPPImpl::HexEncode(input);
}

std::string DPAPICryptProvider::Decode(const std::string& input)
{ 
	return CryptoPPImpl::HexDecode(input);
}

std::string DPAPICryptProvider::Protect(const std::string& input)
{
    std::string output = DPAPIImpl::Protect(input, m_Entropy);
    output.insert(0, DPAPICryptProvider::DPAPI_ENCRYPTED_PREFIX);
    return output;
}

std::string DPAPICryptProvider::Unprotect(const std::string& input)
{
	std::string data;	
	size_t prefix_len = DPAPICryptProvider::DPAPI_ENCRYPTED_PREFIX.length();
	
    if (! AppSecInc::StringUtils::startsWith(input, DPAPICryptProvider::DPAPI_ENCRYPTED_PREFIX))
		return input;
	
	data = input.substr(prefix_len);
	if (data.length() == 0)
        return "";

    return DPAPIImpl::UnProtect(data, m_Entropy);
}

bool DPAPICryptProvider::CanUnprotect(const std::string& input)
{
    return AppSecInc::StringUtils::startsWith(input, DPAPICryptProvider::DPAPI_ENCRYPTED_PREFIX);
}