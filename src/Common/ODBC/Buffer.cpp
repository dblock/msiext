#include "StdAfx.h"
#include "Buffer.h"

using namespace AppSecInc::Databases::ODBC;

ODBCBuffer::ODBCBuffer()
    : _size(0)
    , _type(SQL_UNKNOWN_TYPE)
{

}

ODBCBuffer::ODBCBuffer(SQLSMALLINT type, SQLINTEGER size)
    : _size(size)
    , _type(type)
{
    // automatically select size from type
	if (_size <= 0) 
    {
        _size = GetSize(_type);
    }

    // automatically resize buffer
    // note that some types don't have a pre-allocated buffer
    if (_size > 0)
    {
        _buffer.resize(_size);
    }
}

ODBCBuffer::ODBCBuffer(const std::wstring& value)
    : _type(SQL_C_WCHAR)
	, _size(value.length() * sizeof(WCHAR))
{
	if (value.size())
	{
		_buffer.resize((value.length() + 1) * sizeof(WCHAR));
		memcpy(& * _buffer.begin(), & * value.begin(), _buffer.size());
	}
	else
	{
		_buffer.resize(2);
	}
}

ODBCBuffer::ODBCBuffer(const std::string& value)
    : _type(SQL_C_CHAR)
	, _size(value.length())
{
	if (value.size())
	{
		_buffer.resize(value.length() + 1);
		memcpy(& * _buffer.begin(), & * value.begin(), _buffer.size());
	}
	else
	{
		_buffer.resize(1);
	}
}

ODBCBuffer::ODBCBuffer(const SYSTEMTIME& value)
	: _type(SQL_C_TYPE_TIMESTAMP)
	, _size(sizeof("yyyy-mm-dd hh:mm:ss"))
{
	SQL_TIMESTAMP_STRUCT ts = { 0 };
	ts.hour = value.wHour;
	ts.minute = value.wMinute;
	ts.second = value.wSecond;
	ts.day = value.wDay;
	ts.month = value.wMonth;
	ts.year = value.wYear;

	_buffer.resize(sizeof(ts));
	memcpy(& * _buffer.begin(), & ts, _buffer.size());
}

ODBCBuffer::ODBCBuffer(const GUID& value)
    : _type(SQL_C_GUID)
    , _size(sizeof(GUID))
{
	_buffer.resize(sizeof(GUID));
	memcpy(& * _buffer.begin(), & value, _buffer.size());
}

ODBCBuffer::ODBCBuffer(int value)
    : _type(SQL_C_LONG)
	, _size(sizeof(int))
{
	_buffer.resize(sizeof(int));
	memcpy(& * _buffer.begin(), & value, _buffer.size());
}

ODBCBuffer::ODBCBuffer(bool value)
    : _type(SQL_C_BIT)
	, _size(sizeof(bool))
{
	_buffer.resize(sizeof(bool));
	memcpy(& * _buffer.begin(), & value, _buffer.size());
}

ODBCBuffer::ODBCBuffer(char value)
    : _type(SQL_C_CHAR)
	, _size(sizeof(char))
{
	_buffer.resize(sizeof(char));
	memcpy(& * _buffer.begin(), & value, _buffer.size());
}

ODBCBuffer::ODBCBuffer(wchar_t value)
    : _type(SQL_C_WCHAR)
	, _size(sizeof(wchar_t))
{
	_buffer.resize(sizeof(wchar_t));
	memcpy(& * _buffer.begin(), & value, _buffer.size());
}

ODBCBuffer::ODBCBuffer(short value)
	: _type(SQL_C_SHORT)
	, _size(sizeof(short))
{
	_buffer.resize(sizeof(short));
	memcpy(& * _buffer.begin(), & value, _buffer.size());
}

ODBCBuffer::ODBCBuffer(double value)
	: _type(SQL_C_DOUBLE)
	, _size(sizeof(double))
{
	_buffer.resize(sizeof(double));
	memcpy(& * _buffer.begin(), & value, _buffer.size());
}

ODBCBuffer::ODBCBuffer(float value)
	: _type(SQL_C_FLOAT)
	, _size(sizeof(float))
{
	_buffer.resize(sizeof(float));
	memcpy(& * _buffer.begin(), & value, _buffer.size());
}

ODBCBuffer::ODBCBuffer(const ODBCBuffer& rhs)
{
	operator=(rhs);
}

void ODBCBuffer::operator=(const ODBCBuffer& value)
{
    _type = value._type;
    _size = value._size;
    _buffer = value._buffer;
}

