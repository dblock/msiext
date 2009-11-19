#include "StdAfxUnitTests.h"
#include "FileImplUnitTests.h"
#include "File.h"

using namespace AppSecInc::UnitTests::File;

CPPUNIT_TEST_SUITE_REGISTRATION(FileUnitTests);

void FileUnitTests::testGetTemporaryFileName()
{
	std::string path = AppSecInc::File::GetTemporaryFileNameA();
	std::cout << std::endl << "Temporary filename: " << path;
	std::string directory = AppSecInc::File::GetFileDirectoryA(path);
	std::cout << std::endl << "Directory: " << directory;
	CPPUNIT_ASSERT(directory.length() > 0);
	std::string filename = AppSecInc::File::GetFileNameA(path);
	std::cout << std::endl << "File: " << filename;
	CPPUNIT_ASSERT(filename.length() > 0);
	std::stringstream s_path;
	s_path << directory << "\\" << filename;
	std::cout << std::endl << "Joined directory: " << s_path.str();
	CPPUNIT_ASSERT(path == s_path.str());
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(path));
	AppSecInc::File::FileDelete(path);
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(path));
}

void FileUnitTests::testGetModuleDirectory()
{
	std::string path = AppSecInc::File::GetModuleDirectoryA();
	std::cout << std::endl << "Module directory: " << path;
	CPPUNIT_ASSERT(path.length() > 0);
	char moduleFileName[MAX_PATH];
	CPPUNIT_ASSERT(::GetModuleFileNameA(NULL, moduleFileName, MAX_PATH));
	std::cout << std::endl << "Compare: " << moduleFileName;
	CPPUNIT_ASSERT(AppSecInc::StringUtils::startsWith(moduleFileName, path));
}

void FileUnitTests::testFileDirectoryExists()
{
	std::string path = AppSecInc::File::GetTemporaryFileNameA();
	std::cout << std::endl << "Temporary filename: " << path;
	
	std::string directory = AppSecInc::File::GetFileDirectoryA(path);
	std::cout << std::endl << "Directory: " << directory;
	
	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(directory));
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(directory));
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(path));		
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(path));
	AppSecInc::File::FileDelete(path);

	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists("C:\\"));
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists("C:\\"));
	
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(""));
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(""));

	std::string filename = AppSecInc::Com::GenerateGUIDStringA();
	std::string guidpath = "C:\\" + filename;
	std::cout << std::endl << "Guid path: " << guidpath;
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(guidpath));
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(guidpath));
}

void FileUnitTests::testDelete()
{
	std::string path = AppSecInc::File::GetTemporaryFileNameA();
	std::cout << std::endl << "Temporary filename: " << path;
	bool exists = false;
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(path.c_str()));
	CPPUNIT_ASSERT(::PathFileExistsA(path.c_str()));
	AppSecInc::File::FileDelete(path.c_str());
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(path.c_str()));
	CPPUNIT_ASSERT(FALSE == ::PathFileExistsA(path.c_str()));
}

void FileUnitTests::testDirectoryCombine()
{
    struct TestData
    {
        LPCWSTR dir;
        LPCWSTR file;
        LPCWSTR expected_result;
    };

    TestData testdata[] = 
    {
        { L"C:", L"One\\Two\\Three", L"C:\\One\\Two\\Three" },
        { L"C:\\One", L"Two", L"C:\\One\\Two" },
        { L"C:\\One\\", L"Two", L"C:\\One\\Two" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wcout << std::endl << testdata[i].dir << L" + " << testdata[i].file;
        std::wstring result = AppSecInc::File::DirectoryCombine(testdata[i].dir, testdata[i].file);
        std::wcout << L" => " << result;
        CPPUNIT_ASSERT(result == testdata[i].expected_result);
    }
}

void FileUnitTests::testGetFileSize()
{
    std::wstring moduledir = AppSecInc::File::GetModuleDirectoryW();
    std::list<std::wstring> files = AppSecInc::File::GetFiles(moduledir, L"*.xml", AppSecInc::File::GET_FILES_FILES | AppSecInc::File::GET_FILES_RECURSIVE);
    for each (const std::wstring& file in files)
    {
        long size = AppSecInc::File::GetFileSize(file);
        std::wcout << std::endl << L" " << file << L": " << AppSecInc::StringUtils::toWString(size) << L" byte(s)";
        CPPUNIT_ASSERT(size >= 0);
    }
}

void FileUnitTests::testGetFilesRecursive()
{
    std::list<std::wstring> files = AppSecInc::File::GetFiles(
        AppSecInc::File::GetModuleDirectoryW(), L"*.exe", AppSecInc::File::GET_FILES_ALL);

    bool found = false;
    for each (const std::wstring& file in files)
        found |= (file == AppSecInc::File::GetModuleFileNameW());

    CPPUNIT_ASSERT(found);
}

void FileUnitTests::testGetTemporaryDirectory()
{
	std::wstring directory = AppSecInc::File::GetTemporaryDirectoryW();
	std::wcout << std::endl << L"Temporary directory: " << directory;
	CPPUNIT_ASSERT(directory.length() > 0);
    CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(directory));
}

