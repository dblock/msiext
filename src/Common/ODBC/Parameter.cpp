#include "StdAfx.h"
#include "Parameter.h"

using namespace AppSecInc::Databases::ODBC;

ODBCParameter::ODBCParameter(
    const std::wstring& name
    , SQLSMALLINT iotype
    , SQLSMALLINT valuetype
    , SQLSMALLINT parametertype
    , SQLINTEGER datasize)
: ODBCBuffer(valuetype, datasize)
    , _iotype(iotype)
    , _parametertype(parametertype)
    , _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, const std::wstring& value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
    , _iotype(iotype)
	, _parametertype(SQL_WLONGVARCHAR)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, const std::string& value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
    , _iotype(iotype)
	, _parametertype(SQL_LONGVARCHAR)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, const SYSTEMTIME& value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
	, _iotype(iotype)
	, _parametertype(SQL_TIMESTAMP)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, const GUID& value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
	, _iotype(iotype)
	, _parametertype(SQL_GUID)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, int value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
	, _iotype(iotype)
	, _parametertype(SQL_INTEGER)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, char value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
	, _iotype(iotype)
	, _parametertype(SQL_CHAR)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, wchar_t value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
	, _iotype(iotype)
	, _parametertype(SQL_WCHAR)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, bool value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
	, _iotype(iotype)
	, _parametertype(SQL_BIT)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, short value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
    , _iotype(iotype)
	, _parametertype(SQL_SMALLINT)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, float value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
    , _iotype(iotype)
	, _parametertype(SQL_FLOAT)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(
	const std::wstring& name
	, double value
	, SQLSMALLINT iotype)
: ODBCBuffer(value)
    , _iotype(iotype)
	, _parametertype(SQL_DOUBLE)
	, _name(name)
{

}

ODBCParameter::ODBCParameter(const ODBCParameter& rhs)
	: _iotype(SQL_PARAM_TYPE_UNKNOWN)
	, _parametertype(SQL_C_DEFAULT)
{
	operator=(rhs);
}

void ODBCParameter::operator=(const ODBCParameter& rhs)
{
	_name = rhs._name;
	_iotype = rhs._iotype;
	_parametertype = rhs._parametertype;
    ODBCBuffer::operator=(rhs);
}

ODBCParameter::~ODBCParameter()
{

}

void ODBCParameter::BindAt(SQLHANDLE hstmt, SQLHDESC hipd, int index)
{
	CHECK_BOOL(_buffer.size() > 0, "Invalid buffer at index " << index);

	CHECK_BOOL(SQL_SUCCEEDED(SQLBindParameter(
		hstmt, index, _iotype, _type, _parametertype, _size, 0, & * _buffer.begin(), _buffer.size(), & _size)),
		L"Error binding parameter " << _name << L" at index " << index << L": " << ODBCHandle::GetError(hstmt, SQL_HANDLE_STMT));

	if (hipd != NULL && _name.length())
	{
		std::wstringstream name;
		name << L"@" << _name;
		CHECK_BOOL(SQL_SUCCEEDED(SQLSetDescField(hipd, index, SQL_DESC_NAME, (SQLPOINTER) name.str().c_str(), SQL_NTS)),
			L"Error binding parameter by name @" << _name << L" at index " << index << L": " << ODBCHandle::GetError(hipd, SQL_HANDLE_DESC));
	}
}

ODBCParameter ODBCParameter::Create(const std::wstring name, const std::wstring& value, SQLSMALLINT sqltype, SQLSMALLINT iotype)
{
    switch(sqltype)
    {
    case SQL_BIT:
        return ODBCParameter(name, AppSecInc::StringUtils::stringToLong(value) != 0, iotype);        
    case SQL_CHAR:
        CHECK_BOOL(value.length() <= 1, L"String data will be truncated (SQL_WCHAR).");
        return ODBCParameter(name, AppSecInc::StringUtils::wc2mb(value)[0], iotype);
    case SQL_TINYINT:
        return ODBCParameter(name, static_cast<short>(AppSecInc::StringUtils::stringToLong(value)), iotype);        
    case SQL_SMALLINT:
        return ODBCParameter(name, static_cast<short>(AppSecInc::StringUtils::stringToLong(value)), iotype);        
    case SQL_INTEGER:
    case SQL_DECIMAL:
        return ODBCParameter(name, static_cast<int>(AppSecInc::StringUtils::stringToLong(value)), iotype);        
    //case SQL_BIGINT:
    //case SQL_BINARY:
    //case SQL_VARBINARY:
    //case SQL_LONGVARBINARY:
    //case SQL_DATETIME:
    //case SQL_FLOAT:
    //case SQL_REAL:
    //case SQL_DOUBLE:
    case SQL_VARCHAR:
    case SQL_LONGVARCHAR:
        return ODBCParameter(name, AppSecInc::StringUtils::wc2mb(value), iotype);
    case SQL_WCHAR:
        CHECK_BOOL(value.length() <= 1, L"String data will be truncated (SQL_WCHAR).");
        return ODBCParameter(name, value[0], iotype);
    case SQL_WVARCHAR:
    case SQL_WLONGVARCHAR:
        return ODBCParameter(name, value, iotype);
    default:
        THROW("Unsupported type: " << sqltype);
    }
}