ODBCBuffer::~ODBCBuffer()
{

}


std::string ODBCBuffer::ToString() const
{
    if (_buffer.size() == 0)
        return "NULL";

    switch(_type)
    {
    case SQL_BIT:
        return AppSecInc::StringUtils::toString(GetBoolValue());
    case SQL_NUMERIC:
    case SQL_DECIMAL:
    case SQL_INTEGER:
    case SQL_SMALLINT:
        return AppSecInc::StringUtils::toString(GetIntValue());
    case SQL_TINYINT:
        return AppSecInc::StringUtils::toString(GetShortValue());
    case SQL_FLOAT:
    case SQL_REAL:
        return AppSecInc::StringUtils::toString(GetFloatValue());
    case SQL_DOUBLE:
        return AppSecInc::StringUtils::toString(GetDoubleValue());
    case SQL_BIGINT:
        return AppSecInc::StringUtils::toString(GetLongLongValue());
    case SQL_CHAR:
    case SQL_VARCHAR:
    case SQL_LONGVARCHAR:
        return GetStringValue();
    case SQL_WCHAR:
    case SQL_WVARCHAR:
    case SQL_WLONGVARCHAR:
        return AppSecInc::StringUtils::wc2mb(GetWStringValue());
	case SQL_TYPE_DATE:
		{
			DATE_STRUCT ds = GetDate();
			return AppSecInc::Formatter::FormatMessage("%04d-%02d-%02d", 
				ds.year, ds.month, ds.day);
		}
	case SQL_TYPE_TIME:
		{
			TIME_STRUCT tt = GetTime();
			return AppSecInc::Formatter::FormatMessage("%02d:%02d:%02d",
				tt.hour, tt.minute, tt.second);
		}
	case SQL_TYPE_TIMESTAMP:
		{
			TIMESTAMP_STRUCT ts = GetTimeStamp();
			return AppSecInc::Formatter::FormatMessage("%04d-%02d-%02d %02d:%02d:%02d.%03d", 
				ts.year, ts.month, ts.day, ts.hour, ts.minute, ts.second, ts.fraction / 1000000);
		}
    case SQL_BINARY:
	case SQL_VARBINARY:
    case SQL_LONGVARBINARY:
        // this is probably incorrect for SQL_VARBINARY, we shouldn't be truncating the buffer
        {
            std::string binary = AppSecInc::Formatter::FormatHexStringA(
			    (byte *) & * _buffer.begin(), _buffer.size());
            AppSecInc::StringUtils::rtrim(binary, "0");
            return binary;
        }
    }

    THROW("Unsupported buffer type: " << _type);
}

std::wstring ODBCBuffer::ToWString() const
{
    if (_buffer.size() == 0)
        return L"NULL";

    switch(_type)
    {
    case SQL_BIT:
        return AppSecInc::StringUtils::toWString(GetBoolValue());
    case SQL_NUMERIC:
    case SQL_DECIMAL:
    case SQL_INTEGER:
    case SQL_SMALLINT:
        return AppSecInc::StringUtils::toWString(GetIntValue());
    case SQL_TINYINT:
        return AppSecInc::StringUtils::toWString(GetShortValue());
    case SQL_FLOAT:
    case SQL_REAL:
        return AppSecInc::StringUtils::toWString(GetFloatValue());
    case SQL_DOUBLE:
        return AppSecInc::StringUtils::toWString(GetDoubleValue());
    case SQL_BIGINT:
        return AppSecInc::StringUtils::toWString(GetLongLongValue());
    case SQL_CHAR:
    case SQL_VARCHAR:
    case SQL_LONGVARCHAR:
        return AppSecInc::StringUtils::mb2wc(GetStringValue());
    case SQL_WCHAR:
    case SQL_WVARCHAR:
    case SQL_WLONGVARCHAR:
        return GetWStringValue();
	case SQL_TYPE_DATE:
		{
			DATE_STRUCT ds = GetDate();
			return AppSecInc::Formatter::FormatMessage(L"%04d-%02d-%02d", 
				ds.year, ds.month, ds.day);
		}
	case SQL_TYPE_TIME:
		{
			TIME_STRUCT tt = GetTime();
			return AppSecInc::Formatter::FormatMessage(L"%02d:%02d:%02d",
				tt.hour, tt.minute, tt.second);
		}
	case SQL_TYPE_TIMESTAMP:
		{
			TIMESTAMP_STRUCT ts = GetTimeStamp();
			return AppSecInc::Formatter::FormatMessage(L"%04d-%02d-%02d %02d:%02d:%02d.%03d", 
				ts.year, ts.month, ts.day, ts.hour, ts.minute, ts.second, ts.fraction / 1000000);
		}
    case SQL_BINARY:
	case SQL_VARBINARY:
    case SQL_LONGVARBINARY:
        // this is probably incorrect for SQL_VARBINARY, we shouldn't be truncating the buffer
        {
            std::wstring binary = AppSecInc::Formatter::FormatHexStringW(
			    (byte *) & * _buffer.begin(), _buffer.size());
            AppSecInc::StringUtils::rtrim(binary, L"0");
            return binary;
        }
    }

    THROW("Unsupported buffer type: " << _type);
}

