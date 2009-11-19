#include "StdAfx.h"

CA_API UINT __stdcall BinaryWrite(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    // the name of the binary property to fetch
    std::wstring propertyname = msiInstall.GetProperty(L"BINARYWRITE_PROPERTYNAME");
    CHECK_BOOL(propertyname.length() > 0, L"Missing BINARYWRITE_PROPERTYNAME.");

    // the target filename to write
    std::wstring targetfilename = msiInstall.GetProperty(L"BINARYWRITE_TARGETFILENAME");
    CHECK_BOOL(targetfilename.length() > 0, L"Missing BINARYWRITE_TARGETFILENAME.");

    std::vector<char> data;
    msiInstall.GetBinaryData(propertyname, data);
    AppSecInc::File::FileWrite(targetfilename, data);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
