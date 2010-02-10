#pragma once

namespace AppSecInc {
namespace Msi {

struct MsiDatabaseSummaryEntry
{
    DWORD dwPropertyId; // see http://msdn.microsoft.com/en-us/library/aa372045(VS.85).aspx
    VARENUM varPropertyType;
    CComVariant varValue;
};

//! A smart pointer for an MSI database
class MsiDatabase : public MsiHandle
{
private:
    std::wstring _filepath;
public:
    //! empty database object
	MsiDatabase();
    //! create a new or open an existing msi database
    MsiDatabase(const std::wstring& filepath, LPCTSTR openmode = MSIDBOPEN_READONLY);
    //! commit database changes to disk
    void Commit();
    //! create a usable empty database with a base summary
    void Create(const std::wstring& filepath);
    //! create or open a database file
    void Open(const std::wstring& filepath, LPCTSTR openmode = MSIDBOPEN_READONLY);
    //! close the database
    void Close();
    //! set database summary fields
    void SetSummary(const std::vector<MsiDatabaseSummaryEntry>& summary);
    //! set database summary fields
    void SetSummary(const MsiDatabaseSummaryEntry summary[], int size);
    //! import a previously exported database file
    void Import(const std::wstring& path, const std::wstring& file);
	//! execute an MSI query
	void Execute(const std::wstring& query);
};

}}
