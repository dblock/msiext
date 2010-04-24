#include "StdAfxUnitTests.h"
#include "Win32ImplUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Win32::Win32ImplUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Win32;

void Win32ImplUnitTests::Test_Win32_CopyMoveFile()
{
    typedef UINT (__stdcall * LPFWin32)(MSIHANDLE h);

    typedef struct
    {
        LPCWSTR func;
        bool source_exists_after;
        bool target_exists_after;
    } TestData;

    TestData testdata[] = 
    {
        { L"Win32_CopyFile", true, true },
        { L"Win32_MoveFile", false, true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
	    AppSecInc::Msi::MsiShim hInstall;
        MsiInstall msiInstall(hInstall);
        std::wstring dir = AppSecInc::File::GetModuleDirectoryW();
        std::wstring filename1 = AppSecInc::Com::GenerateGUIDStringW();
        filename1.insert(0, L"\\");
        filename1.insert(0, dir);
        std::wstring filename2 = AppSecInc::Com::GenerateGUIDStringW();
        std::wcout << std::endl << i << L": " << filename1 << L" => " << filename2;
        filename2.insert(0, L"\\");
        filename2.insert(0, dir);
		std::wofstream file1(filename1.c_str());
        file1 << filename1;
        file1.close();
        // source always exists first
        CPPUNIT_ASSERT(AppSecInc::File::FileExists(filename1));
        // target never exists first
        CPPUNIT_ASSERT(! AppSecInc::File::FileExists(filename2));
        // call the function
        msiInstall.SetProperty(L"WIN32_SOURCE_FILENAME", filename1);
        msiInstall.SetProperty(L"WIN32_TARGET_FILENAME", filename2);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", testdata[i].func));
        CPPUNIT_ASSERT(testdata[i].source_exists_after == AppSecInc::File::FileExists(filename1));
        CPPUNIT_ASSERT(testdata[i].target_exists_after == AppSecInc::File::FileExists(filename2));
        // delete temp files
		if (testdata[i].source_exists_after) AppSecInc::File::FileDelete(filename1);
        if (testdata[i].target_exists_after) AppSecInc::File::FileDelete(filename2);
    }
}

void Win32ImplUnitTests::Test_Win32_DeleteFile()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    std::wstring dir = AppSecInc::File::GetModuleDirectoryW();
    std::wstring filename = AppSecInc::Com::GenerateGUIDStringW();
    filename.insert(0, L"\\");
    filename.insert(0, dir);
	std::wofstream file1(filename.c_str());
    file1 << filename;
    file1.close();
    // source always exists first
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(filename));
    msiInstall.SetProperty(L"WIN32_FILENAME", filename);
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_DeleteFile"));
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(filename));
}

void Win32ImplUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"SystemTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing SystemTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_CopyFile"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_CopyFiles_Deferred"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_CopyFiles_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_MoveFiles_Deferred"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_MoveFiles_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_DeleteFiles_Deferred"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_DeleteFiles_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_MoveFile"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_DeleteFile"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_GetFileSize"));
    CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_Execute_Immediate"));
    CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_Execute_Deferred"));
    CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_Execute_Rollback"));
    CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_CreateDirectory"));
    CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_DeleteDirectory"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_GetParentDirectory"));
    CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_FileExists"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_ReadFile"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_WriteFile"));
	::FreeLibrary(h);
}

