#pragma once

namespace AppSecInc 
{
    namespace LSA
    {
        //! A user account
        class Account
        {
        private:
			Sid m_sid;
            std::wstring m_domain;
            std::wstring m_username;
        public:
            Account();
            //! copy
            Account& operator=(const Account&);
            //! lookup an account by name
            void LookupAccount(const std::wstring& account_name, const std::wstring& computer_name = L"");
			//! lookup an account by SID
			void LookupSid(PSID psid, const std::wstring& computer_name = L"");
            //! SID
			const Sid& GetSid() const { return m_sid; }
			//! set SID
			void SetSID(const Sid& sid) { m_sid = sid; }
			//! set FQN (username, domain\\username or username\@domain)
			void SetFQN(const std::wstring& fqn);
			//! fully qualified name
			std::wstring GetFQN() const { return m_domain.empty() ? m_username : m_domain + L"\\" + m_username; }
            //! username
            const std::wstring& GetUserName() const { return m_username; }
            //! computer or domain name
            const std::wstring& GetDomain() const { return m_domain; }
            //! get a list of user rights
			void GetUserRights(std::vector<std::wstring>& rights, const std::wstring& computername = L"") const;
            //! add a user right
            void AddUserRight(const std::wstring& right, const std::wstring& computername = L"");
            //! revoke a user right
            void RemoveUserRight(const std::wstring& right, const std::wstring& computername = L"");
            //! get the current username
            static std::wstring GetCurrentUserName();
            //! get the current username with extended format
            static std::wstring GetCurrentUserName(EXTENDED_NAME_FORMAT format);
            //! create a local user
            static void Create(USER_INFO_1 ui, const std::wstring& servername = L"");
            //! create a local user
            static void Create(const std::wstring& username, const std::wstring& password, const std::wstring& servername = L"");
            //! delete a local user
            static void Delete(const std::wstring& username, const std::wstring& servername = L"");
            //! check whether the user exists
            static bool Exists(const std::wstring& username, const std::wstring& servername = L"");
			//! converts a directory service object name from one format to another
			static std::wstring Translate(const std::wstring& name, EXTENDED_NAME_FORMAT from, EXTENDED_NAME_FORMAT to);
        };
    }
}

