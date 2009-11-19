#pragma once

namespace AppSecInc {
namespace LSA {
	
/*! 
	\class LSAUnicodeString
	\brief Local storage for an LSA Unicode String. This is only used as an IN string to LSA functions.
*/
class LSAUnicodeString
{
private:
	std::wstring m_s;
	LSA_UNICODE_STRING m_us;
	LSAUnicodeString(const LSAUnicodeString& ) { };
	LSAUnicodeString& operator= (const LSAUnicodeString& ) { };
public:
	LSAUnicodeString();
	LSAUnicodeString(LPCWSTR lpwz);
	LSAUnicodeString(const std::wstring& w);
	LSAUnicodeString& operator=(LPCWSTR lpwz);
	LSAUnicodeString& operator=(const std::wstring& s);
	PLSA_UNICODE_STRING operator& () { return & m_us; }
	const LSA_UNICODE_STRING& operator() () const { return m_us; }
	int Length() const { return m_us.Length; }
	int MaximumLength() const { return m_us.MaximumLength; }
};

}}