void Win32ImplUnitTests::Test_Win32_CopyFileOverwrite()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    std::wstring dir = AppSecInc::File::GetModuleDirectoryW();
    std::wstring filename1 = AppSecInc::Com::GenerateGUIDStringW();
    filename1.insert(0, L"\\");
    filename1.insert(0, dir);
    std::wstring filename2 = AppSecInc::Com::GenerateGUIDStringW();
	std::wcout << std::endl << filename1 << L" => " << filename2;
    filename2.insert(0, L"\\");
    filename2.insert(0, dir);
	std::wofstream file1(filename1.c_str());
    file1 << filename1;
    file1.close();
    // source always exists first
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(filename1));
    // target never exists first
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(filename2));
    msiInstall.SetProperty(L"WIN32_SOURCE_FILENAME", filename1);
    msiInstall.SetProperty(L"WIN32_TARGET_FILENAME", filename2);

    // 1: copy without overwrite, first call succeeds, second fails
    msiInstall.SetProperty(L"WIN32_TARGET_OVERWRITE", L"no");
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CopyFile"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CopyFile"));

    //! 2: copy with overwirte, \todo make sure the file has changed
    msiInstall.SetProperty(L"WIN32_TARGET_OVERWRITE", L"yes");
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CopyFile"));

    // 3: copy with error
    msiInstall.SetProperty(L"WIN32_TARGET_OVERWRITE", L"error");
    CPPUNIT_ASSERT(ERROR_SUCCESS != hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CopyFile"));

    // delete temp files
    AppSecInc::File::FileDelete(filename1);
    AppSecInc::File::FileDelete(filename2);
}

void Win32ImplUnitTests::Test_Win32_CopyFiles()
{
    AppSecInc::Msi::MsiShim hInstall;
    std::wstring testdata_directory = AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests";
    hInstall.Import(testdata_directory, L"Win32_CopyFiles.idt");
    hInstall.Import(testdata_directory, L"Binary.idt");
    hInstall.Import(testdata_directory, L"CustomAction.idt");

    MsiInstall msiInstall(hInstall);
    std::wstring install_location = AppSecInc::File::GetTemporaryDirectoryW();
    std::wstring source_location = AppSecInc::File::GetModuleDirectoryW() + L"\\";

    std::wstring copy_always_file = install_location + L"CopyAlways.wxs";
    std::wstring copy_conditional_file = install_location + L"CopyConditional.wxs";

    msiInstall.SetProperty(L"INSTALLLOCATION", install_location);
    msiInstall.SetProperty(L"SOURCELOCATION", source_location);

    // delete temporary files from previous runs
    ::DeleteFileW(copy_always_file.c_str());
    ::DeleteFileW(copy_conditional_file.c_str());

    // execute the immediate CA that processes the Win32_CopyFiles table and sets Win32_CopyFiles_Deferred property
    {
        hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CopyFiles_Immediate");
        std::wstring win32_copyfiles_deferred = msiInstall.GetProperty(L"Win32_CopyFiles_Deferred_Install");
        AppSecInc::Xml::XmlDocument win32_copyfiles_deferred_xml;
        win32_copyfiles_deferred_xml.LoadXml(win32_copyfiles_deferred);
        // there're 3 files in the list
        CPPUNIT_ASSERT(5 == win32_copyfiles_deferred_xml.SelectNodes(L"//Row")->length);
		// two are copied, one isn't copied because of a condition
		CPPUNIT_ASSERT(4 == win32_copyfiles_deferred_xml.SelectNodes(L"//Data[@Column='Attributes'][text() = '1']")->length);
		CPPUNIT_ASSERT(1 == win32_copyfiles_deferred_xml.SelectNodes(L"//Data[@Column='Attributes'][text() = '17']")->length);
        CPPUNIT_ASSERT(4 == win32_copyfiles_deferred_xml.SelectNodes(L"//Row[@copy='true']")->length);
        CPPUNIT_ASSERT(1 == win32_copyfiles_deferred_xml.SelectNodes(L"//Row[@copy='false']")->length);
        // there's 1 node with conditional text
        CPPUNIT_ASSERT(1 == win32_copyfiles_deferred_xml.SelectNodes(L"//Data[@Column='Condition']/text()")->length);
    }

    // run the deferred action
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"Win32_CopyFiles_Deferred_Install"));
    hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CopyFiles_Deferred");
    // we should have the always file and not the conditional file
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(copy_always_file));
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(copy_conditional_file));

    // check copy of *.idt from test data directory
    std::wstring copydirectory_files_path = install_location + L"CopyDirectory";
    std::list<std::wstring> copydirectory_files = AppSecInc::File::GetFiles(copydirectory_files_path, L"*.*");
    std::list<std::wstring> testdatadirectory_files = AppSecInc::File::GetFiles(testdata_directory, L"*.idt");
    std::wcout << std::endl << copydirectory_files_path << L": " << copydirectory_files.size() << L" file(s)";
    CPPUNIT_ASSERT(copydirectory_files.size() == testdatadirectory_files.size());

    // check recursive copy of *.* from test data directory
    std::wstring copydirectoryrecursive_files_path = install_location + L"CopyDirectoryRecursive";
    std::list<std::wstring> copydirectoryrecursive_files = AppSecInc::File::GetFiles(copydirectoryrecursive_files_path, L"*.*", AppSecInc::File::GET_FILES_ALL);
    std::list<std::wstring> testdatadirectoryrecursive_files = AppSecInc::File::GetFiles(testdata_directory, L"*.*", AppSecInc::File::GET_FILES_ALL);
    std::wcout << std::endl << copydirectoryrecursive_files_path << L": " << copydirectoryrecursive_files.size() << L" file(s)";
    CPPUNIT_ASSERT(copydirectoryrecursive_files.size() == testdatadirectoryrecursive_files.size());

    // set the condition to true, reevaluate
    msiInstall.SetProperty(L"COPY_CONDITIONAL", L"1");

    {
        hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CopyFiles_Immediate");
        AppSecInc::Xml::XmlDocument win32_copyfiles_deferred_xml;
        win32_copyfiles_deferred_xml.LoadXml(msiInstall.GetProperty(L"Win32_CopyFiles_Deferred_Install"));
    } 

    // run the deferred action
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"Win32_CopyFiles_Deferred_Install"));
    hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CopyFiles_Deferred");
    // we should have both the conditional and the always file
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(copy_always_file));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(copy_conditional_file));

    // delete temporary files from current run
    AppSecInc::File::FileDelete(copy_always_file);
    AppSecInc::File::FileDelete(copy_conditional_file);
    // delete files x-copied
    AppSecInc::File::DirectoryDelete(copydirectory_files_path);
    AppSecInc::File::DirectoryDelete(copydirectoryrecursive_files_path);
}

