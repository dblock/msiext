#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace Access
		{
			//! An authenticated Microsoft SQL Server connection info.
            class AccessConnectionInfo : public AppSecInc::Databases::ODBC::ODBCConnectionInfo
			{
			protected:
                //! the database ip address
				std::wstring _dbq;
                //! username
				std::wstring _username;
                //! password
				std::wstring _password;
			public:
				//! get username
				inline const std::wstring& GetUsername() const { return _username; }
				//! set username
				inline void SetUsername(const std::wstring& username) { _username = username; }
				//! get password
				inline const std::wstring& GetPassword() const { return _password; }
				//! set password
				inline void SetPassword(const std::wstring& password) { _password = password; }
				//! get database (.mdf file) name
				inline const std::wstring& GetDBQ() const { return _dbq; }
				//! set database (.mdf file) name
				inline void SetDBQ(const std::wstring& dbq) { _dbq = dbq; }
				//! constructors/destructors
				AccessConnectionInfo(const AccessConnectionInfo&);
				AccessConnectionInfo(const std::wstring& dbq = L"");
				~AccessConnectionInfo();
				void operator=(const AccessConnectionInfo&);
                //! get the connection string
                std::wstring GetConnectionString() const;
			};
		}
	}
}
