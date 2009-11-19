#pragma once

namespace AppSecInc
{
	namespace TcpIp
	{
		/*! Initializes Winsock in its constructor, and cleans up in the destructor.

			It's safe to instantiate this class more than once, but trying to load a second instance
			may result in an error, such as WSAEINPROGRESS, that may clear up in time.
			In fact, this can happen trying to load the first instance.
			Because of these oddities, all information returned from WSAStartup is retained and made available.

			The Winsock implementation may support higher versions: if some functionality from a
			later version is desired, call highestSupportedVersion() to see if it's supported.
		*/
		class CWSAStartup
		{
		public:
			//@{
			//! \brief The application is written and built for this verion of Winsock.
			const static int default_major_version = 2;
			const static int default_minor_version = 1;
			const static int default_version = MAKEWORD(default_major_version, default_minor_version);
			//@}

			CWSAStartup();
			explicit CWSAStartup(WORD version);
			CWSAStartup(int major, int minor);
			~CWSAStartup();

			bool wasRequestedVersionNegotiated() const;
			bool initialized() const;

			WORD negotiatedVersion() const;
			BYTE negotiatedMajorVersion() const;
			BYTE negotiatedMinorVersion() const;
			void negotiatedVersion(BYTE& major, BYTE& minor) const;
			void negotiatedVersion(int& major, int& minor) const;

			WORD highestSupportedVersion() const;
			void highestSupportedVersion(WORD& major, WORD& minor) const;
			void highestSupportedVersion(int& major, int& minor) const;

			int ErrorCode() const;
			std::wstring ErrorMessage() const;
			const WSADATA& WsaData() const;

			static std::wstring ErrorMessage(int errcode);
			static BYTE majorVersion(WORD version) { return LOBYTE(version); }
			static BYTE minorVersion(WORD version) { return HIBYTE(version); }
			static WORD packVersion(BYTE major, BYTE minor) { return MAKEWORD(major, minor); }
			static WORD packVersion(int major, int minor) { return MAKEWORD(major, minor); }

		private:
			void CWSAStartup::init();
			
			CWSAStartup(const CWSAStartup&); //! not implemented
			CWSAStartup& operator=(const CWSAStartup&); //! not implemented

			bool m_bInitialized;
			bool m_bVersionSupported;
			int m_rc;
			BYTE m_requestedMajorVersion;
			BYTE m_requestedMinorVersion;
			WSADATA m_wsadata;
		};
	}
}
