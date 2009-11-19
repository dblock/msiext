#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace MSSQL
		{
			//! An authenticated Microsoft SQL Server connection info.
            class MSSQLConnectionInfo : public AppSecInc::Databases::ODBC::ODBCConnectionInfo
			{
			protected:
                //! the database ip address
				std::wstring _ipaddress;
                //! the database port
				int _port;
                //! the connection protocol to use; default is unspecified
                AppSecInc::Databases::ODBC::ODBCConnectionProtocol _protocol;
                //! the name of the database instance
				std::wstring _instancename;
                //! use trusted auth (windows auth)
				bool _trusted_auth;
                //! username
				std::wstring _username;
                //! password
				std::wstring _password;
                //! database name
				std::wstring _database;
                //! application name connecting to the remote database
				std::wstring _appname;
				//! named pipe for the database instance
				std::wstring _namedpipe;
			public:
				//! the default ip address
				static LPCWSTR DEFAULT_IPADDRESS;
				//! an invalid port
				static const int INVALID_PORT = -1;
				//! the default port
				static const int DEFAULT_PORT = 1433;
                //! the default instance name; MSSQLSERVER
				static LPCWSTR DefaultInstanceName;
				//! get the database ip address or host name
				inline const std::wstring& GetIPAddress() const { return _ipaddress; }
				//! set the database ip address or host name
				inline void SetIPAddress(const std::wstring& ipaddress) { _ipaddress = ipaddress; }
				//! get the database port number				
				inline int GetPort() const { return _port; }
				//! set the database port number
				inline void SetPort(int port) { _port = port; }
                //! get the connection protocol: TCP/IP or named pipes
                inline AppSecInc::Databases::ODBC::ODBCConnectionProtocol GetProtocol() const { return _protocol; }
                //! set the connection protocol
                inline void SetProtocol(AppSecInc::Databases::ODBC::ODBCConnectionProtocol protocol) { _protocol = protocol; }
				//! get whether to use trusted auth
				inline bool GetTrustedAuth() const { return _trusted_auth; }
				//! set whether to use trusted auth
				inline void SetTrustedAuth(bool value) { _trusted_auth = value; }
				//! get username
				inline const std::wstring& GetUsername() const { return _username; }
				//! set username
				inline void SetUsername(const std::wstring& username) { _username = username; }
				//! get password
				inline const std::wstring& GetPassword() const { return _password; }
				//! set password
				inline void SetPassword(const std::wstring& password) { _password = password; }
				//! get default database name
				inline const std::wstring& GetDatabase() const { return _database; }
				//! set default database name
				inline void SetDatabase(const std::wstring& database) { _database = database; }
				//! get application name
				inline const std::wstring& GetAppName() const { return _appname; }
				//! set application name
				inline void SetAppName(const std::wstring& value) { _appname = value; }
                //! get the database instance name
				inline const std::wstring& GetInstanceName() const { return _instancename; }
                //! set the database instance name
				inline void SetInstanceName(const std::wstring& instancename) { _instancename = instancename; }
				//! get the instance named pipe value
				inline const std::wstring& GetNamedPipeValue() const { return _namedpipe; }
				//! set the instance named pipe value
				inline void SetNamedPipeValue(const std::wstring& namedpipe) { _namedpipe = namedpipe; }
				//! constructors/destructors
				MSSQLConnectionInfo(const MSSQLConnectionInfo&);
				MSSQLConnectionInfo(
					const std::wstring& ipaddress = DEFAULT_IPADDRESS, 
					int port = DEFAULT_PORT);
				~MSSQLConnectionInfo();
				void operator=(const MSSQLConnectionInfo&);
                //! get the connection string
                std::wstring GetConnectionString() const;
			};
		}
	}
}
