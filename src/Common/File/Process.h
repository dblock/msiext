#pragma once

namespace AppSecInc
{
    namespace File
    {
	    //! Win32 process support functions
	    class Process
	    {
        private:
            std::string _buffer;
		    STARTUPINFO _si;
		    PROCESS_INFORMATION _pi;
            HANDLE _stdout_read;
            HANDLE _stdout_write;
        public:
            Process();
            virtual ~Process();
            //! create a process
            void Create(const std::wstring& commandline, const std::wstring directory = L"");
            //! create a process with redirected pipes
            void CreateWithRedirectedOutput(const std::wstring& commandline, const std::wstring directory = L"");
            //! wait for the process to complete
            void Wait(DWORD dwMilliseconds = INFINITE);
            //! return process exit code
            DWORD GetExitCode();
            //! read a line from an executing process' output
            std::string ReadLine(bool& finished);
            //! execute a process, wait for it to complete and return its exit code
            static DWORD Execute(const std::wstring commandline, const std::wstring& directory = L"");
	    };
    }
}