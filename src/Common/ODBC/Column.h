#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace ODBC
		{
            //! An ODBC column
            class ODBCColumn : public ODBCBuffer
			{
            private:
                //! the name of the column
				std::wstring _name;
                //! a bound/unbound column
                bool _bound;
                //! get the binding data type
                SQLSMALLINT GetBindDataType() const;
			public:
                //! returns true if the column has been bound to a statement
                bool IsBound() const { return _bound; }
                //! copy operator for data only, not binding
                void operator=(const ODBCColumn&);
                //! get the name of the column
				const std::wstring& GetName() const { return _name; }
                //! bind the column to a statement at a given index
				void BindAt(SQLHANDLE hstmt, int index);
                //! get all column data
                void GetDataAt(SQLHANDLE hstmt, int index);
				ODBCColumn(const ODBCColumn& column);
                /*! ODBC column
                    \param name column name
                    \param type SQL type
                    \param size column size in bytes
                */
                ODBCColumn(const std::wstring& name, SQLSMALLINT type, SQLINTEGER size = ODBCBuffer::INVALID_SIZE);
				virtual ~ODBCColumn();
			};
		}
	}
}



