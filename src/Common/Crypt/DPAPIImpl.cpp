#include "StdAfx.h"
#include "DPAPIImpl.h"

using namespace AppSecInc::Crypt;

std::wstring DPAPIImpl::Protect(const std::wstring& input, const std::wstring& entropy)
{
	// Data to protect
	DATA_BLOB blobIn;
	// removes the constness and cast it as a byte*
	blobIn.pbData = reinterpret_cast<BYTE *>(const_cast<wchar_t*>(input.c_str())); 
	blobIn.cbData = (input.length() + 1) * sizeof(wchar_t);
	
	// Optional entropy
	DATA_BLOB blobEntropy;
	blobEntropy.pbData = reinterpret_cast<BYTE *>(const_cast<LPWSTR>(entropy.c_str()));
	blobEntropy.cbData = entropy.size() * sizeof(wchar_t);
	
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

	std::vector<byte> data(blobOut.cbData);
	memcpy_s(& * data.begin(), data.size(), blobOut.pbData, blobOut.cbData);
	return AppSecInc::StringUtils::mb2wc(CryptoPPImpl::HexEncode(data));
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

	std::vector<byte> data(blobOut.cbData);
	memcpy_s(& * data.begin(), data.size(), blobOut.pbData, blobOut.cbData);
	return CryptoPPImpl::HexEncode(data);
}

std::wstring DPAPIImpl::UnProtect(const std::wstring& input, const std::wstring& entropy)
{
	if (input.length() == 0)
        return L"";

	std::vector<byte> decoded_input = CryptoPPImpl::HexDecode(AppSecInc::StringUtils::wc2mb(input));

    // Data to unprotect
    DATA_BLOB blobIn;
	blobIn.pbData = & * decoded_input.begin();
	blobIn.cbData = decoded_input.size();
		
	// Optional entropy
	DATA_BLOB blobEntropy;
	blobEntropy.pbData = reinterpret_cast<BYTE *>(const_cast<LPWSTR>(entropy.c_str()));
	blobEntropy.cbData = entropy.size() * sizeof(wchar_t);

    // Decrypt the data
	DATA_BLOB blobVerify = { 0 };
    boost::shared_ptr<void> blobVerifyPtr(blobVerify.pbData, ::LocalFree);
	CHECK_WIN32_BOOL(CryptUnprotectData(& blobIn, NULL, & blobEntropy, NULL, NULL, CRYPTPROTECT_UI_FORBIDDEN, & blobVerify),
        L"CryptUnprotectData failed");

	return reinterpret_cast<LPWSTR>(blobVerify.pbData);
}

std::string DPAPIImpl::UnProtect(const std::string& input, const std::string& entropy)
{
	if (input.length() == 0)
        return "";

	std::vector<byte> decoded_input = CryptoPPImpl::HexDecode(input);

    // Data to unprotect
    DATA_BLOB blobIn;
	blobIn.pbData = & * decoded_input.begin();
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
