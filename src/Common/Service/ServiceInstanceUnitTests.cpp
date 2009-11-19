#include "StdAfxUnitTests.h"
#include "ServiceInstanceUnitTests.h"
#include "ServiceInstance.h"

using namespace AppSecInc::Service;
using namespace AppSecInc::UnitTests::Service;

CPPUNIT_TEST_SUITE_REGISTRATION(ServiceInstanceUnitTests);

void ServiceInstanceUnitTests::testConstructorDestructor()
{
    {
        ServiceInstance Instance;
        CPPUNIT_ASSERT(! Instance.IsOpen());
    }
}

void ServiceInstanceUnitTests::testOpenClose()
{
    ServiceManager scm;
    scm.Open();
    ServiceInstance Instance;
    Instance.Open(scm, L"Eventlog");
    CPPUNIT_ASSERT(Instance.IsOpen());
    Instance.Close();
    CPPUNIT_ASSERT(! Instance.IsOpen());
    Instance.Open(scm, L"Winmgmt");
    CPPUNIT_ASSERT(Instance.IsOpen());
}

void ServiceInstanceUnitTests::testGetServiceProcessStatus()
{
    ServiceManager scm;
    scm.Open();
    ServiceInstance instance;
    instance.Open(scm, L"Eventlog");
    SERVICE_STATUS_PROCESS status = { 0 };
    instance.GetServiceProcessStatus(& status);
    std::wcout << std::endl << L"Process ID: " << status.dwProcessId;
    CPPUNIT_ASSERT(0 != status.dwProcessId);
}

void ServiceInstanceUnitTests::testControl()
{
    ServiceManager scm;
    scm.Open();
    ServiceInstance instance;
    instance.Open(scm, L"W32Time");    
    CPPUNIT_ASSERT(instance.IsStarted());
    instance.Stop();
    CPPUNIT_ASSERT(instance.Wait());
    CPPUNIT_ASSERT(! instance.IsStarted());
    CPPUNIT_ASSERT(instance.IsStopped());
    instance.Start();
    CPPUNIT_ASSERT(instance.Wait());
    CPPUNIT_ASSERT(instance.IsStarted());
}

void ServiceInstanceUnitTests::testGetConfig()
{
    ServiceManager scm;
    scm.Open();
    ServiceInstance instance;
    instance.Open(scm, L"W32Time");
	ServiceConfig config = instance.GetConfig();
	std::wcout << std::endl << config.service_start_name;
	CPPUNIT_ASSERT(config.display_name == L"Windows Time");
	std::wcout << std::endl << config.service_start_name;
	CPPUNIT_ASSERT(config.service_start_name == L"LocalSystem" || config.service_start_name == L"NT AUTHORITY\\LocalService");
}

void ServiceInstanceUnitTests::testGetDescription()
{
    ServiceManager scm;
    scm.Open();
    ServiceInstance instance;
    instance.Open(scm, L"W32Time");
	std::wcout << std::endl << instance.GetDescription();
	CPPUNIT_ASSERT(AppSecInc::StringUtils::startsWith(instance.GetDescription(), 
		L"Maintains date and time synchronization on all clients and servers in the network."));
}

void ServiceInstanceUnitTests::testCreateDelete()
{
	// \todo: create a test service rather than dup-ing an existing one (ClipBook doesn't exist on Vista)
	CPPUNIT_IGNORE(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\ClipSrv"));

    ServiceManager scm;
    scm.Open();
    ServiceInstance instance;
	// dup the ClipBook service, C:\WINDOWS\system32\clipsrv.exe
	// HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\ClipSrv
	AppSecInc::Service::ServiceCreateInfo create_info;
	create_info.name = AppSecInc::Com::GenerateGUIDStringW();
	create_info.binary_path_name = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\ClipSrv", L"ImagePath");
	std::wcout << std::endl << L"Copying ClipSrv (" << create_info.binary_path_name << L") to " << create_info.name;
    instance.Create(scm, create_info);

	try
	{
		{
			ServiceInstance instance2;
			instance2.Open(scm, create_info.name);
		}

		instance.Start();
		instance.Wait();
		CPPUNIT_ASSERT(instance.IsStarted());
		instance.Stop();
		instance.Delete();

		try
		{
			ServiceInstance instance2;
			instance2.Open(scm, create_info.name);
			throw "expected std::exception";
		}
		catch(std::exception&) { }
	}
	catch(std::exception&)
	{
		instance.Delete();
		throw;
	}
}
