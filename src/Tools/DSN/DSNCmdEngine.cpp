#include "StdAfx.h"
#include "DSNCmdEngine.h"
#include "DSNAttributes.h"

DSNCmdEngine::DSNCmdEngine(int argc, wchar_t * argv[])
    : _cmd(L"DSN " _T(VERSION_VALUE), L' ', _T(VERSION_VALUE))
	, _nologo(L"", L"nologo", L"Suppress logo, raw output only.", _cmd)
    , _operation(L"operation", L"Operation to perform: \"add\", \"configure\" or \"remove\".", true, L"add", L"operation", _cmd)
    , _params(L"parameters", L"DSN parameters, eg. Server=localhost", true, L"name=value", _cmd)
    , _system(L"", L"system", L"Create a system DSN", false)
    , _user(L"", L"user", L"Create a user DSN", true)
    , _driver(L"", L"driver", L"Database driver, eg. \"SQL Server\"", true, L"", L"driver", _cmd)
{
    _cmd.xorAdd(_system, _user);
    _cmd.parse(argc, argv, false);
}

void DSNCmdEngine::Execute()
{    
    WORD request = ODBC_ADD_DSN;
    std::wcout << std::endl;
    if (_operation.getValue() == L"add")
    {
        request = (_system.isSet() ? ODBC_ADD_SYS_DSN : ODBC_ADD_DSN);
        std::wcout << L"Adding ";
    }
    else if (_operation.getValue() == L"remove") 
    {
        request = (_system.isSet() ? ODBC_REMOVE_SYS_DSN : ODBC_REMOVE_DSN);
        std::wcout << L"Removing ";
    }
    else if (_operation.getValue() == L"configure") 
    {
        request = (_system.isSet() ? ODBC_CONFIG_SYS_DSN : ODBC_CONFIG_DSN);
        std::wcout << L"Configuring ";
    }
    else 
    {
        THROW(L"Invalid operation \"" << _operation.getValue() << L"\"");
    }

    if (_system.isSet())
    {
        std::wcout << L"system ";
    }

    std::wcout << L"\"" << _driver.getValue() << L"\" DSN";

    DSNAttributes dsn_attributes_collection;
    dsn_attributes_collection.AddRange(_params.getValue());
    std::wstring dsn_attributes_string = dsn_attributes_collection.GetAttributes();
    std::wcout << std::endl << L" " << dsn_attributes_string;
    AppSecInc::Databases::ODBC::ODBCDataSource::Configure(request, _driver.getValue(), dsn_attributes_string);
}
