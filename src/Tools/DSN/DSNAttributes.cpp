#include "StdAfx.h"
#include "DSNAttributes.h"

DSNAttributes::DSNAttributes()
{

}

void DSNAttributes::AddRange(const std::vector<std::wstring>& namevaluepairs)
{
    for each(const std::wstring& namevaluepair in namevaluepairs)
    {
        Add(namevaluepair);
    }
}

void DSNAttributes::Add(const std::wstring& namevaluepair)
{
    CHECK_BOOL(namevaluepair.find(L"=") != namevaluepair.npos,
        L"Missing = in \"" << namevaluepair << L"\"");

    _attributes.push_back(namevaluepair);
}

std::wstring DSNAttributes::GetAttributes() const
{
	return AppSecInc::StringUtils::join(_attributes, L";");
}
