#pragma once

namespace AppSecInc 
{
    namespace LSA
    {
        //! A logged-on user
        class LoggedOnUser
        {
        protected:
            HANDLE m_hUser;
		private:
			//! return token information for a given class
			void GetTokenInformation(TOKEN_INFORMATION_CLASS, std::vector<byte>&) const;
        public:
            LoggedOnUser();
            virtual ~LoggedOnUser();
            //! logon a user
            void Logon(const std::wstring& username, const std::wstring& domain, const std::wstring& password,
                DWORD dwLogonType, DWORD dwLogonProvider = LOGON32_PROVIDER_DEFAULT);
            //! logon a user, supports various username syntaxes; supports domain\\username and username\@domain
            void Logon(const std::wstring& username, const std::wstring& password,
                DWORD dwLogonType, DWORD dwLogonProvider = LOGON32_PROVIDER_DEFAULT);
            //! logout a user
            void Logout();
            //! returns true on logon
            bool IsLoggedOn() const { return m_hUser != NULL; }
			//! returns the user SID
			Sid GetSid() const;
			//! returns the user group memberships (SIDs)
			std::vector<Sid> GetGroups() const;
			//! returns a set of privileges that the logged on user has
			std::vector<Privilege> GetPrivileges() const;
			//! return true if the user holds a specific privilege
			bool HasPrivilege(LUID luid) const;
        };
    }
}

