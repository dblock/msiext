#include "StdAfx.h"
#include "MSSQLDataFile.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;

MSSQLDataFile::~MSSQLDataFile()
{
}

MSSQLDataFile& MSSQLDataFile::operator=(const MSSQLDataFile& value)
{
    _filename = value._filename;
    _schema = value._schema;
    _table = value._table;
    _database = value._database;
    _parameters = value._parameters;
    return * this;
}

MSSQLDataFile::MSSQLDataFile(const MSSQLDataFile& value)
{
    operator=(value);
}

MSSQLDataFile::MSSQLDataFile()
{

}

std::wostream& AppSecInc::Databases::MSSQL::operator<<(std::wostream& s, const MSSQLDataFile& spec)
{
    s << spec.GetInsertQuery();
    return s;
}

std::wstring MSSQLDataFile::GetInsertQuery() const
{
    CHECK_BOOL(! _table.empty(), L"Missing table");
    CHECK_BOOL(! _filename.empty(), L"Missing filename");

    std::wstringstream result;
    result << "BULK INSERT ";
    if (! _database.empty()) result << L"[" << _database << L"].";
    if (! _schema.empty()) result << L"[" << _schema << L"].";
    result << L"[" << _table << L"] FROM '" << _filename << L"'";
    if (_parameters.size())
    {
        result << L" WITH ( " << AppSecInc::StringUtils::join(_parameters, L", ") << L" )";
    }
    return result.str();
}

void MSSQLDataFile::AddParameter(const std::wstring& name, const std::wstring& value)
{
    AddParameter(name + L" = " + value);
}

MSXML2::IXMLDOMNodePtr MSSQLDataFile::Save(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent) const
{
    MSXML2::IXMLDOMNodePtr root = xmldoc.AppendChild(L"MSSQLDataFile", parent);
    xmldoc.AppendChild(L"Database", root)->text = _bstr_t(_database.c_str());
    xmldoc.AppendChild(L"Schema", root)->text = _bstr_t(_schema.c_str());
    xmldoc.AppendChild(L"Table", root)->text = _bstr_t(_table.c_str());
    xmldoc.AppendChild(L"Filename", root)->text = _bstr_t(_filename.c_str());

    MSXML2::IXMLDOMNodePtr parameters_root = xmldoc.AppendChild(L"MSSQLDataFileParameters", root);
    for each (const std::wstring& parameter in _parameters)        
        xmldoc.AppendChild(L"MSSQLDataFileParameter", parameters_root)->text = _bstr_t(parameter.c_str());

    return root;
}

void MSSQLDataFile::Load(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr root)
{
    _database = xmldoc.SelectNodeValue(L"Database", root, L"");
    _schema = xmldoc.SelectNodeValue(L"Schema", root, L"");
    _table = xmldoc.SelectNodeValue(L"Table", root);
    _filename = xmldoc.SelectNodeValue(L"Filename", root);

    MSXML2::IXMLDOMNodeListPtr parameter_rows = xmldoc.SelectNodes(L"MSSQLDataFileParameters/MSSQLDataFileParameter", root);
    MSXML2::IXMLDOMNodePtr parameter_row = NULL;
    while (NULL != (parameter_row = parameter_rows->nextNode()))
        _parameters.push_back(static_cast<LPCWSTR>(parameter_row->text));
}
