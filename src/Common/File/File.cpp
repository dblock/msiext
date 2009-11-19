#include "StdAfx.h"
#include "File.h"

std::string AppSecInc::File::GetTemporaryFileNameA()
{
	char tf[MAX_PATH];
	CHECK_WIN32_BOOL(GetTempFileNameA(GetTemporaryDirectoryA().c_str(), "MSI", 0, tf),
		L"GetTempFileNameA");

	return tf;
}

std::wstring AppSecInc::File::GetTemporaryFileNameW()
{	
	wchar_t tf[MAX_PATH];
    CHECK_WIN32_BOOL(GetTempFileNameW(GetTemporaryDirectoryW().c_str(), L"MSI", 0, tf),
		_T("GetTempFileNameW"));

	return tf;
}

std::string AppSecInc::File::GetFileDirectoryA(const std::string& path)
{
	int backslashPos = path.rfind('\\', path.length());
	if (backslashPos == path.npos)
		throw std::exception("missing \\");

	return path.substr(0, backslashPos);
}

std::wstring AppSecInc::File::GetFileDirectoryW(const std::wstring& path)
{
	int backslashPos = path.rfind(L'\\', path.length());
	if (backslashPos == path.npos)
		throw std::exception("missing \\");

	return path.substr(0, backslashPos);
}

std::string AppSecInc::File::GetFileNameA(const std::string& path)
{
	int backslashPos = path.rfind('\\', path.length());
	if (backslashPos == path.npos)
		throw std::exception("missing \\");

	return path.substr(backslashPos + 1, path.length() - backslashPos - 1);
}

std::wstring AppSecInc::File::GetFileNameW(const std::wstring& path)
{
	int backslashPos = path.rfind(L'\\', path.length());
	if (backslashPos == path.npos)
		throw std::exception("missing \\");

	return path.substr(backslashPos + 1, path.length() - backslashPos - 1);
}

std::string AppSecInc::File::GetModuleDirectoryA()
{
	return GetFileDirectoryA(GetModuleFileNameA());
}

std::wstring AppSecInc::File::GetModuleDirectoryW()
{
	return GetFileDirectoryW(GetModuleFileNameW());
}

std::string AppSecInc::File::GetModuleFileNameA(HINSTANCE h)
{
	char moduleFileName[MAX_PATH];
	CHECK_WIN32_BOOL(::GetModuleFileNameA(h, moduleFileName, MAX_PATH),
		_T("GetModuleFileNameA"));

	return moduleFileName;
}

std::wstring AppSecInc::File::GetModuleFileNameW(HINSTANCE h)
{
	wchar_t moduleFileName[MAX_PATH];
	CHECK_WIN32_BOOL(::GetModuleFileNameW(h, moduleFileName, MAX_PATH),
		_T("GetModuleFileNameW"));

	return moduleFileName;
}

bool AppSecInc::File::FileExists(const std::string& filename)
{
	return FileExists(StringUtils::mb2wc(filename));
}

bool AppSecInc::File::FileExists(const std::wstring& filename)
{
	DWORD dwAttr = GetFileAttributesW(filename.c_str());
	
	if (dwAttr == INVALID_FILE_ATTRIBUTES)
	{
		DWORD dwErr = GetLastError();
		
		switch(dwErr)
		{
		case ERROR_FILE_NOT_FOUND:
		case ERROR_PATH_NOT_FOUND:
            return false;
		default:
			CHECK_WIN32_DWORD(dwErr,
                L"GetFileAttributesW: " << filename);
		}
	}
	else if (dwAttr & FILE_ATTRIBUTE_DIRECTORY)
	{
		return false;
	}

	return true;
}

bool AppSecInc::File::DirectoryExists(const std::string& path)
{
    return DirectoryExists(StringUtils::mb2wc(path));
}

