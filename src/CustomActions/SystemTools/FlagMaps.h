#pragma once

using namespace AppSecInc::Msi::Flags;

static const FlagMapEntry s_TcpSocketTypeFlags[] = 
{
    { L"SOCK_STREAM", SOCK_STREAM },
    { L"SOCK_DGRAM", SOCK_DGRAM },
    { L"SOCK_RAW", SOCK_RAW },
    { L"SOCK_RDM", SOCK_RDM },
    { L"SOCK_SEQPACKET", SOCK_SEQPACKET },
};

static const FlagMapEntry s_IpProtocolFlags[] = 
{
    { L"IPPROTO_TCP", IPPROTO_TCP },
    { L"IPPROTO_UDP", IPPROTO_UDP }
};

typedef struct
{
    LPCWSTR name;
    HKEY value;
} FlagMapEntryHKEY;

static const FlagMapEntryHKEY s_RegistryRoot[] = 
{
    { L"HKEY_LOCAL_MACHINE", HKEY_LOCAL_MACHINE },
    { L"HKEY_CURRENT_USER", HKEY_CURRENT_USER },
	{ L"HKEY_CURRENT_CONFIG", HKEY_CURRENT_CONFIG },
	{ L"HKEY_CLASSES_ROOT", HKEY_CLASSES_ROOT },
	{ L"HKEY_USERS", HKEY_USERS }
};

static const FlagMapEntry s_ServiceControl[] = 
{
    { L"SERVICE_CONTROL_START", SERVICE_CONTROL_START },
    { L"SERVICE_CONTROL_STOP", SERVICE_CONTROL_STOP }, 
    { L"SERVICE_CONTROL_PAUSE", SERVICE_CONTROL_PAUSE },
    { L"SERVICE_CONTROL_CONTINUE", SERVICE_CONTROL_CONTINUE },
};

static const FlagMapEntry s_ServiceType[] = 
{
    { L"SERVICE_FILE_SYSTEM_DRIVER", SERVICE_FILE_SYSTEM_DRIVER },
    { L"SERVICE_KERNEL_DRIVER", SERVICE_KERNEL_DRIVER }, 
    { L"SERVICE_WIN32_OWN_PROCESS", SERVICE_WIN32_OWN_PROCESS },
    { L"SERVICE_WIN32_SHARE_PROCESS", SERVICE_WIN32_SHARE_PROCESS },
    { L"SERVICE_INTERACTIVE_PROCESS", SERVICE_INTERACTIVE_PROCESS },
};

static const FlagMapEntry s_ServiceStartType[] = 
{
    { L"SERVICE_AUTO_START", SERVICE_AUTO_START },
    { L"SERVICE_BOOT_START", SERVICE_BOOT_START }, 
    { L"SERVICE_DEMAND_START", SERVICE_DEMAND_START },
    { L"SERVICE_DISABLED", SERVICE_DISABLED },
    { L"SERVICE_SYSTEM_START", SERVICE_SYSTEM_START },
};

static const FlagMapEntry s_ServiceErrorControl[] = 
{
    { L"SERVICE_ERROR_IGNORE", SERVICE_ERROR_IGNORE },
    { L"SERVICE_ERROR_NORMAL", SERVICE_ERROR_NORMAL }, 
    { L"SERVICE_ERROR_SEVERE", SERVICE_ERROR_SEVERE },
    { L"SERVICE_ERROR_CRITICAL", SERVICE_ERROR_CRITICAL },
};

typedef struct
{
    LPCWSTR name;
    int value;
} FlagMapEntryCSIDL;

