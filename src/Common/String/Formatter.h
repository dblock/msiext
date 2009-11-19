#pragma once

namespace AppSecInc
{
	//! Common message formatting
	namespace Formatter
	{
        //! format an ANSI message from an HRESULT
        std::string FormatMessageFromHRA(HRESULT hr);
        //! format an ANSI message from a Win32 error code
        std::string FormatMessageFromLastErrorCodeA(DWORD);
        //! format a UNICODE message from an HRESULT
        std::wstring FormatMessageFromHRW(HRESULT hr);
        //! format a UNICODE message from a Win32 error code
        std::wstring FormatMessageFromLastErrorCodeW(DWORD);
        //! format a message with a list of arguments (printf-style)
        std::string FormatMessageFromVArgs(char *, va_list&);
        //! format a message with a list of arguments (printf-style)
        std::wstring FormatMessageFromVArgs(wchar_t *, va_list&);
        //! format a message with a list of arguments (printf-style)
		std::string FormatMessage(char *, ...);
		//! format a message with a list of arguments (printf-style)
		std::wstring FormatMessage(wchar_t *, ...);
        //! format an ANSI buffer of bytes into a hex view
        std::string FormatHexA(byte * buffer, unsigned long len);
        //! format a UNICODE buffer of bytes into a hex view
		std::wstring FormatHexW(byte * buffer, unsigned long len);
        //! format an ANSI buffer of bytes into a hex string
        std::string FormatHexStringA(byte * buffer, unsigned long len);
        //! format a UNICODE buffer of bytes into a hex string
		std::wstring FormatHexStringW(byte * buffer, unsigned long len);
        //! format a UNICODE template
        std::wstring FormatTemplate(const std::wstring& buffer, const std::map<std::wstring, std::wstring>& tokens, const std::wstring& left = L"[", const std::wstring& right = L"]");
        //! format an ANSI template
        std::string FormatTemplate(const std::string& buffer, const std::map<std::string, std::string>& tokens, const std::string& left = "[", const std::string& right = "]");
	}
}
