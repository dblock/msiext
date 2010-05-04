#include "StdAfxUnitTests.h"
#include "TcpIpImplUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::TcpIp::TcpIpImplUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::TcpIp;

void TcpIpImplUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"SystemTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing SystemTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "TcpIp_BindSocket"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "TcpIp_Connect"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "TcpIp_ListAddresses"));
	::FreeLibrary(h);
}

void TcpIpImplUnitTests::Test_TcpIp_BindSocket_Local()
{
    AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	wchar_t computername[MAX_COMPUTERNAME_LENGTH + 1] = { 0 };
	int port = 20002;
	DWORD size = MAX_COMPUTERNAME_LENGTH;
	CPPUNIT_ASSERT(::GetComputerName(computername, & size));
	std::wcout << std::endl << L"Binding " << computername << L":" << port;
	msiInstall.SetProperty(L"TCP_IPADDRESS", computername);
	msiInstall.SetProperty(L"TCP_PORT", AppSecInc::StringUtils::toWString(port));
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"TcpIp_BindSocket"));
    CPPUNIT_ASSERT(L"1" == msiInstall.GetProperty(L"TCPIP_BIND_SUCCEEDED"));

	AppSecInc::TcpIp::CWSAStartup wsa;
	std::wstring tcpaddress = AppSecInc::TcpIp::DNS::GetHostIpAddresses(computername)[0];
	std::wcout << std::endl << "Binding " << tcpaddress << L":" << port;
	msiInstall.SetProperty(L"TCP_IPADDRESS", tcpaddress);
	msiInstall.SetProperty(L"TCP_PORT", AppSecInc::StringUtils::toWString(port));
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"TcpIp_BindSocket"));
    CPPUNIT_ASSERT(L"1" == msiInstall.GetProperty(L"TCPIP_BIND_SUCCEEDED"));
}

void TcpIpImplUnitTests::Test_TcpIp_BindSocket()
{
    AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	typedef struct  
	{
		LPCWSTR testTcpPort;
		int testExpectedResult;
	} TestData;

	TestData testData[] = 
	{
		{ L"35208", ERROR_SUCCESS },
		{ L"25931", ERROR_SUCCESS },
		{ L"25931", ERROR_SUCCESS },
		{ L"18632", ERROR_SUCCESS },
		{ L"85000", AppSecInc::Msi::Exceptions::default_error_code },
		{ L"invalid", AppSecInc::Msi::Exceptions::default_error_code },
		{ L"445", AppSecInc::Msi::Exceptions::default_error_code } // Assuming Microsoft-DS is running
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::wcout << std::endl << L"Binding " << testData[i].testTcpPort;
		// msiInstall.SetProperty(L"TCP_IPADDRESS", L"127.0.0.1");
		msiInstall.SetProperty(L"TCP_PORT", testData[i].testTcpPort);
		CPPUNIT_ASSERT(testData[i].testExpectedResult == hInstall.ExecuteCA(L"SystemTools.dll", L"TcpIp_BindSocket"));
		if (testData[i].testExpectedResult != ERROR_SUCCESS)
		{
            CPPUNIT_ASSERT(L"0" == msiInstall.GetProperty(L"TCPIP_BIND_SUCCEEDED"));
			std::wcout << std::endl << L" " << msiInstall.GetProperty(L"CA_ERROR");
		}
        else
        {
            CPPUNIT_ASSERT(L"1" == msiInstall.GetProperty(L"TCPIP_BIND_SUCCEEDED"));
        }
	}
}

void TcpIpImplUnitTests::Test_TcpIp_Connect()
{
    AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	typedef struct  
	{
		LPCWSTR testTcpIpAddress;
		LPCWSTR testTcpPort;
		int testExpectedResult;
	} TestData;

	TestData testData[] = 
	{
		{ L"127.0.0.1", L"135", ERROR_SUCCESS },
		{ L"www.codeplex.com", L"80", ERROR_SUCCESS },
		{ L"www.codeplex.com", L"123", AppSecInc::Msi::Exceptions::default_error_code },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::wcout << std::endl << L"Connecting to " << testData[i].testTcpIpAddress << L":" << testData[i].testTcpPort;
		msiInstall.SetProperty(L"TCP_IPADDRESS", testData[i].testTcpIpAddress);
		msiInstall.SetProperty(L"TCP_PORT", testData[i].testTcpPort);
		// msiInstall.SetProperty(L"TCP_SOCKET_TYPE", L"SOCK_STREAM");
		// msiInstall.SetProperty(L"TCP_PROTOCOL", L"IPPROTO_TCP");
		CPPUNIT_ASSERT(testData[i].testExpectedResult == hInstall.ExecuteCA(L"SystemTools.dll", L"TcpIp_Connect"));
		if (testData[i].testExpectedResult != ERROR_SUCCESS)
		{
            CPPUNIT_ASSERT(L"0" == msiInstall.GetProperty(L"TCPIP_CONNECTION_ESTABLISHED"));
			std::wcout << std::endl << L" " << msiInstall.GetProperty(L"CA_ERROR");
		}
        else
        {
            CPPUNIT_ASSERT(L"1" == msiInstall.GetProperty(L"TCPIP_CONNECTION_ESTABLISHED"));
        }
	}
}

void TcpIpImplUnitTests::Test_TcpIp_ListAddresses()
{
	AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"ComboBox.idt"); 
    MsiInstall msiInstall(hInstall);

    msiInstall.SetProperty("IP_LIST_PROPERTY", "IP_TEST");
    msiInstall.SetProperty("IP_LIST_TYPE", "ComboBox");
    msiInstall.SetProperty("IP_LIST_INDEX", "1");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"TcpIp_ListAddresses"));
    AppSecInc::Xml::XmlDocument listxml;
    listxml.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `ComboBox`"));
	MSXML2::IXMLDOMNodeListPtr rows = listxml.SelectNodes(L"//Row");
    long rowcount = rows->length;
    std::wcout << std::endl << L"Rows: " << rowcount;
    CPPUNIT_ASSERT(rowcount > 0);
	MSXML2::IXMLDOMNodePtr row = NULL;
	
	while (NULL != (row = rows->nextNode()))
	{
		std::wstring value = listxml.GetNodeValue(L"Data[@Column='Value']", row);
		std::wcout << std::endl << L" " << value;
	}
}