SQLINTEGER ODBCBuffer::GetSize(SQLSMALLINT type)
{
	switch(type)
	{
	case SQL_CHAR:
		return sizeof(SQLCHAR);
    case SQL_VARCHAR:
        return sizeof(SQLVARCHAR);
	case SQL_NUMERIC:
		return sizeof(SQLNUMERIC);
	case SQL_DECIMAL:
		return sizeof(SQLDECIMAL);
	case SQL_INTEGER:
		return sizeof(SQLINTEGER);
	case SQL_SMALLINT:
		return sizeof(SQLSMALLINT);
	case SQL_FLOAT:
		return sizeof(SQLFLOAT);
	case SQL_REAL:
		return sizeof(SQLREAL);
	case SQL_DOUBLE:
		return sizeof(SQLDOUBLE);
	case SQL_DATETIME:
	case SQL_TYPE_DATE:
		return sizeof(SQLDATE);
	case SQL_TYPE_TIME:
		return sizeof(SQLTIME);
	case SQL_TYPE_TIMESTAMP:
		return sizeof(SQLTIMESTAMP);
    case SQL_WCHAR:
        return sizeof(SQLWCHAR);
    case SQL_WVARCHAR:
        return sizeof(SQL_C_WCHAR);
    case SQL_WLONGVARCHAR:
        return 0; // no pre-allocated buffer
	}

	return INVALID_SIZE;
}

struct SQLTypeToStringEntry
{
    SQLSMALLINT type;
    LPCWSTR name;
};

static SQLTypeToStringEntry SQLTypeToStringEntry_map[] =
{
	{ SQL_CHAR, L"char" },
    { SQL_VARCHAR, L"varchar" },
    { SQL_LONGVARCHAR, L"text" },
	{ SQL_NUMERIC, L"numeric" },
	{ SQL_DECIMAL, L"decimal" },
	{ SQL_INTEGER, L"integer" },
	{ SQL_SMALLINT, L"smallint" },
	{ SQL_FLOAT, L"float" },
	{ SQL_REAL, L"real" },
	{ SQL_DOUBLE, L"double" },
	{ SQL_DATETIME, L"datetime" },
    { SQL_BINARY, L"binary" },
    { SQL_VARBINARY, L"varbinary" },
    { SQL_LONGVARBINARY, L"longvarbinary" },
    { SQL_BIGINT, L"bigint" },
    { SQL_TINYINT, L"tinyint" },
    { SQL_BIT, L"bit" },
	{ SQL_TYPE_DATE, L"date" },
	{ SQL_TYPE_TIME, L"time" },
	{ SQL_TYPE_TIMESTAMP, L"timestamp" },
    { SQL_WCHAR, L"nchar" },
    { SQL_WVARCHAR, L"nvarchar" },
    { SQL_WLONGVARCHAR, L"ntext" },    
};

SQLSMALLINT ODBCBuffer::StringToSQLType(const std::wstring& type)
{
    for (int i = 0; i < ARRAYSIZE(SQLTypeToStringEntry_map); i++)
    {
        if (type == SQLTypeToStringEntry_map[i].name)
        {
            return SQLTypeToStringEntry_map[i].type;
        }
    }

    THROW(L"Unsupported type: " << type);
}

std::wstring ODBCBuffer::SQLTypeToString(SQLSMALLINT type)
{
    for (int i = 0; i < ARRAYSIZE(SQLTypeToStringEntry_map); i++)
    {
        if (type == SQLTypeToStringEntry_map[i].type)
        {
            return SQLTypeToStringEntry_map[i].name;
        }
    }

    THROW(L"Unsupported type: " << type);
}