void Win32ImplUnitTests::Test_Win32_MoveFiles()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"Win32_MoveFiles.idt");
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"Binary.idt");
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"CustomAction.idt");

    MsiInstall msiInstall(hInstall);
    std::wstring install_location = AppSecInc::File::GetTemporaryDirectoryW();
    std::wstring source_location = AppSecInc::File::GetModuleDirectoryW() + L"\\";

    std::wstring move_always_source_file = install_location + L"MoveAlwaysSource.tmp";
    std::wstring move_conditional_source_file = install_location + L"MoveConditionalSource.tmp";
    AppSecInc::File::FileCreate(move_always_source_file);
    AppSecInc::File::FileCreate(move_conditional_source_file);

    std::wstring move_always_file = install_location + L"MoveAlways.wxs";
    std::wstring move_conditional_file = install_location + L"MoveConditional.wxs";

    std::wstring delete_file_1 = install_location + L"DeleteFile1.tmp";
    std::wstring delete_file_2 = install_location + L"DeleteFile2.tmp";

    AppSecInc::File::FileCreate(delete_file_1);
    AppSecInc::File::FileCreate(delete_file_2);

    // create subdirectory structure
    std::wstring moveall_directory = install_location + L"MoveAllDirectory";
    AppSecInc::File::DirectoryCreate(moveall_directory);
    for (int i = 0; i < 5; i++)
    {
        AppSecInc::File::FileCreate(
            moveall_directory + L"\\MoveFile" + AppSecInc::StringUtils::toWString(i) + L".del");
    }

    std::wstring moveall_subdirectory = moveall_directory + L"\\SubDirectory";
    AppSecInc::File::DirectoryCreate(moveall_subdirectory);
    for (int i = 0; i < 5; i++)
    {
        AppSecInc::File::FileCreate(
            moveall_subdirectory + L"\\MoveFile" + AppSecInc::StringUtils::toWString(i) + L".tmp");
    }

    std::wstring moveempty_directory = install_location + L"MoveEmptyDirectory";
    AppSecInc::File::DirectoryCreate(moveempty_directory);

    msiInstall.SetProperty(L"INSTALLLOCATION", install_location);
    msiInstall.SetProperty(L"SOURCELOCATION", source_location);

    // delete temporary files from previous runs
    ::DeleteFileW(move_always_file.c_str());
    ::DeleteFileW(move_conditional_file.c_str());

    // execute the immediate CA that processes the Win32_MoveFiles table and sets Win32_MoveFiles_Deferred property
    {
        hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_MoveFiles_Immediate");
        std::wstring win32_movefiles_deferred = msiInstall.GetProperty(L"Win32_MoveFiles_Deferred_Install");
        AppSecInc::Xml::XmlDocument win32_movefiles_deferred_xml;
        win32_movefiles_deferred_xml.LoadXml(win32_movefiles_deferred);
        // there're 5 directories in the list
        CPPUNIT_ASSERT(6 == win32_movefiles_deferred_xml.SelectNodes(L"//Row")->length);
		// four are copied, one isn't copied because of a condition
		CPPUNIT_ASSERT(2 == win32_movefiles_deferred_xml.SelectNodes(L"//Data[@Column='Attributes'][text() = '1']")->length);
        CPPUNIT_ASSERT(5 == win32_movefiles_deferred_xml.SelectNodes(L"//Row[@move='true']")->length);
        CPPUNIT_ASSERT(1 == win32_movefiles_deferred_xml.SelectNodes(L"//Row[@move='false']")->length);
        // there're 4 nodes with conditional text
        CPPUNIT_ASSERT(5 == win32_movefiles_deferred_xml.SelectNodes(L"//Data[@Column='Condition']/text()")->length);
    }

    // run the deferred action
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"Win32_MoveFiles_Deferred_Install"));
    hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_MoveFiles_Deferred");
	// the source file that has been moved must have been deleted
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(move_always_source_file));
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(move_conditional_source_file));
    // we should have the always file and not the conditional file
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(move_always_file));
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(move_conditional_file));
	// the empty directory has moved
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(moveempty_directory));
	// since it was empty, the target has not been created
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(install_location + L"MoveEmptyDirectoryMoved"));

	// re-create the file moved
    AppSecInc::File::FileCreate(move_always_source_file);
    // set the condition to true, reevaluate
    msiInstall.SetProperty(L"MOVE_CONDITIONAL", L"1");

    {
        hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_MoveFiles_Immediate");
        AppSecInc::Xml::XmlDocument win32_movefiles_deferred_xml;
        win32_movefiles_deferred_xml.LoadXml(msiInstall.GetProperty(L"Win32_MoveFiles_Deferred_Install"));
    } 

    // run the deferred action
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"Win32_MoveFiles_Deferred_Install"));
    hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_MoveFiles_Deferred");
	// both source files that has been moved must have been deleted
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(move_always_source_file));
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(move_conditional_source_file));
    // we should have both the conditional and the always file
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(move_always_file));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(move_conditional_file));
	// moved directories
	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(moveall_directory + L"Moved"));
	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(moveall_directory + L"SubMoved"));

    // delete temporary files from current run
    AppSecInc::File::FileDelete(move_always_file);
    AppSecInc::File::FileDelete(move_conditional_file);
	// delete target moved directories
	AppSecInc::File::DirectoryDelete(moveall_directory + L"Moved");
	AppSecInc::File::DirectoryDelete(moveall_directory + L"SubMoved");
}

