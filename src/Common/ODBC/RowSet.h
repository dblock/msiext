#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace ODBC
		{
            //! An ODBC rowset
			class ODBCRowSet
			{
			private:
                //! statement that the rowset has resulted from
				ODBCHandle _stmt;
                //! columns bound to the statement
				std::vector<ODBCColumn *> _columns;
                //! a map of columns bound to the statement
				std::map<std::wstring, ODBCColumn *> _columnmap;
                //! a vector of messages, see http://support.microsoft.com/kb/140696
				std::vector<ODBCDiagnosticsMessage> _messages;
                //! copy a rowset is forbidden
                ODBCRowSet& operator=(const ODBCRowSet& value) { };
			public:
                //! get the executed statement messages
				const std::vector<ODBCDiagnosticsMessage>& GetMessages() const { return _messages; }
                //! get the number of columns
                unsigned int GetColumnCount() const { return _columns.size(); }
                //! get a column by name
				const ODBCColumn * operator[](const std::wstring& name) const;
                //! get a column by index
                const ODBCColumn * operator[](int index) const;
                //! get the statement handle
				const ODBCHandle& PeekStatementHandle() const { return _stmt; }
                //! add a named column with a defined type and initial size
				void AddColumn(const std::wstring& name, int type, int size = ODBCColumn::INVALID_SIZE);
                //! bind the rowset to a connection
				void Bind(SQLHANDLE hconn);
				//! bind columns
				void BindColumns();
                //! fetch the next row
                //! \return true if no more rows
				bool Fetch();
                //! execute the query
				void ExecuteDirect(const std::wstring& query);
                //! execute the query
				void Prepare(const std::wstring& query);
                //! execute the query
				void Execute();
                //! get the text representation of the errors on an ODBC connection handle
                std::wstring GetError() const { return _stmt.GetError(); }
                //! get an array of errors on the current ODBC connection
				std::vector<ODBCError> GetErrors() const { return _stmt.GetErrors(); }
				//! get the actual column count in the result set
				SQLSMALLINT GetNumResultCols() const;
				//! get the cached row count in the result set
				//! \returns -1 if the affected row count is not available
				SQLINTEGER GetSQLRowCount() const;
				ODBCRowSet();
				virtual ~ODBCRowSet();
			};
		}
	}
}
