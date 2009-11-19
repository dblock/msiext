#include "StdAfx.h"
#include "StringUtils.h"
#include "Formatter.h"
#include "FormatterImpl.h"

std::string AppSecInc::Formatter::FormatMessageFromHRA(HRESULT hr)
{
    std::string result;
	LPSTR lpMsgBuf = NULL;
    boost::shared_ptr<void> lpMsgBufPtr(lpMsgBuf, ::LocalFree);
	DWORD rc = 0;

    rc = ::FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		reinterpret_cast<LPSTR>(& lpMsgBuf),
		0,
		NULL );

	if (rc != 0)
	{
		result = lpMsgBuf;

		// remove the control line feed characters
		StringUtils::lrtrimcrlf(result);
	}
	else
	{
        std::stringstream result_s;
        result_s << "0x" << std::hex << hr;
		result = result_s.str();
	}
    return result;
}

std::wstring AppSecInc::Formatter::FormatMessageFromHRW(HRESULT hr)
{
    std::wstring result;
	LPWSTR lpMsgBuf = NULL;
	DWORD rc = 0;

    rc = ::FormatMessageW(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		reinterpret_cast<LPWSTR>(& lpMsgBuf),
		0,
		NULL );

	if (rc != 0)
	{
		result = lpMsgBuf;

		// remove the control line feed characters
		StringUtils::lrtrimcrlf(result);
	}
	else
	{
        std::wstringstream result_s;
        result_s << L"0x" << std::hex << hr;
		result = result_s.str();
	}
    return result;
}

std::wstring AppSecInc::Formatter::FormatMessageFromLastErrorCodeW(const DWORD errorCode)
{
	return FormatMessageFromHRW(HRESULT_FROM_WIN32(errorCode));
}

std::string AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(const DWORD errorCode)
{
	return FormatMessageFromHRA(HRESULT_FROM_WIN32(errorCode));
}

std::string AppSecInc::Formatter::FormatMessageFromVArgs(char * fmt, va_list& args)
{
    std::string result;
	int len = 0;
	result.resize(24);
	while( (len = vsnprintf_s(& * result.begin(), result.size(), result.size() - 1, fmt, args)) < 0 )
	{
		result.resize(result.size() * 2);
	}
	result.resize(len);
    return result;
}

std::wstring AppSecInc::Formatter::FormatMessageFromVArgs(wchar_t * fmt, va_list& args)
{
    std::wstring result;
	int len = 0;
	result.resize(24);
	while( (len = _vsnwprintf_s(& * result.begin(), result.size(), result.size() - 1, fmt, args)) < 0 )
	{
		result.resize(result.size() * 2);
	}
	result.resize(len);
    return result;
}

std::string AppSecInc::Formatter::FormatMessage(char * fmt, ...)
{
	va_list args;

	va_start(args, fmt);
    std::string result = FormatMessageFromVArgs(fmt, args);
	va_end(args);
	return result;		
}

std::wstring AppSecInc::Formatter::FormatMessage(wchar_t * fmt, ...)
{
	va_list args;

	va_start(args, fmt);
    std::wstring result = FormatMessageFromVArgs(fmt, args);
	va_end(args);
	return result;		
}

std::string AppSecInc::Formatter::FormatHexA(byte * szObj, unsigned long nNum)
{
    std::string to;
	const int BUF_SIZE = 1024;
    char szTemp[ BUF_SIZE ];
    char szMsg[BUF_SIZE];

    unsigned long i;
    unsigned long j;
    unsigned long max;                

	to.clear();
    
    if ( szObj == NULL || nNum <= 0 )
	{
		return to;
	}

    max    = nNum;
    if ( ( nNum % 8 ) != 0 )
    {
        max += 8 - ( nNum % 8 );
    }
    
    for ( i = 0; i < max; i += 16 )
    {
        SecureZeroMemory(szTemp, sizeof(szTemp));
        SecureZeroMemory(szMsg, sizeof(szMsg));

        StringCchPrintfA(szTemp, BUF_SIZE, "%5.5x\t", i);
        StringCchCopyA(szMsg, BUF_SIZE, szTemp);
    
        for( j = 0; j < 16; j++ )
        {
            if ( ( j + i ) < nNum )
            {
                SecureZeroMemory(szTemp, sizeof(szTemp));
                StringCchPrintfA(szTemp, BUF_SIZE, "%.2x ", szObj[ j + i ]);                    

                if ( strlen( szTemp ) > 3 )
                {
                    szTemp[ 0 ]    = szTemp[ strlen( szTemp ) - 3 ];
                    szTemp[ 1 ]    = szTemp[ strlen( szTemp ) - 2 ];
                    szTemp[ 2 ]    = ' ';
                    szTemp[ 3 ]    = '\0';
                }
            }
            else
            {
                SecureZeroMemory(szTemp, sizeof(szTemp));
                StringCchCopyA(szTemp, BUF_SIZE, "   ");
            }

            StringCchCatA(szMsg, BUF_SIZE, szTemp);                    
        }
        
        StringCchCatA(szMsg, BUF_SIZE, " ");
        SecureZeroMemory(szTemp, sizeof(szTemp));

        for( j = 0; j < 16 && ( j + i ) < nNum; j++ )
        {
            if (    ( szObj[ j + i ] > 31 )    &&
                    ( szObj[ j + i ] < 127 )    )
            {
                szTemp[ 0 ]    = szObj[ j + i ];
                szTemp[ 1 ]    = '\0';                    
                StringCchCatA(szMsg, BUF_SIZE, szTemp);
            }
            else
            {
                StringCchCatA(szMsg, BUF_SIZE, ".");
            }
        }

		if (to.length() > 0) to.append("\n");
		to.append(szMsg);
    }
    return to;
}