void FileUnitTests::testReadToEnd()
{
	std::wstring tmpfile = AppSecInc::File::GetTemporaryFileNameW();
	std::wcout << std::endl << L"Temporary filename: " << tmpfile;
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(tmpfile));
    std::vector<char> data;
    AppSecInc::File::ReadToEnd(tmpfile, data);
    CPPUNIT_ASSERT(data.size() == 0); // temporary files are created empty
    // ansi data
    std::string guid = AppSecInc::Com::GenerateGUIDStringA();
    std::ofstream f(AppSecInc::StringUtils::wc2mb(tmpfile).c_str());
    f << guid.c_str();
    f.close();
    // read as byte data
    std::vector<char> guiddata;
    AppSecInc::File::ReadToEnd(tmpfile, guiddata);
	std::wcout << std::endl << L"Size: " << guiddata.size();    
    CPPUNIT_ASSERT(guiddata.size() > 0);
    CPPUNIT_ASSERT(guiddata.size() == AppSecInc::File::GetFileSize(tmpfile));
    // read as string data
    std::string guidstring;
    AppSecInc::File::ReadToEnd(tmpfile, guidstring);
    std::cout << std::endl << guidstring;
    CPPUNIT_ASSERT(guidstring == guid);
    // unicode data
    std::wstring wguidstring;
    AppSecInc::File::ReadToEnd(tmpfile, wguidstring);
    std::wcout << std::endl << wguidstring;
    CPPUNIT_ASSERT(wguidstring == AppSecInc::StringUtils::mb2wc(guid));
    // delete temp file
    AppSecInc::File::FileDelete(tmpfile);
}

void FileUnitTests::testFileWrite()
{
    std::wstring tmpfile = AppSecInc::File::DirectoryCombine(
        AppSecInc::File::GetTemporaryDirectoryW(), AppSecInc::Com::GenerateGUIDStringW());
	std::wcout << std::endl << L"Temporary filename: " << tmpfile;
    // empty data
    std::vector<char> write_data;
    AppSecInc::File::FileWrite(tmpfile, write_data);
    std::vector<char> read_data;
    AppSecInc::File::ReadToEnd(tmpfile, read_data);
    CPPUNIT_ASSERT(read_data.size() == 0); // temporary files are created empty
    // some data
    std::string write_guid = AppSecInc::Com::GenerateGUIDStringA();
    std::cout << std::endl << "Write GUID: " << write_guid;
    std::vector<char> write_guid_vector(write_guid.begin(), write_guid.end());
    AppSecInc::File::FileWrite(tmpfile, write_guid_vector);
    std::vector<char> read_guid;
    AppSecInc::File::ReadToEnd(tmpfile, read_guid);
	std::wcout << std::endl << L"Size: " << read_guid.size();    
    CPPUNIT_ASSERT(read_guid.size() > 0);
    CPPUNIT_ASSERT(read_guid.size() == AppSecInc::File::GetFileSize(tmpfile));
    std::string read_guid_string(read_guid.begin(), read_guid.end());
    std::cout << std::endl << "Read GUID: " << read_guid_string;
    CPPUNIT_ASSERT(write_guid == read_guid_string);
    // delete temp file
    AppSecInc::File::FileDelete(tmpfile);
}

