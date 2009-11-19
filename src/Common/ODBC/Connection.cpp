#include "StdAfx.h"
#include "ConnectionInfo.h"
#include "Connection.h"

using namespace AppSecInc::Databases;
using namespace AppSecInc::Databases::ODBC;

ODBCConnection::ODBCConnection()
	: _hconnection(NULL)
	, _henvironment(NULL)
	, _connected(FALSE)
{

}

ODBCConnection::~ODBCConnection()
{
	if (_connected) 
	{
		Disconnect();
	}

	if (_henvironment != NULL || _hconnection != NULL) 
	{
		Terminate();
	}
}

void ODBCConnection::Initialize()
{
	CHECK_BOOL(_henvironment == NULL && _hconnection == NULL,
		L"Environment has already been initialized.");

	// allocate an environment handle
	CHECK_BOOL(SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_ENV, NULL, & _henvironment)),
		L"Error allocating SQL environment handle.");

	// set the ODBC version
	CHECK_BOOL(SQL_SUCCEEDED(SQLSetEnvAttr(_henvironment, SQL_ATTR_ODBC_VERSION, reinterpret_cast<LPVOID>(SQL_OV_ODBC3), SQL_IS_INTEGER)),
		L"Error setting environment attributes.");

	// allocate the connection handle
	CHECK_BOOL(SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_DBC, _henvironment, & _hconnection)),
		L"Error allocating SQL connection handle.");
}

void ODBCConnection::Terminate()
{
	if (NULL != _hconnection)
	{
		SQLFreeHandle(SQL_HANDLE_DBC, _hconnection);
		_hconnection = NULL;
	}

	if (NULL != _henvironment) 
	{
		SQLFreeHandle(SQL_HANDLE_ENV, _henvironment);
		_henvironment = NULL;
	}
}

void ODBCConnection::Connect(const ODBCConnectionInfo& connection_info)
{
	if (_henvironment == NULL && _hconnection == NULL)
	{
		Initialize();
	}

	CHECK_BOOL(_henvironment != NULL && _hconnection != NULL,
		L"Environment has not been initialized.");

	CHECK_BOOL(! _connected, L"Connection already opened.");

	std::wstring connection_string = connection_info.GetConnectionString();

    const int ODBC_MAX_BUFFER_LEN = 1024;
	wchar_t buffer[ODBC_MAX_BUFFER_LEN + 1] = { 0 };
	SQLSMALLINT buffer_len = 0;
	
	SQLRETURN rc = SQLDriverConnect(
			_hconnection, 
			NULL,
            (SQLWCHAR *) connection_string.c_str(), 
			connection_string.length(), 
			(SQLWCHAR *) buffer,
			(SQLSMALLINT) sizeof(buffer),
			& buffer_len,
			SQL_DRIVER_NOPROMPT);

	CHECK_BOOL(SQL_SUCCEEDED(rc),
			L"Error connecting to server: " << GetError());

	_connected = true;
}

void ODBCConnection::Disconnect()
{
	CHECK_BOOL(_connected, L"Not connected.");

	CHECK_BOOL(SQL_SUCCEEDED(SQLDisconnect(_hconnection)),
		L"Error disconnecting.");

	_connected = false;
}

long ODBCConnection::GetScalar(const std::wstring& query) const
{
	ODBCHandle stmt;
	return GetScalar(query, stmt);
}

long ODBCConnection::GetScalar(const std::wstring& query, ODBCHandle& stmt) const
{
    stmt.Allocate(SQL_HANDLE_STMT, _hconnection);

    CHECK_BOOL(SQL_SUCCEEDED(SQLExecDirect(stmt.Peek(), (SQLWCHAR *) query.c_str(), SQL_NTS)),
		L"Error executing \"" << query << L"\": " << stmt.GetError());

    CHECK_BOOL(SQL_SUCCEEDED(SQLFetch(stmt.Peek())),
        L"Error fetching \"" << query << L"\": " << stmt.GetError());

    long result = 0;
    CHECK_BOOL(SQL_SUCCEEDED(SQLGetData(stmt.Peek(), 1, SQL_C_LONG, & result, 0, NULL)),
		L"Error getting data for \"" << query << L"\": " << stmt.GetError());

    stmt.Release();
    return result;
}

