#include "StdAfx.h"
#include "DataSource.h"

using namespace AppSecInc::Databases;
using namespace AppSecInc::Databases::ODBC;

void AppSecInc::Databases::ODBC::ODBCDataSource::Configure(WORD fRequest, const std::wstring& odbc_driver, const std::wstring& attributes)
{
    std::vector<wchar_t> dsn_attributes;
    dsn_attributes.resize(attributes.length() + 2, 0); // two null terminators
    attributes._Copy_s(& * dsn_attributes.begin(), dsn_attributes.size(), attributes.length());
    for (unsigned int i = 0; i < dsn_attributes.size(); i++)
    {
        if (dsn_attributes[i] == L';')
        {
            dsn_attributes[i] = 0;
        }
    }

    CHECK_BOOL(::SQLConfigDataSourceW(NULL, (WORD) fRequest, odbc_driver.c_str(), & * dsn_attributes.begin()),
        L"Error configuring \"" << odbc_driver << "\" data source: " << GetError());
}

std::vector<ODBCError> AppSecInc::Databases::ODBC::ODBCDataSource::GetErrors()
{
    DWORD sql_error = 0;
    wchar_t sql_error_message[SQL_MAX_MESSAGE_LENGTH];
    WORD sql_error_message_len = 0;

    std::vector<ODBCError> errors;
	SQLSMALLINT i = 1;
	while (SQL_SUCCEEDED(SQLInstallerError(
        i, & sql_error, sql_error_message, SQL_MAX_MESSAGE_LENGTH - 1, & sql_error_message_len)))
	{
		ODBCError error;
        error.message = static_cast<LPCWSTR>(sql_error_message);
		error.native_error = sql_error;
		error.state = L"";
		errors.push_back(error);
		i++;
	}

    CHECK_BOOL(! errors.empty(),
        L"Error retreiving SQL installer errors");
    
	return errors;
}

std::wstring AppSecInc::Databases::ODBC::ODBCDataSource::GetError()
{
	std::vector<ODBCError> errors = AppSecInc::Databases::ODBC::ODBCDataSource::GetErrors();
	std::wstringstream error_s;
	for (unsigned int i = 0; i < errors.size(); i++)
	{
        if (i > 0) error_s << std::endl;
		error_s << L"Native error: " << errors[i].native_error
			<<	L", Message: " << errors[i].message;
	}
	return error_s.str();
}
