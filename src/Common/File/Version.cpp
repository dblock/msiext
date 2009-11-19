#include "StdAfx.h"
#include "Version.h"

int AppSecInc::Version::Compare(const std::wstring& left, const std::wstring& right)
{
	std::vector<std::wstring> leftParts;
	std::vector<std::wstring> rightParts;
	
	AppSecInc::StringUtils::tokenize(left, leftParts, L".");
	AppSecInc::StringUtils::tokenize(right, rightParts, L".");

    int minLen = ( (leftParts.size() - rightParts.size() < 0) ? leftParts.size() : rightParts.size() ); 

	int i = 0;
	while (i < minLen)
	{
        // \todo replace _wtoi with an exception-throwing conversion function in StringUtils (implement)
		int left = _wtoi(leftParts[i].c_str());
		int right = _wtoi(rightParts[i].c_str());
		if (left > right)
		{
			return 1;
		}
		else if (left < right)
		{
			return -1;
		}
		i++;
	}

	return 0;
}

bool AppSecInc::Version::IsWithinBounds(const std::wstring& version, const std::wstring& min, const std::wstring& max)
{
	// empty version is never within bounds
    bool result = ! version.empty();
    
    if (result && ! max.empty()) 
    {
        result = (Compare(version, max) <= 0);
    }

    if (result && ! min.empty()) 
    {
        result = (Compare(version, min) >= 0);
    }

    return result;
}
