#include "StdAfx.h"
#include "LsaPolicy.h"
#include "LsaUnicodeString.h"

using namespace AppSecInc::LSA;
	
LSAPolicy::LSAPolicy() 
    : m_hPolicy(NULL)
{
}

LSAPolicy::~LSAPolicy()
{
    if (IsOpen())
    {
        Close();
    }
}

void LSAPolicy::Close()
{
    CHECK_WIN32_DWORD(LsaNtStatusToWinError(::LsaClose(m_hPolicy)),
        L"Error closing policy object");

    m_hPolicy = NULL;
}

void LSAPolicy::Open(DWORD access)
{
    LSA_OBJECT_ATTRIBUTES attr = { 0 };
    Open(L"", attr, access);
}

void LSAPolicy::Open(const std::wstring& computer_name, LSA_OBJECT_ATTRIBUTES attr, DWORD access)
{
    if (IsOpen())
    {
        Close();
    }

    LSAUnicodeString lsa_computername(computer_name);
    CHECK_WIN32_DWORD(LsaNtStatusToWinError(::LsaOpenPolicy(& lsa_computername, & attr, POLICY_ALL_ACCESS, & m_hPolicy)),
        L"Error opening policy on " << (computer_name.length() ? computer_name : L"local machine"));
}
