#pragma once

namespace AppSecInc 
{
    namespace LSA 
    {
        //! LSA policy object
        class LSAPolicy
        {
        private:
            LSA_HANDLE m_hPolicy;
        public:
            LSAPolicy();
            virtual ~LSAPolicy();
            //! open the LSA policy object on a computer
            void Open(const std::wstring& computer_name, 
                LSA_OBJECT_ATTRIBUTES attr, 
                DWORD access = POLICY_ALL_ACCESS);
            //! open the LSA policy object on the local computer with all access
            void Open(DWORD access = POLICY_ALL_ACCESS);
            //! close a previously opened LSA policy object
            void Close();
            //! returns true if policy is already open
            bool IsOpen() const { return m_hPolicy != NULL; }
            //! return the policy handle
            LSA_HANDLE GetHandle() const { return m_hPolicy; }
        };
    }
}