bool AppSecInc::File::DirectoryExists(const std::wstring& path)
{
	DWORD dwAttr = GetFileAttributesW(path.c_str());
	
	if (dwAttr == INVALID_FILE_ATTRIBUTES)
	{
		DWORD dwErr = GetLastError();
		
		switch(dwErr)
		{
		case ERROR_FILE_NOT_FOUND:
		case ERROR_PATH_NOT_FOUND:
			return false;
		default:
            CHECK_WIN32_DWORD(dwErr,
                L"GetFileAttributesW: " << path);
            break;
		}
	}
	else if (dwAttr & FILE_ATTRIBUTE_DIRECTORY)
	{
		return true;
	}

	return false;
}

void AppSecInc::File::FileDelete(const std::string& filename)
{
	CHECK_WIN32_BOOL(::DeleteFileA(filename.c_str()),
		_T("DeleteFile"));
}

void AppSecInc::File::FileDelete(const std::wstring& filename)
{
	CHECK_WIN32_BOOL(::DeleteFileW(filename.c_str()),
		_T("DeleteFile"));
}

std::wstring AppSecInc::File::DirectoryCombine(const std::wstring& dir, const std::wstring& file)
{
    wchar_t buffer[MAX_PATH];
    CHECK_BOOL(NULL != ::PathCombineW(buffer, dir.length() ? dir.c_str() : NULL, file.length() ? file.c_str() : NULL),
        L"Error combining \"" << dir << "\" and \"" << file << "\"");
    return buffer;
}

std::list<std::wstring> AppSecInc::File::GetFiles(const std::wstring& path_and_wildcard, int flags)
{
	std::wstring::size_type star_pos = path_and_wildcard.find(L"*");
	std::wstring::size_type question_pos = path_and_wildcard.find(L"?");
	std::wstring::size_type bs_pos = path_and_wildcard.rfind(L"\\");
	
	if (bs_pos == path_and_wildcard.npos)
	{
		// the entire path_and_wildcard is a name or a wildcard
		return GetFiles(GetCurrentDirectoryW(), path_and_wildcard, flags);
	} 

	// the only supported wildcards are part of the file name
	// directory wildcards are not supported
	if ((star_pos != path_and_wildcard.npos && star_pos < bs_pos)
		|| (question_pos != path_and_wildcard.npos && question_pos < bs_pos))
	{
		throw std::exception("wildcard in a directory name");
	}

	// split in 2, path and wildcard
	return GetFiles(
		path_and_wildcard.substr(0, bs_pos),
		path_and_wildcard.substr(bs_pos + 1),
		flags);	
}


std::list<std::wstring> AppSecInc::File::GetDirectoryFiles(const std::wstring& path, const std::wstring& wildcard)
{
    HANDLE h = INVALID_HANDLE_VALUE;
    std::list<std::wstring> result;

    WIN32_FIND_DATA data = { 0 };

    h = ::FindFirstFileW((path + L"\\" + wildcard).c_str(), & data);
    
    if (h != INVALID_HANDLE_VALUE)
    {
		boost::shared_ptr<void> hFind(h, ::FindClose);

        do
        {
            std::wstring filename = data.cFileName;

            if (filename == L"." || filename == L"..")
                continue;

            if (! (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                result.push_back(filename);
            }

        } while(::FindNextFile(h, & data));
    }

    switch(DWORD rc = ::GetLastError())
    {
	case ERROR_PATH_NOT_FOUND: // directory not found in FindFirstFile
    case ERROR_FILE_NOT_FOUND: // file not found in FindFirstFile
    case ERROR_NO_MORE_FILES: // more more files in FindNextFile
        break;
    default:
        CHECK_WIN32_DWORD(rc, "Error in FindFirst/NextFile");
    }
    
    return result;
}

std::list<std::wstring> AppSecInc::File::GetFiles(const std::wstring& path, const std::wstring& wildcard, int flags)
{
    HANDLE h = INVALID_HANDLE_VALUE;
    std::list<std::wstring> result;

    WIN32_FIND_DATA data = { 0 };

    h = ::FindFirstFileW((path + L"\\*.*").c_str(), & data);
    
    DWORD rc = ERROR_SUCCESS;

    if (h != INVALID_HANDLE_VALUE)
    {
		boost::shared_ptr<void> hFind(h, ::FindClose);

		do
        {
            std::wstring filename = data.cFileName;

            if (filename == L"." || filename == L"..")
                continue;

            filename = DirectoryCombine(path, filename);

            if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (flags & GET_FILES_DIRECTORIES)
                    result.push_back(filename);

                if (flags & GET_FILES_RECURSIVE)
                {
                    std::wstring fullsubpath = DirectoryCombine(path, data.cFileName);
                    result.splice(result.end(), GetFiles(fullsubpath, wildcard, flags));
                }
            }

        } while(::FindNextFile(h, & data));
    }

    switch(rc = ::GetLastError())
    {
	case ERROR_PATH_NOT_FOUND: // directory not found in FindFirstFile
    case ERROR_FILE_NOT_FOUND: // file not found in FindFirstFile
    case ERROR_NO_MORE_FILES: // more more files in FindNextFile
        break;
    default:
        CHECK_WIN32_DWORD(rc, "Error in FindFirst/NextFile");
    }
    
    // get files matching wildcard in this directory
    if (flags & GET_FILES_FILES)
    {
        std::list<std::wstring> files = GetDirectoryFiles(path, wildcard);

        for each(const std::wstring& file in files)
        {
            result.push_back(DirectoryCombine(path, file));
        }
    }

    return result;
}