std::string ODBCConnection::GetString(const std::wstring& query, WORD flags) const
{
	ODBCHandle stmt;
	return GetString(query, stmt, flags);
}

std::string ODBCConnection::GetString(const std::wstring& query, ODBCHandle& stmt, WORD flags) const
{
    stmt.Allocate(SQL_HANDLE_STMT, _hconnection);

    CHECK_BOOL(SQL_SUCCEEDED(SQLExecDirect(stmt.Peek(), (SQLWCHAR *) query.c_str(), SQL_NTS)),
		L"Error executing \"" << query << L"\": " << stmt.GetError());

	int rc = SQLFetch(stmt.Peek());
	if ((SQL_NO_DATA == rc) && (flags & ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY)) 
	{
			return "";
	}

	CHECK_BOOL(SQL_SUCCEEDED(rc), 
		L"Error fetching \"" << query << L"\": " << stmt.GetError() << L".");

    std::vector<byte> result;
    result.resize(1);
    SQLINTEGER result_size = 0;

    rc = SQLGetData(stmt.Peek(), 1, SQL_C_CHAR, & * result.begin(), result.size(), & result_size);
    CHECK_BOOL(SQL_SUCCEEDED(rc),
	    L"Error getting data for \"" << query << L"\": " << stmt.GetError());

    if (rc == SQL_SUCCESS_WITH_INFO)
    {
        result.resize(result_size + 1);
        CHECK_BOOL(SQL_SUCCEEDED(SQLGetData(stmt.Peek(), 1, SQL_C_CHAR, & * result.begin(), result.size(), & result_size)),
	        L"Error getting data for \"" << query << L"\": " << stmt.GetError());
    }

    stmt.Release();

    std::string stringresult;
    stringresult.assign((char *) & * result.begin(), result_size);
    return stringresult;
}

std::wstring ODBCConnection::GetWString(const std::wstring& query, WORD flags) const
{
	ODBCHandle stmt;
	return GetWString(query, stmt, flags);
}

std::wstring ODBCConnection::GetWString(const std::wstring& query, ODBCHandle& stmt, WORD flags) const
{
    stmt.Allocate(SQL_HANDLE_STMT, _hconnection);

    CHECK_BOOL(SQL_SUCCEEDED(SQLExecDirect(stmt.Peek(), (SQLWCHAR *) query.c_str(), SQL_NTS)),
		L"Error executing \"" << query << L"\": " << stmt.GetError());

	int rc = SQLFetch(stmt.Peek());
	if ((SQL_NO_DATA == rc) && (flags & ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY)) 
	{
			return L"";
	}

	CHECK_BOOL(SQL_SUCCEEDED(rc), 
		L"Error fetching \"" << query << L"\": " << stmt.GetError() << L".");

    // get the size of the target buffer first, one byte returns the null terminator only
    std::vector<byte> result;
    result.resize(2);
    SQLINTEGER result_size = 0;

    rc = SQLGetData(stmt.Peek(), 1, SQL_C_WCHAR, & * result.begin(), result.size(), & result_size);
    CHECK_BOOL(SQL_SUCCEEDED(rc),
	    L"Error getting data for \"" << query << L"\": " << stmt.GetError());

    if (rc == SQL_SUCCESS_WITH_INFO)
    {
        result.resize(result_size + 2);
        CHECK_BOOL(SQL_SUCCEEDED(SQLGetData(stmt.Peek(), 1, SQL_C_WCHAR, & * result.begin(), result.size(), & result_size)),
	        L"Error getting data for \"" << query << L"\": " << stmt.GetError());
    }

    stmt.Release();

    std::wstring stringresult;
    stringresult.assign(reinterpret_cast<LPCWSTR>(& * result.begin()), result_size / 2);
    return stringresult;
}

void ODBCConnection::Execute(const std::wstring& query, ODBCRowSet& result) const
{
	result.Bind(_hconnection);
	result.Prepare(query);
	result.BindColumns();
	result.Execute();
}

void ODBCConnection::Execute(const std::wstring& query) const
{
	ODBCHandle stmt;
    Execute(query, stmt);
	stmt.Release();
}

