#pragma once

namespace AppSecInc 
{
    namespace LSA
    {
        //! A process 
        class Process
        {
        private:
            HANDLE m_h;
        public:
            Process();
            virtual ~Process();
            //! open a process handle
            void Open(DWORD processid, DWORD access = PROCESS_ALL_ACCESS, BOOL inherit = FALSE);
            //! open a process by name
            void Open(const std::wstring& name, DWORD access = PROCESS_ALL_ACCESS, BOOL inherit = FALSE);
            //! close a process handle
            void Close();
            //! returns true if process handle is open
            bool IsOpen() const { return m_h != NULL; }
            //! returns the process handle
            HANDLE GetHandle() const { return m_h; }
        };
    }
}

