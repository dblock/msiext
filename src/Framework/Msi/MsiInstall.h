#pragma once

namespace AppSecInc {
namespace Msi {

//! A wrapper for an MSIHANDLE with MSI support functions
class MsiInstall
{
private:
    MSIHANDLE _h;
    MsiInstall& msiInstall; // CHECK_* macros need something called msiInstall to log errors
public:
    MSIHANDLE Peek() const { return _h; }
    //! get a property
	std::wstring GetProperty(const std::wstring& name);
    //! set a property
    void SetProperty(const std::wstring& name, const std::wstring& value);
    //! get a property
    std::string GetProperty(const std::string& name);
    //! set a property
    void SetProperty(const std::string& name, const std::string& value);
    //! get binary data from the Binary table
    void GetBinaryData(const std::wstring& name, std::vector<char>& data);
    //! get view data in xml format, executes the query and returns the result in a CustomTable format
	std::wstring GetViewData(const std::wstring& query);
    //! get information on a view (column names and types)
    void GetViewInfo(const std::wstring& query, std::vector<std::wstring>& names, std::vector<std::wstring>& types);
    //! set action data for a deferred custom action
    void SetActionData(const std::wstring& action, const std::wstring& data);
    //! get action data from the CustomActionData property
	std::wstring GetActionData();
    //! log an error defined in the Error table
    void LogError(int error);
    //! log a string error
    void LogError(const std::wstring& message);
    //! log info
    void LogInfo(const std::wstring& action, const std::wstring& message);
    //! get a formatted string
	std::wstring GetFormattedString(const std::wstring& s);
    //! evaluate a condition
    bool EvaluateCondition(const std::wstring& condition);
	//! returns true if the product is being installed
	bool IsInstalling();
	//! returns true if the product is being uninstalled
	bool IsUnInstalling();	
	//! returns true if the current state is rollback
	bool IsRollback();
	//! returns true if the component is being installed
	bool IsComponentInstalling(const std::wstring& component);
	//! returns true if the component is being uninstalled
	bool IsComponentUnInstalling(const std::wstring& component);
	//! returns true if the component is being reinstalled
	bool IsComponentReInstalling(const std::wstring& component);
	//! returns the component state
	void GetComponentState(const std::wstring& component, INSTALLSTATE& component_installed, INSTALLSTATE& component_action);
    //! execute a custom action
    void DoAction(const std::wstring& action);
    MsiInstall(MSIHANDLE h);
    virtual ~MsiInstall();
};

}}

