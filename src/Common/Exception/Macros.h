#pragma once

#define CHECK_WIN32_DWORD( func, message ) \
{ \
	DWORD asi_macro_dw_err_ = ( func ); \
	if ( asi_macro_dw_err_ != 0 ) \
	{ \
		std::wstringstream ss_message; ss_message << message; \
        throw std::exception(AppSecInc::Exception::Win32Exception::GetErrorString(asi_macro_dw_err_, \
            ss_message.str().c_str()).c_str()); \
	} \
}

#define CHECK_WIN32_BOOL( func, message ) \
{ \
	if ( FALSE == ( func ) ) \
	{ \
		std::wstringstream ss_message; ss_message << message; \
        throw std::exception(AppSecInc::Exception::Win32Exception::GetLastErrorString( \
            ss_message.str().c_str()).c_str()); \
	} \
}

#define CHECK_BOOL( func, message ) \
{ \
	if ( FALSE == ( func ) ) \
	{ \
		std::wstringstream ss_message; ss_message << message; \
		throw std::exception(AppSecInc::StringUtils::wc2mb(ss_message.str()).c_str()); \
	} \
}

#define THROW( message ) \
{ \
	std::wstringstream ss_message; ss_message << message; \
	throw std::exception(AppSecInc::StringUtils::wc2mb(ss_message.str()).c_str()); \
}

#define CHECK_HR( func, message ) \
{ \
	HRESULT asi_macro_hr_ = ( func ); \
	if (FAILED(asi_macro_hr_)) \
	{ \
		std::wstringstream ss_message; ss_message << message; \
        throw std::exception(AppSecInc::Exception::Win32Exception::GetErrorString(asi_macro_hr_, \
            ss_message.str().c_str()).c_str()); \
	} \
}
