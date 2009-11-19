#pragma once

namespace AppSecInc 
{
    namespace LSA
    {
		//! Security identifier: a data structure of variable length that identifies user, group, and computer accounts.
		class Sid
		{
		private:
			SID_NAME_USE m_use;
			std::vector<byte> m_data;
		public:
			//! default constructor
			Sid();
			//! copy a sid
			Sid(const Sid& sid);
			//! copy a sid
			Sid(PSID psid, SID_NAME_USE use = SidTypeInvalid);
			//! convert a string to a sid
			Sid(const std::wstring& sid_string, SID_NAME_USE use = SidTypeInvalid);
			//! copy a sid
			Sid& operator=(const Sid& sid);
			//! copy a sid
			Sid& operator=(PSID psid);
			//! convert a string to a sid
			Sid& operator=(const std::wstring&);
			//! return a string representation of a sid
			std::wstring ToString() const;
			//! return the length of the SID
			DWORD GetLength() const;
			//! return a PSID
			PSID GetPSID() const;
			//! return a PSID
			operator PSID() const { return GetPSID(); }
			//! return the type of sid
			SID_NAME_USE GetUse() const { return m_use; }
			//! set sid
			void Set(PSID psid, SID_NAME_USE use = SidTypeUnknown);
			//! set sid
			void Set(const std::wstring& sid_string, SID_NAME_USE use = SidTypeUnknown);
			//! compare two sids
			bool operator==(const Sid&) const;
			//! compare two sids
			bool operator==(PSID) const;
			//! return true if SID is valid
			bool IsValid() const;
		};
    }
}

