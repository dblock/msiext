#include "StdAfx.h"
#include "RowSet.h"

using namespace AppSecInc::Databases::ODBC;

ODBCRowSet::ODBCRowSet()
{

}

ODBCRowSet::~ODBCRowSet()
{
	for (unsigned int i = 0; i < _columns.size(); i++)
	{
		ODBCColumn * p = _columns[i];
		delete p;
	}
}

void ODBCRowSet::AddColumn(const std::wstring& name, int type, int size)
{
    // some types don't need to be pre-allocated, eg. ntext (SQL_WLONGVARCHAR) which is 2GB size
    switch(type)
    {
        case SQL_LONGVARCHAR:
        case SQL_WLONGVARCHAR:
        case SQL_LONGVARBINARY:
            size = 0;
            break;
    }

	ODBCColumn * pc = new ODBCColumn(name, type, size);
	_columns.push_back(pc);
	_columnmap[name] = pc;
}

const ODBCColumn * ODBCRowSet::operator[](const std::wstring& name) const
{   
    std::map<std::wstring, ODBCColumn *>::const_iterator iter = _columnmap.find(name);
    std::map<std::wstring, ODBCColumn *>::const_iterator end = _columnmap.end();
    if (iter != end) return iter->second;
    return NULL;
}

const ODBCColumn * ODBCRowSet::operator[](int index) const
{
    if (static_cast<unsigned int>(index) >= _columns.size() || index < 0) 
    {
        return NULL;
    }

	return _columns[index];
}

void ODBCRowSet::Bind(SQLHANDLE hconn)
{
	_stmt.Allocate(SQL_HANDLE_STMT, hconn);
}

void ODBCRowSet::BindColumns()
{    
    if (_columns.size() == 0)
    {
        unsigned int cols = GetNumResultCols();
        CHECK_BOOL(cols >= 0,
            L"Invalid number of columns: " << cols);

        for (unsigned int col = 1; col <= cols; col++)
        {
            SQLSMALLINT column_name_length = 0;
            SQLULEN column_data_size = 0;
            SQLSMALLINT column_scale = 0;
            SQLSMALLINT column_data_type = 0;
            SQLSMALLINT column_nullable = 0;
            SQLWCHAR column_name[SQL_MAX_COLUMN_NAME_LEN + 1];

            int rc = ::SQLDescribeColW(_stmt.Peek(), col, column_name, SQL_MAX_COLUMN_NAME_LEN, & column_name_length, 
                & column_data_type, & column_data_size, & column_scale, & column_nullable);

	        CHECK_BOOL(SQL_SUCCEEDED(rc),
		        L"Error in SQLDescribeCol(" << col << L"): " << _stmt.GetError());
            
            //! SQLDescribeCol returns the size of the column in characters, ODBCColumn accepts size in bytes
            switch(column_data_type)
            {
            case SQL_WCHAR:
            case SQL_WVARCHAR:
            case SQL_WLONGVARCHAR:
                column_data_size *= sizeof(WCHAR);
                break;
            }

            AddColumn(column_name, column_data_type, column_data_size);
        }
    }
}

void ODBCRowSet::Execute()
{
    _messages.clear();

	int rc = SQLExecute(_stmt.Peek());

    if (rc == SQL_NO_DATA)
        return;

	CHECK_BOOL(SQL_SUCCEEDED(rc),
		L"Error in SQLExecute(): " << _stmt.GetError());

	while(rc == SQL_SUCCESS_WITH_INFO)
	{
		std::vector<ODBCDiagnosticsMessage> messages = _stmt.GetDiagMessages();
        _messages.insert(_messages.end(), messages.begin(), messages.end());

		rc = SQLMoreResults(_stmt.Peek());

        if (rc == SQL_NO_DATA)
            return;

		CHECK_BOOL(SQL_SUCCEEDED(rc),
			L"Error in SQLMoreResults(): " << _stmt.GetError());
	}
}

void ODBCRowSet::Prepare(const std::wstring& query)
{
    int rc = SQLPrepare(_stmt.Peek(), (SQLWCHAR *) query.c_str(), SQL_NTS);

	CHECK_BOOL(SQL_SUCCEEDED(rc),
		L"Error in SQLPrepare(" << query << L"): " << _stmt.GetError());
}


void ODBCRowSet::ExecuteDirect(const std::wstring& query)
{
    int rc = SQLExecDirect(_stmt.Peek(), (SQLWCHAR *) query.c_str(), SQL_NTS);

    if (rc == SQL_NO_DATA)
        return;

	CHECK_BOOL(SQL_SUCCEEDED(rc),
		L"Error in SQLExecuteDirect(" << query << L"): " << _stmt.GetError());
}

bool ODBCRowSet::Fetch()
{
	int rc = SQLFetch(_stmt.Peek());

	if (rc == SQL_NO_DATA) 
        return false;

	CHECK_BOOL(SQL_SUCCEEDED(rc),
		L"Error in SQLFetch(): " << _stmt.GetError());

    // call SQLGetData for every unbound column
	for (unsigned int i = 0; i < _columns.size(); i++)
	{
		ODBCColumn * p = _columns[i];
		if (! p->IsBound())
        {
            p->GetDataAt(_stmt.Peek(), i + 1);
        }
	}

    return true;
}

SQLSMALLINT ODBCRowSet::GetNumResultCols() const
{
    SQLSMALLINT count = 0;
	int rc = SQLNumResultCols(_stmt.Peek(), & count);

	CHECK_BOOL(SQL_SUCCEEDED(rc),
		L"Error in SQLNumResultCols(): " << _stmt.GetError());

    return count;
}

SQLINTEGER ODBCRowSet::GetSQLRowCount() const
{
    SQLINTEGER count = 0;

    int rc = SQLRowCount(_stmt.Peek(), & count);

	CHECK_BOOL(SQL_SUCCEEDED(rc),
		L"Error in SQLNumResultRows(): " << _stmt.GetError());

    return count;
}