long AppSecInc::File::GetFileSize(const std::wstring& filename)
{
    WIN32_FILE_ATTRIBUTE_DATA attr = { 0 };
	CHECK_WIN32_BOOL(GetFileAttributesExW(filename.c_str(), GetFileExInfoStandard, & attr),
        L"Error getting file attributes of " << filename);
    CHECK_BOOL(0 == attr.nFileSizeHigh,
        L"File " << filename << L" is > 2GB (" << attr.nFileSizeHigh << ")");
    return (long) attr.nFileSizeLow; 
}

long AppSecInc::File::GetFileSize(const std::string& filename)
{
    return GetFileSize(AppSecInc::StringUtils::mb2wc(filename));
}

std::string AppSecInc::File::GetTemporaryDirectoryA()
{
	char td[MAX_PATH];
	
	CHECK_WIN32_BOOL(GetTempPathA(MAX_PATH, td),
        L"GetTempPathA");

	return td;
}

std::wstring AppSecInc::File::GetTemporaryDirectoryW()
{
	wchar_t td[MAX_PATH];
	
	CHECK_WIN32_BOOL(GetTempPathW(MAX_PATH, td),
		_T("GetTempPathW"));

	return td;
}

void AppSecInc::File::ReadToEnd(const std::wstring& filename, std::wstring& data)
{
    std::string char_data;
    ReadToEnd(filename, char_data);
    data = AppSecInc::StringUtils::mb2wc(char_data);
}

void AppSecInc::File::ReadToEnd(const std::wstring& filename, std::string& data)
{
    std::vector<char> char_data;
    ReadToEnd(filename, char_data);
    data.resize(char_data.size());
    std::copy(char_data.begin(), char_data.end(), data.begin());
}

