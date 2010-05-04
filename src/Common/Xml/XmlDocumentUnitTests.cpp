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

void XmlDocumentUnitTests::testGetNodeValue()
{	
	struct testGetNodeValue_TestData
	{
		LPCWSTR xpath;
		LPCWSTR result;
		LPCWSTR xml;
	};

	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);

    testGetNodeValue_TestData testdata[] = 
    {
        { L"/bookstore/book[@id=1]/title", L"'Emma'", L"<title xmlns=\"http://www.lucernepublishing.com\">'Emma'</title>" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        // default value
		std::wstring default_value = xml.GetNodeValue(L"/invalid/xpath", NULL, L"default");
		std::wcout << std::endl << L"Value: " << default_value;
		CPPUNIT_ASSERT(L"default" == default_value);
		// value
		std::wstring result_value = xml.GetNodeValue(testdata[i].xpath);
		std::wcout << std::endl << L"Value: " << result_value;
		CPPUNIT_ASSERT(testdata[i].result == result_value);
		// xml
		std::wstring result_xml = xml.GetNodeXml(testdata[i].xpath);
		std::wcout << std::endl << L"Xml: " << result_xml;
		CPPUNIT_ASSERT(testdata[i].xml == result_xml);
    }
}

void XmlDocumentUnitTests::testGetNodeBoolValue()
{
	struct testGetNodeBoolValue_TestData
	{
		LPCWSTR xpath;
		bool result;
	};

	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile.c_str();
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);

    testGetNodeBoolValue_TestData testdata[] = 
    {
        { L"/bookstore/book[@id=1]/read", false },
        { L"/bookstore/book[@id=2]/read", true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
		// value
		bool result_value = xml.GetNodeBoolValue(testdata[i].xpath);
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

void XmlDocumentUnitTests::testGetAttributeValue()
{
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile);
	std::wstring result = xml.GetAttributeValue(L"/bookstore/book", L"id");
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

void XmlDocumentUnitTests::testGetAttributeValueXPath()
{	
	struct testGetAttributeValue_TestData
	{
		LPCWSTR xpath;
		LPCWSTR name;
		LPCWSTR result;
	};

	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile;
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);

    testGetAttributeValue_TestData testdata[] = 
    {
        { L"/bookstore/book[@id=1]", L"id", L"1" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
		MSXML2::IXMLDOMNodePtr node = xml.SelectNode(testdata[i].xpath);
        // default value
		std::wstring default_value = xml.GetAttributeValue(L"invalid", node, L"default");
		std::wcout << std::endl << L"Value: " << default_value;
		CPPUNIT_ASSERT(L"default" == default_value);
		// value
		std::wstring result_value = xml.GetAttributeValue(testdata[i].name, node);
		std::wcout << std::endl << L"Value: " << result_value;
		CPPUNIT_ASSERT(testdata[i].result == result_value);
    }
}

void XmlDocumentUnitTests::testGetAttributeBoolValue()
{
	struct testGetAttributeBoolValue_TestData
	{
		LPCWSTR xpath;
		LPCWSTR name;
		bool result;
	};

	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile.c_str();
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);

    testGetAttributeBoolValue_TestData testdata[] = 
    {
        { L"/bookstore/book[@id=1]", L"returned", false },
        { L"/bookstore/book[@id=2]", L"returned", true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
		MSXML2::IXMLDOMNodePtr node = xml.SelectNode(testdata[i].xpath);
		// value
		bool result_value = xml.GetAttributeBoolValue(testdata[i].name, node);
		std::wcout << std::endl << L"Value: " << result_value;
		CPPUNIT_ASSERT(testdata[i].result == result_value);
    }
}

void XmlDocumentUnitTests::testLoad() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile.c_str();
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	CPPUNIT_ASSERT(AppSecInc::StringUtils::startsWith(xml.GetXml(), 
		L"<bookstore xmlns=\"http://www.lucernepublishing.com\">"));
}

void XmlDocumentUnitTests::testLoadXml() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	std::wcout << std::endl << L"Xml: " << xmlfile.c_str();
	std::wstring data;
	AppSecInc::File::ReadToEnd(xmlfile, data);
	AppSecInc::Xml::XmlDocument xml;
	xml.LoadXml(data);
	CPPUNIT_ASSERT(AppSecInc::StringUtils::startsWith(xml.GetXml(), 
		L"<bookstore xmlns=\"http://www.lucernepublishing.com\">"));
}

