#include "StdAfx.h"
#include "EncodeDecode.h"

using namespace AppSecInc::Crypt;

CA_API UINT __stdcall HexEncodeW(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring data = msiInstall.GetProperty(L"HEXENCODE_DATA");

    if (! data.length())
    {
        msiInstall.SetProperty(L"HEXENCODE_RESULT", L"");
        return ERROR_SUCCESS;        
    }

    std::wstring output = CryptoPPImpl::HexEncode(data);
    msiInstall.SetProperty(L"HEXENCODE_RESULT", output);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall HexEncodeA(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::string data = msiInstall.GetProperty("HEXENCODE_DATA");

    if (! data.length())
    {
        msiInstall.SetProperty(L"HEXENCODE_RESULT", L"");
        return ERROR_SUCCESS;        
    }

    std::string output = CryptoPPImpl::HexEncode(data);
    msiInstall.SetProperty("HEXENCODE_RESULT", output);
    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall HexDecodeW(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring data = msiInstall.GetProperty(L"HEXDECODE_DATA");

    if (! data.length())
    {
        msiInstall.SetProperty(L"HEXDECODE_RESULT", L"");
        return ERROR_SUCCESS;        
    }

    std::wstring output = CryptoPPImpl::HexDecode(data);
    msiInstall.SetProperty(L"HEXDECODE_RESULT", output);    
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall HexDecodeA(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::string data = msiInstall.GetProperty("HEXDECODE_DATA");

    if (! data.length())
    {
        msiInstall.SetProperty(L"HEXDECODE_RESULT", L"");
        return ERROR_SUCCESS;        
    }

    std::string output = CryptoPPImpl::HexDecode(data);
    msiInstall.SetProperty("HEXDECODE_RESULT", output);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