void FileUnitTests::testFileCreate()
{
    std::wstring tmpfile = AppSecInc::File::DirectoryCombine(
        AppSecInc::File::GetTemporaryDirectoryW(), AppSecInc::Com::GenerateGUIDStringW());
	std::wcout << std::endl << L"Temporary filename: " << tmpfile;
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(tmpfile));
    // create the file
    AppSecInc::File::FileCreate(tmpfile);
    CPPUNIT_ASSERT(AppSecInc::File::GetFileSize(tmpfile) == 0);
    // populate the temp file with data, then re-create, ensure that it is empty
    std::vector<char> data;
    data.push_back('x');
    AppSecInc::File::FileWrite(tmpfile, data);
    CPPUNIT_ASSERT(AppSecInc::File::GetFileSize(tmpfile) == 1);
    AppSecInc::File::FileCreate(tmpfile);
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(tmpfile));
    CPPUNIT_ASSERT(AppSecInc::File::GetFileSize(tmpfile) == 0);
    AppSecInc::File::FileDelete(tmpfile);
}

void FileUnitTests::testDirectoryCreate()
{
	std::wstring root = AppSecInc::File::GetTemporaryDirectoryW();
	// check that we can create one level
	std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring path1 = root + guid;
	std::wcout << std::endl << L"Creating: " << path1;
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(path1));
	std::wstring path1_created = AppSecInc::File::DirectoryCreate(path1);
	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(path1));
	CPPUNIT_ASSERT(path1 == path1_created);
	// check that we can create two more levels
	std::wstring path2 = path1 + L"\\" + guid;
	std::wstring path3 = path2 + L"\\" + guid;
	std::wcout << std::endl << L"Creating: " << path3;
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(path3));
	std::wstring path3_created = AppSecInc::File::DirectoryCreate(path3);
	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(path2));
	// the first created directory is path2
	CPPUNIT_ASSERT(path2 == path3_created);
	// delete the final result
	AppSecInc::File::DirectoryDelete(path1);
}

void FileUnitTests::testDirectoryDelete()
{
	std::wstring root = AppSecInc::File::GetTemporaryDirectoryW();
	std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring deeppath = root + guid + L"\\" + guid + L"\\" + guid;
	std::wstring newpath = AppSecInc::File::DirectoryCreate(deeppath);
	std::wcout << std::endl << "Path: " << newpath;
	// delete files in a directory that doesn't have any files or subdirectories
	AppSecInc::File::DirectoryDelete(deeppath, AppSecInc::File::DELETE_DIRECTORY_FILES);
	// delete files in a directory that doesn't have any files, but has subdirectories
	AppSecInc::File::DirectoryDelete(newpath, AppSecInc::File::DELETE_DIRECTORY_FILES);
	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(newpath));
	// create two files
	std::wstring filename1 = newpath + L"\\" + guid + L"-1.tmp";
	std::wstring filename2 = newpath + L"\\" + guid + L"-2.tmp";
	AppSecInc::File::FileCreate(filename1);
	AppSecInc::File::FileCreate(filename2);
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(filename1));
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(filename2));
    // two directories + two files
	std::list<std::wstring> files = AppSecInc::File::GetFiles(newpath, L"*.*", AppSecInc::File::GET_FILES_ALL);
    CPPUNIT_ASSERT(4 == files.size());
	// try to delete effectively nothing, this will fail
	try
	{
		AppSecInc::File::DirectoryDelete(newpath, 0);
		throw "DeleteDirectory was expected to throw std::exception";
	}
	catch(std::exception& ex)
	{
		// expected exception, this directory can't be deleted since it has files in it
		std::cout << std::endl << "Expected exception: " << ex.what();
		CPPUNIT_ASSERT(AppSecInc::File::FileExists(filename1));
		CPPUNIT_ASSERT(AppSecInc::File::FileExists(filename2));
	}
    // make sure nothing was deleted
    CPPUNIT_ASSERT(4 == AppSecInc::File::GetFiles(newpath, L"*.*", AppSecInc::File::GET_FILES_ALL).size());
	// delete without deleting files, the empty subdirectories will be deleted, leaving us with 2 files
    AppSecInc::File::DirectoryDelete(newpath, AppSecInc::File::DELETE_DIRECTORY_EMPTY);
    CPPUNIT_ASSERT(2 == AppSecInc::File::GetFiles(newpath, L"*.*", AppSecInc::File::GET_FILES_ALL).size());
	// delete with file and non-empty subdirectories
	AppSecInc::File::DirectoryDelete(newpath);
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(filename1));
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(filename2));
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(newpath));
}