void AppSecInc::File::ReadToEnd(const std::wstring& filename, std::vector<char>& data)
{
    data.clear();
    long size = GetFileSize(filename);
    if (size > 0)
    {
        HANDLE h = ::CreateFile(filename.c_str(), GENERIC_READ, 0,  
            NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        CHECK_WIN32_BOOL(h != NULL,
            L"Error opening " << filename);

        boost::shared_ptr<void> hFile(h, ::CloseHandle);
        data.resize(size);

        DWORD dwRead = 0;
        CHECK_WIN32_BOOL(::ReadFile(h, & * data.begin(), size, & dwRead, NULL),
            L"Error reading " << filename);

        CHECK_BOOL(dwRead == size,
            L"Invalid number of bytes read from " << filename);
    }
}

void AppSecInc::File::FileWrite(
    const std::wstring& filename, 
    const std::vector<char>& data,
    DWORD dwShareMode, // GENERIC_READ | GENERIC_WRITE
    DWORD dwCreationDisposition, // CREATE_ALWAYS
    DWORD dwFlagsAndAttributes) // FILE_ATTRIBUTE_NORMAL)
{
    HANDLE hFile = ::CreateFile(filename.c_str(), dwShareMode, 0, 
        NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL);

    CHECK_WIN32_BOOL(hFile != NULL,
        L"Error opening " << filename);

    boost::shared_ptr<void> file_ptr(hFile, ::CloseHandle);

    if (data.size() > 0) // empty files are ok
    {
        DWORD dwWritten = 0;
        CHECK_WIN32_BOOL(::WriteFile(hFile, & * data.begin(), data.size(), & dwWritten, NULL),
            L"Error writing " << data.size() << " byte(s) to " << filename);

        CHECK_BOOL(dwWritten == data.size(), 
            L"Invalid number of bytes written.");
    }
}

void AppSecInc::File::FileCreate(
    const std::wstring& filename, 
    DWORD dwShareMode, // GENERIC_READ | GENERIC_WRITE
    DWORD dwCreationDisposition, // CREATE_ALWAYS
    DWORD dwFlagsAndAttributes) // FILE_ATTRIBUTE_NORMAL)
{
    HANDLE hFile = ::CreateFile(filename.c_str(), dwShareMode, 0, 
        NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL);

    CHECK_WIN32_BOOL(hFile != NULL,
        L"Error opening " << filename);

    CHECK_WIN32_BOOL(::CloseHandle(hFile),
        L"Error closing file handle");
}

std::string AppSecInc::File::DirectoryCreate(const std::string& path)
{
	return AppSecInc::StringUtils::wc2mb(
		DirectoryCreate(AppSecInc::StringUtils::mb2wc(path)));
}

std::wstring AppSecInc::File::DirectoryCreate(const std::wstring& path)
{
	std::wstring result;
	std::vector<std::wstring> parts;
	AppSecInc::StringUtils::tokenize(path, parts, L"\\");
	
	std::wstring current;
	for each (std::wstring part in parts)
	{
		if (current.length() > 0) current.append(L"\\");
		current.append(part);

		if (! DirectoryExists(current))
		{
			CHECK_WIN32_BOOL(::CreateDirectoryW(current.c_str(), NULL),
				L"Error in CreateDirectory: " << current);

			if (result.empty()) result = current;
		}
	}

	return result;
}

bool AppSecInc::File::DirectoryDelete(const std::string& path, int flags)
{
	return DirectoryDelete(AppSecInc::StringUtils::mb2wc(path), flags);
}

bool AppSecInc::File::DirectoryDelete(const std::wstring& path, int flags)
{
    CHECK_BOOL(flags > 0,
        L"Missing flags");

	WIN32_FIND_DATAW data = { 0 };
    bool directory_empty = true;
	bool directory_exists = false;
	std::wstring wildcard = path;
	AppSecInc::StringUtils::rtrim(wildcard, L"\\");
	wildcard.append(L"\\*");

    HANDLE h = FindFirstFileW(wildcard.c_str(), & data); // find the first file
    
    if (h != INVALID_HANDLE_VALUE)
    {
		boost::shared_ptr<void> hFind(h, ::FindClose);
		directory_exists = true;

		do
		{
            std::wstring filename = data.cFileName;

            if (filename == L"." || filename == L"..")
                continue;

			std::wstring sub = path;
			AppSecInc::StringUtils::rtrim(sub, L"\\");
			sub.append(L"\\");
			sub.append(filename);

			if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((flags & DELETE_DIRECTORY_SUBDIRECTORIES) > 0)
				{
					directory_empty &= DirectoryDelete(sub, flags);
				}
			}
			else if ((flags & DELETE_DIRECTORY_FILES) > 0)
			{
				CHECK_WIN32_BOOL(::DeleteFileW(sub.c_str()),
					L"Error deleting " << sub);
			}
            else
            {
                directory_empty = false;
            }

		} while (FindNextFileW(h, & data));
	}

    switch(DWORD rc = ::GetLastError())
    {
	case ERROR_PATH_NOT_FOUND: // directory not found in FindFirstFile
    case ERROR_FILE_NOT_FOUND: // file not found in FindFirstFile
    case ERROR_NO_MORE_FILES: // more more files in FindNextFile
        break;
    default:
        CHECK_WIN32_DWORD(rc, "Error in FindFirst/NextFile");
    }
        
	if (directory_exists && directory_empty && ((flags & DELETE_DIRECTORY_FOLDERS) > 0))
	{
		CHECK_WIN32_BOOL(::RemoveDirectoryW(path.c_str()),
			L"Error deleting directory: " << path);
	}

    return directory_empty;
}