void XmlDocumentUnitTests::testFindNode() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	CPPUNIT_ASSERT(xml.FindNode(L"/bookstore/book[@id=1]/title") != NULL);
	CPPUNIT_ASSERT(xml.FindNode(L"/bookstore/book[@id=1]/invalid") == NULL);
}

void XmlDocumentUnitTests::testHasNode() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	CPPUNIT_ASSERT(xml.HasNode(L"/bookstore/book[@id=1]/title"));
	CPPUNIT_ASSERT(! xml.HasNode(L"/bookstore/book[@id=1]/invalid"));
}

void XmlDocumentUnitTests::testSelectNode() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	CPPUNIT_ASSERT(xml.SelectNode(L"/bookstore/book[@id=1]/title") != NULL);
	try
	{
		xml.SelectNode(L"/bookstore/book[@id=1]/invalid");
		throw "expected std::exception";
	}
	catch(std::exception& e)
	{
		std::cout << std::endl << "Expected exception: " << e.what();
	}
}

void XmlDocumentUnitTests::testHasNodes() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	CPPUNIT_ASSERT(xml.HasNodes(L"/bookstore/book[@id=1]"));
	CPPUNIT_ASSERT(! xml.HasNodes(L"/bookstore/book[@id=1]/invalid/"));
}

void XmlDocumentUnitTests::testFindNodes() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	CPPUNIT_ASSERT(NULL != xml.FindNodes(L"/bookstore/book[@id=1]"));
	CPPUNIT_ASSERT(NULL == xml.FindNodes(L"/bookstore/book[@id=1]/invalid/"));
}

void XmlDocumentUnitTests::testGetNodeXml() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	std::wstring data = xml.GetNodeXml(L"/bookstore/book[@id=1]");
	CPPUNIT_ASSERT(AppSecInc::StringUtils::startsWith(data, L"<book"));
}

void XmlDocumentUnitTests::testFindAttribute() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	CPPUNIT_ASSERT(NULL != xml.FindAttribute(L"id", xml.SelectNode(L"/bookstore/book[@id=1]")));
	CPPUNIT_ASSERT(NULL == xml.FindAttribute(L"iddoesntexist", xml.SelectNode(L"/bookstore/book[@id=1]")));
}

void XmlDocumentUnitTests::testSelectAttribute() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	CPPUNIT_ASSERT(NULL != xml.SelectAttribute(L"id", xml.SelectNode(L"/bookstore/book[@id=1]")));
	try
	{
		xml.SelectAttribute(L"iddoesntexist", xml.SelectNode(L"/bookstore/book[@id=1]"));
		throw "expected std::exception";
	}
	catch(std::exception& e)
	{
		std::cout << std::endl << "Expected exception: " << e.what();
	}
}

void XmlDocumentUnitTests::testHasAttribute() 
{ 
	std::wstring xmlfile = GetLocalFileLocation(L"store.xml");
	AppSecInc::Xml::XmlDocument xml;
	xml.Load(xmlfile, CLSID_DOMDocument);
	CPPUNIT_ASSERT(xml.HasAttribute(L"id", xml.SelectNode(L"/bookstore/book[@id=1]")));
	CPPUNIT_ASSERT(! xml.HasAttribute(L"iddoesntexist", xml.SelectNode(L"/bookstore/book[@id=1]")));
}