void FileUnitTests::testSizeToString()
{
    struct TestData
    {
        long size;
        int precision;
        LPCWSTR expected_result_none;
        LPCWSTR expected_result_auto;
        LPCWSTR expected_result_gbytes;
        LPCWSTR expected_result_mbytes;
        LPCWSTR expected_result_kbytes;
        LPCWSTR expected_result_bytes;
    };

    TestData testdata[] = 
    {
        { 0, 0, L"0", L"0 bytes", L"0 GB", L"0 MB", L"0 KB", L"0 bytes" },
        { 1, 0, L"1", L"1 byte", L"0 GB", L"0 MB", L"0 KB", L"1 byte" },
        { 2, 0, L"2", L"2 bytes", L"0 GB", L"0 MB", L"0 KB", L"2 bytes" },
        // kilobytes
        { AppSecInc::File::KBYTE - 1, 0, L"1023", L"1023 bytes", L"0 GB", L"0 MB", L"1 KB", L"1023 bytes" },
        { AppSecInc::File::KBYTE, 0, L"1024", L"1 KB", L"0 GB", L"0 MB", L"1 KB", L"1024 bytes" },
        // megabytes
        { AppSecInc::File::MBYTE, 0, L"1048576", L"1 MB", L"0 GB", L"1 MB", L"1024 KB", L"1048576 bytes" },
        { AppSecInc::File::MBYTE + AppSecInc::File::MBYTE / 5, 0, L"1258291", L"1 MB", L"0 GB", L"1 MB", L"1229 KB", L"1258291 bytes" },
        { AppSecInc::File::MBYTE + AppSecInc::File::MBYTE / 5, 1, L"1258291", L"1.2 MB", L"0.0 GB", L"1.2 MB", L"1228.8 KB", L"1258291 bytes" },
        // gigabytes
        { AppSecInc::File::GBYTE, 0, L"1073741824", L"1 GB", L"1 GB", L"1024 MB", L"1048576 KB", L"1073741824 bytes" },
        { AppSecInc::File::GBYTE + 100 * AppSecInc::File::MBYTE, 2, L"1178599424", L"1.10 GB", L"1.10 GB", L"1124.00 MB", L"1150976.00 KB", L"1178599424 bytes" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wstring result_auto = AppSecInc::File::SizeToStringW(testdata[i].size, AppSecInc::File::FILESIZE_AUTO, testdata[i].precision);
        std::wstring result_gbytes = AppSecInc::File::SizeToStringW(testdata[i].size, AppSecInc::File::FILESIZE_GBYTES, testdata[i].precision);
        std::wstring result_mbytes = AppSecInc::File::SizeToStringW(testdata[i].size, AppSecInc::File::FILESIZE_MBYTES, testdata[i].precision);
        std::wstring result_kbytes = AppSecInc::File::SizeToStringW(testdata[i].size, AppSecInc::File::FILESIZE_KBYTES, testdata[i].precision);
        std::wstring result_bytes = AppSecInc::File::SizeToStringW(testdata[i].size, AppSecInc::File::FILESIZE_BYTES, testdata[i].precision);
        std::wcout << std::endl << testdata[i].size << L" => " << result_auto
            << L", " << result_bytes << L", " << result_kbytes << L", " << result_mbytes << L", " << result_gbytes;
        CPPUNIT_ASSERT(testdata[i].expected_result_auto == result_auto);
        CPPUNIT_ASSERT(testdata[i].expected_result_gbytes == result_gbytes);
        CPPUNIT_ASSERT(testdata[i].expected_result_mbytes == result_mbytes);
        CPPUNIT_ASSERT(testdata[i].expected_result_kbytes == result_kbytes);
        CPPUNIT_ASSERT(testdata[i].expected_result_bytes == result_bytes);
    }
}

void FileUnitTests::testGetCurrentDirectory()
{
    char expected_result[MAX_PATH];
    CPPUNIT_ASSERT(0 < ::GetCurrentDirectoryA(MAX_PATH, expected_result));
    std::string curdir_a = AppSecInc::File::GetCurrentDirectoryA();
    std::wstring curdir_w = AppSecInc::File::GetCurrentDirectoryW();
    std::wcout << std::endl << "Unicode: " << curdir_w;
    std::cout << std::endl << "ANSI: " << curdir_a;
    CPPUNIT_ASSERT(curdir_w.length() > 0);
    CPPUNIT_ASSERT(curdir_w.length() == strlen(expected_result));
    CPPUNIT_ASSERT(curdir_w.length() == curdir_a.length());
    CPPUNIT_ASSERT(strcmp(curdir_a.c_str(), expected_result) == 0);
    CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(curdir_w));
}

