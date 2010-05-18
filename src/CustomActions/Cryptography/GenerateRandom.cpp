#include "StdAfx.h"
#include "GenerateRandom.h"

CA_API UINT __stdcall GenerateRandomString(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	long size = AppSecInc::StringUtils::stringToLong(msiInstall.GetProperty(L"GENERATE_RANDOM_LENGTH"));
	std::vector<byte> data = AppSecInc::Crypt::CryptoPPImpl::GenerateRandom(size);
	std::string output = AppSecInc::Crypt::CryptoPPImpl::Base64Encode(data);
	output.erase(size);
    msiInstall.SetProperty("GENERATE_RANDOM_RESULT", output);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
