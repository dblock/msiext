#include "StdAfx.h"
#include "HexEncodeDecode.h"

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

	std::vector<byte> data_bytes;
	data_bytes.resize(data.length() * sizeof(wchar_t));
	memcpy_s(& * data_bytes.begin(), data_bytes.size(), & * data.begin(), data.length() * sizeof(wchar_t));

    std::string output = CryptoPPImpl::HexEncode(data_bytes);
    msiInstall.SetProperty("HEXENCODE_RESULT", output);
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

	std::vector<byte> data_bytes;
	data_bytes.resize(data.length() * sizeof(char));
	memcpy_s(& * data_bytes.begin(), data_bytes.size(), & * data.begin(), data.length() * sizeof(char));

    std::string output = CryptoPPImpl::HexEncode(data_bytes);
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

    std::vector<byte> output_bytes = CryptoPPImpl::HexDecode(
		AppSecInc::StringUtils::wc2mb(data));

	std::wstring output;
	output.resize(output_bytes.size() / sizeof(wchar_t));
	memcpy_s(& * output.begin(), output.size() * sizeof(wchar_t), & * output_bytes.begin(), output_bytes.size());

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

    std::vector<byte> output_bytes = CryptoPPImpl::HexDecode(data);

	std::string output;
	output.resize(output_bytes.size() / sizeof(char));
	memcpy_s(& * output.begin(), output.size() * sizeof(char), & * output_bytes.begin(), output_bytes.size());

    msiInstall.SetProperty("HEXDECODE_RESULT", output);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