void Win32ImplUnitTests::Test_Win32_DeleteFiles()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"Win32_DeleteFiles.idt");

    MsiInstall msiInstall(hInstall);
    std::wstring install_location = AppSecInc::File::GetTemporaryDirectoryW();

    std::wstring delete_file_1 = install_location + L"DeleteFile1.tmp";
    std::wstring delete_file_2 = install_location + L"DeleteFile2.tmp";

    AppSecInc::File::FileCreate(delete_file_1);
    AppSecInc::File::FileCreate(delete_file_2);

    // create files that will be deleted by wildcard
    std::wstring deleteall_directory = install_location + L"DeleteAllDirectory";
    AppSecInc::File::DirectoryCreate(deleteall_directory);
    for (int i = 0; i < 5; i++)
    {
        AppSecInc::File::FileCreate(
            deleteall_directory + L"\\DeleteFile" + AppSecInc::StringUtils::toWString(i) + L".del");
    }
    // create files that are subdirectory of DeleteAllDirectory and that will be deleted by the second wildcard
    std::wstring deleteall_subdirectory = deleteall_directory + L"\\SubDirectory";
    AppSecInc::File::DirectoryCreate(deleteall_subdirectory);
    for (int i = 0; i < 5; i++)
    {
        AppSecInc::File::FileCreate(
            deleteall_subdirectory + L"\\DeleteFile" + AppSecInc::StringUtils::toWString(i) + L".tmp");
    }
    // we've created 10 files in two subdirectories
    std::list<std::wstring> deleteall_files = AppSecInc::File::GetFiles(deleteall_directory, L"*.*", AppSecInc::File::GET_FILES_FILES | AppSecInc::File::GET_FILES_RECURSIVE);
    CPPUNIT_ASSERT(deleteall_files.size() == 10);

    msiInstall.SetProperty(L"INSTALLLOCATION", install_location);

    // execute the immediate CA that processes the Win32_DeleteFiles table and sets Win32_DeleteFiles_Deferred property
    {
        hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_DeleteFiles_Immediate");
        std::wstring win32_deletefiles_deferred = msiInstall.GetProperty(L"Win32_DeleteFiles_Deferred_Install");
        AppSecInc::Xml::XmlDocument win32_deletefiles_deferred_xml;
        win32_deletefiles_deferred_xml.LoadXml(win32_deletefiles_deferred);
        // there're 2 files in the list
        CPPUNIT_ASSERT(4 == win32_deletefiles_deferred_xml.SelectNodes(L"//Row")->length);
		// one is copied (install), one isn't copied (uninstall)
        CPPUNIT_ASSERT(3 == win32_deletefiles_deferred_xml.SelectNodes(L"//Row[@delete='true']")->length);
        CPPUNIT_ASSERT(1 == win32_deletefiles_deferred_xml.SelectNodes(L"//Row[@recurse='true']")->length);
        CPPUNIT_ASSERT(1 == win32_deletefiles_deferred_xml.SelectNodes(L"//Row[@delete='false']")->length);
    }

    // run the deferred action
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"Win32_DeleteFiles_Deferred_Install"));
    hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_DeleteFiles_Deferred");
    // we should have the always file and not the conditional file
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(delete_file_1));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(delete_file_2));

    // check that the wildcard files have been deleted too
    CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(deleteall_directory));

    // delete temporary files from current run
    AppSecInc::File::FileDelete(delete_file_2);
}

