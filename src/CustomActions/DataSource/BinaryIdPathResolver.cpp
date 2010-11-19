#include "StdAfx.h"
#include "BinaryIdPathResolver.h"

using namespace AppSecInc::Databases::ODBC;

//------------------------------------------------------------------------------
// helper classes/functions
//------------------------------------------------------------------------------
BinaryIdPathResolver::BinaryIdPathResolver(MsiInstall* msiInstall)
: msiInstall(msiInstall)
{
}

std::wstring BinaryIdPathResolver::readContent(const std::wstring& path)
{
	std::wstring binaryid = pathToId(path);
	std::vector<char> data;
	msiInstall->GetBinaryData(binaryid, data);
	std::string char_data(&*data.begin(), data.size());
	std::wstring sql = AppSecInc::StringUtils::mb2wc(char_data);
	return sql;
}

std::wstring BinaryIdPathResolver::pathToId(const std::wstring& path)
{
	std::wstring id;
	std::wstring rest = path;
	size_t pos = rest.find(L'\\');
	while (pos != rest.npos) {
		std::wstring dir = rest.substr(0, pos);
		if (dir != L"" && dir != L"." && dir != L"..") {
			id.append(dir).append(L"_");
		}
		rest = rest.substr(pos+1);
		pos = rest.find(L'\\');
	}
	id.append(rest);
	replaceNonIdCharsWithUnderscore(id);
	return id;
}
	
void BinaryIdPathResolver::replaceNonIdCharsWithUnderscore(std::wstring& str)
{
	static std::wstring validChars =
		L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_.-";

	size_t pos = str.find_first_not_of(validChars);
	while (pos != str.npos) {
		str[pos] = L'_';
		pos = str.find_first_not_of(validChars,pos+1);
	}
}
