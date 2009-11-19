#include "StdAfx.h"
#include "Adsi.h"

CA_API UINT __stdcall ADSI_GetAttributeValue(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);
	CComPtr<IADs> pRoot;

	// LDAP path, default to LDAP://RootDSE
	std::wstring ldap_path = msiInstall.GetProperty(L"ADSI_LDAP_PATH");
	if (ldap_path.empty()) ldap_path = L"LDAP://RootDSE";

	std::wstring property_name = msiInstall.GetProperty(L"ADSI_PROPERTY_NAME");
	
	CHECK_HR(::ADsGetObject(ldap_path.c_str(), IID_IADs, (void**) & pRoot),
		L"Error in ADsGetObject");

	CComVariant varPropertyValue;
	CHECK_HR(pRoot->Get(_bstr_t(property_name.c_str()), & varPropertyValue),
		L"Error getting value of \"" << property_name << L"\"");

	std::wstring property_value = AppSecInc::StringUtils::toWString(varPropertyValue);
	
	std::wstringstream s;
	s << property_name << L": \"" << property_value << L"\"";
	msiInstall.LogInfo(L"ADSI_GetAttributeValue", s.str());

    msiInstall.SetProperty(L"ADSI_PROPERTY_VALUE", property_value);

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}
