#include "StdAfxUnitTests.h"
#include "XmlDocumentUnitTests.h"

using namespace AppSecInc::UnitTests::Xml;

CPPUNIT_TEST_SUITE_REGISTRATION(XmlDocumentUnitTests);

void XmlDocumentUnitTests::testConstructorDestructor()
{
	{
        AppSecInc::Xml::XmlDocument document;
	}

	{
		AppSecInc::Xml::XmlDocument * p = new AppSecInc::Xml::XmlDocument();
		delete p;
	}
}

std::wstring GetLocalFileLocation(LPCWSTR pszFilename)
{
	return AppSecInc::File::GetModuleDirectoryW() + 
		std::wstring(L"\\TestData_XmlUnitTests\\") + 
		std::wstring(pszFilename);
}

void XmlDocumentUnitTests::testSelectNodeValue()
{	
	struct testSelectNodeValue_TestData
	{
		LPCWSTR xpath;
		LPCWSTR result;
		LPCWSTR xml;
	};

	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);

    testSelectNodeValue_TestData testdata[] = 
    {
        { L"/bookstore/book[@id=1]/title", L"'Emma'", L"<title xmlns=\"http://www.lucernepublishing.com\">'Emma'</title>" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        // default value
		std::wstring default_value = xml.SelectNodeValue(L"/invalid/xpath", NULL, L"default");
		std::wcout << std::endl << L"Value: " << default_value;
		CPPUNIT_ASSERT(L"default" == default_value);
		// value
		std::wstring result_value = xml.SelectNodeValue(testdata[i].xpath);
		std::wcout << std::endl << L"Value: " << result_value;
		CPPUNIT_ASSERT(testdata[i].result == result_value);
		// xml
		std::wstring result_xml = xml.SelectNodeXml(testdata[i].xpath);
		std::wcout << std::endl << L"Xml: " << result_xml;
		CPPUNIT_ASSERT(testdata[i].xml == result_xml);
    }
}

void XmlDocumentUnitTests::testSelectNodeBoolValue()
{
	struct testSelectNodeBoolValue_TestData
	{
		LPCWSTR xpath;
		bool result;
	};

	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile.c_str();
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);

    testSelectNodeBoolValue_TestData testdata[] = 
    {
        { L"/bookstore/book[@id=1]/read", false },
        { L"/bookstore/book[@id=2]/read", true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
		// value
		bool result_value = xml.SelectNodeBoolValue(testdata[i].xpath);
		std::wcout << std::endl << L"Value: " << result_value;
		CPPUNIT_ASSERT(testdata[i].result == result_value);
    }
}

void XmlDocumentUnitTests::testXslTransform()
{
    // check test xml file
	std::wstring xmlfile = GetLocalFileLocation(L"simple.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
    CPPUNIT_ASSERT(File::FileExists(xmlfile));
    // check test xsl file
	std::wstring xslfile = GetLocalFileLocation(L"simple.xsl");
	std::wcout << std::endl << L"Xsl: " << xslfile;
    CPPUNIT_ASSERT(File::FileExists(xslfile));
    // transform
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile);
	AppSecInc::Xml::XmlDocument transformedXml;
	std::wstring transformResult = xml.XslTransform(xslfile);
	transformedXml.LoadXml(transformResult);
    // load the result
	CPPUNIT_ASSERT(transformResult.length() > 0);
}

void XmlDocumentUnitTests::testSelectNodeAttributeValue()
{
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile);
	std::wstring result = xml.SelectNodeAttributeValue(L"/bookstore/book", L"id");
	std::wcout << std::endl << L"Value: " << result;
    CPPUNIT_ASSERT(result == L"1");
}

void XmlDocumentUnitTests::testGetXml()
{
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile);
    std::wstring outerxml = xml.GetXml();
    CPPUNIT_ASSERT(! outerxml.empty());
    //! \todo read the file with File::ReadToEnd (implement) and compare data
}

