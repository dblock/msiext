#pragma once

#include "Account.h"

namespace AppSecInc 
{
    namespace LSA
    {
        //! A local group
        namespace LocalGroup
        {
            //! create a local group
            void Create(const std::wstring& name, const std::wstring& servername = L"");
            //! create a local group
            void Create(GROUP_INFO_1 gi, const std::wstring& servername = L"");
            //! delete a local group
            void Delete(const std::wstring& name, const std::wstring& servername = L"");
            //! returns true if a local group exists
            bool Exists(const std::wstring& name, const std::wstring& servername = L"");
            //! add a user to the local group
            void AddMember(const std::wstring& groupname, const std::wstring& username, const std::wstring& servername = L"");
            //! add a user to the local group
            void DeleteMember(const std::wstring& groupname, const std::wstring& username, const std::wstring& servername = L"");
            //! check whether the user is a member of a group
            bool IsMember(const std::wstring& groupname, const std::wstring& username, const std::wstring& servername = L"");
            //! get local group members
            std::vector<Account> GetMembers(const std::wstring& groupname, const std::wstring& servername = L"");
        };
    }
}

