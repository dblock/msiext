#pragma once

namespace AppSecInc 
{
    namespace Service 
    {
		//! service implementation
		class ServiceImpl
		{
		private:
			SERVICE_STATUS_HANDLE _status;
			HANDLE _thread;
			HANDLE _stop;
			static ServiceImpl * _instance;
			static DWORD ServiceExecutionThread(LPVOID param);
			static void ServiceCtrlHandler(DWORD controlCode);
			static void UpdateSCMStatus(
				DWORD dwCurrentState, 
				DWORD dwWin32ExitCode,
				DWORD dwServiceSpecificExitCode,
				DWORD dwCheckPoint, 
				DWORD dwWaitHint);
			static void ServiceMain();
			static void StartThread();
		protected:
			BOOL _running;
			BOOL _paused;
			std::wstring _name;
			virtual void Run() = 0;
		public:
			ServiceImpl(const std::wstring& name);
			virtual ~ServiceImpl();
			void Stop();
			void Start();
			void Wait();
		};
	}
}
