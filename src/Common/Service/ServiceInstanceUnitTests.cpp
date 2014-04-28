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

void ServiceInstanceUnitTests::testGetServiceStateString()
{
    ServiceManager scm;
    scm.Open();
    ServiceInstance instance;
    instance.Open(scm, L"W32Time");
    std::wstring state = instance.GetServiceStateString();
    CPPUNIT_ASSERT( L"Running" == state );
}

void ServiceInstanceUnitTests::testControl()
{
    ServiceManager scm;
    scm.Open();
    ServiceInstance instance;
    instance.Open(scm, L"W32Time");    
	if (! instance.IsStarted())
	{
		instance.Start();
		instance.Wait();
	}

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
    ServiceManager scm;
    scm.Open();
    ServiceInstance instance;
	AppSecInc::Service::ServiceCreateInfo create_info;
	create_info.name = L"MsiExtDemoService";

	if (scm.ServiceExists(create_info.name))
	{
		ServiceInstance deleteinstance;
		deleteinstance.Open(scm, create_info.name);
		deleteinstance.Delete();
	}

	create_info.binary_path_name = AppSecInc::File::DirectoryCombine(AppSecInc::File::GetModuleDirectoryW(), L"DemoService.exe");
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(create_info.binary_path_name));	
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
	}
	catch(std::exception& ex)
	{
		std::wcout << std::endl << L"Unexpected exception: " << AppSecInc::StringUtils::mb2wc(ex.what());
		instance.Delete();
		throw;
	}
}
