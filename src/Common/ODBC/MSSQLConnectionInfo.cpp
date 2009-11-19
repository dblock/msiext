#include "StdAfx.h"
#include "MSSQLConnectionInfo.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;

LPCWSTR MSSQLConnectionInfo::DEFAULT_IPADDRESS = L"localhost";
LPCWSTR MSSQLConnectionInfo::DefaultInstanceName = L"MSSQLSERVER";

MSSQLConnectionInfo::MSSQLConnectionInfo(
	const std::wstring& ipaddress, 
	int port)	
	: _ipaddress(ipaddress)
	, _port(port)
	, _protocol(ODBC_CONNECTION_UNSPECIFIED)
	, _trusted_auth(TRUE)
{

}

MSSQLConnectionInfo::MSSQLConnectionInfo(const MSSQLConnectionInfo& info)
{
	operator=(info);
}

void MSSQLConnectionInfo::operator=(const MSSQLConnectionInfo& info)
{
	_ipaddress = info._ipaddress;
	_port = info._port;
	_protocol = info._protocol;
	_trusted_auth = info._trusted_auth;
	_username = info._username;
	_password = info._password;
	_database = info._database;
	_namedpipe = info._namedpipe;
	_appname = info._appname;
	_instancename = info._instancename;
}

std::wstring MSSQLConnectionInfo::GetConnectionString() const
{
	CHECK_BOOL(_ipaddress.length() > 0, L"IP address has not been set.");
	CHECK_BOOL(_port != INVALID_PORT, L"Port number has not been set.");

	std::wstringstream connect_string_s;
	connect_string_s << L"Driver={SQL Server};Server=";
	
	switch(_protocol)
	{
	case ODBC_CONNECTION_UNSPECIFIED:
		break;
	case ODBC_CONNECTION_TCPIP:
		connect_string_s << L"tcp:";
		break;
	case ODBC_CONNECTION_NAMEDPIPES:
		connect_string_s << L"np:";
		break;
	case ODBC_CONNECTION_RPC:
		connect_string_s << L"rpc:";
		break;
	case ODBC_CONNECTION_LPC:
		connect_string_s << L"lpc:";
		break;
	case ODBC_CONNECTION_SPX:
		connect_string_s << L"spx:";
		break;
	case ODBC_CONNECTION_VINES:
		connect_string_s << L"vines:";
		break;
	case ODBC_CONNECTION_ADSP:
		connect_string_s << L"adsp:";
		break;
	default:
		THROW(L"Unsupported connection protocol.");
	}
	
	// named pipes protocol needs to specify the pipe name
	if ((_protocol == ODBC_CONNECTION_NAMEDPIPES) && (_namedpipe.length() == 0))
	{
		connect_string_s << L"\\\\" << (_ipaddress == L"localhost" ? L"." : _ipaddress) << L"\\pipe";

		if (! _instancename.empty() && _instancename != DefaultInstanceName)
		{
			connect_string_s << L"\\MSSQL$" << _instancename;
		}		
		connect_string_s << L"\\sql\\query";
	}
	else if ((_protocol == ODBC_CONNECTION_NAMEDPIPES) && (_namedpipe.length() != 0))
	{
		connect_string_s << _namedpipe;
	}
	else
	{
		// The port needs to be set regardless if it is a default port.  
        connect_string_s << _ipaddress << L"," << _port ;
	}

	connect_string_s << L";" ;
	
	if (_database.length() > 0)
	{
		connect_string_s << L"Database=" << _database << L";";
	}

	if (_appname.length() > 0)
	{
		connect_string_s << L"App=" << _appname << L";";
	}

	if (_trusted_auth)
	{
		connect_string_s << L"Trusted_Connection=Yes;";
	}
	else
	{
		connect_string_s << L"Uid=" << _username << L";Pwd=" << _password << L";";
	}

	return connect_string_s.str();
}

MSSQLConnectionInfo::~MSSQLConnectionInfo()
{

}