void Win32ImplUnitTests::Test_Win32_Execute()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"Win32_Execute.idt");

    MsiInstall msiInstall(hInstall);
    std::wstring install_location = AppSecInc::File::GetTemporaryDirectoryW();
    std::wstring source_location = AppSecInc::File::GetModuleDirectoryW() + L"\\";

    std::wstring target_file = install_location + L"Win32_Execute_Copy.idt";
    std::wstring target_file_conditional = install_location + L"Win32_Execute_Conditional.idt";

    msiInstall.SetProperty(L"INSTALLLOCATION", install_location);
    msiInstall.SetProperty(L"SOURCELOCATION", source_location);
    
    // delete temporary files from previous runs
    ::DeleteFileW(target_file.c_str());
    ::DeleteFileW(target_file_conditional.c_str());

    // execute the immediate CA that processes the Win32_Execute table and sets Win32_Execute_Deferred property
    {
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_Execute_Immediate"));
        AppSecInc::Xml::XmlDocument win32_execute_deferred_xml;
        win32_execute_deferred_xml.LoadXml(msiInstall.GetProperty(L"Win32_Execute_Deferred"));
        // there're 5 execute statements in the list
        CPPUNIT_ASSERT(5 == win32_execute_deferred_xml.SelectNodes(L"//Row")->length);
        // there's 1 node with conditional text
        CPPUNIT_ASSERT(1 == win32_execute_deferred_xml.SelectNodes(L"//Data[@Column='Condition']/text()")->length);
        // there's 1 row that is going to be executed
        CPPUNIT_ASSERT(1 == win32_execute_deferred_xml.SelectNodes(L"//Row[@execute='true']")->length);
        CPPUNIT_ASSERT(4 == win32_execute_deferred_xml.SelectNodes(L"//Row[@execute='false']")->length);
    }

    // execute the deferred CA that copies files
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"Win32_Execute_Deferred"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_Execute_Deferred"));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(target_file));
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(target_file_conditional));
    ::DeleteFileW(target_file.c_str());
};

