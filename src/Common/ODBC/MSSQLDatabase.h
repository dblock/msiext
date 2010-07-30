#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace MSSQL
		{
			//! A Microsoft SQL Server database.
            class MSSQLDatabase : public AppSecInc::Databases::ODBC::ODBCDatabase
			{
            private:
                std::list<MSSQLDatabaseFileSpec> _filespecs;
                std::list<std::wstring> _database_options;
                std::wstring _database_collate;
                std::wstring _database_purpose;
                AppSecInc::Databases::ODBC::ODBCConnection _connection;
                std::wstring _connection_string;
                std::wstring _database_name;
                MSSQLDatabase& operator=(const MSSQLDatabase&);
            public:
                //! get the database name
                const std::wstring GetName() const { return _database_name; }
                //! set the database name
                void SetName(const std::wstring& value) { _database_name = value; }
                //! get the database collate
                const std::wstring GetCollate() const { return _database_collate; }
                //! set the database collate
                void SetCollate(const std::wstring& value) { _database_collate = value; }
                //! get the database purpose, eg. ATTACH or ATTACH_REBUILD_LOG
                const std::wstring GetPurpose() const { return _database_purpose; }
                //! set the database for
                void SetPurpose(const std::wstring& value) { _database_purpose = value; }
                //! get the database file specs
                const std::list<MSSQLDatabaseFileSpec>& GetFileSpecs() const { return _filespecs; }
                //! add a database file spec
                void AddFileSpec(const MSSQLDatabaseFileSpec& value) { _filespecs.push_back(value); }
                //! get the database with options
                const std::list<std::wstring>& GetOptions() const { return _database_options; }
                //! add a database file spec
                void AddOption(const std::wstring& value) { _database_options.push_back(value); }
                //! returns the connection object
                AppSecInc::Databases::ODBC::ODBCConnection& GetConnection() { return _connection; }
                const AppSecInc::Databases::ODBC::ODBCConnection& GetConnection() const { return _connection; }
			public:
				//! constructors/destructors
                MSSQLDatabase();
                MSSQLDatabase(const AppSecInc::Databases::ODBC::ODBCConnectionInfo& connectioninfo);
                void Create();
                bool Exists();
                void Connect();
                void Disconnect();
                void Drop();
                void CreateIfNotExists();
                void DropIfExists();
				~MSSQLDatabase();
                std::wstring GetCreateQuery() const;
				std::vector<std::wstring> GetOptionQueries() const;
                std::wstring GetDropQuery() const;
                std::wstring GetExistsQuery() const;
                std::wstring GetNotExistsQuery() const;
                //! serialize database to xml
                MSXML2::IXMLDOMNodePtr Save(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent) const;
                //! deserialize database from xml
                void Load(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr root);
			};
		}
	}
}
