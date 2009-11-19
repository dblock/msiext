#include "StdAfx.h"
#include "DSNAttributes.h"

DSNAttributes::DSNAttributes(MSIHANDLE h)
    : _h(h)
{

}

void DSNAttributes::AddPropertyValue(const std::wstring& property_name, const std::wstring& attribute_name, bool addblank)
{
    MsiInstall msiInstall(_h);
    std::wstring value = msiInstall.GetProperty(property_name);

    if (! value.empty() | addblank)
    {
        std::wstring result;
        result.append(attribute_name);
        result.append(L"=");
        result.append(value);
        _attributes.push_back(result);
    }
}

std::wstring DSNAttributes::GetAttributes() const
{
	return AppSecInc::StringUtils::join(_attributes, L";");
}