void ODBCConnection::Execute(const std::wstring& query, ODBCHandle& stmt) const
{
    stmt.Allocate(SQL_HANDLE_STMT, _hconnection);

    int rc = SQLExecDirect(stmt.Peek(), (SQLWCHAR *) query.c_str(), SQL_NTS);

    switch(rc)
    {
    case SQL_NO_DATA:
        break;
    default:
        CHECK_BOOL(SQL_SUCCEEDED(rc),
		    L"Error executing \"" << query << L"\": " << stmt.GetError());
    }
}

MSXML2::IXMLDOMNodePtr ODBCConnection::GetXml(const std::wstring& query, AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent_node) const
{
    MSXML2::IXMLDOMNodePtr root_node = xmldoc.AppendChild(L"DataSet", parent_node); 
    MSXML2::IXMLDOMNodePtr query_node = xmldoc.AppendChild(L"Query", root_node);
    query_node->text = _bstr_t(query.c_str());
    MSXML2::IXMLDOMNodePtr rows_node = xmldoc.AppendChild(L"RowSet", root_node);
    MSXML2::IXMLDOMNodePtr messages_node = xmldoc.AppendChild(L"Messages", root_node);

	ODBCRowSet results;
    Execute(query, results);

	for each(const ODBCDiagnosticsMessage& message in results.GetMessages())
    {
        MSXML2::IXMLDOMNodePtr message_node = xmldoc.AppendChild(L"Message", messages_node);
		xmldoc.SetAttribute(L"component", message.component, message_node);
		xmldoc.SetAttribute(L"datasource", message.datasource, message_node);
		xmldoc.SetAttribute(L"vendor", message.vendor, message_node);
        message_node->text = _bstr_t(message.text.c_str());
    }

	SQLSMALLINT columns = results.GetNumResultCols();
    SQLINTEGER rows = (columns > 0 ? results.GetSQLRowCount() : 0); // \todo on SELECT @@VERSION this returns -1 (?)

    // the column count might only be known after the statement has been executed
    results.BindColumns();

    xmldoc.SetAttribute(L"columns", AppSecInc::StringUtils::toWString(columns), root_node);

    int rowcount = 0;
	while(rows != 0 && results.Fetch())
	{
        CHECK_BOOL(results.GetNumResultCols() > 0,
            L"Invalid column count at row " << rows);

        MSXML2::IXMLDOMNodePtr row_node = xmldoc.AppendChild(L"Row", rows_node);
        for (unsigned int i = 0; i < results.GetColumnCount(); i++)
        {
            std::wstring name = results[i]->GetName();
            if (name.empty()) name = L"Column" + AppSecInc::StringUtils::toWString(i + 1);
            MSXML2::IXMLDOMNodePtr column_node = xmldoc.AppendChild(name, row_node);
            xmldoc.SetAttribute(L"type", ODBCBuffer::SQLTypeToString(results[i]->GetType()), column_node);
            column_node->text = _bstr_t(results[i]->ToWString().c_str());
        }

        rowcount ++;
	}

    xmldoc.SetAttribute(L"rows", AppSecInc::StringUtils::toWString(rowcount), root_node);
    return root_node;
}

std::wstring ODBCConnection::GetXml(const std::wstring& query) const
{
    AppSecInc::Xml::XmlDocument xmldoc;
    xmldoc.Create();    
    GetXml(query, xmldoc, NULL);
    return xmldoc.GetXml();
}

void ODBCConnection::Execute(const std::wstring& query, ODBCParameters& params) const
{
	ODBCHandle stmt;
	stmt.Allocate(SQL_HANDLE_STMT, _hconnection);
	params.Bind(stmt.Peek());

	std::wstring query_copy = query;

    int rc = SQLExecDirect(stmt.Peek(), (SQLWCHAR *) query_copy.c_str(), SQL_NTS);

	while(rc == SQL_SUCCESS_WITH_INFO)
	{
		// there was a warning, execute the next statement to fetch the data set
		rc = SQLMoreResults(stmt.Peek());

        if (rc == SQL_NO_DATA)
            break;

		CHECK_BOOL(SQL_SUCCEEDED(rc),
			L"Error in SQLMoreResults(): " << stmt.GetError());
	}

    switch(rc)
    {
    case SQL_NO_DATA:
        break;
    default:
        CHECK_BOOL(SQL_SUCCEEDED(rc),
		    L"Error executing \"" << query << L"\": " << stmt.GetError());
    }

    stmt.Release();
}

