#include "stdAfx.h"
#include "FlagMaps.h"

CA_API UINT __stdcall TcpIp_BindSocket(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
	MsiInstall msiInstall(hInstall);
	msiInstall.SetProperty(L"TCPIP_BIND_SUCCEEDED", L"0");

	// validate the port number
	std::wstring tcpport_s = msiInstall.GetProperty(L"TCP_PORT");
	long tcpport = AppSecInc::StringUtils::stringToLong(tcpport_s, -1);
	CHECK_BOOL(tcpport > 0 && tcpport < 65536, L"Invalid port: " << tcpport_s);

	std::string tcpaddress = msiInstall.GetProperty("TCP_IPADDRESS");
	if (tcpaddress.empty()) tcpaddress = "127.0.0.1";

	AppSecInc::TcpIp::CWSAStartup wsa;
	if (! AppSecInc::TcpIp::DNS::IsIpAddress(tcpaddress))
	{
		tcpaddress = AppSecInc::TcpIp::DNS::GetHostIpAddresses(tcpaddress)[0];
	}

	AppSecInc::TcpIp::Sockets::Socket socket;
	
	socket.Bind(tcpaddress, tcpport);
	msiInstall.SetProperty(L"TCPIP_BIND_SUCCEEDED", L"1");

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}

CA_API UINT __stdcall TcpIp_Connect(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
	MsiInstall msiInstall(hInstall);
	msiInstall.SetProperty(L"TCPIP_CONNECTION_ESTABLISHED", L"0");

	// validate the port number
	std::wstring tcpport_s = msiInstall.GetProperty(L"TCP_PORT");
	long tcpport = AppSecInc::StringUtils::stringToLong(tcpport_s, -1);
	CHECK_BOOL(tcpport > 0 && tcpport < 65536, L"Invalid port: " << tcpport_s);

	std::string tcpaddress = msiInstall.GetProperty("TCP_IPADDRESS");
	if (tcpaddress.empty()) tcpaddress = "127.0.0.1";

	AppSecInc::TcpIp::CWSAStartup wsa;
	if (! AppSecInc::TcpIp::DNS::IsIpAddress(tcpaddress))
	{
		tcpaddress = AppSecInc::TcpIp::DNS::GetHostIpAddresses(tcpaddress)[0];
	}

	int type = GetPropertyValue(msiInstall, L"TCP_SOCKET_TYPE", s_TcpSocketTypeFlags);
	if (type == 0) type = SOCK_STREAM;
	int flags = GetPropertyValue(msiInstall, L"TCP_PROTOCOL", s_IpProtocolFlags);
	if (flags == 0) flags = IPPROTO_TCP;

	AppSecInc::TcpIp::Sockets::Socket socket;
	socket.Connect(tcpaddress, tcpport, type, flags);
	msiInstall.SetProperty(L"TCPIP_CONNECTION_ESTABLISHED", L"1");	

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}

CA_API UINT __stdcall TcpIp_ListAddresses(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
	
	MsiInstall msiInstall(hInstall);
    MsiView msiView;
    MsiHandle msiDatabase(MsiGetActiveDatabase(hInstall));

    // find the listbox to populate and clear it

	// the name of the property attached to the list
    std::wstring listbox = msiInstall.GetProperty(L"IP_LIST_PROPERTY");
	if (listbox.length() == 0) throw std::exception("Missing IP_LIST_PROPERTY");
    // the type of the list
    std::wstring listtype = msiInstall.GetProperty(L"IP_LIST_TYPE");
    if (listtype.length() == 0) throw std::exception("Missing IP_LIST_TYPE");
    // the index at which to start
    std::wstring listindex = msiInstall.GetProperty(L"IP_LIST_INDEX");

    // by default we assume that the list has 1 item, so start at index 2
	long index = AppSecInc::StringUtils::stringToLong(listindex, 2);

	std::wstringstream query;
    query << L"SELECT * FROM `" << listtype << "` WHERE `Property`='" << listbox << L"'";
    
    CHECK_WIN32_DWORD(MsiDatabaseOpenView(msiDatabase, query.str().c_str(), & msiView),
		L"MsiDatabaseOpenView query \"" << query << L"\" failed");

    // list Network Adapter Information
	std::vector<std::wstring> names;
	std::vector<std::wstring> addresses;
	std::wstring hostname;

	AppSecInc::TcpIp::CWSAStartup wsa;
	AppSecInc::TcpIp::DNS::GetHostInfo(AppSecInc::TcpIp::NetBIOS::GetComputerName(), 
		hostname, names, addresses);

    LONG insert_index = index;
	for each (const std::wstring& address in addresses)
	{
        // the first record is inserted at index 2, there's at least one default item in the view
        MsiHandle hRec(MsiCreateRecord(4));
        CHECK_WIN32_DWORD(MsiRecordSetString(hRec, 1, listbox.c_str()),
			L"MsiRecordSetString(1) failed"); // Column1: Property tied to the entry
        CHECK_WIN32_DWORD(MsiRecordSetInteger(hRec, 2, insert_index),
			"MsiRecordSetInteger(2) failed"); // Column2: Display order of the item
        CHECK_WIN32_DWORD(MsiRecordSetString(hRec, 3, address.c_str()),
			"MsiRecordSetString(3) failed"); //Column3: Value to set property to
        CHECK_WIN32_DWORD(MsiRecordSetString(hRec, 4, address.c_str()),
			L"MsiRecordSetString(4) failed"); //Column4: Display text for item
        CHECK_WIN32_DWORD(MsiViewModify(msiView, MSIMODIFY_INSERT_TEMPORARY, hRec),
			"MsiViewModify failed");
        
		insert_index ++;
	}

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}