#include "StdAfx.h"
#include "Account.h"
#include "LSAUnicodeString.h"
#include "LSAPolicy.h"

using namespace AppSecInc::LSA;

Account::Account()
{

}

Account& Account::operator=(const Account& rhs)
{
    m_sid = rhs.m_sid;
    m_domain = rhs.m_domain;
    m_username = rhs.m_username;
    return * this;
}

void Account::SetFQN(const std::wstring& username)
{
	m_username = username;

	std::wstring::size_type cut = std::wstring::npos;

	if ((cut = username.find(L"\\")) != std::wstring::npos)
	{
		m_domain = username.substr(0, cut);
		m_username = username.substr(cut + 1, username.length()); 
	}
	else if ((cut = username.find(L"@")) != std::wstring::npos)
	{
		m_username = username.substr(0, cut);
		m_domain = username.substr(cut + 1, username.length()); 
	}
}

void Account::LookupAccount(const std::wstring& account_name, const std::wstring& computer_name)
{
    DWORD dwSid = 0;
    DWORD dwDomain = 0;
	SID_NAME_USE peUse = SidTypeUnknown;

    CHECK_WIN32_BOOL(! ::LookupAccountName(computer_name.c_str(), account_name.c_str(), NULL, & dwSid, NULL, & dwDomain, & peUse),
        L"Account name lookup was expected to fail with ERROR_INSUFFICIENT_BUFFER");
    
    DWORD dwError = GetLastError();
    if (dwSid == 0 || dwError != ERROR_INSUFFICIENT_BUFFER)
    {
        CHECK_WIN32_DWORD(dwError,
            L"Error searching for " << computer_name << L"\\" << account_name);
    }

	std::vector<byte> sid;
    sid.resize(dwSid);
    m_domain.resize(dwDomain + 1);

    CHECK_WIN32_BOOL(LookupAccountName(computer_name.c_str(), account_name.c_str(), static_cast<PSID>(& * sid.begin()), & dwSid, & * m_domain.begin(), & dwDomain, & peUse),
        L"Error searching for " << computer_name << L"\\" << account_name);

	m_sid.Set(static_cast<PSID>(& * sid.begin()), peUse);
    m_domain.resize(dwDomain);
    m_username = account_name;
}

void Account::GetUserRights(std::vector<std::wstring>& rights, const std::wstring& computername) const
{
    LSAUnicodeString userRights;
    PLSA_UNICODE_STRING puserRights = & userRights;
    ULONG count = 0;

    LSAPolicy policy;
    LSA_OBJECT_ATTRIBUTES attr = { 0 };
    policy.Open(computername, attr, POLICY_LOOKUP_NAMES);

    DWORD dwError = LsaNtStatusToWinError(LsaEnumerateAccountRights(
		policy.GetHandle(), static_cast<PSID>(m_sid), & puserRights, & count));

    switch(dwError)
    {
    case ERROR_SUCCESS:
        break;
    case ERROR_FILE_NOT_FOUND:
        // user has no privileges, hide the File Not Found error
        rights.clear();
        return;
    default:
	    CHECK_WIN32_DWORD(dwError,
            L"Error enumerating policy rights");
        break;
    };

    rights.clear();

	for (UINT i = 0; i < count; ++ i)
	{									
		rights.push_back(puserRights[i].Buffer);
	}
}

void Account::AddUserRight(const std::wstring& right, const std::wstring& computername)
{
    AppSecInc::LSA::LSAUnicodeString right_s(right);
 
    LSAPolicy policy;
    LSA_OBJECT_ATTRIBUTES attr = { 0 };
    policy.Open(computername, attr, POLICY_LOOKUP_NAMES | POLICY_CREATE_ACCOUNT);

    CHECK_WIN32_DWORD(LsaNtStatusToWinError(LsaAddAccountRights(policy.GetHandle(), static_cast<PSID>(m_sid), & right_s, 1)),
        L"Error adding " << right << L" right");
}

void Account::RemoveUserRight(const std::wstring& right, const std::wstring& computername)
{
    AppSecInc::LSA::LSAUnicodeString right_s(right);
 
    LSAPolicy policy;
    LSA_OBJECT_ATTRIBUTES attr = { 0 };
    policy.Open(computername, attr, POLICY_ALL_ACCESS); // \todo: change to a lower policy security flag

    CHECK_WIN32_DWORD(LsaNtStatusToWinError(LsaRemoveAccountRights(policy.GetHandle(), static_cast<PSID>(m_sid), false, & right_s, 1)),
        L"Error adding " << right << L" right");
}

std::wstring Account::GetCurrentUserName()
{
    wchar_t username[256];
    DWORD dwBuffer = sizeof(username);
    CHECK_WIN32_BOOL(::GetUserNameW(username, & dwBuffer),
        L"Error in GetUserName");
    return username;
}

