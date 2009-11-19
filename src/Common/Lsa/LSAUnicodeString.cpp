#include "StdAfx.h"
#include "LsaUnicodeString.h"

using namespace AppSecInc::LSA;
	
LSAUnicodeString::LSAUnicodeString(void) 
{
	ZeroMemory(& m_us, sizeof(LSA_UNICODE_STRING));		
}

LSAUnicodeString::LSAUnicodeString(LPCWSTR lpwz)
{
	operator=(lpwz);
}

LSAUnicodeString::LSAUnicodeString(const std::wstring& w)
{
	operator=(w);
}

LSAUnicodeString& LSAUnicodeString::operator=(LPCWSTR lpwz)
{
	return operator=(std::wstring(lpwz));
}

LSAUnicodeString& LSAUnicodeString::operator=(const std::wstring& s)
{
	m_s = s;
	if (m_s.length() > 0)
	{
		m_us.Buffer = & * m_s.begin();
		m_us.Length = m_s.length() * sizeof( WCHAR );
		m_us.MaximumLength = m_s.size() * sizeof( WCHAR );
	}
	else
	{
		ZeroMemory(& m_us, sizeof(LSA_UNICODE_STRING));
	}
	return * this;
}
