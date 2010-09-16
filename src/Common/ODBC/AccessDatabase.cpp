#include "StdAfx.h"
#include "AccessDatabase.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::Access;

AccessDatabase::AccessDatabase()
{
}

AccessDatabase& AccessDatabase::operator=(const AccessDatabase&)
{
    throw std::exception("private method not implemented");
}

AccessDatabase::AccessDatabase(const AppSecInc::Databases::ODBC::ODBCConnectionInfo& connection_info) 
    : _connection_string(connection_info.GetConnectionString())
{
}

AccessDatabase::~AccessDatabase()
{
}

void AccessDatabase::Create()
{
    CHECK_BOOL(! _dbq.empty(), L"Missing DBQ");
    // http://support.microsoft.com/kb/126606
    ODBCDataSource::Configure(ODBC_ADD_DSN, L"Microsoft Access Driver (*.mdb)", L"CREATE_DB=\"" + _dbq + L"\" General;");
}

bool AccessDatabase::Exists()
{
    CHECK_BOOL(! _dbq.empty(), L"Missing DBQ");
    return AppSecInc::File::FileExists(_dbq);
}

void AccessDatabase::Drop()
{
    CHECK_BOOL(! _dbq.empty(), L"Missing DBQ");
    AppSecInc::File::FileDelete(_dbq);
}

void AccessDatabase::Connect()
{
    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection_info(_connection_string);
    _connection.Connect(connection_info);
}

void AccessDatabase::Disconnect()
{
    _connection.Disconnect();
}

MSXML2::IXMLDOMNodePtr AccessDatabase::Save(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent) const
{
    MSXML2::IXMLDOMNodePtr root = xmldoc.AppendChild(L"AccessDatabase", parent);
    xmldoc.AppendChild(L"DBQ", root)->text = _bstr_t(_dbq.c_str());
    xmldoc.AppendChild(L"ConnectionString", root)->text = _bstr_t(AppSecInc::Crypt::DPAPIImpl::Protect(_connection_string).c_str());
    return root;
}

void AccessDatabase::Load(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr root)
{
    _dbq = xmldoc.GetNodeValue(L"DBQ", root);
    _connection_string = AppSecInc::Crypt::DPAPIImpl::UnProtect(xmldoc.GetNodeValue(L"ConnectionString", root, L""));
}
