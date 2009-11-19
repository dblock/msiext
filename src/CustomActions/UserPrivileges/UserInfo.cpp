#include "StdAfx.h"
#include "UserInfo.h"

using namespace AppSecInc::Msi::Flags;

static const FlagMapEntry s_ExtendedNameFormats[] = 
{
	{ L"NameFullyQualifiedDN", NameFullyQualifiedDN },
	{ L"NameSamCompatible", NameSamCompatible },
	{ L"NameDisplay", NameDisplay }, 
	{ L"NameUniqueId", NameUniqueId },
	{ L"NameCanonical", NameCanonical },
	{ L"NameUserPrincipal", NameUserPrincipal },
	{ L"NameCanonicalEx", NameCanonicalEx },
	{ L"NameServicePrincipal", NameServicePrincipal },
	{ L"NameDnsDomain", NameDnsDomain }
};

CA_API UINT __stdcall GetUserInfo(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiImpersonatedInstall msiInstall(hInstall);

    std::wstring username = AppSecInc::LSA::Account::GetCurrentUserName(NameSamCompatible);
	msiInstall.SetProperty(L"USER_FQN", username);

    AppSecInc::LSA::Account account;
    account.LookupAccount(username);
    msiInstall.SetProperty(L"USER_NAME", account.GetUserName());
    msiInstall.SetProperty(L"USER_DOMAIN", account.GetDomain());
    msiInstall.SetProperty(L"USER_SID", account.GetSid().ToString());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall GetUserNameFormatted(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiImpersonatedInstall msiInstall(hInstall);

    EXTENDED_NAME_FORMAT format = (EXTENDED_NAME_FORMAT) GetPropertyValue(
		msiInstall, L"USERNAME_FORMAT", s_ExtendedNameFormats);
    std::wstring username = AppSecInc::LSA::Account::GetCurrentUserName(format);
	msiInstall.SetProperty(L"USER_FQN", username);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
