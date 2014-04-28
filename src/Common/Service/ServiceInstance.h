#pragma once

#define SERVICE_CONTROL_START 0

namespace AppSecInc 
{
    namespace Service 
    {
        //! a service instance
        class ServiceInstance
        {
        private:
            SC_HANDLE m_h;
        public:
            ServiceInstance();
            virtual ~ServiceInstance();
            //! open the service instance object
            void Open(const ServiceManager& scm, const std::wstring& name, DWORD access = SERVICE_ALL_ACCESS);
			//! create a new service
			void Create(const ServiceManager& scm, const ServiceCreateInfo& info);
			//! delete the service
			void Delete();
            //! close a previously opened service object
            void Close();
            //! returns true if service is already open
            bool IsOpen() const { return m_h != NULL; }
            //! return the service handle
            SC_HANDLE GetHandle() const { return m_h; }
            //! return process information
            void GetServiceProcessStatus(LPSERVICE_STATUS_PROCESS) const;
            //! control a service
            void Control(DWORD control);
            //! stop a service
            void Stop();
            //! start a service
            void Start();
            //! restart a service
            void Restart();
            //! pause a service
            void Pause();
            //! continue (resume) a service
            void Continue();
            //! return the service state
            DWORD GetServiceState() const;
            //! return string presentation of the service state
            std::wstring GetServiceStateString();
            //! returns true if the service is started
            bool IsStarted() const { return (GetServiceState() == SERVICE_RUNNING); }
            //! returns true if the service is stopped
            bool IsStopped() const { return (GetServiceState() == SERVICE_STOPPED); }
            //! returns true if the service is paused
            bool IsPaused() const { return (GetServiceState() == SERVICE_PAUSED); }
            //! wait for a transition to complete while the service is pausing, starting, stopping, etc.
            // \param sleep number of milliseconds to sleep between checks
            // \param timeout timeout to wait
            // \return true if operation successful, false on timeout
            bool Wait(DWORD timeout = INFINITE) const;
			//! get service configuration
			ServiceConfig GetConfig() const;
			//! get service description
			std::wstring GetDescription() const;
        };
    }
}

