#include "StdAfx.h"
#include "LocalGroup.h"
#include "Account.h"

using namespace AppSecInc::LSA;

void LocalGroup::Create(const std::wstring& name, const std::wstring& servername)
{
    std::wstring name_l = name;
    GROUP_INFO_1 gi = { 0 };
    gi.grpi1_name = const_cast<LPWSTR>(name_l.c_str());
    Create(gi, servername);
}

void LocalGroup::Create(GROUP_INFO_1 gi, const std::wstring& servername)
{
    CHECK_WIN32_DWORD(::NetLocalGroupAdd(servername.empty() ? NULL : servername.c_str(), 1, reinterpret_cast<LPBYTE>(& gi), NULL),
        L"Error creating group \"" << (servername.empty() ? L"." : servername) << L"\\" << gi.grpi1_name << L"\"");        
}

void LocalGroup::Delete(const std::wstring& name, const std::wstring& servername)
{
    CHECK_WIN32_DWORD(::NetLocalGroupDel(servername.empty() ? NULL : servername.c_str(), name.c_str()),
        L"Error deleting group \"" << (servername.empty() ? L"." : servername) << L"\\" << name << L"\"");        
}

bool LocalGroup::Exists(const std::wstring& name, const std::wstring& servername)
{
    GROUP_INFO_0 * gui = NULL;
    boost::shared_ptr<void> guiPtr(gui, ::LocalFree);
    DWORD rc = ::NetLocalGroupGetInfo(servername.empty() ? NULL : servername.c_str(), name.c_str(), 0, reinterpret_cast<LPBYTE *>(& gui));

    switch(rc)
    {
    case NERR_Success:
        break;
    case NERR_GroupNotFound:
        return false;
    default:
        CHECK_WIN32_DWORD(rc,
            L"Error getting group information for \"" << (servername.empty() ? L"." : servername) << L"\\" << name << L"\"");
    }

    return true;
}

void LocalGroup::AddMember(const std::wstring &groupname, const std::wstring &username, const std::wstring& servername)
{
    LOCALGROUP_MEMBERS_INFO_0 member = { 0 };

    Account acct;
    acct.LookupAccount(username, servername);
    member.lgrmi0_sid = static_cast<PSID>(acct.GetSid());

	CHECK_WIN32_DWORD(::NetLocalGroupAddMembers(servername.empty() ? NULL : servername.c_str(), groupname.c_str(), 0, reinterpret_cast<LPBYTE>(& member), 1),
        L"Error adding \"" << username << L" to group \"" << (servername.empty() ? L"." : servername) << L"\\" << groupname << L"\"");
}

void LocalGroup::DeleteMember(const std::wstring &groupname, const std::wstring &username, const std::wstring& servername)
{
    LOCALGROUP_MEMBERS_INFO_0 member = { 0 };

    Account acct;
    acct.LookupAccount(username, servername);
    member.lgrmi0_sid = (PSID) acct.GetSid();

    CHECK_WIN32_DWORD(::NetLocalGroupDelMembers(servername.empty() ? NULL : servername.c_str(), groupname.c_str(), 0, reinterpret_cast<LPBYTE>(& member), 1),
        L"Error deleting \"" << username << L" from group \"" << (servername.empty() ? L"." : servername) << L"\\" << groupname << L"\"");
}

bool LocalGroup::IsMember(const std::wstring &groupname, const std::wstring &username, const std::wstring& servername)
{
    Account account;
    account.LookupAccount(username, servername);
    std::vector<Account> members = GetMembers(groupname, servername);
    for each(const Account& member in members)
    {
        if (member.GetSid() == account.GetSid())
        {
            return true;
        }
    }
    return false;
}

std::vector<Account> LocalGroup::GetMembers(const std::wstring& groupname, const std::wstring& servername)
{
    std::vector<Account> result;
    DWORD entriesread = 0;
    DWORD totalentries = 0; 
    LOCALGROUP_MEMBERS_INFO_2 * buffer = NULL;
    CHECK_WIN32_DWORD(::NetLocalGroupGetMembers(servername.empty() ? NULL : servername.c_str(), groupname.c_str(), 
        2, reinterpret_cast<LPBYTE *>(& buffer), MAX_PREFERRED_LENGTH, & entriesread, & totalentries, NULL),
        L"Error enumerating members of \"" << (servername.empty() ? L"." : servername) << L"\\" << groupname << L"\"");

    boost::shared_ptr<void> buffer_h(buffer, ::LocalFree);

    for (DWORD i = 0; i < entriesread; i++)
    {
		Sid sid(buffer[i].lgrmi2_sid, buffer[i].lgrmi2_sidusage);
        Account acct;
		acct.SetSID(sid);
		acct.SetFQN(buffer[i].lgrmi2_domainandname);
        result.push_back(acct);
    }

    return result;
}
