#include "StdAfxUnitTests.h"
#include "ServiceImplUnitTests.h"
#include <boost/smart_ptr.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Service::ServiceImplUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Service;

#define TEST_SERVICE_BINARY_PATH L"C:\\bogus.exe"

void ServiceImplUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"SystemTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing SystemTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Service_RenameRegistryEntry"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Service_ChangeBinaryPathName"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Service_ChangeDisplayName"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Service_ChangeDescription"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Service_Control"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Service_Delete"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Service_GetConfig"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Service_Exists"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Service_GetState"));
	::FreeLibrary(h);
}

void ServiceImplUnitTests::Test_Service_RenameRegistryEntry()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	std::wstring serviceDisplayName = L"";
	std::wstring renamedServiceDisplayName = L"";

	serviceDisplayName = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\" + service_name, L"DisplayName");

	msiInstall.SetProperty(L"SERVICE_RENAME_REGISTRY_ENTRY_FROM", service_name);
	msiInstall.SetProperty(L"SERVICE_RENAME_REGISTRY_ENTRY_TO", L"TEST_SERVICE_TEMP");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_RenameRegistryEntry"));	

	renamedServiceDisplayName = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\TEST_SERVICE_TEMP", L"DisplayName");

	CPPUNIT_ASSERT(serviceDisplayName == renamedServiceDisplayName);

	msiInstall.SetProperty(L"SERVICE_RENAME_REGISTRY_ENTRY_FROM", L"TEST_SERVICE_TEMP");
	msiInstall.SetProperty(L"SERVICE_RENAME_REGISTRY_ENTRY_TO", service_name);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_RenameRegistryEntry"));

	AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\" + service_name, L"DisplayName");
}

void ServiceImplUnitTests::Test_Service_ChangeBinaryPathName()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	std::wstring serviceBinaryPathName = L"";
	std::wstring serviceDisplayName = L"";
	std::wstring serviceDescription = L"";

	AppSecInc::Service::ServiceManager scm;
	scm.Open();
	AppSecInc::Service::ServiceInstance testinstance;
	testinstance.Open(scm, service_name);

	CPPUNIT_ASSERT(testinstance.GetConfig().binary_path_name != L"C:\\test.exe");

	msiInstall.SetProperty(L"SERVICE_CHANGE_SERVICE_NAME", service_name);
	msiInstall.SetProperty(L"SERVICE_CHANGE_BINARY_PATH_NAME", L"C:\\test.exe");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_ChangeBinaryPathName"));

	CPPUNIT_ASSERT(testinstance.GetConfig().binary_path_name == L"C:\\test.exe");
}

void ServiceImplUnitTests::Test_Service_ChangeDisplayName()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	std::wstring serviceBinaryPathName = L"";
	std::wstring serviceDisplayName = L"";
	std::wstring serviceDescription = L"";

	AppSecInc::Service::ServiceManager scm;
	scm.Open();
	AppSecInc::Service::ServiceInstance testinstance;
	testinstance.Open(scm, service_name);

	CPPUNIT_ASSERT(testinstance.GetConfig().display_name != L"New display name");

	msiInstall.SetProperty(L"SERVICE_CHANGE_SERVICE_NAME", service_name);
	msiInstall.SetProperty(L"SERVICE_CHANGE_DISPLAY_NAME", L"New display name");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_ChangeDisplayName"));

	CPPUNIT_ASSERT(testinstance.GetConfig().display_name == L"New display name");
}

void ServiceImplUnitTests::Test_Service_ChangeDescription()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	std::wstring serviceBinaryPathName = L"";
	std::wstring serviceDisplayName = L"";
	std::wstring serviceDescription = L"";

	AppSecInc::Service::ServiceManager scm;
	scm.Open();
	AppSecInc::Service::ServiceInstance testinstance;
	testinstance.Open(scm, service_name);

	CPPUNIT_ASSERT(testinstance.GetDescription() != L"New description");

	msiInstall.SetProperty(L"SERVICE_CHANGE_SERVICE_NAME", service_name);
	msiInstall.SetProperty(L"SERVICE_CHANGE_DESCRIPTION", L"New description");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_ChangeDescription"));

	CPPUNIT_ASSERT(testinstance.GetDescription() == L"New description");
}

void ServiceImplUnitTests::setUp()
{
	service_name = AppSecInc::Com::GenerateGUIDStringW();
	AppSecInc::Service::ServiceManager scm;
    scm.Open();
	AppSecInc::Service::ServiceCreateInfo create_info;
	create_info.name = service_name;
	create_info.display_name = service_name;
	create_info.binary_path_name = TEST_SERVICE_BINARY_PATH;
    AppSecInc::Service::ServiceInstance instance;
	instance.Create(scm, create_info);
}

void ServiceImplUnitTests::tearDown()
{
	AppSecInc::Service::ServiceManager scm;
    scm.Open();
    AppSecInc::Service::ServiceInstance instance;
	instance.Open(scm, service_name);
	instance.Delete();
}

