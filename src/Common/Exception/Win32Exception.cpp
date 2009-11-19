#include "StdAfx.h"
#include "Win32Exception.h"

#include <String/StringUtils.h>
#include <String/Formatter.h>

using namespace AppSecInc::Exception;

std::string Win32Exception::GetErrorString(HRESULT hr, LPCTSTR error)
{
    std::stringstream ss;
    ss << "0x" << std::hex << hr;
	if (NULL != error)
	{
		ss << " - " << StringUtils::wc2mb(error);
	}
    ss << ": " << AppSecInc::Formatter::FormatMessageFromHRA(hr);
    return ss.str();
}

std::string Win32Exception::GetErrorString(DWORD dwErr, LPCTSTR error)
{
    return GetErrorString(HRESULT_FROM_WIN32(dwErr));
}

std::string Win32Exception::GetLastErrorString(LPCTSTR error)
{
    return GetErrorString(GetLastError(), error);
}
