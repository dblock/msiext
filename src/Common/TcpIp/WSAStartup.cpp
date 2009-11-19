#include "StdAfx.h"
#include "WSAStartup.h"
#include <String/String.h>

using namespace AppSecInc::TcpIp;

//! Calls WSAStartup to initialize Winsock for the default version: 2.1.
CWSAStartup::CWSAStartup()
: m_bInitialized(false), m_bVersionSupported(false), m_rc(0),
	m_requestedMajorVersion(default_major_version), m_requestedMinorVersion(default_minor_version)
{
	init();
}

//! Calls WSAStartup to initialize Winsock for the given version
CWSAStartup::CWSAStartup(WORD version)
: m_bInitialized(false), m_bVersionSupported(false), m_rc(0),
	m_requestedMajorVersion(majorVersion(version)), m_requestedMinorVersion(minorVersion(version))
{
	init();
}

//! Calls WSAStartup to initialize Winsock for the given version.
CWSAStartup::CWSAStartup(int major, int minor)
: m_bInitialized(false), m_bVersionSupported(false), m_rc(0),
	m_requestedMajorVersion(major), m_requestedMinorVersion(minor)
{
	init();
}

//! body of constructor code
void CWSAStartup::init()
{
	memset(&m_wsadata, 0, sizeof m_wsadata);
	WORD version_requested = MAKEWORD(m_requestedMajorVersion, m_requestedMinorVersion);
	m_rc = ::WSAStartup(version_requested, &m_wsadata);
	if (0 == m_rc)
	{
		m_bInitialized = true;
		// Which version was negotiated?
		m_bVersionSupported = (version_requested == negotiatedVersion());
		if (!m_bVersionSupported) {
			std::ostringstream os;
			os << "Winsock version " << m_requestedMajorVersion << '.' << m_requestedMinorVersion
				<< "not available. The latest available version is "
				<< negotiatedMajorVersion() << '.' << negotiatedMinorVersion() << ". "
				<< m_wsadata.szDescription;
		}
	}
}

//! Calls WSACleanup, if necessary.
CWSAStartup::~CWSAStartup()
{
	if (m_bInitialized) {
		::WSACleanup();
	}
}

//! returns true if Winsock was successfully initialized to use the requested version, false otherwise.
bool CWSAStartup::wasRequestedVersionNegotiated() const
{
	return m_bVersionSupported;
}

//! returns true if Winsock was successfully initialized, false otherwise.
bool CWSAStartup::initialized() const
{
	return m_bInitialized;
}

//@{
//! It's possible to use a higher version's functionality,
//! but not to call functions that only exist in the later version.
//! These functions let you test the highest version supported by the loaded Winsock library.
WORD CWSAStartup::highestSupportedVersion() const
{
	return m_wsadata.wHighVersion;
}

void CWSAStartup::highestSupportedVersion(WORD& major, WORD& minor) const
{
	major = majorVersion(m_wsadata.wHighVersion);
	minor = minorVersion(m_wsadata.wHighVersion);
}

void CWSAStartup::highestSupportedVersion(int& major, int& minor) const
{
	major = majorVersion(m_wsadata.wHighVersion);
	minor = minorVersion(m_wsadata.wHighVersion);
}
//@}

//@{
//! returns the loaded version of Winsock support.
WORD CWSAStartup::negotiatedVersion() const
{
	return m_wsadata.wVersion;
}

BYTE CWSAStartup::negotiatedMajorVersion() const
{
	return majorVersion(m_wsadata.wVersion);
}

BYTE CWSAStartup::negotiatedMinorVersion() const
{
	return minorVersion(m_wsadata.wVersion);
}

void CWSAStartup::negotiatedVersion(BYTE& major, BYTE& minor) const
{
	major = majorVersion(m_wsadata.wVersion);
	minor = minorVersion(m_wsadata.wVersion);
}

void CWSAStartup::negotiatedVersion(int& major, int& minor) const
{
	major = majorVersion(m_wsadata.wVersion);
	minor = minorVersion(m_wsadata.wVersion);
}
//@}

const WSADATA& CWSAStartup::WsaData() const
{
	return m_wsadata;
}

//! returns the error code returnd from WSAStartup, 0 on success.
int CWSAStartup::ErrorCode() const
{
	return m_rc;
}

//! returns the error message text if there was an error, or an empty string if there was no error.
std::wstring CWSAStartup::ErrorMessage() const
{
	return ErrorMessage(m_rc);
}

//! returns the error message text for the given error code, an empty string for no error,
//! or "unknown error code" if the code is unknown.
std::wstring CWSAStartup::ErrorMessage(int errcode)
{
	return AppSecInc::StringUtils::mb2wc(AppSecInc::Exception::Win32Exception::GetErrorString(
		static_cast<DWORD>(errcode)));
}
