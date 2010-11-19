#include "StdAfx.h"
#include "MsiDatabase.h"

MsiDatabase::MsiDatabase() 
{

}

MsiDatabase::MsiDatabase(const std::wstring& filepath, LPCTSTR openmode)
{
    Open(filepath, openmode);    
}

void MsiDatabase::Close()
{
    MsiHandle::Close();
    _filepath.clear();
}

void MsiDatabase::Create(const std::wstring& filepath)
{
    Open(filepath, MSIDBOPEN_CREATEDIRECT);

    const MsiDatabaseSummaryEntry summary[] =
    {
        { PID_REVNUMBER, VT_LPSTR, "{00000000-0000-0000-0000-000000000000}" },
        { PID_PAGECOUNT, VT_I4, 100 },
        { PID_WORDCOUNT, VT_I4, 100 },
    };

    SetSummary(summary, ARRAYSIZE(summary));
}

void MsiDatabase::Open(const std::wstring& filepath, LPCTSTR openmode)
{
    if (IsOpen())
    {
        Close();
    }

    CHECK_WIN32_DWORD(::MsiOpenDatabase(filepath.c_str(), openmode, & m_h),
        L"Error opening MSI database \"" << filepath << "\"");

    _filepath = filepath;
}

void MsiDatabase::Commit()
{
    CHECK_BOOL(IsOpen(), 
        L"A database must be opened first");

    CHECK_WIN32_DWORD(::MsiDatabaseCommit(m_h),
        L"Error committing MSI database \"" << _filepath << "\"");
}

void MsiDatabase::SetSummary(const std::vector<MsiDatabaseSummaryEntry>& summary)
{
    SetSummary(& * summary.begin(), summary.size());
}

void MsiDatabase::SetSummary(const MsiDatabaseSummaryEntry summary[], int size)
{
    // http://msdn.microsoft.com/en-us/library/aa372045(VS.85).aspx

    MsiHandle h_summary;

    CHECK_WIN32_DWORD(::MsiGetSummaryInformation(m_h, NULL, size, & h_summary),
        L"Error getting MSI summary information");

    for (int i = 0; i < size; i++)
    {
        switch(summary[i].varValue.vt)
        {
        case VT_BSTR:
            CHECK_WIN32_DWORD(MsiSummaryInfoSetProperty(h_summary, summary[i].dwPropertyId, summary[i].varPropertyType, 0, NULL, static_cast<LPCWSTR>(summary[i].varValue.bstrVal)),
                L"Error setting property " << summary[i].dwPropertyId);
            break;
        case VT_I2:
        case VT_I4:
            CHECK_WIN32_DWORD(MsiSummaryInfoSetProperty(h_summary, summary[i].dwPropertyId, summary[i].varPropertyType, summary[i].varValue.iVal, NULL, NULL),
                L"Error setting property " << summary[i].dwPropertyId);
            break;
        default:
            THROW("unsupported VT type: " << summary[i].varValue.vt);
        }
    }

    CHECK_WIN32_DWORD(::MsiSummaryInfoPersist(h_summary),
        L"Error persisting summary information");
}

void MsiDatabase::Import(const std::wstring& path, const std::wstring& file)
{
    CHECK_BOOL(IsOpen(), 
        L"A database must be opened first");

    CHECK_WIN32_DWORD(::MsiDatabaseImport(m_h, path.c_str(), file.c_str()),
        L"Error importing " << path << L"\\" << file);
}

void MsiDatabase::Execute(const std::wstring& query)
{
	MsiView msiView;

    CHECK_WIN32_DWORD(::MsiDatabaseOpenView(m_h, query.c_str(), & msiView),
        L"Error executing " << query);

    // fetch the record from the view
    CHECK_WIN32_DWORD(::MsiViewExecute(msiView, NULL),
        L"Error executing binary view");
}