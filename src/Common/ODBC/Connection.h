#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace ODBC
		{
			enum ODBCConnectionProtocol
			{
				ODBC_CONNECTION_UNSPECIFIED = -1,
				ODBC_CONNECTION_TCPIP = 0,
				ODBC_CONNECTION_NAMEDPIPES = 1,
				ODBC_CONNECTION_RPC, // multi-protocol
				ODBC_CONNECTION_LPC, // shared memory
				ODBC_CONNECTION_SPX, // nwlink ipx/spx
				ODBC_CONNECTION_VINES, // Banyan VINES
				ODBC_CONNECTION_ADSP // Apple Talk
			};

			// Bit flags controlling behaviour of Get-methods:
			//! In GetString don't consider empty rowset as error, return empty string instead
			const WORD ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY = 0x0001; 


			//! An ODBC connection
			class ODBCConnection
			{
			protected:
                //! ODBC connection handle
				SQLHDBC _hconnection;
                //! ODBC environment
				SQLHENV _henvironment;
                //! successful initialization and connection flag
				BOOL _connected;
			public:
				ODBCConnection();
				virtual ~ODBCConnection();
                //! initialize the ODBC environment at ODBC version 3.0, fails if previously initialized
				void Initialize();
                //! terminate the ODBC environment, succeeds if Initialize has not been called
				void Terminate();
                //! connect to a host, fails if already connected
                void Connect(const ODBCConnectionInfo& connection_info);
                //! disconnect from a host, fails if not connected
				void Disconnect();
                //! get the text representation of the errors on an ODBC connection handle
                std::wstring GetError() const { return ODBCHandle::GetError(_hconnection, SQL_HANDLE_DBC); }
                //! get an array of errors on the current ODBC connection
				std::vector<ODBCError> GetErrors() const { return ODBCHandle::GetErrors(_hconnection, SQL_HANDLE_DBC); }
                //! returns the connection handle
                operator SQLHDBC() const { return _hconnection; }
                //! returns true if connected
				BOOL IsConnected() const { return _connected; }
                //! returns the environment handle
                SQLHENV GetEnvironmentHandle() const { return _henvironment; }
				//! Return a scalar result from a query (eg. a count)
				long GetScalar(const std::wstring& query) const;
				long GetScalar(const std::wstring& query, ODBCHandle& stmt) const;
                //! Return the data set from a query in xml format
                std::wstring GetXml(const std::wstring& query) const;
                //! Return the data set from a query in xml format
                MSXML2::IXMLDOMNodePtr GetXml(const std::wstring& query, AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent_node = NULL) const;
                //! Insert data from xml
                void InsertXml(const AppSecInc::Xml::XmlDocument& xmldatadoc);
                //! Insert data from xml
                void InsertXml(const AppSecInc::Xml::XmlDocument& xmldatadoc, AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent_node);
                //! Insert a single result set from xml
                void InsertXml(const AppSecInc::Xml::XmlDocument& xmldatadoc, MSXML2::IXMLDOMNodePtr result_node, AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent_node);
                //! Return a string result from a query
                std::string GetString(const std::wstring& query, WORD flags = 0) const;
				//! Return a string result and a statement handle from a query with flags
                std::string GetString(const std::wstring& query, ODBCHandle& stmt, WORD flags = 0) const;
				//! Return a string result from a query
                std::wstring GetWString(const std::wstring& query, WORD flags = 0) const;
				//! Return a string result and a statement handle from a query with flags
                std::wstring GetWString(const std::wstring& query, ODBCHandle& stmt, WORD flags = 0) const;
                //! Execute a statement
				void Execute(const std::wstring& query) const;
				void Execute(const std::wstring& query, ODBCHandle&) const;
                //! Return a row set from a query (eg. SELECT *)
				void Execute(const std::wstring& query, ODBCRowSet&) const;
                //! Execute with parameters
				void Execute(const std::wstring& query, ODBCParameters&) const;
                //! Execute with parameters and return data
				void Execute(const std::wstring& query, ODBCParameters&, ODBCRowSet&) const;
			};
		}
	}
}








