#include "StdAfx.h"
#include "MSSQLDatabaseFileSpec.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;

MSSQLDatabaseFileSpec::~MSSQLDatabaseFileSpec()
{
}

MSSQLDatabaseFileSpec& MSSQLDatabaseFileSpec::operator=(const MSSQLDatabaseFileSpec& value)
{
    _type = value._type;
    _size = value._size;
    _maxsize = value._maxsize;
    _growthsize = value._growthsize;
    _filename = value._filename;
    _name = value._name;
    return * this;
}

MSSQLDatabaseFileSpec::MSSQLDatabaseFileSpec(const MSSQLDatabaseFileSpec& value)
{
    operator=(value);
}

MSSQLDatabaseFileSpec::MSSQLDatabaseFileSpec()
{

}

std::wostream& AppSecInc::Databases::MSSQL::operator<<(std::wostream& s, const MSSQLDatabaseFileSpec& spec)
{
    s << spec.GetCreateQuery();
    return s;
}

std::wstring MSSQLDatabaseFileSpec::GetCreateQuery() const
{
    std::vector<std::wstring> parameters;
    if (! _name.empty()) parameters.push_back(L"NAME = [" +_name + L"]");
    if (! _filename.empty()) parameters.push_back(L"FILENAME = '" + _filename + L"'");
    if (! _size.empty()) parameters.push_back(L"SIZE = " + _size);
    if (! _maxsize.empty()) parameters.push_back(L"MAXSIZE = " + _maxsize);
    if (! _growthsize.empty()) parameters.push_back(L"FILEGROWTH = " + _growthsize);

    if (parameters.empty()) return L"";

    std::wstring result;
    if (! _type.empty()) result.append(_type + L" ");
    result.append(L"( " + AppSecInc::StringUtils::join(parameters, L", ") + L" )");
    return result;
}

MSXML2::IXMLDOMNodePtr MSSQLDatabaseFileSpec::Save(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent) const
{
    MSXML2::IXMLDOMNodePtr root = xmldoc.AppendChild(L"MSSQLDatabaseFileSpec", parent);
    xmldoc.AppendChild(L"Name", root)->text = _bstr_t(_name.c_str());
    xmldoc.AppendChild(L"Filename", root)->text = _bstr_t(_filename.c_str());
    xmldoc.AppendChild(L"Type", root)->text = _bstr_t(_type.c_str());
    xmldoc.AppendChild(L"Size", root)->text = _bstr_t(_size.c_str());
    xmldoc.AppendChild(L"MaxSize", root)->text = _bstr_t(_maxsize.c_str());
    xmldoc.AppendChild(L"GrowthSize", root)->text = _bstr_t(_growthsize.c_str());
    return root;
}

void MSSQLDatabaseFileSpec::Load(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr root)
{
    _name = xmldoc.GetNodeValue(L"Name", root);
    _filename = xmldoc.GetNodeValue(L"Filename", root);
    _type = xmldoc.GetNodeValue(L"Type", root, L"");
    _size = xmldoc.GetNodeValue(L"Size", root, L"");
    _maxsize = xmldoc.GetNodeValue(L"MaxSize", root, L"");
    _growthsize = xmldoc.GetNodeValue(L"GrowthSize", root, L"");
}
