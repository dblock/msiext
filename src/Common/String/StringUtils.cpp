#include "StdAfx.h"
#include "StringUtils.h"

int AppSecInc::StringUtils::replace(std::string& ss, const std::string& from, const std::string& to)
{
    return StringUtilsImpl<char>::replace(ss, from, to);
}

int AppSecInc::StringUtils::replace(std::wstring& ss, const std::wstring& from, const std::wstring& to)
{
    return StringUtilsImpl<wchar_t>::replace(ss, from, to);
}

void AppSecInc::StringUtils::tokenize(const std::string& ss, std::vector<std::string>& tokens, const std::string& delims)
{
    StringUtilsImpl<char>::tokenize(ss, tokens, delims);
}

void AppSecInc::StringUtils::tokenize(const std::wstring& ss, std::vector<std::wstring>& tokens, const std::wstring& delims)
{
    StringUtilsImpl<wchar_t>::tokenize(ss, tokens, delims);
}

std::string AppSecInc::StringUtils::join(const std::vector<std::string>& tokens, const std::string& delims)
{
    return StringUtilsImpl<char>::join(tokens, delims);
}

std::wstring AppSecInc::StringUtils::join(const std::vector<std::wstring>& tokens, const std::wstring& delims)
{
    return StringUtilsImpl<wchar_t>::join(tokens, delims);
}

std::string AppSecInc::StringUtils::join(const std::list<std::string>& tokens, const std::string& delims)
{
    return StringUtilsImpl<char>::join(tokens, delims);
}

std::wstring AppSecInc::StringUtils::join(const std::list<std::wstring>& tokens, const std::wstring& delims)
{
    return StringUtilsImpl<wchar_t>::join(tokens, delims);
}

void AppSecInc::StringUtils::tokenizeWithSkip(const std::string& ss, std::vector<std::string>& tokens, const std::string& delim)
{
    StringUtilsImpl<char>::tokenizeWithSkip(ss, tokens, delim);
}

void AppSecInc::StringUtils::tokenizeWithSkip(const std::wstring& ss, std::vector<std::wstring>& tokens, const std::wstring& delim)
{
    StringUtilsImpl<wchar_t>::tokenizeWithSkip(ss, tokens, delim);
}

void AppSecInc::StringUtils::tokenizeOnChar(const std::string& ss, std::vector<std::string>& tokens, const std::string& delims)
{
    StringUtilsImpl<char>::tokenizeOnChar(ss, tokens, delims);
}

void AppSecInc::StringUtils::tokenizeOnChar(const std::wstring& ss, std::vector<std::wstring>& tokens, const std::wstring& delims)
{
    StringUtilsImpl<wchar_t>::tokenizeOnChar(ss, tokens, delims);
}

void AppSecInc::StringUtils::ltrim(std::string& ss, const std::string& whitespaces)
{
    StringUtilsImpl<char>::ltrim(ss, whitespaces);
}

void AppSecInc::StringUtils::ltrim(std::wstring& ss, const std::wstring& whitespaces)
{
    StringUtilsImpl<wchar_t>::ltrim(ss, whitespaces);
}

void AppSecInc::StringUtils::rtrim(std::string& ss, const std::string& whitespaces)
{
    StringUtilsImpl<char>::rtrim(ss, whitespaces);
}

void AppSecInc::StringUtils::rtrim(std::wstring& ss, const std::wstring& whitespaces)
{
    StringUtilsImpl<wchar_t>::rtrim(ss, whitespaces);
}

void AppSecInc::StringUtils::lrtrim(std::string& ss, const std::string& whitespaces)
{
    StringUtilsImpl<char>::lrtrim(ss, whitespaces);
}

void AppSecInc::StringUtils::lrtrim(std::wstring& ss, const std::wstring& whitespaces)
{
    StringUtilsImpl<wchar_t>::lrtrim(ss, whitespaces);
}

void AppSecInc::StringUtils::lrtrimcrlf(std::string& ss, const std::string& whitespaces)
{
    StringUtilsImpl<char>::lrtrimcrlf(ss, whitespaces);
}

void AppSecInc::StringUtils::lrtrimcrlf(std::wstring& ss, const std::wstring& whitespaces)
{
    StringUtilsImpl<wchar_t>::lrtrimcrlf(ss, whitespaces);
}

void AppSecInc::StringUtils::uppercase(std::string& ss)
{
    StringUtilsImpl<char>::uppercase(ss);
}

