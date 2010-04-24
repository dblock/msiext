#include "StdAfx.h"
#include "MicrosoftCryptProvider.h"

using namespace AppSecInc::Crypt;

MicrosoftCryptProvider::MicrosoftCryptProvider()
	: _hprov(NULL)
{
	
}

MicrosoftCryptProvider::~MicrosoftCryptProvider()
{
	if (_hprov != NULL)
	{
		UnInitialize();
	}
}

void MicrosoftCryptProvider::Initialize()
{
	CHECK_BOOL(_hprov == NULL, "Provider already initialized.");

    // get a handle to the CryptoAPI
    CHECK_WIN32_BOOL(CryptAcquireContextW(& _hprov, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT),
        "Error acquiring the cryptographic provider context.");
}

void MicrosoftCryptProvider::UnInitialize()
{
	CHECK_BOOL(_hprov != NULL, "Provider not initialized.");

    CHECK_WIN32_BOOL(CryptReleaseContext(_hprov, 0),
		"Error releasing crypto provider context.");

	_hprov = NULL;
}

std::vector<BYTE> MicrosoftCryptProvider::GenerateRandom(DWORD dwLen)
{
	CHECK_BOOL(_hprov != NULL, "Provider not initialized.");

	std::vector<BYTE> data;
	data.resize(dwLen);
	
	CHECK_WIN32_BOOL(::CryptGenRandom(_hprov, dwLen, & * data.begin()),
		L"CryptGenRandom");

	return data;
}