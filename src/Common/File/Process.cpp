#include "StdAfx.h"
#include "Process.h"

using namespace AppSecInc::File;

Process::Process()
    : _stdout_read(NULL)
    , _stdout_write(NULL)
{
    ZeroMemory(& _si, sizeof(_si));
    ZeroMemory(& _pi, sizeof(_pi));
}

Process::~Process()
{
    if (_pi.hProcess != NULL) ::CloseHandle(_pi.hProcess);
    if (_pi.hThread != NULL) ::CloseHandle(_pi.hThread);
    if (_stdout_read != NULL) ::CloseHandle(_stdout_read);
    if (_stdout_write != NULL) ::CloseHandle(_stdout_write);
}

void Process::Create(const std::wstring& commandline, const std::wstring directory)
{
    CHECK_BOOL(_pi.hProcess == NULL,
        L"Process already created");

    CHECK_BOOL(_pi.hThread == NULL,
        L"Thread already created");

    _si.cb = sizeof(_si);
    _si.dwFlags = STARTF_USESTDHANDLES;
    _si.wShowWindow = SW_HIDE; // hidden console window
    _si.hStdInput = NULL;
    _si.hStdOutput = _stdout_write;
    _si.hStdError = _stdout_write;

    CHECK_WIN32_BOOL(::CreateProcessW(NULL, const_cast<LPWSTR>(commandline.c_str()), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, 
        directory.empty() ? NULL : directory.c_str(), & _si, & _pi),
	    L"Error creating process with \"" << commandline << L"\"");
}

void Process::CreateWithRedirectedOutput(const std::wstring& commandline, const std::wstring directory)
{
    CHECK_BOOL(_stdout_write == NULL && _stdout_read == NULL,
        L"StdOut/StdErr is already redirected");

     // security attributes for an inheritable handle
     SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
     CHECK_WIN32_BOOL(::CreatePipe(& _stdout_read, & _stdout_write, & sa, 0),
         L"Error connecting stdout r/w");

     // ensure the read handle to the pipe for STDOUT is not inherited
     CHECK_WIN32_BOOL(::SetHandleInformation(_stdout_read, HANDLE_FLAG_INHERIT, 0),
         L"Error setting stdout read handle information");

     Create(commandline, directory);

     // force a broken pipe at the end of output
     ::CloseHandle(_stdout_write);
     _stdout_write = NULL;
}

void Process::Wait(DWORD dwMilliseconds)
{
    CHECK_WIN32_DWORD(::WaitForSingleObject(_pi.hProcess, dwMilliseconds ),
        L"Error waiting for process " << _pi.dwProcessId);
}

DWORD Process::GetExitCode()
{
    DWORD exitcode = 0;
    CHECK_WIN32_BOOL(::GetExitCodeProcess(_pi.hProcess, & exitcode),
	    L"Error in GetExitCodeProcess for process " << _pi.dwProcessId);
    return exitcode;
}

std::string Process::ReadLine(bool& finished)
{
    finished = false;

    CHECK_BOOL(_stdout_read != NULL,
        L"Invalid child handle");

    char buffer[128] = { 0 };
    DWORD dwRead = 0;

    do
    {
        if (::ReadFile(_stdout_read, buffer, sizeof(buffer), & dwRead, NULL))
        {
            if (0 >= dwRead)
                break;

            _buffer.append(buffer, dwRead);
        }

        // keep reading until we find a CR/LF
        int cr = _buffer.find_first_of("\r\n");
        if (cr != _buffer.npos)
        {
            std::string result = _buffer.substr(0, cr);
            // look for the other CR/LF character
            char lf = _buffer[cr] == '\n' ? '\r' : '\n';
            cr++; // pass the current CR/LF character
            while(cr != _buffer.npos && buffer[cr] == lf)
                cr++; // increment while the other CR/LF character
            if (cr == _buffer.npos)
                _buffer.clear();
            else 
                _buffer.erase(0, cr + 1); // erase all including the last read CR character
            return result;
        }
    } while(dwRead); // keep reading until there's an error

    DWORD dwError = ::GetLastError();
    // end of process output
    if (dwError == ERROR_BROKEN_PIPE)
    {
        finished = true;
        return _buffer;
    }

    CHECK_WIN32_DWORD(dwError,
        L"Error reading pipe");

    THROW(L"Error reading pipe");
}

DWORD Process::Execute(const std::wstring commandline, const std::wstring& directory)
{
    Process p;
    p.Create(commandline, directory);
    p.Wait();
    return p.GetExitCode();
}