std::string AppSecInc::Formatter::FormatHexStringA(byte * szObj, unsigned long nNum)
{
    std::string to;
	to.resize(nNum * 2);
    
    if ( szObj == NULL || nNum <= 0 )
	{
		return to;
	}

	for (unsigned long i = 0; i < nNum; i++)
	{
		StringCchPrintfA(& * to.begin() + i * 2, 3, "%02x", szObj[i]);
    }

    return to;
}

std::wstring AppSecInc::Formatter::FormatHexStringW(byte * szObj, unsigned long nNum)
{
    std::wstring to;
	to.resize(nNum * 2);
    
    if ( szObj == NULL || nNum <= 0 )
	{
		return to;
	}

	for (unsigned long i = 0; i < nNum; i++)
	{
		StringCchPrintfW(& * to.begin() + i * 2, 3, L"%02x", szObj[i]);
    }

    return to;
}

std::wstring AppSecInc::Formatter::FormatHexW(byte * szObj, unsigned long nNum)
{
    std::wstring to;
    const int BUF_SIZE = 1024;
    WCHAR szTemp[ BUF_SIZE ];
    WCHAR szMsg[BUF_SIZE];

    unsigned long i;
    unsigned long j;
    unsigned long max;                

	to.clear();

    if ( szObj == NULL || nNum <= 0 )
	{
		return to;
	}

    max    = nNum;
    if ( ( nNum % 8 ) != 0 )
    {
        max    += 8 - ( nNum % 8 );
    }
    
    for ( i = 0; i < max; i += 16 )
    {
        SecureZeroMemory(szTemp, sizeof(szTemp));
        SecureZeroMemory(szMsg, sizeof(szMsg));

        StringCchPrintfW(szTemp, BUF_SIZE, L"%5.5x\t", i);
        StringCchCopyW(szMsg, BUF_SIZE, szTemp);
    
        for( j = 0; j < 16; j++ )
        {
            if ( ( j + i ) < nNum )
            {
                SecureZeroMemory(szTemp, sizeof(szTemp));
                StringCchPrintfW(szTemp, BUF_SIZE, L"%.2x ", szObj[ j + i ]);                    

                if ( wcslen( szTemp ) > 3 )
                {
                    szTemp[ 0 ]    = szTemp[ wcslen( szTemp ) - 3 ];
                    szTemp[ 1 ]    = szTemp[ wcslen( szTemp ) - 2 ];
                    szTemp[ 2 ]    = ' ';
                    szTemp[ 3 ]    = '\0';
                }
            }
            else
            {
                SecureZeroMemory(szTemp, sizeof(szTemp));
                StringCchCopyW(szTemp, BUF_SIZE, L"   ");
            }

            StringCchCat(szMsg, BUF_SIZE, szTemp);                    
        }
        
        StringCchCat(szMsg, BUF_SIZE, L" ");
        SecureZeroMemory(szTemp, sizeof(szTemp));

        for( j = 0; j < 16 && ( j + i ) < nNum; j++ )
        {
            if (    ( szObj[ j + i ] > 31 )    &&
                    ( szObj[ j + i ] < 127 )    )
            {
                szTemp[ 0 ]    = szObj[ j + i ];
                szTemp[ 1 ]    = L'\0';
                
                StringCchCat(szMsg, BUF_SIZE, szTemp);
            }
            else
            {                    
                StringCchCat(szMsg, BUF_SIZE, L".");
            }
        }
    
		if (to.length() > 0) to.append(L"\n");
		to.append(szMsg);
    }
    return to;
}

std::wstring AppSecInc::Formatter::FormatTemplate(const std::wstring& buffer, const std::map<std::wstring, std::wstring>& tokens, const std::wstring& left, const std::wstring& right)
{
    std::wstring copy_buffer = buffer;
    FormatterImpl<wchar_t>::FormatTemplate(copy_buffer, tokens, left, right);
    return copy_buffer;
}

std::string AppSecInc::Formatter::FormatTemplate(const std::string& buffer, const std::map<std::string, std::string>& tokens, const std::string& left, const std::string& right)
{
    std::string copy_buffer = buffer;
    FormatterImpl<char>::FormatTemplate(copy_buffer, tokens, left, right);
    return copy_buffer;
}