void XmlDocumentUnitTests::testSelectNodes()
{	
	struct testSelectNodes_TestData
	{
		LPCWSTR xpath;
		long count;
	};

    testSelectNodes_TestData testdata[] = 
    {
        { L"/bookstore", 1 },
        { L"/bookstore/book", 2 }
    };

	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        MSXML2::IXMLDOMNodeListPtr nodes = xml.SelectNodes(testdata[i].xpath);
        std::wcout << std::endl << testdata[i].xpath << L": " << nodes->length;
        CPPUNIT_ASSERT(testdata[i].count == nodes->length);
    }
}

void XmlDocumentUnitTests::testCreate()
{
	AppSecInc::Xml::XmlDocument xml;
    xml.LoadXml(L"<xml />");
    CPPUNIT_ASSERT(! xml.GetXml().empty());
    xml.Create();
    CPPUNIT_ASSERT(xml.GetXml().empty());
}

void XmlDocumentUnitTests::testAppendChild()
{
	AppSecInc::Xml::XmlDocument xml;
    xml.Create();
    xml.AppendChild(L"xml");

    {
        std::wstring data = xml.GetXml();
        AppSecInc::StringUtils::lrtrim(data, L"\r\n");
        std::wcout << std::endl << data;
        CPPUNIT_ASSERT(! data.empty());
        CPPUNIT_ASSERT(data == L"<xml/>");
    }

    {
        xml.AppendChild(L"node", xml.SelectNode(L"/xml"));
        std::wstring data = xml.GetXml();
        AppSecInc::StringUtils::lrtrim(data, L"\r\n");
        std::wcout << std::endl << data;
        CPPUNIT_ASSERT(! data.empty());
        CPPUNIT_ASSERT(data == L"<xml><node/></xml>");
    }
}

void XmlDocumentUnitTests::testSetAttribute()
{
	AppSecInc::Xml::XmlDocument xml;
    xml.Create();
    xml.AppendChild(L"xml");

    {
        xml.SetAttribute(L"name", L"value", xml.SelectNode(L"/xml"));
        std::wstring data = xml.GetXml();
        AppSecInc::StringUtils::lrtrim(data, L"\r\n");
        std::wcout << std::endl << data;
        CPPUNIT_ASSERT(data == L"<xml name=\"value\"/>");
    }
}

void XmlDocumentUnitTests::testSelectAttributeValue()
{	
	struct testSelectAttributeValue_TestData
	{
		LPCWSTR xpath;
		LPCWSTR name;
		LPCWSTR result;
	};

	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);

    testSelectAttributeValue_TestData testdata[] = 
    {
        { L"/bookstore/book[@id=1]", L"id", L"1" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
		MSXML2::IXMLDOMNodePtr node = xml.SelectNode(testdata[i].xpath);
        // default value
		std::wstring default_value = xml.SelectAttributeValue(L"invalid", node, L"default");
		std::wcout << std::endl << L"Value: " << default_value;
		CPPUNIT_ASSERT(L"default" == default_value);
		// value
		std::wstring result_value = xml.SelectAttributeValue(testdata[i].name, node);
		std::wcout << std::endl << L"Value: " << result_value;
		CPPUNIT_ASSERT(testdata[i].result == result_value);
    }
}

void XmlDocumentUnitTests::testSelectAttributeBoolValue()
{
	struct testSelectAttributeBoolValue_TestData
	{
		LPCWSTR xpath;
		LPCWSTR name;
		bool result;
	};

	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile.c_str();
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);

    testSelectAttributeBoolValue_TestData testdata[] = 
    {
        { L"/bookstore/book[@id=1]", L"returned", false },
        { L"/bookstore/book[@id=2]", L"returned", true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
		MSXML2::IXMLDOMNodePtr node = xml.SelectNode(testdata[i].xpath);
		// value
		bool result_value = xml.SelectAttributeBoolValue(testdata[i].name, node);
		std::wcout << std::endl << L"Value: " << result_value;
		CPPUNIT_ASSERT(testdata[i].result == result_value);
    }
}
