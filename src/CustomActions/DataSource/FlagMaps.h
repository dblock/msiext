#pragma once

using namespace AppSecInc::Msi::Flags;
using namespace AppSecInc::Databases::ODBC;

static const FlagMapEntry s_ODBCDSNFlags[] = 
{
    { L"ODBC_ADD_DSN", ODBC_ADD_DSN },
    { L"ODBC_CONFIG_DSN", ODBC_CONFIG_DSN },
    { L"ODBC_REMOVE_DSN", ODBC_REMOVE_DSN },
    { L"ODBC_ADD_SYS_DSN", ODBC_ADD_SYS_DSN },
    { L"ODBC_CONFIG_SYS_DSN", ODBC_CONFIG_SYS_DSN },
    { L"ODBC_REMOVE_SYS_DSN", ODBC_REMOVE_SYS_DSN },
    { L"ODBC_REMOVE_DEFAULT_DSN", ODBC_REMOVE_DEFAULT_DSN }
};

static const FlagMapEntry s_OdbcSqlFlags[] = 
{
    { L"ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY", ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY },
};