void FileUnitTests::testGetFilesWithWildcard()
{
    std::list<std::wstring> files = AppSecInc::File::GetFiles(
        AppSecInc::File::GetModuleDirectoryW() + L"\\*.exe", AppSecInc::File::GET_FILES_ALL);

    bool found = false;
    for each (const std::wstring& file in files)
        found |= (file == AppSecInc::File::GetModuleFileNameW());

    CPPUNIT_ASSERT(found);
}

void FileUnitTests::testGetFilesWithNoWildcard()
{
    std::list<std::wstring> files = AppSecInc::File::GetFiles(
        AppSecInc::File::GetModuleFileNameW(), AppSecInc::File::GET_FILES_FILES);

	CPPUNIT_ASSERT(files.size() == 1);
	CPPUNIT_ASSERT(* files.begin() == AppSecInc::File::GetModuleFileNameW());
}

void FileUnitTests::testGetFilesWithInvalidWildcard()
{
	LPCWSTR file_wildcards[] = 
	{
		{ L"x:\\temp\\*\\*.txt" },
		{ L"x:\\temp\\?\\*.txt" },
		{ L"x:\\temp\\?*\\*.txt" },
		{ L"x:\\temp\\*?\\*.txt" },
		{ L"?*\\no wildcard here" },
	};

	for (int i = 0; i < ARRAYSIZE(file_wildcards); i++)
	{
		try 
		{ 
			AppSecInc::File::GetFiles(L"x:\\temp\\*\\*.txt", AppSecInc::File::GET_FILES_FILES); 
			throw "expected std::exception";
		} 
		catch(std::exception&) 
		{ 
			// expected
		}
	}
}


void FileUnitTests::testGetParentDirectory()
{
    struct TestData
    {
        LPCWSTR path;
        LPCWSTR expected_parent_path;
    };

    TestData testdata[] = 
    {
		{ L"", L"" },
		{ L"c:", L"c:\\" },
		{ L"c:\\", L"c:\\" },
		{ L"c:\\windows", L"c:\\" },
		{ L"c:\\foo\\bar", L"c:\\foo\\" },
		{ L"c:\\foo\\bar\\", L"c:\\foo\\" },
		{ L"e:\\foo\\bar", L"e:\\foo\\" },
		{ L"e:\\foo\\bar\\", L"e:\\foo\\" },
		{ L"e:\\foo foo\\bar bar", L"e:\\foo foo\\" },
		{ L"x:\\foo bar\\foo bar\\", L"x:\\foo bar\\" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wstring parent_path = AppSecInc::File::GetParentDirectory(testdata[i].path);
		std::wcout << std::endl << testdata[i].path << L" => " << parent_path;
        CPPUNIT_ASSERT(testdata[i].expected_parent_path == parent_path);
    }
}

void FileUnitTests::testGetSpecialFolderPath()
{
	int csidls[] = 
	{
		CSIDL_APPDATA,
		CSIDL_COMMON_APPDATA, 
		CSIDL_LOCAL_APPDATA
	};

	for (int i = 0; i < ARRAYSIZE(csidls); i++)
	{
		std::wstring path_current = AppSecInc::File::GetSpecialFolderPath(csidls[i]);
		std::wcout << std::endl << " " << csidls[i] << L" => " << path_current;
		CPPUNIT_ASSERT(path_current.length() > 0);
	}
}