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
	std::wstring fullpath = getFullPath(path);
	CHECK_BOOL(AppSecInc::File::FileExists(fullpath), 
		L"File does not exist: " << fullpath);
	AppSecInc::File::ReadToEnd(fullpath, content);
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
