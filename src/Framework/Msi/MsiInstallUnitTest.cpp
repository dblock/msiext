#include "StdAfxUnitTests.h"
#include "MsiInstallUnitTest.h"

using namespace AppSecInc;
using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::Msi;
using namespace AppSecInc::Msi;

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Msi::MsiInstallUnitTests);

void MsiInstallUnitTests::testGetSetProperty()
{
    MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    // Add three values. We'll reuse the first one, so just point to the string literal.
    const wchar_t *value1    = L"value1";
    const wchar_t *property1 = L"property1";
    msiInstall.SetProperty(property1, value1);
    msiInstall.SetProperty(L"property2", L"value2");
    msiInstall.SetProperty(L"property3", L"value3");

    std::wstring buf = msiInstall.GetProperty(property1);
    CPPUNIT_ASSERT(wcslen(buf.c_str()) == buf.length());
    CPPUNIT_ASSERT(0 == wcscmp(value1, buf.c_str()));

    // Setting a property to NULL or L"" removes it.
    // To check, we'll have to get the map again--Properties() returns a copy.
    msiInstall.SetProperty(L"property2", L"");

    // A property that doesn't exist returns an empty string, but doesn't become a new property.
    buf = msiInstall.GetProperty(L"property7");
    CPPUNIT_ASSERT(buf.length() == 0);
}

void MsiInstallUnitTests::testGetBinaryData()
{
    MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_MsiUnitTests", L"Binary.idt"); 
    MsiInstall msiInstall(hInstall);

    std::wstring binpath = AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_MsiUnitTests\\Binary";
    std::list<std::wstring> binary_files = AppSecInc::File::GetFiles(binpath);
    for each (const std::wstring& binary_file in binary_files)
    {
        long filesize = AppSecInc::File::GetFileSize(AppSecInc::File::DirectoryCombine(binpath, binary_file));
        std::vector<std::wstring> tokens;
        StringUtils::tokenize(AppSecInc::File::GetFileNameW(binary_file), tokens, L".");
        std::wstring binary_name = tokens[0];
        std::vector<char> data;
        msiInstall.GetBinaryData(binary_name, data);
        std::wcout << std::endl << binary_file << L" (" << binary_name << L") => " 
            << std::dec << data.size() << L" byte(s), expecting " << filesize << " byte(s)";
        CPPUNIT_ASSERT(data.size() == filesize);
    }
}

int MsiInstallUnitTests::testPrologEpilogImpl_CaError(MSIHANDLE hInstall)
{
    MsiInstall msiInstall(hInstall);
    std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
    msiInstall.SetProperty(L"CA_ERROR", guid);
    CPPUNIT_ASSERT(guid == msiInstall.GetProperty(L"CA_ERROR"));
    MSI_EXCEPTION_HANDLER_PROLOG;
    // check that the prolog clears CA_ERROR
    CPPUNIT_ASSERT(msiInstall.GetProperty(L"CA_ERROR").empty());
    throw std::exception(AppSecInc::StringUtils::wc2mb(guid).c_str());
    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

int MsiInstallUnitTests::testPrologEpilogImpl_StdException(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    throw std::exception("test exception");
    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

int MsiInstallUnitTests::testPrologEpilogImpl_CppException(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    throw "test exception";
    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

int MsiInstallUnitTests::testPrologEpilogImpl_ComException(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    throw _com_error(_com_error::WCodeToHRESULT(ERROR_FILE_NOT_FOUND));
    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

void MsiInstallUnitTests::testPrologEpilog()
{
    MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    CPPUNIT_ASSERT(AppSecInc::Msi::Exceptions::default_error_code == testPrologEpilogImpl_CaError(hInstall));
    CPPUNIT_ASSERT(! msiInstall.GetProperty(L"CA_ERROR").empty());
    std::wcout << std::endl << msiInstall.GetProperty(L"CA_ERROR");
    CPPUNIT_ASSERT(ERROR_FILE_NOT_FOUND == testPrologEpilogImpl_ComException(hInstall));
    CPPUNIT_ASSERT(! msiInstall.GetProperty(L"CA_ERROR").empty());
    std::wcout << std::endl << msiInstall.GetProperty(L"CA_ERROR");
    CPPUNIT_ASSERT(AppSecInc::Msi::Exceptions::default_error_code == testPrologEpilogImpl_StdException(hInstall));
    CPPUNIT_ASSERT(! msiInstall.GetProperty(L"CA_ERROR").empty());
    std::wcout << std::endl << msiInstall.GetProperty(L"CA_ERROR");
    CPPUNIT_ASSERT(AppSecInc::Msi::Exceptions::default_error_code == testPrologEpilogImpl_CppException(hInstall));
    CPPUNIT_ASSERT(! msiInstall.GetProperty(L"CA_ERROR").empty());
    std::wcout << std::endl << msiInstall.GetProperty(L"CA_ERROR");
}

void MsiInstallUnitTests::testGetViewData()
{
    MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_MsiUnitTests", L"ComboBox.idt"); 
    MsiInstall msiInstall(hInstall);

    AppSecInc::Xml::XmlDocument xmlDoc;
    xmlDoc.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `ComboBox`"));
    CPPUNIT_ASSERT(L"DATABASE_SERVER" == xmlDoc.SelectNodeValue(L"/Table/Row/Data[@Column=\"Property\"]"));
}

void MsiInstallUnitTests::testGetViewInfo()
{
    MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_MsiUnitTests", L"ComboBox.idt"); 
    MsiInstall msiInstall(hInstall);

    std::vector<std::wstring> column_names;
    std::vector<std::wstring> column_types;
    msiInstall.GetViewInfo(L"SELECT * FROM `ComboBox`", column_names, column_types);
    std::wcout << std::endl << L"ComboBox: " << column_names.size() << L"x" << column_types.size();
    CPPUNIT_ASSERT(4 == column_names.size());
    CPPUNIT_ASSERT(4 == column_types.size());
    for (unsigned int i = 0; i < column_names.size(); i++)
    {
        std::wcout << std::endl << L" " << column_names[i] << L" (" << column_types[i] << L")";
    }
}

void MsiInstallUnitTests::testGetFormattedString()
{
    struct TestData
    {
        LPCWSTR format;
        LPCWSTR result;
    };

    MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
    msiInstall.SetProperty(L"GUID", guid);

    TestData testdata[] = 
    {
        { L"", L"" },
        { L"[NOTHING]", L"" },
        { L"String", L"String" },
        { L"[GUID]", guid.c_str() },
        { L"String[NOTHING]String", L"StringString" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wstring result = msiInstall.GetFormattedString(testdata[i].format);
        std::wcout << std::endl << testdata[i].format << L" => \"" << result << L"\"";
        CPPUNIT_ASSERT(result == testdata[i].result);
    }
}

void MsiInstallUnitTests::testActionData()
{
    MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
    msiInstall.SetProperty(L"CustomActionData", guid);
    CPPUNIT_ASSERT(guid == msiInstall.GetActionData());
}