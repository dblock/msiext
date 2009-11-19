#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace MSSQL
		{
			//! A Microsoft SQL Server database file specification.
            class MSSQLDataFile
			{
            private:
                std::wstring _database;
                std::wstring _schema;
                std::wstring _table;
                std::wstring _filename;
                std::list<std::wstring> _parameters;
            public:
                //! get the database name
                const std::wstring& GetDatabase() const { return _database; }
                void SetDatabase(const std::wstring& value) { _database = value; }
                //! the schema name
                const std::wstring& GetSchema() const { return _schema; }
                void SetSchema(const std::wstring& value) { _schema = value; }
                //! the operating-system file name for the database file
                const std::wstring& GetTable() const { return _table; }
                void SetTable(const std::wstring& value) { _table = value; }
                //! the name of the data file
                const std::wstring& GetFilename() const { return _filename; }
                void SetFilename(const std::wstring& value) { _filename = value; }
                //! get the parameters
                const std::list<std::wstring>& GetParameters() const { return _parameters; }
                //! add a data file option
                void AddParameter(const std::wstring& value) { _parameters.push_back(value); }
                void AddParameter(const std::wstring& name, const std::wstring& value);
			public:
                std::wstring GetInsertQuery() const;
                friend std::wostream& operator<<(std::wostream&, const MSSQLDataFile&);
                //! copy constructor and operator=
                MSSQLDataFile& operator=(const MSSQLDataFile&);
				//! constructors/destructors
                MSSQLDataFile();
                MSSQLDataFile(const MSSQLDataFile&);
				~MSSQLDataFile();
                //! serialize the data file spec to xml
                MSXML2::IXMLDOMNodePtr Save(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent) const;
                //! deserialize the data file spec from xml
                void Load(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr root);
			};
		}
	}
}
