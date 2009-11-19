#include "StdAfxUnitTests.h"
#include "Win32ExceptionUnitTests.h"
#include <String/StringUtils.h>

using namespace AppSecInc::UnitTests::Exception;

CPPUNIT_TEST_SUITE_REGISTRATION(Win32ExceptionUnitTests);

void Win32ExceptionUnitTests::testDWORD()
{
	try
	{
        throw std::exception(AppSecInc::Exception::Win32Exception::GetErrorString(ERROR_NOT_FOUND).c_str());		
	}
    catch(std::exception& ex)
	{
		std::wcout << std::endl << ex.what();
	}
}

void Win32ExceptionUnitTests::testGetLastError()
{
	try
	{
		::SetLastError(ERROR_SUCCESS);
        throw std::exception(AppSecInc::Exception::Win32Exception::GetLastErrorString().c_str());		
	}
    catch(std::exception& ex)
	{
		std::wcout << std::endl << ex.what();
	}
}

void Win32ExceptionUnitTests::testHRESULT()
{
	try
	{
        throw std::exception(AppSecInc::Exception::Win32Exception::GetErrorString(HRESULT_FROM_WIN32(ERROR_NOT_FOUND)).c_str());		
	}
    catch(std::exception& ex)
	{
		std::wcout << std::endl << ex.what();
	}
}

void Win32ExceptionUnitTests::testGetLastErrorComposite()
{
	try
	{
		::SetLastError(ERROR_SUCCESS);
        throw std::exception(AppSecInc::Exception::Win32Exception::GetLastErrorString(_T("UT")).c_str());		
	}
    catch(std::exception& ex)
	{
		std::wcout << std::endl << ex.what();
	}
}