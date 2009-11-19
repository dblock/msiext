#include "StdAfxUnitTests.h"
#include "MsiBinaryUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::MsiTools::MsiBinaryUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::MsiTools;

void MsiBinaryUnitTests::Test_BinaryWrite()
{
	AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_MsiToolsUnitTests", L"Binary.idt");

    MsiInstall msiInstall(hInstall);

    std::wstring binpath = AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_MsiToolsUnitTests\\Binary";
    std::list<std::wstring> binary_files = AppSecInc::File::GetFiles(binpath);
    for each (const std::wstring& binary_file in binary_files)
    {
        std::wstring binary_file_path = AppSecInc::File::DirectoryCombine(binpath, binary_file);
        long filesize = AppSecInc::File::GetFileSize(binary_file_path);
        std::vector<std::wstring> tokens;
        StringUtils::tokenize(AppSecInc::File::GetFileNameW(binary_file), tokens, L".");
        std::wstring binary_name = tokens[0];

        msiInstall.SetProperty(L"BINARYWRITE_PROPERTYNAME", binary_name); 
        std::wstring target_binary_file_path = AppSecInc::File::GetTemporaryFileNameW();
        msiInstall.SetProperty(L"BINARYWRITE_TARGETFILENAME", target_binary_file_path); 

        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"MsiTools.dll", L"BinaryWrite"));

        long target_filesize = AppSecInc::File::GetFileSize(target_binary_file_path);
        std::wcout << std::endl << binary_file << L" (" << binary_name << L") => " 
            << target_filesize << L" byte(s), expecting " << filesize << " byte(s)";
        CPPUNIT_ASSERT(filesize == target_filesize);
        AppSecInc::File::FileDelete(target_binary_file_path);
    }
}
