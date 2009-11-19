#include "StdAfx.h"
#include "CryptProtectDataHex.h"
#include "FlagMaps.h"

CA_API UINT __stdcall CryptProtectDataHex(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring data = msiInstall.GetProperty(L"CRYPTPROTECT_DATA");
    std::wstring entropy = msiInstall.GetProperty(L"CRYPTPROTECT_ENTROPY");
    std::wstring description = msiInstall.GetProperty(L"CRYPTPROTECT_DESCRIPTION");

	// Data to protect
	DATA_BLOB blobIn;
	// removes the constness and cast it as a byte*
	blobIn.pbData = reinterpret_cast<BYTE *>(const_cast<wchar_t*>(data.c_str())); 
	blobIn.cbData = data.length() * sizeof(wchar_t);
	
	// Optional entropy
	DATA_BLOB blobEntropy;
	blobEntropy.pbData = reinterpret_cast<BYTE *>(const_cast<wchar_t*>(entropy.c_str()));
	blobEntropy.cbData = entropy.length() * sizeof(wchar_t);
	
	// Local machine flag   
	DWORD dwFlags = GetPropertyValue(msiInstall, L"CRYPTPROTECT_FLAGS", s_CryptProtectDataFlags);

	// Encrypt the data
	DATA_BLOB blobOut = { 0 };
    boost::shared_ptr<void> blobOutPtr(blobOut.pbData, ::LocalFree);

    CHECK_WIN32_BOOL(::CryptProtectData( & blobIn,
        description.c_str(), // Windows 2000 requires a description (bug 13227)
		& blobEntropy,
		NULL,                         
		NULL, //! \todo Support PromptStruct.                   
		dwFlags,
		&blobOut), L"Error in CryptProtectData.");

    CryptoPP::HexEncoder hexEncoder;
	hexEncoder.Put(blobOut.pbData, blobOut.cbData);
	hexEncoder.MessageEnd();

    std::string output;
	output.resize(blobOut.cbData * 2);
	hexEncoder.Get(reinterpret_cast<LPBYTE>(& * output.begin()), output.size());

    msiInstall.SetProperty("CRYPTPROTECT_RESULT", output);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall CryptUnprotectDataHex(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::string hexdata = msiInstall.GetProperty("CRYPTUNPROTECT_DATA");
    std::wstring entropy = msiInstall.GetProperty(L"CRYPTUNPROTECT_ENTROPY");

	CryptoPP::HexDecoder hexDecoder;
    hexDecoder.Put(reinterpret_cast<LPBYTE>(const_cast<char *>(hexdata.c_str())), hexdata.length());
    hexDecoder.MessageEnd();
    
    ULONG len = hexdata.length() / 4;
    std::wstring data;
	data.resize(len);
    hexDecoder.Get(reinterpret_cast<LPBYTE>(& * data.begin()), len * sizeof(wchar_t));

	// Data to unprotect
	DATA_BLOB blobIn;
	// removes the constness and cast it as a byte*
	blobIn.pbData = reinterpret_cast<BYTE *>(const_cast<wchar_t*>(data.c_str())); 
	blobIn.cbData = data.length() * sizeof(wchar_t);
	
	// Optional entropy
	DATA_BLOB blobEntropy;
	blobEntropy.pbData = reinterpret_cast<BYTE *>(const_cast<wchar_t*>(entropy.c_str()));
	blobEntropy.cbData = entropy.length() * sizeof(wchar_t);
	
	// Local machine flag   
	DWORD dwFlags = GetPropertyValue(msiInstall, L"CRYPTUNPROTECT_FLAGS", s_CryptProtectDataFlags);

    // Decrypt the data
	DATA_BLOB blobOut = { 0 };
    boost::shared_ptr<void> blobOutPtr(blobOut.pbData, ::LocalFree);
    LPWSTR descriptionOut = NULL;
    boost::shared_ptr<void> descriptionOutPtr(descriptionOut, ::LocalFree);
    CHECK_WIN32_BOOL(::CryptUnprotectData( & blobIn,
        & descriptionOut,
		& blobEntropy,
		NULL,                         
		NULL, //! \todo Support PromptStruct.                   
		dwFlags,
		&blobOut), L"Error in CryptUnprotectData.");

    std::wstring output;
    
    if (blobOut.cbData != 0)
    {
        output.resize(blobOut.cbData / sizeof(wchar_t));
        memcpy(& * output.begin(), blobOut.pbData, blobOut.cbData);
    }

    msiInstall.SetProperty(L"CRYPTUNPROTECT_DESCRIPTION", descriptionOut);
    msiInstall.SetProperty(L"CRYPTUNPROTECT_RESULT", output);
    
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