void Win32ImplUnitTests::Test_Win32_ConditionalExecute()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"Win32_Execute.idt");

    MsiInstall msiInstall(hInstall);
    std::wstring install_location = AppSecInc::File::GetTemporaryDirectoryW();
    std::wstring source_location = AppSecInc::File::GetModuleDirectoryW() + L"\\";

    std::wstring target_file = install_location + L"Win32_Execute_Copy.idt";
    std::wstring target_file_conditional = install_location + L"Win32_Execute_Conditional.idt";

    msiInstall.SetProperty(L"INSTALLLOCATION", install_location);
    msiInstall.SetProperty(L"SOURCELOCATION", source_location);

    // delete temporary files from previous runs
    ::DeleteFileW(target_file.c_str());
    ::DeleteFileW(target_file_conditional.c_str());

    // set the conditional copy to 1
    msiInstall.SetProperty(L"EXECUTE_CONDITIONAL", L"1");

    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_Execute_Immediate"));
    AppSecInc::Xml::XmlDocument win32_execute_deferred_xml;
    win32_execute_deferred_xml.LoadXml(msiInstall.GetProperty(L"Win32_Execute_Deferred"));
    // there're 5 execute statements in the list
    CPPUNIT_ASSERT(5 == win32_execute_deferred_xml.SelectNodes(L"//Row")->length);
    // there's 1 node with conditional text
    CPPUNIT_ASSERT(1 == win32_execute_deferred_xml.SelectNodes(L"//Data[@Column='Condition']/text()")->length);
    // there're 2 rows that are going to be executed
    CPPUNIT_ASSERT(2 == win32_execute_deferred_xml.SelectNodes(L"//Row[@execute='true']")->length);
    CPPUNIT_ASSERT(3 == win32_execute_deferred_xml.SelectNodes(L"//Row[@execute='false']")->length);

    // execute the deferred CA that copies files
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"Win32_Execute_Deferred"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_Execute_Deferred"));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(target_file));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(target_file_conditional));
    ::DeleteFileW(target_file.c_str());
    ::DeleteFileW(target_file_conditional.c_str());
};

