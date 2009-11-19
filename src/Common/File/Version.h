#pragma once

namespace AppSecInc
{
	//! Win32 version support functions
	namespace Version
	{
        /*!
        \brief Check whether a dotted version string is within min/max bounds
        \return true if version within bounds, false otherwise
        */
        bool IsWithinBounds(const std::wstring& version, const std::wstring& min, const std::wstring& max = L"");

        /*!
        \brief Compare the two version strings
        \return -1 if left is less than right
        \return 0 if left and right are equal
        \return 1 if left is larger than right
        */
        int Compare(const std::wstring& left, const std::wstring& right);
	}
}