void AppSecInc::StringUtils::uppercase(std::wstring& ss)
{
    StringUtilsImpl<wchar_t>::uppercase(ss);
}

void AppSecInc::StringUtils::lowercase(std::string& ss)
{
    StringUtilsImpl<char>::lowercase(ss);
}

void AppSecInc::StringUtils::lowercase(std::wstring& ss)
{
    StringUtilsImpl<wchar_t>::lowercase(ss);
}

bool AppSecInc::StringUtils::comparei(const std::string& ss1, const std::string& ss2)
{
    return StringUtilsImpl<char>::comparei(ss1, ss2);
}

bool AppSecInc::StringUtils::comparei(const std::wstring& ss1, const std::wstring& ss2)
{
    return StringUtilsImpl<wchar_t>::comparei(ss1, ss2);
}

bool AppSecInc::StringUtils::startsWith(const std::string& ss, const std::string& what)
{
    return StringUtilsImpl<char>::startsWith(ss, what);
}

bool AppSecInc::StringUtils::startsWith(const std::wstring& ss, const std::wstring& what)
{
    return StringUtilsImpl<wchar_t>::startsWith(ss, what);
}

bool AppSecInc::StringUtils::endsWith(const std::string& ss, const std::string& what)
{
    return StringUtilsImpl<char>::endsWith(ss, what);
}

bool AppSecInc::StringUtils::endsWith(const std::wstring& ss, const std::wstring& what)
{
    return StringUtilsImpl<wchar_t>::endsWith(ss, what);
}

std::wstring AppSecInc::StringUtils::mb2wc(const std::string& from) 
{
    return mb2wc(from.c_str(), from.length());
}

std::wstring AppSecInc::StringUtils::mb2wc(const char * from) 
{
    return mb2wc(from, from != NULL ? lstrlenA(from) : 0);
}

std::wstring AppSecInc::StringUtils::mb2wc(const char * from, unsigned int len) 
{
    std::wstring to;

    if (from == NULL || len == 0)
    {
	    return to;
    }

    std::vector<wchar_t> p;
    p.resize(len + 1);
    wchar_t * pdata = & * p.begin();
    // null terminates the output
    size_t converted = 0;
    mbstowcs_s(& converted, pdata, p.size(), from, len);
    // assign number of characters w/o null terminator
    to.assign(pdata, converted - 1); 
    return to;
}

std::string AppSecInc::StringUtils::wc2mb(const std::wstring& from) 
{
    return wc2mb(from.c_str(), from.length());
}

std::string AppSecInc::StringUtils::wc2mb(const wchar_t * from) 
{
    return wc2mb(from, from != NULL ? lstrlenW(from) : 0);
}

std::string AppSecInc::StringUtils::wc2mb(const wchar_t * from, unsigned int len) 
{
    std::string to;
    if (from == NULL || len == 0)
    {
	    return to;
    }

    std::vector<char> p;
    p.resize(len + 1);
    char * pdata = & * p.begin();
    // null terminates the output
    size_t converted = 0;
    wcstombs_s(& converted, pdata, p.size(), from, len);
    // assign number of characters w/o null terminator
    to.assign(pdata, converted - 1); 
    return to;
}

std::wstring AppSecInc::StringUtils::utf82wc(const std::string& from) 
{
    return utf82wc(from.c_str(), from.length());
}

std::wstring AppSecInc::StringUtils::utf82wc(const char * from) 
{
    return utf82wc(from, from != NULL ? lstrlenA(from) : 0);
}

std::wstring AppSecInc::StringUtils::utf82wc(const char * from, unsigned int len) 
{
    std::wstring to;

    if (from == NULL || len == 0)
    {
	    return to;
    }

	int to_len = ::MultiByteToWideChar(CP_UTF8, 0, from, len, NULL, 0);
	CHECK_WIN32_BOOL(to_len > 0, L"MultiByteToWideChar");

	to.resize(to_len);
	to_len = ::MultiByteToWideChar(CP_UTF8, 0, from, len, & * to.begin(), to.size());	
	CHECK_WIN32_BOOL(to_len > 0, L"MultiByteToWideChar");

	return to;
}

std::string AppSecInc::StringUtils::wc2utf8(const std::wstring& from) 
{
    return wc2utf8(from.c_str(), from.length());
}

std::string AppSecInc::StringUtils::wc2utf8(const wchar_t * from) 
{
    return wc2utf8(from, from != NULL ? lstrlenW(from) : 0);
}

