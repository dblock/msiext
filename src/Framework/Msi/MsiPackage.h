#pragma once

namespace AppSecInc {
namespace Msi {

//! A smart pointer for an MSI database
class MsiPackage : public MsiHandle
{
private:
    std::wstring _filepath;
 public:
	MsiPackage();
    MsiPackage(const std::wstring& filepath);
    void Open(const std::wstring& filepath);
    void Close();
};

}}
