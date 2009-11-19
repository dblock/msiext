#include "StdAfxUnitTests.h"
#include "ProcessUnitTests.h"
#include "Process.h"
#include "File.h"

using namespace AppSecInc::UnitTests::File;

CPPUNIT_TEST_SUITE_REGISTRATION(ProcessUnitTests);

void ProcessUnitTests::testExecute()
{
    std::wstring source = AppSecInc::File::GetModuleFileNameW();
    std::wstring target = AppSecInc::File::DirectoryCombine(AppSecInc::File::GetModuleDirectoryW(), AppSecInc::Com::GenerateGUIDStringW());
    std::wostringstream cmd;
    cmd << L"cmd.exe /C copy \"" << source << L"\" \"" << target << L"\""; 
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(target));
    AppSecInc::File::Process::Execute(cmd.str());
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(target));
    AppSecInc::File::FileDelete(target);
}

void ProcessUnitTests::testExecuteWithOutput()
{
    std::wstringstream cmd;
    cmd << L"cmd.exe /C dir /b \"" << AppSecInc::File::GetModuleDirectoryW() << L"\"";
    AppSecInc::File::Process p;
    p.CreateWithRedirectedOutput(cmd.str());
    bool finished = false;
    bool found = false;
    std::string filename = AppSecInc::File::GetFileNameA(AppSecInc::File::GetModuleFileNameA());
    std::cout << std::endl << "Looking: " << filename;
    while (! finished)
    {
        std::string line = p.ReadLine(finished);
        if (line == filename) 
        {
            std::cout << " - match!";
            found = true;
        }
        std::cout << std::endl << line;
    }
    p.Wait();
    CPPUNIT_ASSERT(found);
}


void ProcessUnitTests::testExecuteWithOutputLines()
{
    struct TestData
    {
        LPCWSTR command;
        LPCSTR output;
        int lines;
    };

    TestData testdata[] =
    {
        { L"cmd.exe /C echo.", "\r\n", 2 }, // two lines, one is the output, the other one is a returned prompt
        { L"cmd.exe /C echo Hello World", "Hello World\r\n", 2 }, // two lines, one is Hello World, and a prompt carriage return
        { L"cmd.exe /C echo Line1 & echo Line2", "Line1 \r\nLine2\r\n", 3 }, // two lines, one is Hello World, and a prompt carriage return
        { 
            L"cmd.exe /C echo 0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789", 
                             "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789\r\n", 
            2 
        }, // bigger than 128 internal buffer of ReadLine inside the function
    };
    
    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        AppSecInc::File::Process p;
        p.CreateWithRedirectedOutput(testdata[i].command);
        std::list<std::string> lines;
        bool finished = false;
        while (! finished)
        {
            std::string line = p.ReadLine(finished);
            lines.push_back(line);
            if (! line.empty())
            {
                std::cout << std::endl << line;
            }
        }
        p.Wait();
        std::cout << std::endl << "Lines: " << lines.size();
        CPPUNIT_ASSERT(lines.size() == testdata[i].lines);
        CPPUNIT_ASSERT(AppSecInc::StringUtils::join(lines, "\r\n") == testdata[i].output);
    }
}