std::string AppSecInc::StringUtils::wc2utf8(const wchar_t * from, unsigned int len) 
{
    std::string to;
    if (from == NULL || len == 0)
    {
	    return to;
    }

	int to_len = ::WideCharToMultiByte(CP_UTF8, 0, from, len, NULL, 0, NULL, NULL);
	CHECK_WIN32_BOOL(to_len > 0, L"WideCharToMultiByte");

	to.resize(to_len);
	to_len = ::WideCharToMultiByte(CP_UTF8, 0, from, len, & * to.begin(), to.size(), NULL, NULL);
	CHECK_WIN32_BOOL(to_len > 0, L"WideCharToMultiByte");

	return to;
}

long AppSecInc::StringUtils::stringToLong(const std::string& ss, long default_on_error, int base)
{
    return stringToLong(ss.c_str(), default_on_error, base);
}

long AppSecInc::StringUtils::stringToLong(const std::wstring& ss, long default_on_error, int base)
{
    return stringToLong(ss.c_str(), default_on_error, base);
}

long AppSecInc::StringUtils::stringToLong(const char * psz, long default_on_error, int base)
{
    char *endPtr = NULL;
    int retValue = 0; 

    if ( psz != NULL && *psz != '\0' )
    {
	    // errrange
	    retValue = strtol(psz, &endPtr, base);
		
	    if ( *endPtr != '\0' || (errno == ERANGE && (retValue == LONG_MAX || retValue == LONG_MIN)) )
	    {
		    retValue = default_on_error;
	    }
    }
    else
    {
	    retValue = default_on_error;
    }

    return retValue;
}

long AppSecInc::StringUtils::stringToLong(const wchar_t * psz, long default_on_error, int base)
{
    wchar_t *endPtr = NULL;
    int retValue = 0; 
	
    retValue = wcstol(psz, &endPtr, base);
    if ( psz != NULL && *psz != L'\0' )
    {
	    if ( *endPtr != L'\0' || (errno == ERANGE && (retValue == LONG_MAX || retValue == LONG_MIN)) )
	    {
		    retValue = default_on_error;
	    }
    }
    else
    {
	    retValue = default_on_error;
    }
	
    return retValue;
}

std::string AppSecInc::StringUtils::bstr2mb(BSTR from)
{
    return bstr2mb(from, from != NULL ? SysStringLen(from) : 0);
}

std::string AppSecInc::StringUtils::bstr2mb(BSTR from, int len)
{
    std::string out;
	
    if (from == NULL || len == 0)
    {
	    return out;
    }

    out.resize(len);
    char * p = & * out.begin();
	
    if (0 == WideCharToMultiByte(CP_ACP, 0, static_cast<LPCWSTR>(from), len, p, len + 1, NULL, NULL ))
    {
	    throw std::exception("WideCharToMultiByte failed");
    }

    return out; // don't alter to until a successful conversion (ddoubro)
}

std::string AppSecInc::StringUtils::bstr2mb(const _bstr_t& from)
{
    return bstr2mb(static_cast<BSTR>(from), from.length());
}

std::string AppSecInc::StringUtils::bstr2mb(const CComBSTR& from)
{
    return bstr2mb(static_cast<BSTR>(from), from.Length());
}

std::string AppSecInc::StringUtils::toString(VARIANT v)
{
	return wc2mb(toWString(v));
}

std::wstring AppSecInc::StringUtils::toWString(VARIANT v)
{
	std::wostringstream os;
	wchar_t buf[64];
	switch (v.vt)
	{
	case VT_BSTR:
		os << (v.bstrVal ? v.bstrVal : L"");
		break;
	case VT_I4:
		os << v.intVal;
		break;
	case VT_UI4:
		os << v.uintVal;
		break;
	case VT_INT:
		os << v.intVal;
		break;
	case VT_UINT:
		os << v.uintVal;
		break;
	case VT_UI1:
		os << static_cast<unsigned int>(v.bVal);
		break;
	case VT_I1:
		os << v.cVal;
		break;
	case VT_I2:
		os << v.iVal;
		break;
	case VT_UI2:
		os << v.uiVal;
		break;
	case VT_BOOL:
		os << (v.boolVal == ATL_VARIANT_FALSE ? L"false" : L"true") ;
		break;
	case VT_R4:
		os << v.fltVal;
		break;
	case VT_R8:
		os << v.dblVal;
		break;
	case VT_UNKNOWN:
		os << L"IUnknown: 0x" << reinterpret_cast<void*>(v.ppunkVal);
		break;
	case VT_DISPATCH:
		os << L"IDspatch: 0x" << reinterpret_cast<void*>(v.ppdispVal);
		break;
	case VT_ERROR:
		os << L"Error: " << std::hex << v.lVal;
		break;
#if (_WIN32_WINNT >= 0x0501) || defined(_ATL_SUPPORT_VT_I8)
	case VT_I8:
		_i64tow_s(v.llVal, buf, ARRAYSIZE(buf), 10);
		os << buf;
		break;
	case VT_UI8:
		_i64tow_s(v.ullVal, buf, ARRAYSIZE(buf), 10);
		os << buf;
		break;
#endif
	case VT_CY:
		_i64tow_s(v.cyVal.int64, buf, ARRAYSIZE(buf), 10);
		os << buf;
		break;
	case VT_DATE:
	default:
		throw std::exception("Unsupported type");
	}

	return os.str();
}

