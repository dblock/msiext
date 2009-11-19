#pragma once

namespace AppSecInc {
namespace Msi {
namespace Flags {

typedef struct
{
    LPCWSTR name;
    WORD value;
} FlagMapEntryWORD, FlagMapEntry;

typedef struct
{
    LPCWSTR name;
    UINT value;
} FlagMapEntryUINT;

typedef struct
{
    LPCWSTR name;
    DWORD value;
} FlagMapEntryDWORD;

//! convert a single flag to its flag value
template<typename T, typename R>
R GetFlagValue(const std::wstring& name, const T& flagmap)
{
    for (int i = 0; i < ARRAYSIZE(flagmap); i++)
    {
        if (flagmap[i].name == name)
        {
            return flagmap[i].value;
        }
    }

	std::stringstream error;
	error << "invalid flag name: " << AppSecInc::StringUtils::wc2mb(name);
	throw std::exception(error.str().c_str());
}

//! convert a single flag value to its flag name
template<typename T, typename R>
std::wstring GetFlagName(const R& value, const T& flagmap)
{
    for (int i = 0; i < ARRAYSIZE(flagmap); i++)
    {
        if (flagmap[i].value == value)
        {
            return flagmap[i].name;
        }
    }

	std::stringstream error;
	error << "invalid flag value: " << AppSecInc::StringUtils::toString(value);
	throw std::exception(error.str().c_str());
}

//! convert a vector of flags to the combined flag value
template<typename T, typename R>
R GetFlagsValue(const std::vector<std::wstring>& flags, const T& flagmap)
{
    R result = 0;

    for each (const std::wstring& flag_entry in flags)
    {
        if (flag_entry.length() == 0)
            continue;

        R item_result = GetFlagValue<T, R>(flag_entry, flagmap);
        result |= item_result;
    }

    return result;
}

//! convert a string of flags to the combined flag value
template <typename T, typename R>
R GetStringFlagsValue(const std::wstring& flags, const T& flagmap)
{
    std::vector<std::wstring> flags_vector;
	AppSecInc::StringUtils::tokenizeOnChar(flags, flags_vector, L"|,; \t\n");
    return GetFlagsValue<T, R>(flags_vector, flagmap);
}

//! retreive an MSI property and convert to a flag value
template <typename T, typename R>
R GetPropertyValue(MsiInstall& msiInstall, const std::wstring& name, const T& flagmap)
{
	std::wstring property_value = msiInstall.GetProperty(name);
    return GetStringFlagsValue<T, R>(property_value, flagmap);
}

//! convert a single flag to its flag value
template<typename T>
ULONG GetFlagValue(const std::wstring& name, const T& flagmap)
{
    return GetFlagValue<T, ULONG>(name, flagmap);
}

template<typename T>
ULONG GetFlagsValue(const std::vector<std::wstring>& flags, const T& flagmap)
{
    return GetFlagsValue<T, ULONG>(flags, flagmap);
}

//! convert a string of flags to the combined flag value
template <typename T>
ULONG GetStringFlagsValue(const std::wstring& flags, const T& flagmap)
{
    return GetStringFlagsValue<T, ULONG>(flags, flagmap);
}

//! retreive an MSI property and convert to a flag value
template <typename T>
ULONG GetPropertyValue(MsiInstall& msiInstall, const std::wstring& name, const T& flagmap)
{
    return GetPropertyValue<T, ULONG>(msiInstall, name, flagmap);
}

}}}
        
