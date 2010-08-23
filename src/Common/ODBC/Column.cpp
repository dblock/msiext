#include "StdAfx.h"
#include "Column.h"

using namespace AppSecInc::Databases::ODBC;

ODBCColumn::ODBCColumn(const std::wstring& name, SQLSMALLINT type, SQLINTEGER size)
	: ODBCBuffer(type, 0)
    , _name(name)
    , _bound(false)
{

}

ODBCColumn::ODBCColumn(const ODBCColumn& column)
    : _bound(false)
{
	operator=(column);
}

// \todo: disable copy operator, it's not really a copy what we're doing here
void ODBCColumn::operator=(const ODBCColumn& rhs)
{
    ODBCBuffer::operator=(rhs);
	_name = rhs._name;
}

ODBCColumn::~ODBCColumn()
{

}

SQLSMALLINT ODBCColumn::GetBindDataType() const
{
    SQLSMALLINT bind_datatype = _type;
    switch(bind_datatype)
    {
    case SQL_FLOAT:
        bind_datatype = SQL_DOUBLE;
        break;
    case SQL_DECIMAL:
    case SQL_BIGINT:
        bind_datatype = SQL_INTEGER;
        break;
    case SQL_VARCHAR:
    case SQL_LONGVARCHAR:
        bind_datatype = SQL_CHAR;
        break;
    case SQL_WLONGVARCHAR:
    case SQL_WVARCHAR:
        bind_datatype = SQL_WCHAR;
        break;
    case SQL_LONGVARBINARY:
	case SQL_VARBINARY:
        bind_datatype = SQL_BINARY;
        break;
	case SQL_SS_VARIANT:
		bind_datatype = SQL_BINARY;
		break;
    }
    return bind_datatype;
}

void ODBCColumn::BindAt(SQLHANDLE hstmt, int index)
{
    CHECK_BOOL(! _bound,
        L"Column already bound to a statement");

	CHECK_BOOL(_buffer.size() > 0, 
        "Invalid buffer at index " << index);

	CHECK_BOOL(SQL_SUCCEEDED(SQLBindCol(
		hstmt, index, GetBindDataType(), & * _buffer.begin(), _buffer.size(), & _size)),
        "Error binding column of type " << _type << " at index " << index << L": " << ODBCHandle::GetError(hstmt, SQL_HANDLE_STMT));

    _bound = true;
}

void ODBCColumn::GetDataAt(SQLHANDLE hstmt, int index)
{
    // this is probably not working correctly for SQL_VARBINARY and other VAR types
    // the driver claims that the data size = the field size

    CHECK_BOOL(! _bound,
        L"Cannot get data on a bound column");

    int rc = 0;
    // start without knowing how many bytes are coming
    SQLLEN available_data_len = SQL_NO_TOTAL;
    // start with an empty buffer, fetched_len of zero bytes
    _buffer.clear();
    SQLLEN fetched_len = 0;

    do
    {
        switch(available_data_len)
        {
        case SQL_NO_TOTAL:
            // the driver doesn't know how much data is coming or first loop
            available_data_len = 256;
            break;
        }

        // we fetched the buffer size of bytes in the previous round
        fetched_len = _buffer.size();
        // grow the buffer to the current fetched data + data available for the iteration
        _buffer.resize(fetched_len + available_data_len);
        // fetch the next data segment
	    rc = SQLGetData(hstmt, index, GetBindDataType(), & * _buffer.begin() + fetched_len, available_data_len, & available_data_len);

        CHECK_BOOL(SQL_SUCCEEDED(rc),
            "Error getting data for column of type " << _type << " at index " << index << L": " << 
                    ODBCHandle::GetError(hstmt, SQL_HANDLE_STMT));

		// variant type needs to be changed to the actual type
		// see http://msdn.microsoft.com/en-us/library/ms130902.aspx
		switch(_type)
		{
		case SQL_SS_VARIANT:
			rc = SQLColAttribute(hstmt, index, SQL_CA_SS_VARIANT_TYPE, NULL, NULL, NULL, & _type);

			CHECK_BOOL(SQL_SUCCEEDED(rc),
				"Error getting data type for sql_variant column at index " << index << L": " << 
						ODBCHandle::GetError(hstmt, SQL_HANDLE_STMT));

			break;
		}

		// text types are null-terminated, the last character was the null terminator
        switch(_type)
        {
        case SQL_LONGVARCHAR:
        case SQL_VARCHAR:
        case SQL_CHAR:
            _buffer.resize(_buffer.size() - sizeof(char));
            break;
        case SQL_WLONGVARCHAR:
        case SQL_WVARCHAR:
        case SQL_WCHAR:
            _buffer.resize(_buffer.size() - sizeof(wchar_t));
            break;
        }

    } while (rc == SQL_SUCCESS_WITH_INFO);

    switch(available_data_len)
    {
        // the driver returned NULL
    case SQL_NULL_DATA:
        _buffer.clear();
        break;
    default:
        // the last available_data_len is the actual size of bytes returned in the last segment
        fetched_len += available_data_len;
        _buffer.resize(fetched_len);
        break;
    }

    _size = _buffer.size();
}
