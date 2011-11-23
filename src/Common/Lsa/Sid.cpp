#include "StdAfx.h"
#include "Sid.h"

using namespace AppSecInc::LSA;

Sid::Sid()
	: m_use(SidTypeUnknown)
{

}

Sid::Sid(PSID psid, SID_NAME_USE use)
{
	Set(psid, use);
}

Sid::Sid(const Sid& sid)
{
	Set(sid.GetPSID(), sid.GetUse());
}

Sid::Sid(const std::wstring& sid_string, SID_NAME_USE use)
{
	Set(sid_string, use);
}

Sid& Sid::operator=(const Sid& sid)
{
	Set(sid.GetPSID(), sid.GetUse());
	return * this;
}

Sid& Sid::operator=(PSID psid)
{
	Set(psid, SidTypeUnknown);
	return * this;
}

Sid& Sid::operator=(const std::wstring& sid_string)
{
	Set(sid_string, SidTypeUnknown);
	return * this;
}

void Sid::Set(const std::wstring& sid_string, SID_NAME_USE use)
{
	PSID psid = NULL;
    boost::shared_ptr<void> psidPtr(psid, ::LocalFree);
	CHECK_WIN32_BOOL(::ConvertStringSidToSid(sid_string.c_str(), & psid),
		L"Error in ConvertStringSidToSid");
	Set(psid, use);
}

std::wstring Sid::ToString() const
{
	LPWSTR buffer = NULL;
    boost::shared_ptr<void> bufferPtr(buffer, ::LocalFree);
    CHECK_WIN32_BOOL(::ConvertSidToStringSid(GetPSID(), & buffer),
        L"Error in ConvertSidToStringSid");
	return buffer;
}

std::wstring Sid::ToHexString() const
{
	CHECK_BOOL(IsValid(), L"Invalid sid");

    std::wstringstream ss(std::wstringstream::out);
	ss << L"0x";
	ss.flags (std::ios::right| std::ios::hex | std::ios::uppercase);
	ss.fill('0');
	std::vector<byte>::const_iterator it;
	for (it = m_data.begin(); it != m_data.end(); it++)
	{
		ss.width(2);
		ss << *it;
	}

	return ss.str();
}

void Sid::Set(PSID psid, SID_NAME_USE use)
{
	CHECK_BOOL(NULL != psid, L"Missing sid");
	CHECK_BOOL(::IsValidSid(psid), L"Invalid sid");
	m_data.resize(::GetLengthSid(psid));
	CHECK_WIN32_BOOL(::CopySid(m_data.size(), static_cast<PSID>(& * m_data.begin()), psid),
		L"Error copying SID");
	m_use = use;
}

DWORD Sid::GetLength() const 
{ 
	// if the SID structure is not valid, the return value of ::GetLengthSid is undefined
	CHECK_BOOL(IsValid(), L"Invalid sid");
	return ::GetLengthSid(GetPSID());
}

PSID Sid::GetPSID() const
{
	CHECK_BOOL(IsValid(), L"Invalid sid");
	return (PSID) & * m_data.begin();
}

bool Sid::operator==(const Sid& sid) const
{
	CHECK_BOOL(IsValid(), L"Invalid sid");
	return ::EqualSid(GetPSID(), sid.GetPSID()) ? true : false;
}

bool Sid::operator==(PSID psid) const
{
	CHECK_BOOL(IsValid(), L"Invalid source sid");
	CHECK_BOOL(::IsValidSid(psid), L"Invalid target sid");
	return ::EqualSid(GetPSID(), psid) ? true : false;
}

bool Sid::IsValid() const
{
	CHECK_BOOL(m_data.size() > 0, L"Missing sid");
	return ::IsValidSid(reinterpret_cast<PSID>(const_cast<byte *>(& * m_data.begin()))) ? true : false;
}