void Win32ImplUnitTests::Test_Win32_ScheduledExecute()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"Win32_Execute.idt");

    MsiInstall msiInstall(hInstall);
    std::wstring install_location = AppSecInc::File::GetTemporaryDirectoryW();
    std::wstring source_location = AppSecInc::File::GetModuleDirectoryW() + L"\\";

    msiInstall.SetProperty(L"INSTALLLOCATION", install_location);
    msiInstall.SetProperty(L"SOURCELOCATION", source_location);

    std::wstring target_file = install_location + L"Win32_Execute_ScheduledCopy.idt";
    ::DeleteFileW(target_file.c_str());

    // execute the immediate CA that processes the Win32_Execute table and sets Win32_Execute_Deferred property
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_Execute_Immediate"));

    {
        // for the manually scheduled CA there should be 2 properties set to the execute xml, this one is for the scheduled copy
        AppSecInc::Xml::XmlDocument scheduledxml;
        scheduledxml.LoadXml(msiInstall.GetProperty(L"CopySystemToolsMsiScheduled_Copy"));
        // there's only 1 row
        CPPUNIT_ASSERT(1 == scheduledxml.SelectNodes(L"//Row")->length);
        // the one row is marked execute=true
        CPPUNIT_ASSERT(scheduledxml.SelectAttributeBoolValue(L"execute", scheduledxml.SelectNode(L"/Row")));
    }

    {
        // for the manually scheduled CA there should be 2 properties set to the execute xml, this one is for the scheduled delete
        AppSecInc::Xml::XmlDocument scheduledxml;
        scheduledxml.LoadXml(msiInstall.GetProperty(L"CopySystemToolsMsiScheduled_Delete"));
        // there's only 1 row
        CPPUNIT_ASSERT(1 == scheduledxml.SelectNodes(L"//Row")->length);
        // the one row is marked execute=false, this is an install sequence
        CPPUNIT_ASSERT(! scheduledxml.SelectAttributeBoolValue(L"execute", scheduledxml.SelectNode(L"/Row")));
    }

    // execute the deferred CA
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"CopySystemToolsMsiScheduled_Copy"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_Execute_Deferred"));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(target_file));
    AppSecInc::File::FileDelete(target_file);
};

void Win32ImplUnitTests::Test_Win32_CreateDirectory()
{
    AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);
	std::wstring root = AppSecInc::File::GetTemporaryDirectoryW();
	// check that we can create one level
	std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring path1 = root + guid;
	std::wcout << std::endl << L"Creating: " << path1;
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(path1));
	msiInstall.SetProperty(L"WIN32_PATH", path1);	
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CreateDirectory"));
	std::wstring path1_created = msiInstall.GetProperty(L"WIN32_PATH_CREATED");
	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(path1));
	CPPUNIT_ASSERT(path1 == path1_created);
	// check that we can create two more levels
	std::wstring path2 = path1 + L"\\" + guid;
	std::wstring path3 = path2 + L"\\" + guid;
	std::wcout << std::endl << L"Creating: " << path3;
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(path3));
	msiInstall.SetProperty(L"WIN32_PATH", path3);	
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_CreateDirectory"));
	std::wstring path3_created = msiInstall.GetProperty(L"WIN32_PATH_CREATED");
	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(path2));
	// the first created directory is path2
	CPPUNIT_ASSERT(path2 == path3_created);
	// delete the final result
	AppSecInc::File::DirectoryDelete(path1);
}

void Win32ImplUnitTests::Test_Win32_DeleteDirectory()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);
	std::wstring root = AppSecInc::File::GetTemporaryDirectoryW();
	std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring newpath = AppSecInc::File::DirectoryCreate(root + guid + L"\\" + guid + L"\\" + guid);
	std::wcout << std::endl << "Path: " << newpath;
	std::wstring filename = newpath + L"\\" + guid + L".tmp";
	AppSecInc::File::FileCreate(filename);
	msiInstall.SetProperty(L"WIN32_PATH", newpath);	
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_DeleteDirectory"));
	CPPUNIT_ASSERT(! AppSecInc::File::FileExists(filename));
	CPPUNIT_ASSERT(! AppSecInc::File::DirectoryExists(newpath));
}

void Win32ImplUnitTests::Test_Win32_GetFileSize()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);
	std::wstring root = AppSecInc::File::GetTemporaryDirectoryW();
	std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
    std::wstring filename = AppSecInc::File::DirectoryCombine(root, guid);
    // empty file
	AppSecInc::File::FileCreate(filename);
	msiInstall.SetProperty(L"WIN32_FILENAME", filename);	
	msiInstall.SetProperty(L"WIN32_FILESIZE_FORMAT", L"AUTO");
	msiInstall.SetProperty(L"WIN32_FILESIZE_PRECISION", L"2");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_GetFileSize"));
    CPPUNIT_ASSERT(msiInstall.GetProperty(L"WIN32_FILESIZE") == L"0");
    CPPUNIT_ASSERT(msiInstall.GetProperty(L"WIN32_FILESIZE_BYTES") == L"0");
    CPPUNIT_ASSERT(msiInstall.GetProperty(L"WIN32_FILESIZE_FORMATTED") == L"0 bytes");
    // write a kilobyte of data
    std::vector<char> data;
    data.insert(data.end(), 1024, 0);
    AppSecInc::File::FileWrite(filename, data);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_GetFileSize"));
    CPPUNIT_ASSERT(msiInstall.GetProperty(L"WIN32_FILESIZE") == L"1.00");
    CPPUNIT_ASSERT(msiInstall.GetProperty(L"WIN32_FILESIZE_BYTES") == L"1024");
    CPPUNIT_ASSERT(msiInstall.GetProperty(L"WIN32_FILESIZE_FORMATTED") == L"1.00 KB");
    AppSecInc::File::FileDelete(filename);
}


