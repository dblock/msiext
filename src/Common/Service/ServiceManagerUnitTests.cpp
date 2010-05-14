#include "StdAfxUnitTests.h"
#include "ServiceManagerUnitTests.h"
#include "ServiceManager.h"

using namespace AppSecInc::Service;
using namespace AppSecInc::UnitTests::Service;

CPPUNIT_TEST_SUITE_REGISTRATION(ServiceManagerUnitTests);

void ServiceManagerUnitTests::testConstructorDestructor()
{
    {
        ServiceManager manager;
        CPPUNIT_ASSERT(! manager.IsOpen());
    }
}

void ServiceManagerUnitTests::testOpenClose()
{
    ServiceManager manager;
    manager.Open();
    CPPUNIT_ASSERT(manager.IsOpen());
    manager.Close();
    CPPUNIT_ASSERT(! manager.IsOpen());
    manager.Open();
    CPPUNIT_ASSERT(manager.IsOpen());
}

void ServiceManagerUnitTests::testGetServices()
{
	ServiceManager manager;
	manager.Open();
	std::list<ServiceStatusProcess> services = manager.GetServices();
	CPPUNIT_ASSERT(services.size() > 0);
	for each(const ServiceStatusProcess& sp in services)
	{
		if (sp.name == L"MsiExtDemoService")
			continue;

		CPPUNIT_ASSERT(sp.name.size() > 0);
		std::wcout << std::endl 
			<< sp.name << L" (" << sp.display_name << L")"
			<< (sp.status_process.dwProcessId ? L" [" + AppSecInc::StringUtils::toWString(sp.status_process.dwProcessId) + L"]" : L"");
		ServiceInstance si;
		si.Open(manager, sp.name, GENERIC_READ);
		ServiceConfig config = si.GetConfig();
		std::wcout << std::endl << L" " << config.binary_path_name;
		for each(const std::wstring dependency in config.dependencies)
		{
			std::wcout << std::endl << L"  " << dependency;
			if (! AppSecInc::StringUtils::startsWith(dependency, AppSecInc::StringUtils::toWString(SC_GROUP_IDENTIFIER)))
			{
				ServiceInstance si_dependency;
				si_dependency.Open(manager, dependency, GENERIC_READ);
				ServiceConfig config_dependency = si_dependency.GetConfig();
				std::wcout << L" (" << config_dependency.display_name << L")";
			}
		}
	}
}

void ServiceManagerUnitTests::testServiceExists()
{
	ServiceManager manager;
	manager.Open();
	CPPUNIT_ASSERT(! manager.ServiceExists(AppSecInc::Com::GenerateGUIDStringW()));
	CPPUNIT_ASSERT(manager.ServiceExists(L"W32Time"));
}