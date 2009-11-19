#include "StdAfx.h"
#include "CompareVersionImpl.h"

CA_API UINT __stdcall CompareVersions(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
	MsiInstall msiInstall(hInstall);
    std::wstring xml = msiInstall.GetViewData(L"SELECT * FROM `CompareVersions`");
	MSXML2::IXMLDOMDocumentPtr spXMLDOM;
    CHECK_HR(spXMLDOM.CreateInstance(MSXML2::CLSID_DOMDocument), L"Error creating xml document");
    CHECK_BOOL(VARIANT_TRUE == spXMLDOM->loadXML(xml.c_str()), L"Invalid xml data");

    MSXML2::IXMLDOMNodeListPtr rows = spXMLDOM->selectNodes(L"//Row");
    CHECK_BOOL(NULL != rows, L"Missing data rows");
    MSXML2::IXMLDOMNodePtr row = rows->nextNode();
    while (NULL != row)
    {
        MSXML2::IXMLDOMNodePtr instVersion_node = row->selectSingleNode(L"Data[@Column =\"InstalledVersion\"]");
        MSXML2::IXMLDOMNodePtr minVersion_node = row->selectSingleNode(L"Data[@Column =\"MinimumVersion\"]");
		MSXML2::IXMLDOMNodePtr maxVersion_node = row->selectSingleNode(L"Data[@Column =\"MaximumVersion\"]");
		MSXML2::IXMLDOMNodePtr property_node = row->selectSingleNode(L"Data[@Column =\"Property\"]");

        CHECK_BOOL(instVersion_node != NULL && minVersion_node != NULL && property_node != NULL,
            L"Invalid xml data, missing data column");

		std::wstring instVersion = instVersion_node->text;
		std::wstring minVersion = minVersion_node->text;
		std::wstring prop = property_node->text;

        // check version
		std::wstringstream status;
		bool versionCheck = false;
		if (maxVersion_node == NULL)
		{
            versionCheck = AppSecInc::Version::IsWithinBounds(instVersion, minVersion);
			status << L"Check " << minVersion << L" <= " << instVersion << L"? " << (versionCheck ? L"Yes" : L"No");
		}
		else
		{
			std::wstring maxVersion = maxVersion_node->text;
			versionCheck = AppSecInc::Version::IsWithinBounds(instVersion, minVersion, maxVersion);
			status << L"Check " << minVersion << L" <= " << instVersion << L" <= " << maxVersion << L"? " << (versionCheck ? L"Yes" : L"No");
		}
		
        msiInstall.LogInfo(L"CompareVersions", status.str());
		// If the version check passes, set the property to the installed version
        msiInstall.SetProperty(prop, versionCheck ? instVersion : L"");
        row = rows->nextNode();
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}

CA_API UINT __stdcall CompareVersion(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
	MsiInstall msiInstall(hInstall);

	std::wstring instVersion = msiInstall.GetProperty(L"VERSION_INSTALLED");
	std::wstring minVersion = msiInstall.GetProperty(L"VERSION_MINIMUM");
	std::wstring maxVersion = msiInstall.GetProperty(L"VERSION_MAXIMUM");
	std::wstring prop = msiInstall.GetProperty(L"VERSION_PROPERTY");

    // check version
	std::wstringstream status;
	bool versionCheck = false;
	if (maxVersion.empty())
	{
		versionCheck = AppSecInc::Version::IsWithinBounds(instVersion, minVersion);
		status << L"Check " << minVersion << L" <= " << instVersion << L"? " << (versionCheck ? L"Yes" : L"No");
	}
	else
	{
		versionCheck = AppSecInc::Version::IsWithinBounds(instVersion, minVersion, maxVersion);
		status << L"Check " << minVersion << L" <= " << instVersion << L" <= " << maxVersion << L"? " << (versionCheck ? L"Yes" : L"No");
	}
	
    msiInstall.LogInfo(L"CompareVersion", status.str());
    msiInstall.SetProperty(prop, versionCheck ? instVersion : L"");
	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}
