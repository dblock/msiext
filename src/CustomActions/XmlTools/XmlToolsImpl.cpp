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

	std::wstring value = doc.SelectNodeValue(xpath);
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

	std::wstring xml = doc.SelectNodeXml(xpath);
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

	std::wstring value = doc.SelectNodeAttributeValue(xpath, attributename);
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

	doc.XslTransform(xslt_filename, xslt_result_filename);

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}
