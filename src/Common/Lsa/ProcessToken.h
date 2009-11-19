#pragma once

namespace AppSecInc 
{
    namespace LSA
    {
        //! A process token
        class ProcessToken
        {
        private:
            HANDLE m_h;
        public:
            ProcessToken();
            virtual ~ProcessToken();
            //! open a process token handle
            void Open(HANDLE hProc, DWORD access = TOKEN_ALL_ACCESS);
            //! close a process token handle
            void Close();
            //! returns true if process token handle is open
            bool IsOpen() const { return m_h != NULL; }
            //! returns the process handle
            HANDLE GetHandle() const { return m_h; }
            //! adjust a process token privilege
            void AdjustPrivilege(const std::wstring& privilege, DWORD type = SE_PRIVILEGE_ENABLED);
        };
    }
}

