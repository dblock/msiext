#include "StdAfx.h"
#include <boost/regex.hpp>


CA_API UINT __stdcall String_Replace(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring string_value = msiInstall.GetProperty(L"STRING_VALUE_FROM");
	std::wstring from_value = msiInstall.GetProperty(L"STRING_REPLACE_FROM");
	std::wstring to_value = msiInstall.GetProperty(L"STRING_REPLACE_TO");
	int found = AppSecInc::StringUtils::replace(string_value, from_value, to_value);
	msiInstall.SetProperty(L"STRING_VALUE_TO", string_value);
	msiInstall.SetProperty(L"STRING_REPLACE_COUNT", AppSecInc::StringUtils::toWString(found));

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall String_Trim(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring input = msiInstall.GetProperty(L"STRING_TRIM_INPUT");
	std::wstring whitespaces = msiInstall.GetProperty(L"STRING_TRIM_WHITESPACES");

	if (whitespaces.empty()) whitespaces = L" \t";
	AppSecInc::StringUtils::lrtrim(input, whitespaces);
	msiInstall.SetProperty(L"STRING_TRIM_RESULT", input);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Regex_Match(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring input = msiInstall.GetProperty(L"REGEX_MATCH_INPUT_STRING");
	std::wstring pattern = msiInstall.GetProperty(L"REGEX_MATCH_EXPRESSION");

	boost::wregex expression(pattern.c_str());
	boost::wcmatch what;

	if(boost::regex_match(input.c_str(), what, expression))
	{
		msiInstall.SetProperty(L"REGEX_MATCH_RESULT", L"1");
	}
	else
	{
		msiInstall.SetProperty(L"REGEX_MATCH_RESULT", L"0");
	}

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Regex_Replace(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring input = msiInstall.GetProperty(L"REGEX_REPLACE_INPUT_STRING");
	std::wstring pattern = msiInstall.GetProperty(L"REGEX_REPLACE_EXPRESSION");
	std::wstring format = msiInstall.GetProperty(L"REGEX_REPLACE_FORMAT");

	boost::wregex expression(pattern.c_str());

	msiInstall.SetProperty(L"REGEX_REPLACE_RESULT", boost::regex_replace(input, expression, format));

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}


CA_API UINT __stdcall String_ToLower(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring input = msiInstall.GetProperty(L"STRING_TOLOWER_INPUT");
    AppSecInc::StringUtils::lowercase( input );
	msiInstall.SetProperty(L"STRING_TOLOWER_RESULT", input );

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall String_ToUpper(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring input = msiInstall.GetProperty(L"STRING_TOUPPER_INPUT");
    AppSecInc::StringUtils::uppercase( input );
	msiInstall.SetProperty(L"STRING_TOUPPER_RESULT", input );

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
