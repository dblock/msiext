#pragma once

namespace AppSecInc
{
	namespace Exceptions
	{
		void COM_EXCEPTION_HANDLER_BLOCK_impl(_com_error& e);
		void STD_EXCEPTION_HANDLER_BLOCK_impl(std::exception& e);
		void ELLIPSIS_EXCEPTION_HANDLER_BLOCK_impl();
		const HRESULT default_error_code = E_FAIL;
	}
}

#define STD_EXCEPTION_HANDLER_BLOCK catch (std::exception& e) { AppSecInc::Exceptions::STD_EXCEPTION_HANDLER_BLOCK_impl(e); return AppSecInc::Exceptions::default_error_code; }
#define COM_EXCEPTION_HANDLER_BLOCK catch (_com_error& e) { AppSecInc::Exceptions::COM_EXCEPTION_HANDLER_BLOCK_impl(e); return e.Error(); }
#define ELLIPSIS_EXCEPTION_HANDLER_BLOCK catch (...) { AppSecInc::Exceptions::ELLIPSIS_EXCEPTION_HANDLER_BLOCK_impl(); return E_UNEXPECTED; }

#define EXCEPTION_HANDLER_PROLOG try {
#define EXCEPTION_HANDLER_EPILOG  } STD_EXCEPTION_HANDLER_BLOCK COM_EXCEPTION_HANDLER_BLOCK ELLIPSIS_EXCEPTION_HANDLER_BLOCK
