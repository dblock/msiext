#include "StdAfx.h"
#include "MsiPackage.h"

MsiPackage::MsiPackage() 
{

}

MsiPackage::MsiPackage(const std::wstring& filepath)
{
    Open(filepath);    
}

void MsiPackage::Close()
{
    MsiHandle::Close();
    _filepath.clear();
}

void MsiPackage::Open(const std::wstring& filepath)
{
    if (IsOpen())
    {
        Close();
    }

    CHECK_WIN32_DWORD(::MsiOpenPackage(filepath.c_str(), & m_h),
        L"Error opening MSI package \"" << filepath << "\"");

    _filepath = filepath;
}
