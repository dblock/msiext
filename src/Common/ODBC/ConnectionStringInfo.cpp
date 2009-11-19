#include "StdAfx.h"
#include "ConnectionStringInfo.h"

using namespace AppSecInc::Databases::ODBC;

ODBCConnectionStringInfo::ODBCConnectionStringInfo(const std::wstring& cs)
    : m_cs(cs)
{

}

ODBCConnectionStringInfo::~ODBCConnectionStringInfo()
{

}
