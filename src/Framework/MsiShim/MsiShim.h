#pragma once

namespace AppSecInc {
namespace Msi {

//! A temporary package that exposes MSI functions
class MsiShim : public MsiPackage
{
private:
	AppSecInc::Com::CCoInitialize coinit;
    std::wstring _filename;
    MsiDatabase _database;
public:
    MsiShim();
    ~MsiShim();
    //! import table data into the current database
    void Import(const std::wstring& path, const std::wstring& file);
    //! execute a custom action in a custom action DLL
    int ExecuteCA(const std::wstring& dll, const std::wstring& name);
};

}}