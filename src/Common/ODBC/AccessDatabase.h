#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace Access
		{
			//! A Microsoft SQL Server database.
            class AccessDatabase : public AppSecInc::Databases::ODBC::ODBCDatabase
			{
            private:
                AppSecInc::Databases::ODBC::ODBCConnection _connection;
                std::wstring _connection_string;
                std::wstring _dbq;
                AccessDatabase& operator=(const AccessDatabase&);
            public:
                //! get the database (.mdf file) name
                const std::wstring GetDBQ() const { return _dbq; }
                //! set the database (.mdf file) name
                void SetDBQ(const std::wstring& value) { _dbq = value; }
                //! returns the connection object
                AppSecInc::Databases::ODBC::ODBCConnection& GetConnection() { return _connection; }
                const AppSecInc::Databases::ODBC::ODBCConnection& GetConnection() const { return _connection; }
			public:
				//! constructors/destructors
                AccessDatabase();
                AccessDatabase(const AppSecInc::Databases::ODBC::ODBCConnectionInfo& connectioninfo);
                void Create();
                bool Exists();
                void Connect();
                void Disconnect();
                void Drop();
				~AccessDatabase();
                //! serialize database to xml
                MSXML2::IXMLDOMNodePtr Save(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent) const;
                //! deserialize database from xml
                void Load(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr root);
			};
		}
	}
}
