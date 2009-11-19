#include "StdAfxUnitTests.h"
#include "XmlToolsImplUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Xml::XmlToolsGetUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Xml;

void XmlToolsGetUnitTests::Test_SelectNodeValue()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    std::wstring xmlfile = AppSecInc::File::GetModuleDirectoryW();
    xmlfile.append(L"\\TestData_XmlToolsUnitTests\\store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
    CComPtr<MSXML2::IXMLDOMDocument> xmldoc;
    CPPUNIT_ASSERT(S_OK == xmldoc.CoCreateInstance(CLSID_DOMDocument));
    CPPUNIT_ASSERT(VARIANT_TRUE == xmldoc->load(CComVariant(xmlfile.c_str())));
    msiInstall.SetProperty(L"XML_FILENAME", xmlfile);

    struct TestData
    {
        int rc;
        LPCWSTR xpath;
        LPCWSTR result;
        LPCWSTR xml;
    };

    TestData testdata[] = 
    {
        { ERROR_SUCCESS, L"/bookstore/book[@id=1]/title", L"'Emma'", L"<title xmlns=\"http://www.lucernepublishing.com\">'Emma'</title>" },
        { AppSecInc::Msi::Exceptions::default_error_code, L"/bookstore/book[@id=3]/title", L"", L"" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wcout << std::endl << testdata[i].xpath;
        std::wstring result;
        // value
        msiInstall.SetProperty(L"XML_NODEVALUE", L""); // clear the test value
        msiInstall.SetProperty(L"XML_XPATH", testdata[i].xpath);
	    CPPUNIT_ASSERT(testdata[i].rc == hInstall.ExecuteCA(L"XmlTools.dll", L"Xml_SelectNodeValue"));
        result = msiInstall.GetProperty(L"XML_NODEVALUE");
		std::wcout << std::endl << L"Value: " << result;
        CPPUNIT_ASSERT(testdata[i].result == result);
        // xml
        msiInstall.SetProperty(L"XML_NODEXML", L""); // clear the test value
        msiInstall.SetProperty(L"XML_XPATH", testdata[i].xpath);
	    CPPUNIT_ASSERT(testdata[i].rc == hInstall.ExecuteCA(L"XmlTools.dll", L"Xml_SelectNodeXml"));
        result = msiInstall.GetProperty(L"XML_NODEXML");
        std::wcout << std::endl << L"Xml: " << result;
        CPPUNIT_ASSERT(testdata[i].xml == result);
    }
}

void XmlToolsGetUnitTests::Test_XslTranform()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    // check test xml file
    std::wstring xmlfile = AppSecInc::File::GetModuleDirectoryW();
    xmlfile.append(L"\\TestData_XmlToolsUnitTests\\simple.xml");
    std::wcout << std::endl << L"Xml: " << xmlfile;
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(xmlfile));
    // check test xsl file
    std::wstring xslfile = AppSecInc::File::GetModuleDirectoryW();
    xslfile.append(L"\\TestData_XmlToolsUnitTests\\simple.xsl");
    std::wcout << std::endl << L"Xsl: " << xslfile;
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(xslfile));    
    // check target filename, delete
    std::wstring xmlresult = AppSecInc::File::GetModuleDirectoryW();
    xmlresult.append(L"\\TestData_XmlToolsUnitTests\\result.htm");
    std::wcout << std::endl << L"Result: " << xmlresult;
	if (AppSecInc::File::FileExists(xmlresult)) AppSecInc::File::FileDelete(xmlresult);
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(xmlresult));
    // transform
    msiInstall.SetProperty(L"XML_FILENAME", xmlfile);
    msiInstall.SetProperty(L"XSLT_FILENAME", xslfile);
    msiInstall.SetProperty(L"XSLT_RESULT_FILENAME", xmlresult);
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"XmlTools.dll", L"Xml_XslTransform"));
    // load the result
    CComPtr<MSXML2::IXMLDOMDocument> xmldoc;
    CPPUNIT_ASSERT(S_OK == xmldoc.CoCreateInstance(CLSID_DOMDocument));
    CPPUNIT_ASSERT(VARIANT_TRUE == xmldoc->load(CComVariant(xmlresult.c_str())));
    CComBSTR bstrXml;
    CPPUNIT_ASSERT(S_OK == xmldoc->get_xml(& bstrXml));
    int len = SysStringLen(bstrXml);
    std::wcout << std::endl << L"Result: " << len;
    CPPUNIT_ASSERT(len > 0);
}

void XmlToolsGetUnitTests::Test_SelectNodeAttributeValue()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    std::wstring xmlfile = AppSecInc::File::GetModuleDirectoryW();
    xmlfile.append(L"\\TestData_XmlToolsUnitTests\\store.xml");
    std::wcout << std::endl << L"Xml: " << xmlfile;
    CComPtr<MSXML2::IXMLDOMDocument> xmldoc;
    CPPUNIT_ASSERT(S_OK == xmldoc.CoCreateInstance(CLSID_DOMDocument));
    CPPUNIT_ASSERT(VARIANT_TRUE == xmldoc->load(CComVariant(xmlfile.c_str())));
    msiInstall.SetProperty(L"XML_FILENAME", xmlfile);
    msiInstall.SetProperty(L"XML_XPATH", L"/bookstore/book");
    msiInstall.SetProperty(L"XML_ATTRIBUTENAME", L"id");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"XmlTools.dll", L"Xml_SelectNodeAttributeValue"));
    std::wstring result = msiInstall.GetProperty(L"XML_ATTRIBUTEVALUE");
    std::wcout << std::endl << L"Value: " << result;
    CPPUNIT_ASSERT(result == L"1");
}

void XmlToolsGetUnitTests::Test_EntryPoints()
{
	HMODULE h  = ::LoadLibrary(L"XmlTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing XmlTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Xml_SelectNodeValue"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Xml_SelectNodeXml"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Xml_SelectNodeAttributeValue"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Xml_XslTransform"));
	::FreeLibrary(h);
}