std::pair<std::string, std::string> AppSecInc::File::SizeToStringPairA(long size, AppSecInc::File::FILESIZE_STRING_TYPE type, int precision)
{
    std::pair<std::wstring, std::wstring> size_s = SizeToStringPairW(size, type, precision);
    return std::make_pair(
        AppSecInc::StringUtils::wc2mb(size_s.first),
        AppSecInc::StringUtils::wc2mb(size_s.second));
}

std::pair<std::wstring, std::wstring> AppSecInc::File::SizeToStringPairW(long size, AppSecInc::File::FILESIZE_STRING_TYPE type, int precision)
{
    if (type == AppSecInc::File::FILESIZE_AUTO)
    {
        if (size >= AppSecInc::File::GBYTE) type = AppSecInc::File::FILESIZE_GBYTES;
        else if (size >= AppSecInc::File::MBYTE) type = AppSecInc::File::FILESIZE_MBYTES;
        else if (size >= AppSecInc::File::KBYTE) type = AppSecInc::File::FILESIZE_KBYTES;
        else type = AppSecInc::File::FILESIZE_BYTES;
    }

    std::wstringstream size_value;
    std::wstring size_type;
    switch(type)
    {
    case AppSecInc::File::FILESIZE_GBYTES:
        size_value << std::fixed << std::setprecision(precision) << (double) size / AppSecInc::File::GBYTE;
        size_type = L"GB";
        break;
    case AppSecInc::File::FILESIZE_MBYTES:
        size_value << std::fixed << std::setprecision(precision) << (double) size / AppSecInc::File::MBYTE;
        size_type = L"MB";
        break;
    case AppSecInc::File::FILESIZE_KBYTES:
        size_value << std::fixed << std::setprecision(precision) << (double) size / AppSecInc::File::KBYTE;
        size_type = L"KB";
        break;
    case AppSecInc::File::FILESIZE_BYTES:
        size_value << size;
        size_type = L"byte";
        if (size != 1) size_type.append(L"s");
        break;
    }

    return std::make_pair(size_value.str(), size_type);
}

std::string AppSecInc::File::SizeToStringA(long size, FILESIZE_STRING_TYPE type, int precision)
{
    return AppSecInc::StringUtils::wc2mb(SizeToStringW(size, type, precision));
}

std::wstring AppSecInc::File::SizeToStringW(long size, FILESIZE_STRING_TYPE type, int precision)
{
    std::pair<std::wstring, std::wstring> size_pair = SizeToStringPairW(size, type, precision);
    return size_pair.first + L" " + size_pair.second;
}

std::string AppSecInc::File::GetCurrentDirectoryA()
{
    char result[MAX_PATH];
    CHECK_WIN32_BOOL(0 < ::GetCurrentDirectoryA(MAX_PATH, result),
        L"Error in GetCurrentDirectoryA");
    return result;
}

std::wstring AppSecInc::File::GetCurrentDirectoryW()
{
    wchar_t result[MAX_PATH];
    CHECK_WIN32_BOOL(0 < ::GetCurrentDirectoryW(MAX_PATH, result),
        L"Error in GetCurrentDirectoryW");
    return result;
}

std::string AppSecInc::File::GetParentDirectory(const std::string& path)
{
	return AppSecInc::StringUtils::wc2mb(GetParentDirectory(
		AppSecInc::StringUtils::mb2wc(path)));
}

std::wstring AppSecInc::File::GetParentDirectory(const std::wstring& path)
{
	if (path.length() == 0) return L"";
	return DirectoryCombine(path, L"..\\");
}

std::wstring AppSecInc::File::GetSpecialFolderPath(int csidl, SHGFP_TYPE flags)
{
	wchar_t buffer [MAX_PATH] = { 0 };

	CHECK_HR(::SHGetFolderPath(NULL, csidl, NULL, flags,  buffer),
		"SHGetFolderPath failed");

	return buffer;
}