void ServiceImplUnitTests::Test_Service_Control()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    AppSecInc::Service::ServiceManager scm;
    scm.Open();
    AppSecInc::Service::ServiceInstance instance;
    instance.Open(scm, L"W32Time");    
    msiInstall.SetProperty(L"SERVICE_NAME", L"W32Time");
	if (! instance.IsStarted())
	{
		instance.Start();
		::Sleep(2000);
	}
    CPPUNIT_ASSERT(instance.IsStarted());
    msiInstall.SetProperty(L"SERVICE_CONTROL", L"SERVICE_CONTROL_STOP");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_Control"));
    CPPUNIT_ASSERT(! instance.IsStarted());
    CPPUNIT_ASSERT(instance.IsStopped());
    msiInstall.SetProperty(L"SERVICE_CONTROL", L"SERVICE_CONTROL_START");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_Control"));
    CPPUNIT_ASSERT(instance.IsStarted());
}

void ServiceImplUnitTests::Test_Service_Delete()
{
	AppSecInc::Service::ServiceManager scm;
	scm.Open();
	std::wstring old_service_name = service_name;

    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    msiInstall.SetProperty(L"SERVICE_NAME", service_name);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_Delete"));

	try
	{
		AppSecInc::Service::ServiceInstance instance;
		instance.Open(scm, service_name);
		throw "expected std::exception";
	}
	catch(std::exception&) { } 

	service_name = old_service_name;
	setUp(); // prevent teardown failure
}

void ServiceImplUnitTests::Test_Service_GetConfig()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    msiInstall.SetProperty(L"SERVICE_NAME", service_name);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_GetConfig"));
	CPPUNIT_ASSERT(service_name == msiInstall.GetProperty(L"SERVICE_DISPLAY_NAME"));
	CPPUNIT_ASSERT(TEST_SERVICE_BINARY_PATH == msiInstall.GetProperty(L"SERVICE_BINARY_PATH_NAME"));
	CPPUNIT_ASSERT(L"SERVICE_ERROR_NORMAL" == msiInstall.GetProperty(L"SERVICE_ERROR_CONTROL"));
	CPPUNIT_ASSERT(L"" == msiInstall.GetProperty(L"SERVICE_LOAD_ORDER_GROUP"));
	CPPUNIT_ASSERT(L"LocalSystem" == msiInstall.GetProperty(L"SERVICE_START_NAME"));
	CPPUNIT_ASSERT(L"SERVICE_WIN32_OWN_PROCESS" == msiInstall.GetProperty(L"SERVICE_TYPE"));
	CPPUNIT_ASSERT(L"SERVICE_DEMAND_START" == msiInstall.GetProperty(L"SERVICE_START_TYPE"));
	CPPUNIT_ASSERT(L"0" == msiInstall.GetProperty(L"SERVICE_TAG_ID"));
	CPPUNIT_ASSERT(L"" == msiInstall.GetProperty(L"SERVICE_DEPENDENCIES"));
}

void ServiceImplUnitTests::Test_Service_Exists()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    msiInstall.SetProperty(L"SERVICE_NAME", service_name);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_Exists"));
	CPPUNIT_ASSERT(L"1" == msiInstall.GetProperty(L"SERVICE_EXISTS"));
	msiInstall.SetProperty(L"SERVICE_NAME", AppSecInc::Com::GenerateGUIDStringW());
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_Exists"));
	CPPUNIT_ASSERT(L"0" == msiInstall.GetProperty(L"SERVICE_EXISTS"));
}

void ServiceImplUnitTests::Test_Service_GetState()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	msiInstall.SetProperty(L"SERVICE_STATE_SERVICE_NAME", L"Eventlog");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_GetState"));
	CPPUNIT_ASSERT(L"Running" == msiInstall.GetProperty(L"SERVICE_STATE"));

	msiInstall.SetProperty(L"SERVICE_STATE_SERVICE_NAME", L"Wecsvc");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_GetState"));
	CPPUNIT_ASSERT(L"Stopped" == msiInstall.GetProperty(L"SERVICE_STATE"));

	msiInstall.SetProperty(L"SERVICE_STATE_SERVICE_NAME", AppSecInc::Com::GenerateGUIDStringW());
	CPPUNIT_ASSERT(ERROR_SUCCESS != hInstall.ExecuteCA(L"SystemTools.dll", L"Service_GetState"));
	// SERVICE_STATE should remain unchanged
	CPPUNIT_ASSERT(L"Stopped" == msiInstall.GetProperty(L"SERVICE_STATE"));
}

void ServiceImplUnitTests::Test_Service_GetState_Accepts_SERVICE_NAME()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	msiInstall.SetProperty(L"SERVICE_NAME", L"W32Time");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_GetState"));
	CPPUNIT_ASSERT(L"Running" == msiInstall.GetProperty(L"SERVICE_STATE"));

	// more specific name should override generic one:
	msiInstall.SetProperty(L"SERVICE_STATE_SERVICE_NAME", L"Wecsvc");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Service_GetState"));
	CPPUNIT_ASSERT(L"Stopped" == msiInstall.GetProperty(L"SERVICE_STATE"));
}
