#include "StdAfx.h"
#include "Handle.h"
#include "Connection.h"

using namespace AppSecInc::Databases::ODBC;

ODBCHandle::ODBCHandle()
    : _type(SQL_UNKNOWN_TYPE)
    , _hconn(NULL)
    , _handle(NULL)
{

}

ODBCHandle::~ODBCHandle()
{
    if (_handle != NULL)
    {
        Release();
    }
}

void ODBCHandle::Allocate(SQLSMALLINT type, SQLHANDLE conn)
{
    CHECK_BOOL(_handle == NULL, L"Error, handle already allocated.");

    SQLRETURN rc = SQLAllocHandle(type, conn, & _handle);

    CHECK_BOOL(SQL_SUCCEEDED(rc),
        L"Error allocating handle. " << GetError(_hconn, SQL_HANDLE_DBC));

	_type = type;
	_hconn = conn;
}

void ODBCHandle::Release()
{
    CHECK_BOOL(_handle != NULL, L"Error, handle not allocated.");

    SQLRETURN rc = SQLFreeHandle(_type, _handle);

    CHECK_BOOL(SQL_SUCCEEDED(rc),
        L"Error releasing handle. " << GetError(_hconn, SQL_HANDLE_DBC));

    _handle = NULL;
}

std::vector<std::wstring> ODBCHandle::GetDiagFields(SQLHANDLE handle, int type, int diagidentifier)
{
	SQLWCHAR sql_message[SQL_MAX_MESSAGE_LENGTH];
	SQLSMALLINT sql_message_len;

	std::vector<std::wstring> messages;
	SQLSMALLINT i = 1;
	while (SQL_SUCCEEDED(SQLGetDiagField(type, handle, i, diagidentifier, sql_message, SQL_MAX_MESSAGE_LENGTH, & sql_message_len))) 
	{
		messages.push_back(sql_message);
		i++;
	}

    CHECK_BOOL(! messages.empty(),
        L"Error retreiving ODBC diag fields, handle=" << std::hex << handle << L", type=" << diagidentifier);

	return messages;
}

std::vector<ODBCDiagnosticsMessage> ODBCHandle::GetDiagMessages(SQLHANDLE handle, int type)
{
	SQLWCHAR sql_message[SQL_MAX_MESSAGE_LENGTH];
	SQLSMALLINT sql_message_len;

	std::vector<ODBCDiagnosticsMessage> messages;
	SQLSMALLINT i = 1;
	while (SQL_SUCCEEDED(SQLGetDiagField(type, handle, i, SQL_DIAG_MESSAGE_TEXT, sql_message, SQL_MAX_MESSAGE_LENGTH, & sql_message_len))) 
	{
		ODBCDiagnosticsMessage message;
		// the messages are formatted according to http://msdn.microsoft.com/en-us/library/ms713606(VS.85).aspx
		// For errors and warnings that do not occur in a data source, the diagnostic message must use this format:
		// [ vendor-identifier ][ ODBC-component-identifier ] component-supplied-text 
		// For errors and warnings that occur in a data source, the diagnostic message must use this format:
		// [ vendor-identifier ][ ODBC-component-identifier ][ data-source-identifier ] data-source-supplied-text 
		std::vector<std::wstring> message_tokens;
		AppSecInc::StringUtils::tokenizeWithSkip(static_cast<LPCWSTR>(sql_message), message_tokens, L"][");
		CHECK_BOOL(message_tokens.size() == 3 || message_tokens.size() == 4, L"Invalid message format");
		message.vendor = message_tokens[0];
		message.component = message_tokens[1];
		
		if (message_tokens.size() == 4) 
		{
			message.datasource = message_tokens[2];
			message.text = message_tokens[3];
		}
		else if (message_tokens.size() == 3)
		{
			message.text = message_tokens[2];
		}

		messages.push_back(message);
		i++;
	}

    CHECK_BOOL(! messages.empty(),
        L"Error retreiving ODBC diag fields, handle=" << std::hex << handle << L", type=" << type);

	return messages;
}

std::vector<ODBCError> ODBCHandle::GetErrors(SQLHANDLE handle, int type)
{
	SQLWCHAR sql_state[6];
	SQLWCHAR sql_message[SQL_MAX_MESSAGE_LENGTH];
	SQLINTEGER sql_native_error;
	SQLSMALLINT sql_message_len;

    std::vector<ODBCError> errors;
	SQLSMALLINT i = 1;
	while (SQL_SUCCEEDED(SQLGetDiagRec(type, handle, i, sql_state, & sql_native_error,
		sql_message, SQL_MAX_MESSAGE_LENGTH, & sql_message_len))) 
	{
		ODBCError error;
        error.message = sql_message;
		error.native_error = sql_native_error;
		error.state = sql_state;
		errors.push_back(error);
		i++;
	}

    CHECK_BOOL(! errors.empty(),
        L"Error retreiving ODBC errors, handle=" << std::hex << handle << L", type=" << type);

	return errors;
}

std::wstring ODBCHandle::GetError(SQLHANDLE handle, int type)
{
	std::vector<ODBCError> errors = GetErrors(handle, type);
	std::wstringstream error_s;
	for (unsigned int i = 0; i < errors.size(); i++)
	{
        if (i > 0) error_s << std::endl;
		error_s << L"SQLSTATE: " << errors[i].state
			<<	L", Native error: " << errors[i].native_error
			<<	L", Message: " << errors[i].message;
	}
	return error_s.str();
}
