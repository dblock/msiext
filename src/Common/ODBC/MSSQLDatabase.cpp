#include "StdAfx.h"
#include "MSSQLDatabase.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;

MSSQLDatabase::MSSQLDatabase()
{
}

MSSQLDatabase& MSSQLDatabase::operator=(const MSSQLDatabase&)
{
    throw std::exception("private method not implemented");
}

MSSQLDatabase::MSSQLDatabase(const AppSecInc::Databases::ODBC::ODBCConnectionInfo& connection_info) 
    : _connection_string(connection_info.GetConnectionString())
{
}

MSSQLDatabase::~MSSQLDatabase()
{
}

std::vector<std::wstring> MSSQLDatabase::GetOptionQueries() const
{
	std::vector<std::wstring> options;
	for each(const std::wstring& database_option in _database_options)
	{
		std::wstringstream query;
		query << L"ALTER DATABASE [" << _database_name << "] SET " << database_option;
		options.push_back(query.str());
	}
	return options;
}

std::wstring MSSQLDatabase::GetCreateQuery() const
{
    std::wstringstream query;
    query << L"CREATE DATABASE [" << _database_name << "]";

    if (_filespecs.size() > 0)
    {
        query << L" ON";

        int filespec_count = 0;
        for each (const MSSQLDatabaseFileSpec& filespec in _filespecs)
        {
            if (filespec_count > 0 && filespec.GetType().empty()) query << L",";
            query << std::endl << L" " << filespec;
            filespec_count++;
        }
    }

    if (! _database_collate.empty())
    {
        query << std::endl << L"COLLATE " << _database_collate;
    }

    if (! _database_purpose.empty())
    {
        query << std::endl << L"FOR " << _database_purpose;
    }

    return query.str();
}

std::wstring MSSQLDatabase::GetDropQuery() const
{
    std::wstringstream query;
    query << L"DROP DATABASE [" << _database_name << "]";
    return query.str();
}

std::wstring MSSQLDatabase::GetExistsQuery() const
{
    std::wstringstream query;
    query << L"IF db_id('" << _database_name << "') IS NOT NULL";
    return query.str();
}

std::wstring MSSQLDatabase::GetNotExistsQuery() const
{
    std::wstringstream query;
	query << L"IF db_id('" << _database_name << "') IS NULL";
    return query.str();
}

void MSSQLDatabase::Create()
{
    _connection.Execute(GetCreateQuery());
	for each (const std::wstring& option in GetOptionQueries())
	{
		_connection.Execute(option);
	}
}

bool MSSQLDatabase::Exists()
{
    std::wstringstream query;
    query << GetExistsQuery() << L" SELECT 'true' ELSE SELECT 'false'";
    return _connection.GetWString(query.str()) == L"true";
}

void MSSQLDatabase::Drop()
{
    _connection.Execute(GetDropQuery());
}

void MSSQLDatabase::Connect()
{
    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection_info(_connection_string);
    _connection.Connect(connection_info);
}

void MSSQLDatabase::Disconnect()
{
    _connection.Disconnect();
}

void MSSQLDatabase::CreateIfNotExists()
{
    std::wstringstream query;
    query << GetNotExistsQuery() << L" " << GetCreateQuery();
    _connection.Execute(query.str());
}

void MSSQLDatabase::DropIfExists()
{
    std::wstringstream query;
    query << GetExistsQuery() << L" " << GetDropQuery();
    _connection.Execute(query.str());
}

MSXML2::IXMLDOMNodePtr MSSQLDatabase::Save(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent) const
{
    MSXML2::IXMLDOMNodePtr root = xmldoc.AppendChild(L"MSSQLDatabase", parent);
    xmldoc.AppendChild(L"Name", root)->text = _bstr_t(_database_name.c_str());
    xmldoc.AppendChild(L"Collate", root)->text = _bstr_t(_database_collate.c_str());
    xmldoc.AppendChild(L"Purpose", root)->text = _bstr_t(_database_purpose.c_str());
    xmldoc.AppendChild(L"ConnectionString", root)->text = _bstr_t(AppSecInc::Crypt::DPAPIImpl::Protect(_connection_string).c_str());

    MSXML2::IXMLDOMNodePtr options_root = xmldoc.AppendChild(L"MSSQLDatabaseOptions", root);
    for each (const std::wstring& option in _database_options)        
        xmldoc.AppendChild(L"MSSQLDatabaseOption", options_root)->text = _bstr_t(option.c_str());

    MSXML2::IXMLDOMNodePtr filespecs_root = xmldoc.AppendChild(L"MSSQLDatabaseFileSpecs", root);
    for each (const MSSQLDatabaseFileSpec& spec in _filespecs)
        spec.Save(xmldoc, filespecs_root);

    return root;
}

void MSSQLDatabase::Load(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr root)
{
    _database_options.clear();
    _filespecs.clear();

    _database_name = xmldoc.GetNodeValue(L"Name", root);
    _database_collate = xmldoc.GetNodeValue(L"Collate", root, L"");
    _database_purpose = xmldoc.GetNodeValue(L"Purpose", root, L"");
    _connection_string = AppSecInc::Crypt::DPAPIImpl::UnProtect(xmldoc.GetNodeValue(L"ConnectionString", root, L""));

    MSXML2::IXMLDOMNodeListPtr option_rows = xmldoc.SelectNodes(L"MSSQLDatabaseOptions/MSSQLDatabaseOption", root);
    MSXML2::IXMLDOMNodePtr option_row = NULL;
    while (NULL != (option_row = option_rows->nextNode()))
        _database_options.push_back(static_cast<LPCWSTR>(option_row->text));
    
    MSXML2::IXMLDOMNodeListPtr filespecs_rows = xmldoc.SelectNodes(L"MSSQLDatabaseFileSpecs/MSSQLDatabaseFileSpec", root);
    MSXML2::IXMLDOMNodePtr filespecs_row = NULL;
    while (NULL != (filespecs_row = filespecs_rows->nextNode()))
    {
        MSSQLDatabaseFileSpec spec;
        spec.Load(xmldoc, filespecs_row);
        _filespecs.push_back(spec);
    }
}
