#include "StdAfx.h"
#include "DESEDE3.h"
#include "FlagMaps.h"

using namespace AppSecInc::Crypt;

CA_API UINT __stdcall DESEDE3_GenerateKey(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::string key = CryptoPPImpl::DESEDE3GenerateKey();
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
    std::string key = CryptoPPImpl::HexDecode(encoded_key);

    std::string cleartext_data = msiInstall.GetProperty("DESEDE3_CLEARTEXT_DATA");
    std::string encrypted_data = CryptoPPImpl::DESEDE3Encrypt(cleartext_data, key);
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
    std::string key = CryptoPPImpl::HexDecode(encoded_key);

    // get and hex-decode data
    std::string encrypted_data_encoded = msiInstall.GetProperty("DESEDE3_ENCRYPTED_DATA");
    if (encrypted_data_encoded.length() == 0) return ERROR_INVALID_PARAMETER;
    std::string decoded_data = CryptoPPImpl::HexDecode(encrypted_data_encoded);
    std::string decrypted_data = CryptoPPImpl::DESEDE3Decrypt(decoded_data, key);

    msiInstall.SetProperty("DESEDE3_CLEARTEXT_DATA", decrypted_data);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
