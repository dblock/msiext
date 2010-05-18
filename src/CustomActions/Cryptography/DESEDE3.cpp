#include "StdAfx.h"
#include "DESEDE3.h"
#include "FlagMaps.h"

using namespace AppSecInc::Crypt;

CA_API UINT __stdcall DESEDE3_GenerateKey(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::vector<byte> key = CryptoPPImpl::DESEDE3GenerateKey();
    std::string encoded_key = CryptoPPImpl::HexEncode(key);

    msiInstall.SetProperty("DESEDE3_KEY", encoded_key);

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;           
}

CA_API UINT __stdcall DESEDE3_Encrypt(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    // get the key
    std::string encoded_key = msiInstall.GetProperty("DESEDE3_KEY");
    if (! encoded_key.length()) return ERROR_INVALID_PARAMETER;
    std::vector<byte> key = CryptoPPImpl::HexDecode(encoded_key);

    std::wstring cleartext_data = msiInstall.GetProperty(L"DESEDE3_CLEARTEXT_DATA");

	std::vector<byte> cleartext_data_bytes;
	if (cleartext_data.size() > 0)
	{
		cleartext_data_bytes.resize(cleartext_data.length() * sizeof(wchar_t));
		memcpy_s(& * cleartext_data_bytes.begin(), cleartext_data_bytes.size(), & * cleartext_data.begin(), cleartext_data.length() * sizeof(wchar_t));
	}

    std::vector<byte> encrypted_data = CryptoPPImpl::DESEDE3Encrypt(cleartext_data_bytes, key);
    std::string encrypted_data_encoded = CryptoPPImpl::HexEncode(encrypted_data);

    msiInstall.SetProperty("DESEDE3_ENCRYPTED_DATA", encrypted_data_encoded);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall DESEDE3_Decrypt(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    // get the key
    std::string encoded_key = msiInstall.GetProperty("DESEDE3_KEY");
    if (encoded_key.length() == 0) return ERROR_INVALID_PARAMETER;
    std::vector<byte> key = CryptoPPImpl::HexDecode(encoded_key);

    // get and hex-decode data
    std::string encrypted_data_encoded = msiInstall.GetProperty("DESEDE3_ENCRYPTED_DATA");
    if (encrypted_data_encoded.length() == 0) 
	{
		msiInstall.SetProperty(L"DESEDE3_CLEARTEXT_DATA", L"");
		return ERROR_SUCCESS;
	}

    std::vector<byte> decoded_data = CryptoPPImpl::HexDecode(encrypted_data_encoded);
    std::vector<byte> decrypted_data = CryptoPPImpl::DESEDE3Decrypt(decoded_data, key);

	std::wstring cleartext_data;
	cleartext_data.resize(decrypted_data.size() / sizeof(wchar_t));
	memcpy_s(& * cleartext_data.begin(), cleartext_data.size() * sizeof(wchar_t), & * decrypted_data.begin(), decrypted_data.size());

    msiInstall.SetProperty(L"DESEDE3_CLEARTEXT_DATA", cleartext_data);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
