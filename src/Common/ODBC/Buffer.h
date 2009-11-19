#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace ODBC
		{
            //! An ODBC column
			class ODBCBuffer
			{
            protected:
                //! column type, eg. SQL_C_CHAR
				SQLSMALLINT _type;
                //! the data size after a Fetch
				SQLINTEGER _size;
                //! the data buffer
				std::vector<char> _buffer;
                //! returns the size for default types, zero otherwise
                static SQLINTEGER GetSize(SQLSMALLINT type);
			public:
                //! invalid data size
				static const SQLINTEGER INVALID_SIZE = 0;
                //! copy operator, data will be copied
                virtual void operator=(const ODBCBuffer&);
                //! get the size of the data
				SQLINTEGER GetDataSize() const { return _size; }
                //! get the size of the buffer
				int GetBufferSize() const { return _buffer.size(); }
                //! get the type of data
				SQLSMALLINT GetType() const { return _type; }
                //! translate a SQL type to its string representation
                static std::wstring SQLTypeToString(SQLSMALLINT type);
                //! translate a string to its SQL type
                static SQLSMALLINT StringToSQLType(const std::wstring& type);
				//! constructors
                ODBCBuffer();
                /*! ODBC buffer
                    \param type SQL type
                    \param size column size in bytes; specify zero to resize automatically to the default size for the given type
                */
                ODBCBuffer(SQLSMALLINT type, SQLINTEGER size);
				ODBCBuffer(const std::wstring& value);
				ODBCBuffer(const std::string& value);
				ODBCBuffer(const SYSTEMTIME& value);
				ODBCBuffer(const GUID& value);
				ODBCBuffer(bool value);
				ODBCBuffer(int value);
				ODBCBuffer(char value);
				ODBCBuffer(wchar_t value);
				ODBCBuffer(short value);
				ODBCBuffer(double value);
				ODBCBuffer(float value);
				ODBCBuffer(const ODBCBuffer& Buffer);
				virtual ~ODBCBuffer();
                //! convert the value to a string regardless of its internal type
                std::string ToString() const;
                //! convert the value to a unicode string regardless of its internal type
                std::wstring ToWString() const;
                //! get the data as a null-terminated string, disregarding fetched data size
				std::string GetStringValue() const { return std::string(static_cast<const char *>(& * _buffer.begin())); }
                //! get the data as a null-terminated unicode string, disregarding fetched data size
				std::wstring GetWStringValue() const { return std::wstring(reinterpret_cast<const wchar_t *>(& * _buffer.begin())); }
                //! get the raw data buffer
				const std::vector<char>& GetValue() const { return _buffer; }
                //! get a value of type integer (SQL_INTEGER, SQL_DECIMAL, etc.)
				int GetIntValue() const { return * (int *) & * _buffer.begin(); }
                //! get a value of type short (SQL_SMALLINT)
				int GetShortValue() const { return * (short *) & * _buffer.begin(); }
                //! get a value of type bool (SQL_BIT)
				bool GetBoolValue() const { return * (bool *) & * _buffer.begin(); }
                //! get a value of type longlong (SQL_BIGINT, etc.)
				LONGLONG GetLongLongValue() const { return * (LONGLONG *) & * _buffer.begin(); }                
				//! get a value of type uniqueidentifier
				GUID GetGUIDValue() const { return * (GUID *) & * _buffer.begin(); }
                //! get a value of type double
				double GetDoubleValue() const { return * (double *) & * _buffer.begin(); }
                //! get the value of type float
				float GetFloatValue() const { return * (float *) & * _buffer.begin(); }
                //! get a single character value
				char GetCharValue() const { return * (char *) & * _buffer.begin(); }
                //! get a single unicode character value
                wchar_t GetVarCharValue() const { return * (wchar_t *) & * _buffer.begin(); }
				//! get a date structure
				DATE_STRUCT GetDate() const { return * (DATE_STRUCT *) & * _buffer.begin(); }
				//! get a time structure
				TIME_STRUCT GetTime() const { return * (TIME_STRUCT *) & * _buffer.begin(); }
				//! get a timestamp structure
				TIMESTAMP_STRUCT GetTimeStamp() const { return * (TIMESTAMP_STRUCT *) & * _buffer.begin(); }
			};
		}
	}
}