static const FlagMapEntryCSIDL s_CSIDL[] = 
{
    { L"CSIDL_ADMINTOOLS", CSIDL_ADMINTOOLS },
	{ L"CSIDL_DESKTOP", CSIDL_DESKTOP },									// <desktop>
	{ L"CSIDL_INTERNET", CSIDL_INTERNET },									// Internet Explorer (icon on desktop)
	{ L"CSIDL_PROGRAMS", CSIDL_PROGRAMS },									// Start Menu\Programs
	{ L"CSIDL_CONTROLS", CSIDL_CONTROLS },									// My Computer\Control Panel
	{ L"CSIDL_PRINTERS", CSIDL_PRINTERS },									// My Computer\Printers
	{ L"CSIDL_PERSONAL", CSIDL_PERSONAL},									// My Documents
	{ L"CSIDL_FAVORITES", CSIDL_FAVORITES },								// <user name>\Favorites
	{ L"CSIDL_STARTUP", CSIDL_STARTUP },									// Start Menu\Programs\Startup
	{ L"CSIDL_RECENT", CSIDL_RECENT },										// <user name>\Recent
	{ L"CSIDL_SENDTO", CSIDL_SENDTO },										// <user name>\SendTo
	{ L"CSIDL_BITBUCKET", CSIDL_BITBUCKET},									// <desktop>\Recycle Bin
	{ L"CSIDL_STARTMENU", CSIDL_STARTMENU },								// <user name>\Start Menu
	{ L"CSIDL_MYDOCUMENTS", CSIDL_MYDOCUMENTS },							// logical "My Documents" desktop icon
	{ L"CSIDL_MYMUSIC", CSIDL_MYMUSIC },										// "My Music" folder
	{ L"CSIDL_MYVIDEO", CSIDL_MYVIDEO },									// "My Videos" folder
	{ L"CSIDL_DESKTOPDIRECTORY", CSIDL_DESKTOPDIRECTORY },					// <user name>\Desktop
	{ L"CSIDL_DRIVES", CSIDL_DRIVES },										// My Computer
	{ L"CSIDL_NETWORK", CSIDL_NETWORK },									// Network Neighborhood (My Network Places)
	{ L"CSIDL_NETHOOD", CSIDL_NETHOOD },									// <user name>\nethood
	{ L"CSIDL_FONTS", CSIDL_FONTS },										// windows\fonts
	{ L"CSIDL_TEMPLATES", CSIDL_TEMPLATES },
	{ L"CSIDL_COMMON_STARTMENU", CSIDL_COMMON_STARTMENU },					// All Users\Start Menu
	{ L"CSIDL_COMMON_PROGRAMS", CSIDL_COMMON_PROGRAMS },					// All Users\Start Menu\Programs
	{ L"CSIDL_COMMON_STARTUP", CSIDL_COMMON_STARTUP },						// All Users\Startup
	{ L"CSIDL_COMMON_DESKTOPDIRECTORY", CSIDL_COMMON_DESKTOPDIRECTORY },	// All Users\Desktop
	{ L"CSIDL_APPDATA", CSIDL_APPDATA },									// <user name>\Application Data
	{ L"CSIDL_PRINTHOOD", CSIDL_PRINTHOOD },								// <user name>\PrintHood
	{ L"CSIDL_LOCAL_APPDATA", CSIDL_LOCAL_APPDATA },						// <user name>\Local Settings\Applicaiton Data (non roaming)
	{ L"CSIDL_ALTSTARTUP", CSIDL_ALTSTARTUP },								// non localized startup
	{ L"CSIDL_COMMON_ALTSTARTUP", CSIDL_COMMON_ALTSTARTUP },				// non localized common startup
	{ L"CSIDL_COMMON_FAVORITES", CSIDL_COMMON_FAVORITES },
	{ L"CSIDL_INTERNET_CACHE", CSIDL_INTERNET_CACHE },
	{ L"CSIDL_COOKIES", CSIDL_COOKIES },
	{ L"CSIDL_HISTORY", CSIDL_HISTORY },
	{ L"CSIDL_COMMON_APPDATA", CSIDL_COMMON_APPDATA },						// All Users\Application Data
	{ L"CSIDL_WINDOWS", CSIDL_WINDOWS },									// GetWindowsDirectory()
	{ L"CSIDL_SYSTEM", CSIDL_SYSTEM },										// GetSystemDirectory()
	{ L"CSIDL_PROGRAM_FILES", CSIDL_PROGRAM_FILES },						// C:\Program Files
	{ L"CSIDL_MYPICTURES", CSIDL_MYPICTURES },								// C:\Program Files\My Pictures
	{ L"CSIDL_PROFILE", CSIDL_PROFILE },									// USERPROFILE
	{ L"CSIDL_SYSTEMX86", CSIDL_SYSTEMX86 },								// x86 system directory on RISC
	{ L"CSIDL_PROGRAM_FILESX86", CSIDL_PROGRAM_FILESX86 },					// x86 C:\Program Files on RISC
	{ L"CSIDL_PROGRAM_FILES_COMMON", CSIDL_PROGRAM_FILES_COMMON },			// C:\Program Files\Common
	{ L"CSIDL_PROGRAM_FILES_COMMONX86", CSIDL_PROGRAM_FILES_COMMONX86 },	// x86 Program Files\Common on RISC
	{ L"CSIDL_COMMON_TEMPLATES", CSIDL_COMMON_TEMPLATES },					// All Users\Templates
	{ L"CSIDL_COMMON_DOCUMENTS", CSIDL_COMMON_DOCUMENTS },					// All Users\Documents
	{ L"CSIDL_COMMON_ADMINTOOLS", CSIDL_COMMON_ADMINTOOLS },				// All Users\Start Menu\Programs\Administrative Tools
	{ L"CSIDL_ADMINTOOLS", CSIDL_ADMINTOOLS },								// <user name>\Start Menu\Programs\Administrative Tools
	{ L"CSIDL_CONNECTIONS", CSIDL_CONNECTIONS },							// Network and Dial-up Connections
	{ L"CSIDL_COMMON_MUSIC", CSIDL_COMMON_MUSIC },							// All Users\My Music
	{ L"CSIDL_COMMON_PICTURES", CSIDL_COMMON_PICTURES },					// All Users\My Pictures
	{ L"CSIDL_COMMON_VIDEO", CSIDL_COMMON_VIDEO },							// All Users\My Video
	{ L"CSIDL_RESOURCES", CSIDL_RESOURCES },								// Resource Direcotry
	{ L"CSIDL_RESOURCES_LOCALIZED", CSIDL_RESOURCES_LOCALIZED },			// Localized Resource Direcotry
	{ L"CSIDL_COMMON_OEM_LINKS", CSIDL_COMMON_OEM_LINKS },					// Links to All Users OEM specific apps
	{ L"CSIDL_CDBURN_AREA", CSIDL_CDBURN_AREA },							// USERPROFILE\Local Settings\Application Data\Microsoft\CD Burning
	{ L"CSIDL_COMPUTERSNEARME", CSIDL_COMPUTERSNEARME },					// Computers Near Me (computered from Workgroup membership)
};
