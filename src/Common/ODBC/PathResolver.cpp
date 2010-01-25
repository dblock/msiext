#include "stdafx.h"
#include "PathResolver.h"

using namespace AppSecInc::Databases::ODBC;

FilesystemPathResolver::FilesystemPathResolver()
{
}

FilesystemPathResolver::~FilesystemPathResolver()
{
}

void FilesystemPathResolver::setBasePath(const std::wstring& path)
{
	basepath = path;
}

std::wstring FilesystemPathResolver::readContent(const std::wstring& path)
{
	std::wstring content;
	CHECK_BOOL(AppSecInc::File::FileExists(path), L"File does not exist: " << path);
	AppSecInc::File::ReadToEnd(getFullPath(path), content);
	return content;
}


std::wstring FilesystemPathResolver::getFolderPath(const std::wstring& path) const
{
	return AppSecInc::File::GetParentDirectory(getFullPath(path));
}

std::wstring FilesystemPathResolver::getFullPath(const std::wstring path) const
{
	if (AppSecInc::File::IsAbsolutePath(path) || basepath.empty()) {
		return path;
	}
	return AppSecInc::File::DirectoryCombine(basepath, path);
}
