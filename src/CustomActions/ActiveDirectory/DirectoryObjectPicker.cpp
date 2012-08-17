#include "StdAfx.h"
#include "DirectoryObjectPicker.h"
#include "FlagMaps.h"

CA_API UINT __stdcall DirectoryObjectPicker(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);
    msiInstall.LogInfo(L"DirectoryObjectPicker", L"Creating an Active Directory object picker dialog.");

    msiInstall.SetProperty(L"DSOP_NAME", L"");
    msiInstall.SetProperty(L"DSOP_CLASS", L"");
    msiInstall.SetProperty(L"DSOP_ADSPATH", L"");
    msiInstall.SetProperty(L"DSOP_UPN", L"");

    CComPtr<IDsObjectPicker> pDsObjectPicker;

    CHECK_HR(::CoCreateInstance(CLSID_DsObjectPicker, NULL, CLSCTX_INPROC_SERVER, IID_IDsObjectPicker, (void**) & pDsObjectPicker),
        L"Error in CoCreateInstance(CLSID_DsObjectPicker, IID_IDsObjectPicker)");

    DSOP_SCOPE_INIT_INFO aScopeInit[1] = { 0 };
    aScopeInit[0].cbSize = sizeof(DSOP_SCOPE_INIT_INFO);

    aScopeInit[0].flType = GetPropertyValue(msiInstall, L"DSOP_SCOPE_TYPES", s_DirectoryServicesScopeTypes);
    aScopeInit[0].flScope = GetPropertyValue(msiInstall, L"DSOP_SCOPE_FLAGS", s_DirectoryServicesScopeFlags);
    aScopeInit[0].FilterFlags.Uplevel.flBothModes = GetPropertyValue(msiInstall, L"DSOP_SCOPE_FILTER_FLAGS", s_DirectoryServicesScopeFilterFlags);
    aScopeInit[0].FilterFlags.flDownlevel = GetPropertyValue(msiInstall, L"DSOP_DOWNLEVEL_SCOPE_FILTER_FLAGS", s_DirectoryServicesDownlevelScopeFilterFlags);

    DSOP_INIT_INFO initInfo = { 0 };
    initInfo.cbSize = sizeof(initInfo);

    // target is the local computer
    //! \todo Expose as property to allow remote computer.
    initInfo.pwzTargetComputer = NULL;
	initInfo.cDsScopeInfos = ARRAYSIZE(aScopeInit);
    initInfo.aDsScopeInfos = aScopeInit;

    //! \todo Expose as property to allow multiple selections, change the return.
    // initInfo.flOptions = DSOP_FLAG_MULTISELECT;

    CHECK_HR(pDsObjectPicker->Initialize(& initInfo), 
        L"Error in pDsObjectPicker->Initialize");

    HWND hwndParent = ::GetConsoleWindow();
    if (hwndParent == NULL) hwndParent = ::GetForegroundWindow();

    CComPtr<IDataObject> pdo;

	HRESULT hr = pDsObjectPicker->InvokeDialog(hwndParent, &pdo);
    CHECK_HR(hr, 
		L"Error in pDsObjectPicker->InvokeDialog");
    
    if (hr == S_FALSE)
    {
        // user made no selection
        return ERROR_SUCCESS;
    }

    // FORMATETC is a generalized Clipboard format.
	// http://msdn2.microsoft.com/en-us/library/ms682177(VS.85).aspx
    FORMATETC fe = { 0 };
    fe.cfFormat = RegisterClipboardFormat(CFSTR_DSOP_DS_SELECTION_LIST);
    fe.ptd = NULL;
	fe.dwAspect = DVASPECT_CONTENT;
	fe.lindex = -1;
	fe.tymed = TYMED_HGLOBAL;

	// STGMEDIUM is a generalized global memory handle used for data transfer operations by the 
	// IAdviseSink, IDataObject, and IOleCache interfaces.
	// http://msdn2.microsoft.com/en-us/library/ms683812(VS.85).aspx
	STGMEDIUM stm = { 0 };
    CHECK_HR(pdo->GetData(&fe, &stm), 
        L"Error in pdo->GetData");

    PDS_SELECTION_LIST pDsSelList = static_cast<PDS_SELECTION_LIST>(GlobalLock(stm.hGlobal));

    CHECK_WIN32_BOOL(pDsSelList != NULL, "Error in GlobalLock");
    
	std::wstring dsop_class, dsop_name, dsop_adspath, dsop_upn;
    for (ULONG i = 0; i < pDsSelList->cItems; i++) 
    {
		// see http://msdn2.microsoft.com/en-us/library/ms676284(VS.85).aspx for DS_SELECTION structure
        //! \todo support returning more than one property

		// The object's ADsPath.
		dsop_class = pDsSelList->aDsSelection[i].pwzClass;

		// The object's relative distinguished name (RDN).
		dsop_name = pDsSelList->aDsSelection[i].pwzName;
		if (dsop_class == L"User")
		{
			if (dsop_name.find(L"\\") == std::wstring::npos)
			{
				// a username without a domain (local)
                dsop_name.insert(0, L"\\");
                dsop_name.insert(0, AppSecInc::TcpIp::NetBIOS::GetComputerName());
			}
		}

		// The object's ADsPath.
        dsop_adspath = pDsSelList->aDsSelection[i].pwzADsPath;
		// Object's userPrincipalName attribute value.
        dsop_upn = pDsSelList->aDsSelection[i].pwzUPN;

		break;
    }

    GlobalUnlock(stm.hGlobal);
    ReleaseStgMedium(& stm);

	msiInstall.SetProperty(L"DSOP_CLASS", dsop_class);
	msiInstall.SetProperty(L"DSOP_NAME", dsop_name);
	msiInstall.SetProperty(L"DSOP_ADSPATH", dsop_adspath);
	msiInstall.SetProperty(L"DSOP_UPN", dsop_upn);

	MSI_EXCEPTION_HANDLER_EPILOG;

	return ERROR_SUCCESS;
}

