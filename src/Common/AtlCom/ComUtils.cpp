#include "StdAfx.h"
#include "ComUtils.h"

#include <String/String.h>


CLSID AppSecInc::Com::CLSIDFromProgID(const std::string& progid)
{
    return CLSIDFromProgID(StringUtils::mb2wc(progid));	
}

CLSID AppSecInc::Com::CLSIDFromProgID(const std::wstring& progid)
{
    CLSID clsid;
	CHECK_HR(::CLSIDFromProgID(static_cast<LPCOLESTR>(progid.c_str()), & clsid),
        _T("Error in ::CLSIDFromProgID"));
    return clsid;
}

CLSID AppSecInc::Com::CLSIDFromString(const std::wstring& guid)
{
    CLSID clsid;
	CHECK_HR(::CLSIDFromString(const_cast<LPOLESTR>(guid.c_str()), & clsid),
        _T("Error in ::CLSIDFromString"));
    return clsid;
}

CLSID AppSecInc::Com::CLSIDFromString(const std::string& guid)
{
    return CLSIDFromString(StringUtils::mb2wc(guid));
}

IID AppSecInc::Com::IIDFromString(const std::wstring& guid)
{
    IID iid;

	CHECK_HR(::IIDFromString(const_cast<LPOLESTR>(guid.c_str()), & iid),
        _T("Error in ::IIDFromString"));
    return iid;
}

IID AppSecInc::Com::IIDFromString(const std::string& guid)
{
	return IIDFromString(StringUtils::mb2wc(guid));	
}

std::wstring AppSecInc::Com::ProgIDFromCLSIDW(REFCLSID clsid)
{
	LPOLESTR pprogid = NULL;
	CHECK_HR(::ProgIDFromCLSID(clsid, & pprogid),
        _T("Error in ::ProgIDFromCLSID"));

    std::wstring progid;
	progid.assign(pprogid);
	::CoTaskMemFree(pprogid);
    return progid;
}

std::string AppSecInc::Com::ProgIDFromCLSIDA(REFCLSID clsid)
{
    return StringUtils::wc2mb(ProgIDFromCLSIDW(clsid));
}

std::wstring AppSecInc::Com::StringFromCLSIDW(REFCLSID clsid)
{
	LPOLESTR pprogid = NULL;

	CHECK_HR(::StringFromCLSID(clsid, & pprogid),
        _T("Error in ::StringFromCLSID"));

    std::wstring progid;
	progid.assign(pprogid);
	::CoTaskMemFree(pprogid);
    return progid;
}

std::string AppSecInc::Com::StringFromCLSIDA(REFCLSID clsid)
{
    return StringUtils::wc2mb(StringFromCLSIDW(clsid));
}

std::wstring AppSecInc::Com::StringFromGUID2W(REFGUID rguid)
{
    std::wstring progid;
	progid.resize(39);
	int len = 0;

	CHECK_WIN32_BOOL(0 != (len = ::StringFromGUID2(
		rguid, static_cast<LPOLESTR>(& * progid.begin()), progid.size())), 
		_T("Error in ::StringFromCLSID"));

	progid.resize(len - 1);
    return progid;
}

std::string AppSecInc::Com::StringFromGUID2A(REFGUID rguid)
{
    return StringUtils::wc2mb(StringFromGUID2W(rguid));
}

std::wstring AppSecInc::Com::StringFromIIDW(REFIID rclsid)
{
	LPOLESTR pprogid = NULL;

	CHECK_HR(::StringFromIID(rclsid, & pprogid),
        _T("Error in ::StringFromIID"));

    std::wstring progid;
	progid.assign(pprogid);
	::CoTaskMemFree(pprogid);
    return progid;
}

std::string AppSecInc::Com::StringFromIIDA(REFIID rclsid)
{
    return StringUtils::wc2mb(StringFromIIDW(rclsid));
}

std::string AppSecInc::Com::GenerateGUIDStringA()
{
	GUID pguid;
	
	CHECK_HR(CoCreateGuid(& pguid),
        _T("Error in ::CoCreateGuid"));

	return StringFromGUID2A(pguid);
}

std::wstring AppSecInc::Com::GenerateGUIDStringW()
{
	GUID pguid;
	
	CHECK_HR(CoCreateGuid(& pguid),
        _T("Error in ::CoCreateGuid"));

	return StringFromGUID2W(pguid);
}

bool AppSecInc::Com::IsValidGUID(const std::wstring& guid)
{
    IID iid;
	HRESULT hr = ::IIDFromString(const_cast<LPOLESTR>(guid.c_str()), & iid);

	if (SUCCEEDED(hr)) return true;
	else if (hr == E_INVALIDARG) return false;
	else
	{
		CHECK_HR(hr,
			_T("Error in ::IIDFromString"));
	}

	return false;
}

bool AppSecInc::Com::IsValidGUID(const std::string& guid)
{
	return IsValidGUID(AppSecInc::StringUtils::mb2wc(guid));
}