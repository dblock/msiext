#include "StdAfx.h"
#include "ServiceImpl.h"

using namespace AppSecInc::Service;

ServiceImpl * ServiceImpl::_instance = NULL;

ServiceImpl::ServiceImpl(const std::wstring& name)
	: _running(FALSE)
	, _paused(FALSE)
	, _status(NULL)
	, _thread(NULL)
	, _stop(NULL)
	, _name(name)
{

}

ServiceImpl::~ServiceImpl()
{

}

void ServiceImpl::Stop()
{
	CHECK_WIN32_BOOL(SetEvent(_stop),
		L"StopService");
}

DWORD ServiceImpl::ServiceExecutionThread(LPVOID param)
{
	try
	{
		_instance->_running = TRUE;
		_instance->Run();
	}
	catch(std::exception&)
	{
		return -1;
	}

	return 0;
}

void ServiceImpl::StartThread()
{
   DWORD id = 0;
   
   CHECK_WIN32_BOOL(NULL != (_instance->_thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE) ServiceExecutionThread, NULL, 0, & id)),
	   L"CreateThread");
}

void ServiceImpl::UpdateSCMStatus(DWORD dwCurrentState, DWORD dwWin32ExitCode, DWORD dwServiceSpecificExitCode,
	DWORD dwCheckPoint, DWORD dwWaitHint)
{
	SERVICE_STATUS serviceStatus;
	serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	serviceStatus.dwCurrentState = dwCurrentState;
	if (dwCurrentState == SERVICE_START_PENDING)
	{
		serviceStatus.dwControlsAccepted = 0;
	}
	else
	{
		serviceStatus.dwControlsAccepted =
			SERVICE_ACCEPT_STOP |
			SERVICE_ACCEPT_PAUSE_CONTINUE |
			SERVICE_ACCEPT_SHUTDOWN;
	}

	if (dwServiceSpecificExitCode == 0)
	{
		serviceStatus.dwWin32ExitCode = dwWin32ExitCode;
	}
	else
	{
		serviceStatus.dwWin32ExitCode = ERROR_SERVICE_SPECIFIC_ERROR;
	}

	serviceStatus.dwServiceSpecificExitCode = dwServiceSpecificExitCode;
	serviceStatus.dwCheckPoint = dwCheckPoint;
	serviceStatus.dwWaitHint = dwWaitHint;

	CHECK_WIN32_BOOL(::SetServiceStatus(_instance->_status, & serviceStatus),
		L"SetServiceStatus");
}

void ServiceImpl::ServiceCtrlHandler(DWORD controlCode)
{
	switch(controlCode)
	{
	case SERVICE_CONTROL_PAUSE:
		if (_instance->_running && ! _instance->_paused)
		{
			UpdateSCMStatus(SERVICE_PAUSE_PENDING, NO_ERROR, 0, 1, 1000);
			CHECK_WIN32_DWORD(SuspendThread(_instance->_thread),
				L"SuspendThread");
			_instance->_paused = TRUE;
			UpdateSCMStatus(SERVICE_PAUSED, NO_ERROR, 0, 0, 0);
		}
		break;
	case SERVICE_CONTROL_CONTINUE:
		if (_instance->_running && _instance->_paused)
		{
			UpdateSCMStatus(SERVICE_CONTINUE_PENDING, NO_ERROR, 0, 1, 1000);
			CHECK_WIN32_DWORD(ResumeThread(_instance->_thread),
				L"ResumeThread");
			_instance->_paused = FALSE;
			UpdateSCMStatus(SERVICE_RUNNING, NO_ERROR, 0, 0, 0);
		}
		break;
	case SERVICE_CONTROL_INTERROGATE:
		break;
	case SERVICE_CONTROL_SHUTDOWN:
	case SERVICE_CONTROL_STOP:
		{
			UpdateSCMStatus(SERVICE_STOP_PENDING, NO_ERROR, 0, 1, 5000);
			_instance->Stop();
		}
		break;
	default:
		break;
	}	
}

void ServiceImpl::ServiceMain()
{
	_instance->_status = RegisterServiceCtrlHandler(
		_instance->_name.c_str(), (LPHANDLER_FUNCTION) ServiceCtrlHandler);

	CHECK_WIN32_BOOL(NULL != _instance->_status, 
		L"RegisterServiceCtrlHandler");

	UpdateSCMStatus(SERVICE_START_PENDING, NO_ERROR, 0, 1, 5000);

	_instance->_stop = CreateEvent(0, TRUE, FALSE, 0);
	CHECK_WIN32_BOOL(_instance->_stop != NULL, 
		L"CreateEvent");

	UpdateSCMStatus(SERVICE_START_PENDING, NO_ERROR, 0, 2, 1000);

	StartThread();
	
	UpdateSCMStatus(SERVICE_RUNNING, NO_ERROR, 0, 0, 0);

	_instance->Wait();
}

void ServiceImpl::Wait()
{
	WaitForSingleObject(_stop, INFINITE);
	_running = FALSE;
	WaitForSingleObject(_thread, INFINITE);
	UpdateSCMStatus(SERVICE_STOPPED, NO_ERROR, 0, 1, 5000);
}

void ServiceImpl::Start()
{
	CHECK_BOOL(_instance == NULL,
		L"Another service instance is already running.");

	_instance = this;

	SERVICE_TABLE_ENTRY serviceTable[] =
	{
		{ const_cast<LPWSTR>(_name.c_str()), (LPSERVICE_MAIN_FUNCTION) ServiceMain},
		{ NULL, NULL }
	};

	CHECK_WIN32_BOOL(StartServiceCtrlDispatcher(serviceTable),
		L"StartServiceCtrlDispatcher");
}

