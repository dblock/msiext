#include "StdAfx.h"
#include "Base64EncodeDecode.h"

using namespace AppSecInc::Crypt;

CA_API UINT __stdcall Base64EncodeW(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring data = msiInstall.GetProperty(L"BASE64ENCODE_DATA");

    if (! data.length())
    {
        msiInstall.SetProperty(L"BASE64ENCODE_RESULT", L"");
        return ERROR_SUCCESS;        
    }

	std::vector<byte> data_bytes;
	data_bytes.resize(data.length() * sizeof(wchar_t));
	memcpy_s(& * data_bytes.begin(), data_bytes.size(), & * data.begin(), data_bytes.size());

	std::string output = CryptoPPImpl::Base64Encode(data_bytes);
    msiInstall.SetProperty("BASE64ENCODE_RESULT", output);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Base64EncodeA(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::string data = msiInstall.GetProperty("BASE64ENCODE_DATA");

    if (! data.length())
    {
        msiInstall.SetProperty(L"BASE64ENCODE_RESULT", L"");
        return ERROR_SUCCESS;        
    }

	std::vector<byte> data_bytes;
	data_bytes.resize(data.length() * sizeof(char));
	memcpy_s(& * data_bytes.begin(), data_bytes.size(), & * data.begin(), data_bytes.size());

    std::string output = CryptoPPImpl::Base64Encode(data_bytes);
    msiInstall.SetProperty("BASE64ENCODE_RESULT", output);
    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Base64DecodeW(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::string data = msiInstall.GetProperty("BASE64DECODE_DATA");

    if (! data.length())
    {
        msiInstall.SetProperty(L"BASE64DECODE_RESULT", L"");
        return ERROR_SUCCESS;        
    }

    std::vector<byte> output_bytes = CryptoPPImpl::Base64Decode(data);
	std::wstring output;
	output.resize(output_bytes.size() / sizeof(wchar_t));
	memcpy_s(& * output.begin(), output.size() * sizeof(wchar_t), & * output_bytes.begin(), output_bytes.size());

    msiInstall.SetProperty(L"BASE64DECODE_RESULT", output);    
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Base64DecodeA(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::string data = msiInstall.GetProperty("BASE64DECODE_DATA");

    if (! data.length())
    {
        msiInstall.SetProperty("BASE64DECODE_RESULT", "");
        return ERROR_SUCCESS;        
    }

    std::vector<byte> output_bytes = CryptoPPImpl::Base64Decode(data);
	std::string output;
	output.resize(output_bytes.size() / sizeof(char));
	memcpy_s(& * output.begin(), output.size() * sizeof(char), & * output_bytes.begin(), output_bytes.size());

	msiInstall.SetProperty("BASE64DECODE_RESULT", output);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