std::wstring Account::GetCurrentUserName(EXTENDED_NAME_FORMAT format)
{
    DWORD dwBuffer = 0;
	::GetUserNameExW(format, NULL, & dwBuffer);
	std::vector<wchar_t> buffer;
	CHECK_WIN32_BOOL(dwBuffer > 0, L"GetUserNameExW failed");
	buffer.resize(dwBuffer);
    CHECK_WIN32_BOOL(::GetUserNameExW(format, & * buffer.begin(), & dwBuffer),
        L"Error in GetUserName");
	std::wstring result = & * buffer.begin();
	return result;
}

void Account::Create(USER_INFO_1 ui, const std::wstring& servername)
{
    CHECK_WIN32_DWORD(::NetUserAdd(servername.empty() ? NULL : servername.c_str(), 1, reinterpret_cast<LPBYTE>(& ui), NULL),
        L"Error creating user \"" << (servername.empty() ? L"." : servername) << L"\\" << ui.usri1_name << L"\"");
}

void Account::Create(const std::wstring& username, const std::wstring& password, const std::wstring& servername)
{
    std::wstring username_l = username;
    std::wstring password_l = password;

    USER_INFO_1 ui = { 0 };
    ui.usri1_name = const_cast<LPWSTR>(username_l.c_str());
    ui.usri1_password = const_cast<LPWSTR>(password_l.c_str());
    ui.usri1_priv = USER_PRIV_USER;
    Create(ui, servername);
}

void Account::Delete(const std::wstring& username, const std::wstring& servername)
{
    CHECK_WIN32_DWORD(::NetUserDel(servername.empty() ? NULL : servername.c_str(), username.c_str()),
        L"Error deleting user \"" << (servername.empty() ? L"." : servername) << L"\\" << username << L"\"");
}

bool Account::Exists(const std::wstring& username, const std::wstring& servername)
{
    USER_INFO_1 * pui = NULL;
    boost::shared_ptr<void> puiPtr(pui, ::LocalFree);
    DWORD rc = ::NetUserGetInfo(servername.empty() ? NULL : servername.c_str(), username.c_str(), 1, reinterpret_cast<LPBYTE *>(& pui));

    switch(rc)
    {
    case NERR_Success:
        break;
    case NERR_UserNotFound:
        return false;
    default:
        CHECK_WIN32_DWORD(rc,
            L"Error getting user information for \"" << (servername.empty() ? L"." : servername) << L"\\" << username << L"\"");
    }

    return true;
}

std::wstring Account::Translate(const std::wstring& name, EXTENDED_NAME_FORMAT from, EXTENDED_NAME_FORMAT to)
{
	ULONG ulSize = 0;
	
	CHECK_WIN32_BOOL(::TranslateName(name.c_str(), from, to, NULL, & ulSize),
		L"Error translating \"" << name << L"\" from format " << from << L" to " << to << L", error fetching result size");

	CHECK_BOOL(ulSize > 0,
		L"Error translating \"" << name << L"\" from format " << from << L" to " << to << L", invalid size");

	std::wstring translated_name;
	translated_name.resize(ulSize);

	CHECK_WIN32_BOOL(::TranslateName(name.c_str(), from, to, & * translated_name.begin(), & ulSize),
		L"Error translating \"" << name << L"\" from format " << from << L" to " << to);

	// ulSize counts the null-terminator
	translated_name.resize(ulSize - 1);
	return translated_name;
}

void Account::LookupSid(PSID psid, const std::wstring& computer_name)
{
    DWORD dwName = 0;
    DWORD dwDomain = 0;
	SID_NAME_USE peUse = SidTypeUnknown;

	CHECK_WIN32_BOOL(! ::LookupAccountSid(computer_name.c_str(), psid, NULL, & dwName, NULL, & dwDomain, & peUse),
        L"Account name lookup was expected to fail with ERROR_INSUFFICIENT_BUFFER");
    
    DWORD dwError = GetLastError();
    if (dwName == 0 || dwError != ERROR_INSUFFICIENT_BUFFER)
    {
        CHECK_WIN32_DWORD(dwError,
			L"Error searching for " << computer_name << L"\\" << Sid(psid).ToString());
    }

    m_domain.resize(dwDomain + 1);
	m_username.resize(dwName + 1);

    CHECK_WIN32_BOOL(LookupAccountSid(computer_name.c_str(), psid, & * m_username.begin(), & dwName, & * m_domain.begin(), & dwDomain, & peUse),
        L"Error searching for " << computer_name << L"\\" << Sid(psid).ToString());

    m_domain.resize(dwDomain);
    m_username.resize(dwName);
	m_sid.Set(psid, peUse);
}