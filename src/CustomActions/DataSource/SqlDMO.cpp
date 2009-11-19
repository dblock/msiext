#include "StdAfx.h"
#include "ConfigDataSource.h"
#include "SqlServer.h"

#include <initguid.h>
#include <sqldmo.h>
#include <sqldmoid.h>

CA_API UINT __stdcall SQLDMO_ListAvailableSQLServers(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);
    MsiView msiView;
    MsiHandle msiDatabase(MsiGetActiveDatabase(hInstall));

    // find the listbox to populate and clear it

	// the name of the property attached to the list
    std::wstring listbox = msiInstall.GetProperty(L"SQLDMO_LIST_PROPERTY");
	if (listbox.length() == 0) throw std::exception("Missing SQLDMO_LIST_PROPERTY");
    // the type of the list
    std::wstring listtype = msiInstall.GetProperty(L"SQLDMO_LIST_TYPE");
    if (listtype.length() == 0) throw std::exception("Missing SQLDMO_LIST_TYPE");
    // the index at which to start
    std::wstring listindex = msiInstall.GetProperty(L"SQLDMO_LIST_INDEX");
    // the name of the local server to skip, set to a unique value not to skip anything
    std::wstring listlocal = msiInstall.GetProperty(L"SQLDMO_LIST_LOCAL");

    // by default we assume that the list has 1 item, so start at index 2
	long index = AppSecInc::StringUtils::stringToLong(listindex, 2);

	std::wstringstream query;
    query << L"SELECT * FROM `" << listtype << "` WHERE `Property`='" << listbox << L"'";
    
    CHECK_WIN32_DWORD(MsiDatabaseOpenView(msiDatabase, query.str().c_str(), & msiView),
		L"MsiDatabaseOpenView query \"" << query << L"\" failed");

    // list SQL servers

	CComPtr<IWSQLDMOApplication> application = NULL;
    CComPtr<ISQLDMONameList> servers = NULL;
    LONG count = 0;

	CHECK_HR(CoCreateInstance(CLSID_SQLDMOApplication, NULL, CLSCTX_INPROC_SERVER, IID_IWSQLDMOApplication, reinterpret_cast<LPVOID *>(& application)),
		L"Error in CoCreateInstance(CLSID_SQLDMOApplication)");

    CHECK_HR(application->ListAvailableSQLServers(& servers),
		L"Error listing available SQL servers");

	CHECK_HR(servers->GetCount(& count),
		"Error counting available SQL servers");

	std::vector<std::wstring> names;

    for (long i = 0; i < count; i++)
    {
        CComBSTR name;
        CHECK_HR(servers->GetItemByOrd(i, & name),
			L"Error in GetItemByOrd");

        // the dialog already contains a local default
        if (StrCmp(listlocal.c_str(), static_cast<LPCWSTR>(name)) == 0)
            continue;

		names.push_back(static_cast<LPCWSTR>(name));
    }

	// get rid of dups
	std::sort(names.begin(), names.end());
	std::vector<std::wstring>::iterator unique = std::unique(names.begin(), names.end());
	names.erase(unique, names.end());

    LONG insert_index = index;
	for each (const std::wstring& name in names)
	{
        // the first record is inserted at index 2, there's at least one default item in the view
        MsiHandle hRec(MsiCreateRecord(4));
        CHECK_WIN32_DWORD(MsiRecordSetString(hRec, 1, listbox.c_str()),
			L"MsiRecordSetString(1) failed"); // Column1: Property tied to the entry
        CHECK_WIN32_DWORD(MsiRecordSetInteger(hRec, 2, insert_index),
			"MsiRecordSetInteger(2) failed"); // Column2: Display order of the item
        CHECK_WIN32_DWORD(MsiRecordSetString(hRec, 3, name.c_str()),
			"MsiRecordSetString(3) failed"); //Column3: Value to set property to
        CHECK_WIN32_DWORD(MsiRecordSetString(hRec, 4, name.c_str()),
			L"MsiRecordSetString(4) failed"); //Column4: Display text for item
        CHECK_WIN32_DWORD(MsiViewModify(msiView, MSIMODIFY_INSERT_TEMPORARY, hRec),
			"MsiViewModify failed");
        
		insert_index ++;
	}

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
