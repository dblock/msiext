#include "StdAfx.h"
#include "Parameters.h"

using namespace AppSecInc::Databases::ODBC;

ODBCParameters::ODBCParameters()
{

}

ODBCParameters::~ODBCParameters()
{

}

void ODBCParameters::AddParameter(const ODBCParameter& pc)
{
	_parameters.push_back(pc);
}

const ODBCParameter& ODBCParameters::operator[](const std::wstring& name) const
{   
    for (unsigned int i = 0; i < _parameters.size(); i++)
    {
        if (_parameters[i].GetName() == name)
            return _parameters[i];
    }

    THROW(L"No such parameter: " << name);
}

const ODBCParameter& ODBCParameters::operator[](int index) const
{
	return _parameters[index];
}

void ODBCParameters::Bind(SQLHSTMT stmt)
{
	SQLHDESC hipd = NULL;
	CHECK_BOOL(SQL_SUCCEEDED(SQLGetStmtAttr(stmt, SQL_ATTR_IMP_PARAM_DESC, & hipd, 0, 0)),
		L"Error in SQLGetStmtAttr: " << ODBCHandle::GetError(stmt, SQL_HANDLE_STMT));

    for (unsigned int i = 0; i < _parameters.size(); i++)
	{
		_parameters[i].BindAt(stmt, hipd, i + 1);
	}
}