void Win32ImplUnitTests::Test_Win32_FileExists()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    std::wstring root = AppSecInc::File::GetTemporaryDirectoryW();
    std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
    std::wstring filename = AppSecInc::File::DirectoryCombine(root, guid);
    AppSecInc::File::FileCreate(filename);

    msiInstall.SetProperty(L"WIN32_FILENAME", filename);	
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_FileExists"));
    CPPUNIT_ASSERT(msiInstall.GetProperty(L"WIN32_FILE_EXISTS") == L"1");
    AppSecInc::File::FileDelete(filename);
    
    // non-existing file (now)
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_FileExists"));
    CPPUNIT_ASSERT(msiInstall.GetProperty(L"WIN32_FILE_EXISTS") == L"0");
}

void Win32ImplUnitTests::Test_Win32_GetParentDirectory()
{
    AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

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
		msiInstall.SetProperty(L"WIN32_DIRECTORY", testdata[i].path);	
		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_GetParentDirectory"));
        CPPUNIT_ASSERT(testdata[i].expected_parent_path == msiInstall.GetProperty(L"WIN32_PARENT_DIRECTORY"));
    }
}

void Win32ImplUnitTests::Test_Win32_ReadFile()
{
    AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);
	std::wstring tmpfile = AppSecInc::File::GetTemporaryFileNameW();
	std::wcout << std::endl << L"Temporary filename: " << tmpfile;
	CPPUNIT_ASSERT(AppSecInc::File::FileExists(tmpfile));
	msiInstall.SetProperty(L"WIN32_FILE_NAME", tmpfile);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_ReadFile"));
	// temporary files are created empty
	CPPUNIT_ASSERT(msiInstall.GetProperty("WIN32_FILE_DATA").length() == 0);
    // ansi data
    std::string guid = AppSecInc::Com::GenerateGUIDStringA();
    std::ofstream f(AppSecInc::StringUtils::wc2mb(tmpfile).c_str());
    f << guid.c_str();
    f.close();
    // read as byte data
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_ReadFile"));
	CPPUNIT_ASSERT(msiInstall.GetProperty("WIN32_FILE_DATA").length() == AppSecInc::File::GetFileSize(tmpfile));
    // delete temp file
    AppSecInc::File::FileDelete(tmpfile);
}

void Win32ImplUnitTests::Test_Win32_WriteFile()
{
    AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);
    std::wstring tmpfile = AppSecInc::File::DirectoryCombine(
        AppSecInc::File::GetTemporaryDirectoryW(), AppSecInc::Com::GenerateGUIDStringW());
	std::wcout << std::endl << L"Temporary filename: " << tmpfile;
    // empty data
	msiInstall.SetProperty(L"WIN32_FILE_NAME", tmpfile);
	msiInstall.SetProperty(L"WIN32_FILE_DATA", L"");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_WriteFile"));
    std::vector<char> read_data;
    AppSecInc::File::ReadToEnd(tmpfile, read_data);
    CPPUNIT_ASSERT(read_data.size() == 0); // temporary files are created empty
    // some data
    std::string write_guid = AppSecInc::Com::GenerateGUIDStringA();
    std::cout << std::endl << "Write GUID: " << write_guid;
	msiInstall.SetProperty("WIN32_FILE_DATA", write_guid);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_WriteFile"));
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
