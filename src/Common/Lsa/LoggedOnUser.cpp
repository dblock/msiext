#include "StdAfx.h"
#include "LoggedOnUser.h"

using namespace AppSecInc::LSA;

LoggedOnUser::LoggedOnUser()
    : m_hUser(NULL)
{

}

void LoggedOnUser::Logon(const std::wstring& username, const std::wstring& domain, const std::wstring& password, 
    DWORD dwLogonType, DWORD dwLogonProvider)
{
    if (IsLoggedOn())
    {
        Logout();
    }

    CHECK_WIN32_BOOL(::LogonUserW(username.c_str(), domain.c_str(), password.c_str(), dwLogonType, dwLogonProvider, & m_hUser),
        L"Error logging on " << domain << L"\\" << username);
}

void LoggedOnUser::Logout()
{
    CHECK_BOOL(m_hUser != NULL,
        L"Invalid user handle");

    CHECK_WIN32_BOOL(::CloseHandle(m_hUser),
        L"Error closing user handle");

    m_hUser = NULL;
}

LoggedOnUser::~LoggedOnUser()
{
    if (IsLoggedOn())
    {
        Logout();
    }
}

void LoggedOnUser::Logon(const std::wstring& usernamedomain, const std::wstring& password, 
    DWORD dwLogonType, DWORD dwLogonProvider)
{
    std::wstring domain;
    std::wstring username = usernamedomain;

    // domain\username
    std::vector<std::wstring> username_tokens;
	AppSecInc::StringUtils::tokenize(usernamedomain, username_tokens, L"\\");
    if (username_tokens.size() == 2)
    {
        username = username_tokens[1];
        domain = username_tokens[0];
    }

    // username@domain
	AppSecInc::StringUtils::tokenize(usernamedomain, username_tokens, L"@");
    if (username_tokens.size() == 2)
    {
        username = username_tokens[0];
        domain = username_tokens[1];
    }

    Logon(username, domain, password, dwLogonType, dwLogonProvider);
}

//! note that GetTokenInformation returns a vector of bytes that might contain pointers into itself and hence cannot be copied
void LoggedOnUser::GetTokenInformation(TOKEN_INFORMATION_CLASS token_information_class, std::vector<byte>& token_data) const
{
	CHECK_BOOL(IsLoggedOn(), "Logon required");

    DWORD dwToken = 0;

    CHECK_WIN32_BOOL(! ::GetTokenInformation(m_hUser, token_information_class, NULL, 0, & dwToken),
        L"GetTokenInformation was expected to fail with ERROR_INSUFFICIENT_BUFFER");
    
    DWORD dwError = GetLastError();
    if (dwToken == 0 || dwError != ERROR_INSUFFICIENT_BUFFER)
    {
        CHECK_WIN32_DWORD(dwError,
            L"Error in GetTokenInformation");
    }

    token_data.resize(dwToken);

	CHECK_WIN32_BOOL(::GetTokenInformation(m_hUser, token_information_class, static_cast<LPVOID>(& * token_data.begin()), token_data.size(), & dwToken),
        L"Error in GetTokenInformation");
}

Sid LoggedOnUser::GetSid() const
{
	std::vector<byte> token;
	GetTokenInformation(TokenUser, token);
	TOKEN_USER * p_token = reinterpret_cast<TOKEN_USER *>(& * token.begin());
	Sid sid(p_token->User.Sid, SidTypeUser);
	return sid;
}

std::vector<Privilege> LoggedOnUser::GetPrivileges() const
{
	std::vector<byte> token;
	GetTokenInformation(TokenPrivileges, token);
	TOKEN_PRIVILEGES * p_token = reinterpret_cast<TOKEN_PRIVILEGES *>(& * token.begin());
	std::vector<Privilege> privileges;
	privileges.reserve(p_token->PrivilegeCount);
    for(unsigned int i = 0; i < p_token->PrivilegeCount; i++)
	{
		Privilege priv;
		priv.Luid = p_token->Privileges[i].Luid;
		priv.Attributes = p_token->Privileges[i].Attributes;
		priv.Name = AppSecInc::LSA::Privileges::GetPrivilegeName(p_token->Privileges[i].Luid);
		priv.DisplayName = AppSecInc::LSA::Privileges::GetPrivilegeDisplayName(priv.Name); 
		privileges.push_back(priv);
	}
	return privileges;
}

std::vector<Sid> LoggedOnUser::GetGroups() const
{
	std::vector<byte> token;
	GetTokenInformation(TokenGroups, token);
	TOKEN_GROUPS * p_token = reinterpret_cast<TOKEN_GROUPS *>(& * token.begin());
	std::vector<Sid> groups;
	groups.reserve(p_token->GroupCount);
    for (unsigned int i = 0; i < p_token->GroupCount; i++)
	{
		Sid sid(p_token->Groups[i].Sid);
		groups.push_back(sid);
	}
	return groups;
}

bool LoggedOnUser::HasPrivilege(LUID luid) const
{
	CHECK_BOOL(IsLoggedOn(), "Logon required");
	PRIVILEGE_SET privileges = { 0 };
	privileges.PrivilegeCount = 1;
	privileges.Privilege[0].Luid = luid;
	// privileges.Control = PRIVILEGE_SET_ALL_NECESSARY;
	BOOL hasAny = FALSE;
	CHECK_WIN32_BOOL(::PrivilegeCheck(m_hUser, & privileges, & hasAny),
		"PrivilegeCheck failed");
	return privileges.Privilege[0].Attributes == SE_PRIVILEGE_USED_FOR_ACCESS;
}
