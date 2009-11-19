#include "StdAfx.h"
#include "DPAPIImpl.h"

using namespace AppSecInc::Crypt;

DPAPIImpl::DPAPIImpl()
{

}

std::string DPAPIImpl::Protect(const std::string& input, const std::string& entropy)
{
	// Data to protect
	DATA_BLOB blobIn;
	// removes the constness and cast it as a byte*
	blobIn.pbData = reinterpret_cast<BYTE *>(const_cast<char*>(input.c_str())); 
	blobIn.cbData = input.length() + 1;
	
	// Optional entropy
	DATA_BLOB blobEntropy;
	blobEntropy.pbData = reinterpret_cast<BYTE *>(const_cast<LPSTR>(entropy.c_str()));
	blobEntropy.cbData = entropy.size();
	
	// Local machine flag   
	DWORD dwFlags = CRYPTPROTECT_LOCAL_MACHINE | CRYPTPROTECT_UI_FORBIDDEN;

	// Encrypt the data
	DATA_BLOB blobOut = { 0 };
    boost::shared_ptr<void> blobOutPtr(blobOut.pbData, ::LocalFree);
	CHECK_WIN32_BOOL(CryptProtectData(
        & blobIn,
		L"", // Windows 2000 requires a description (bug 13227)
        & blobEntropy, NULL, NULL, dwFlags, & blobOut),
        L"CryptProtectData failed");

    return CryptoPPImpl::HexEncode(std::string(reinterpret_cast<LPSTR>(blobOut.pbData), blobOut.cbData));
}

std::string DPAPIImpl::UnProtect(const std::string& input, const std::string& entropy)
{
	if (input.length() == 0)
        return "";

	std::string decoded_input = CryptoPPImpl::HexDecode(input);

    // Data to unprotect
    DATA_BLOB blobIn;
	blobIn.pbData = reinterpret_cast<BYTE *>(const_cast<LPSTR>(decoded_input.c_str()));
	blobIn.cbData = decoded_input.size();
		
	// Optional entropy
	DATA_BLOB blobEntropy;
	blobEntropy.pbData = reinterpret_cast<BYTE *>(const_cast<LPSTR>(entropy.c_str()));
	blobEntropy.cbData = entropy.size();

    // Decrypt the data
	DATA_BLOB blobVerify = { 0 };
    boost::shared_ptr<void> blobVerifyPtr(blobVerify.pbData, ::LocalFree);
	CHECK_WIN32_BOOL(CryptUnprotectData(& blobIn, NULL, & blobEntropy, NULL, NULL, CRYPTPROTECT_UI_FORBIDDEN, & blobVerify),
        L"CryptUnprotectData failed");

    return reinterpret_cast<LPSTR>(blobVerify.pbData);
}