std::string AppSecInc::StringUtils::toString(const _variant_t& from)
{
    return toString(static_cast<VARIANT>(from));
}

std::string AppSecInc::StringUtils::toString(const CComVariant& from)
{
    return toString(static_cast<VARIANT>(from));
}

std::wstring AppSecInc::StringUtils::toWString(const _variant_t& from)
{
    return toWString(static_cast<VARIANT>(from));
}

std::wstring AppSecInc::StringUtils::toWString(const CComVariant& from)
{
    return toWString(static_cast<VARIANT>(from));
}

static unsigned char ASCII_to_EBCDIC [ 256 ] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
    0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x40, 0x5A, 0x7F, 0x7B, 0x5B, 0x6C, 0x50, 0x7D, 0x4D,
    0x5D, 0x5C, 0x4E, 0x6B, 0x60, 0x4B, 0x61,
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8,
    0xF9, 0x7A, 0x5E, 0x4C, 0x7E, 0x6E, 0x6F,
    0x7C, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8,
    0xC9, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6,
    0xD7, 0xD8, 0xD9, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7,
    0xE8, 0xE9, 0xAD, 0xE0, 0xBD, 0x5F, 0x6D,
    0x7D, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88,
    0x89, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96,
    0x97, 0x98, 0x99, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7,
    0xA8, 0xA9, 0xC0, 0x6A, 0xD0, 0xA1, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B,
    0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B 
};

static unsigned char EBCDIC_to_ASCII [ 256 ] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
    0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
    0x2E, 0x2E, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
    0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x2E, 0x3F,
    0x20, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x3C, 0x28, 0x2B, 0x7C,
    0x26, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x21, 0x24, 0x2A, 0x29, 0x3B, 0x5E,
    0x2D, 0x2F, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x7C, 0x2C, 0x25, 0x5F, 0x3E, 0x3F,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x3A, 0x23, 0x40, 0x27, 0x3D, 0x22,
    0x2E, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71,
    0x72, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x7E, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79,
    0x7A, 0x2E, 0x2E, 0x2E, 0x5B, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x2E, 0x2E, 0x2E, 0x2E, 0x5D, 0x2E, 0x2E,
    0x7B, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
    0x49, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x7D, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51,                                             
    0x52, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x5C, 0x2E, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5A, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,                 
    0x39, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E 
};

void AppSecInc::StringUtils::s2ebcdic(std::string& ss)
{
    s2ebcdic(reinterpret_cast<unsigned char *>(& * ss.begin()), ss.length());
}

void AppSecInc::StringUtils::ebcdic2s(std::string& ss)
{
    ebcdic2s(reinterpret_cast<unsigned char *>(& * ss.begin()), ss.length());
}

void AppSecInc::StringUtils::s2ebcdic(unsigned char * s, unsigned long len)
{
    for (unsigned long i = 0; i < len; i++)
    {
	    s[i] = ASCII_to_EBCDIC[s[i]];
    }
}	

void AppSecInc::StringUtils::ebcdic2s(unsigned char * s, unsigned long len)
{
    for (unsigned long i = 0; i < len; i++)
    {
	    s[i] = EBCDIC_to_ASCII[s[i]];
    }
}

std::wstring AppSecInc::StringUtils::escape(std::wstring const &s)
{
    std::size_t n = s.length();
    std::wstring escaped;
    escaped.reserve(n * 2);        // pessimistic preallocation

    for (std::size_t i = 0; i < n; ++i) {
        if (s[i] == L'\\' || s[i] == L'"')
            escaped += L'\\';
        escaped += s[i];
    }
    return escaped;
}
