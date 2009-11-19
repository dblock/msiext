#pragma once

namespace AppSecInc 
{
    namespace Service 
    {
        //! Service manager
        class ServiceManager
        {
        private:
            SC_HANDLE m_h;
        public:
            ServiceManager();
            virtual ~ServiceManager();
            //! open the Service manager object on a computer
            void Open(const std::wstring& computer_name, const std::wstring& database_name, DWORD access = SC_MANAGER_ALL_ACCESS);
            //! open the Service manager on the local computer with all access
            void Open(DWORD access = SC_MANAGER_ALL_ACCESS);
            //! close a previously opened service manager object
            void Close();
            //! returns true if service manager is open
            bool IsOpen() const { return m_h != NULL; }
            //! return the policy handle
            SC_HANDLE GetHandle() const { return m_h; }
			//! return a list of services
			std::list<ServiceStatusProcess> GetServices(
				DWORD service_type = SERVICE_WIN32, 
				DWORD service_state = SERVICE_STATE_ALL,
				LPCTSTR service_group_name = NULL) const;
        };
    }
}

