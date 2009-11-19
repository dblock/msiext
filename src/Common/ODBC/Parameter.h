#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace ODBC
		{
            //! An ODBC column
            class ODBCParameter : public ODBCBuffer
			{
            private:
				//! i/o type, eg. SQL_PARAM_INPUT
				SQLSMALLINT _iotype;
				//! the SQL data type of the parameter, eg. SQL_INTEGER
				SQLSMALLINT _parametertype;
                //! the name of the column
				std::wstring _name;
			public:
                void operator=(const ODBCParameter&);
				//! i/o type, eg. SQL_PARAM_INPUT
				SQLSMALLINT GetIOType() const { return _iotype; }
				//! the SQL data type of the parameter, eg. SQL_INTEGER
				SQLSMALLINT GetParameterType() const { return _parametertype; }
                //! get the name of the parameter
				const std::wstring& GetName() const { return _name; }
                //! bind the parameter to a statement at a given index
				void BindAt(SQLHANDLE hstmt, SQLHDESC hipd, int index);
				//! constructors
				ODBCParameter(const ODBCParameter& parameter);
				ODBCParameter(const std::wstring& name, SQLSMALLINT iotype, SQLSMALLINT valuetype, SQLSMALLINT parametertype, SQLINTEGER datasize);
				ODBCParameter(const std::wstring& name, const std::wstring& value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, const std::string& value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, const SYSTEMTIME& value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, const GUID& value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, bool value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, char value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, wchar_t value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, int value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, short value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, float value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				ODBCParameter(const std::wstring& name, double value, SQLSMALLINT iotype = SQL_PARAM_INPUT);
                //! convert a string value into an ODBC parameter
                static ODBCParameter Create(const std::wstring name, const std::wstring& value, SQLSMALLINT sqltype, SQLSMALLINT iotype = SQL_PARAM_INPUT);
				virtual ~ODBCParameter();
			};
		}
	}
}


