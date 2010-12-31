#include "StdAfx.h"
#include "XmlToolsImpl.h"

CA_API UINT __stdcall Xml_SelectNodeValue(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring filename = msiInstall.GetProperty(L"XML_FILENAME");
	AppSecInc::Xml::XmlDocument doc;
	doc.Load(filename);

	std::wstring xpath = msiInstall.GetProperty(L"XML_XPATH");

	std::wstring value = doc.GetNodeValue(xpath);
	msiInstall.SetProperty(L"XML_NODEVALUE", value);

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}

CA_API UINT __stdcall Xml_SelectNodeXml(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring filename = msiInstall.GetProperty(L"XML_FILENAME");
	AppSecInc::Xml::XmlDocument doc;
	doc.Load(filename);

	std::wstring xpath = msiInstall.GetProperty(L"XML_XPATH");

	std::wstring xml = doc.GetNodeXml(xpath);
	msiInstall.SetProperty(L"XML_NODEXML", xml);

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}

CA_API UINT __stdcall Xml_SelectNodeAttributeValue(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring filename = msiInstall.GetProperty(L"XML_FILENAME");
	AppSecInc::Xml::XmlDocument doc;
	doc.Load(filename);

	std::wstring xpath = msiInstall.GetProperty(L"XML_XPATH");
	std::wstring attributename = msiInstall.GetProperty(L"XML_ATTRIBUTENAME");

	std::wstring value = doc.GetAttributeValue(xpath, attributename);
	msiInstall.SetProperty(L"XML_ATTRIBUTEVALUE", value);

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}

CA_API UINT __stdcall Xml_XslTransform(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring filename = msiInstall.GetProperty(L"XML_FILENAME");
	AppSecInc::Xml::XmlDocument doc;
	doc.Load(filename);

	std::wstring xslt_filename = msiInstall.GetProperty(L"XSLT_FILENAME");
	std::wstring xslt_result_filename = msiInstall.GetProperty(L"XSLT_RESULT_FILENAME");

	std::wstring transformedData = doc.XslTransform(xslt_filename);

    std::string char_data = AppSecInc::StringUtils::wc2mb(transformedData);
    std::vector<char> binary_data;
    binary_data.assign(char_data.begin(), char_data.end());
	AppSecInc::File::FileWrite(xslt_result_filename, binary_data);

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}

CA_API UINT __stdcall Xml_DeleteNodes(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring filename = msiInstall.GetProperty(L"XML_FILENAME");
	AppSecInc::Xml::XmlDocument doc;
	doc.Load(filename);

	std::wstring xpath = msiInstall.GetProperty(L"XML_XPATH");
	MSXML2::IXMLDOMNodeListPtr nodes = doc.FindNodes(xpath);
	int count = 0;
	if (NULL != nodes)
	{
		MSXML2::IXMLDOMNodePtr node = NULL;
		while (NULL != (node = nodes->nextNode()))
		{
			node->parentNode->removeChild(node);
			count++;
		}
	}

	if (count > 0)
	{
		CHECK_HR(doc->save(CComVariant(filename.c_str())),
			L"Error saving '" << filename << L"'");
	}

	msiInstall.SetProperty(L"XML_DELETED", AppSecInc::StringUtils::toWString(count));
	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}