void ODBCConnection::Execute(const std::wstring& query, ODBCParameters& params, ODBCRowSet& result) const
{
	result.Bind(_hconnection);
	result.Prepare(query);
	params.Bind(result.PeekStatementHandle().Peek());
	result.BindColumns();
	result.Execute();
}

void ODBCConnection::InsertXml(const AppSecInc::Xml::XmlDocument& dataxmldoc)
{
    AppSecInc::Xml::XmlDocument xmldoc;
    xmldoc.LoadXml(L"<Data />");
    InsertXml(dataxmldoc, xmldoc, xmldoc.SelectNode(L"/Data"));
}

void ODBCConnection::InsertXml(const AppSecInc::Xml::XmlDocument& dataxmldoc, AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent_node)
{
    MSXML2::IXMLDOMNodeListPtr dataset_rows = dataxmldoc.SelectNodes(L"/Data/DataSet");
    MSXML2::IXMLDOMNodePtr dataset_row = NULL;
    while (NULL != (dataset_row = dataset_rows->nextNode()))
    {
        InsertXml(dataxmldoc, dataset_row, xmldoc, xmldoc.AppendChild(L"DataSet", parent_node));
    }
}

void ODBCConnection::InsertXml(const AppSecInc::Xml::XmlDocument& dataxmldoc, MSXML2::IXMLDOMNodePtr dataset_node, AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent_node)
{
    MSXML2::IXMLDOMNodePtr table_node = dataxmldoc.SelectNode(L"RowSet", dataset_node);
    std::wstring table_name = dataxmldoc.SelectAttributeValue(L"table", table_node, L"");
    CHECK_BOOL(table_name.length() > 0, L"Missing <RowSet table=\"table name\">");
    xmldoc.SetAttribute(L"table", table_name, parent_node);
    MSXML2::IXMLDOMNodePtr messages_node = xmldoc.AppendChild(L"Messages", parent_node);
    MSXML2::IXMLDOMNodeListPtr table_rows = dataxmldoc.SelectNodes(L"RowSet/Row", dataset_node);
    MSXML2::IXMLDOMNodePtr table_row = NULL;
    long rows_affected = 0;
    while (NULL != (table_row = table_rows->nextNode()))
    {
		ODBCParameters parameters;
        std::vector<std::wstring> columns;
        std::vector<std::wstring> args;

        // insert a single row of data
        MSXML2::IXMLDOMNodePtr data_column = NULL;
        MSXML2::IXMLDOMNodeListPtr data_columns = table_row->childNodes;
        while (NULL != (data_column = data_columns->nextNode()))
        {
            std::wstring data_column_value = static_cast<LPCWSTR>(data_column->text);
            if (data_column_value == L"NULL")
                continue;

            std::wstring data_column_name = static_cast<LPCWSTR>(data_column->nodeName);
            data_column_name = L"[" + data_column_name + L"]";
            columns.push_back(data_column_name);
            args.push_back(L"?");
            
            std::wstring type = dataxmldoc.SelectAttributeValue(L"type", data_column, L"wchar");
            int sqltype = ODBCBuffer::StringToSQLType(type);
            parameters.AddParameter(ODBCParameter::Create(static_cast<LPCWSTR>(data_column->nodeName), data_column_value, sqltype));
        }

        std::wstringstream query;
        query << L"INSERT INTO " << table_name 
            << L" ( " << AppSecInc::StringUtils::join(columns, L",") << L" )"
            << L" VALUES ( " << AppSecInc::StringUtils::join(args, L",") << L" )";

        ODBCRowSet rowset;
		Execute(query.str(), parameters, rowset);

	    for each(const ODBCDiagnosticsMessage& message in rowset.GetMessages())
        {
            MSXML2::IXMLDOMNodePtr message_node = xmldoc.AppendChild(L"Message", messages_node);
		    xmldoc.SetAttribute(L"component", message.component, message_node);
		    xmldoc.SetAttribute(L"datasource", message.datasource, message_node);
		    xmldoc.SetAttribute(L"vendor", message.vendor, message_node);
            message_node->text = _bstr_t(message.text.c_str());
        }

        SQLINTEGER row_count = rowset.GetSQLRowCount();
        rows_affected += (row_count > 0) ? row_count : 0;
    }

    xmldoc.SetAttribute(L"rowsaffected", AppSecInc::StringUtils::toWString(rows_affected), parent_node);
}