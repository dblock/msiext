#include "StdAfx.h"
#include "AccessConnectionInfo.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::Access;

AccessConnectionInfo::AccessConnectionInfo(
	const std::wstring& dbq)	
	: _dbq(dbq)
{

}

AccessConnectionInfo::AccessConnectionInfo(const AccessConnectionInfo& info)
{
	operator=(info);
}

void AccessConnectionInfo::operator=(const AccessConnectionInfo& info)
{
	_dbq = info._dbq;
	_username = info._username;
	_password = info._password;
}

std::wstring AccessConnectionInfo::GetConnectionString() const
{
	CHECK_BOOL(! _dbq.empty(), L"DBQ has not been set.");

	std::wstringstream connect_string_s;
	connect_string_s << L"Driver={Microsoft Access Driver (*.mdb)};DBQ=" << _dbq << L";";
	
	if (! _username.empty())
	{
		connect_string_s << L"Uid=" << _username << L";Pwd=" << _password << L";";
	}

	return connect_string_s.str();
}

AccessConnectionInfo::~AccessConnectionInfo()
{

}
