#include "StdAfx.h"

MsiInstall::MsiInstall(MSIHANDLE h)
    : _h(h)
    , msiInstall(* this)
{

}

MsiInstall::~MsiInstall()
{

}

std::string MsiInstall::GetProperty(const std::string& name)
{
	return AppSecInc::StringUtils::wc2mb(
		GetProperty(AppSecInc::StringUtils::mb2wc(name)));
}

void MsiInstall::SetProperty(const std::string& name, const std::string& value)
{
    SetProperty(StringUtils::mb2wc(name), StringUtils::mb2wc(value));
}

std::wstring MsiInstall::GetProperty(const std::wstring& name)
{
    DWORD count = 0;
    // http://msdn2.microsoft.com/en-us/library/aa370574(VS.85).aspx
    // Do not pass NULL into MsiGetProperty.
    DWORD msi_rc = ::MsiGetProperty(_h, name.c_str(), L"", & count);

    std::wstring value;
    if (msi_rc == ERROR_MORE_DATA)
    {
        if (count == 0)
        {
            // http://msdn2.microsoft.com/en-us/library/aa370134(VS.85).aspx
            // If the value for the property retrieved by the MsiGetProperty function is not defined, it is equivalent to a 0-length value. It is not an error.            
            msi_rc = ERROR_SUCCESS;
        }
        else
        {
            value.resize(count + 1);
            count = value.size();
            msi_rc = ::MsiGetProperty(_h, name.c_str(), & * value.begin(), & count);
            
            if (msi_rc == ERROR_SUCCESS)
            {
                value.resize(count);
            }
        }
    }

    CHECK_WIN32_DWORD(msi_rc,
        L"Error retreiving " << name);

    return value;
}

void MsiInstall::SetProperty(const std::wstring& name, const std::wstring& value)
{	
    CHECK_WIN32_DWORD(::MsiSetProperty(_h, name.c_str(), value.c_str()),
        L"Error setting " << name);
}

void MsiInstall::LogInfo(const std::wstring& action, const std::wstring& message)
{
    MsiHandle hRec(MsiCreateRecord(3));
    MsiRecordSetString(hRec, 0, L"[1]: [2]");
    MsiRecordSetString(hRec, 1, action.c_str());
    MsiRecordSetString(hRec, 2, message.c_str());
    DWORD msi_rc = MsiProcessMessage(_h, INSTALLMESSAGE(INSTALLMESSAGE_INFO), hRec);

	if (msi_rc == -1)
	{
        THROW(L"Error logging \"" << action << L": " << message << L"\"");
	}
}
void MsiInstall::LogError(int error)
{
    MsiHandle hRec(MsiCreateRecord(4));
    MsiRecordSetInteger(hRec, 1, error);

    DWORD msi_rc = MsiProcessMessage(_h, INSTALLMESSAGE(INSTALLMESSAGE_ERROR), hRec);

	if (msi_rc == -1)
	{
        THROW(L"Error logging \"" << error << L"\"");
	}
}

void MsiInstall::LogError(const std::wstring& message)
{
    MsiHandle hRec(MsiCreateRecord(4));
    MsiRecordSetString(hRec, 0, message.c_str());

    DWORD msi_rc = MsiProcessMessage(_h, INSTALLMESSAGE(INSTALLMESSAGE_ERROR), hRec);

	if (msi_rc == -1)
	{
        THROW(L"Error logging \"" << message << L"\"");
	}
}

void MsiInstall::GetBinaryData(const std::wstring& name, std::vector<char>& data)
{
    MsiView msiView;
    MsiHandle msiDatabase = MsiGetActiveDatabase(_h);

    // fetch the row from binary table
	std::wstringstream query;
    query << L"SELECT `Data` FROM `Binary` WHERE `Name`='" << name << L"'";
    CHECK_WIN32_DWORD(::MsiDatabaseOpenView(msiDatabase, query.str().c_str(), & msiView),
        L"Error executing " << query.str());

    // fetch the record from the view
    MsiHandle hRecBinary;
    CHECK_WIN32_DWORD(::MsiViewExecute(msiView, NULL),
		L"Error executing binary view for \"" << name << L"\"");
    CHECK_WIN32_DWORD(::MsiViewFetch(msiView, & hRecBinary),
        L"Error fetching \"" << name << L"\" binary record");

    // read the data size
    DWORD cbRead = 0;
    CHECK_WIN32_DWORD(::MsiRecordReadStream(hRecBinary, 1, NULL, & cbRead),
        L"Error reading binary stream data size for \"" << name << L"\"");

    if (cbRead > 0) // an empty stream means a zero-sized file
    {
        // read the data
        data.resize(cbRead);

        CHECK_WIN32_DWORD(::MsiRecordReadStream(hRecBinary, 1, & * data.begin(), & cbRead),
            L"Error reading binary stream data size for \"" << name << L"\"");

        data.resize(cbRead);
        CHECK_BOOL(cbRead > 0 && data.size() > 0, 
            L"Invalid or empty data stream read for \"" << name << L"\"");
    }
    else
    {
        data.clear();
    }
}

void MsiInstall::GetViewInfo(const std::wstring& query, std::vector<std::wstring>& column_names, std::vector<std::wstring>& column_types)
{
    MsiView msiView;
    MsiHandle msiDatabase = MsiGetActiveDatabase(_h);

    // fetch the row from binary table
    CHECK_WIN32_DWORD(::MsiDatabaseOpenView(msiDatabase, query.c_str(), & msiView),
        L"Error executing " << query);

    // fetch the record from the view
    MsiHandle hRow;
    CHECK_WIN32_DWORD(::MsiViewExecute(msiView, NULL),
        L"Error executing binary view");

    // get the information on rows and columns
    // http://msdn.microsoft.com/en-us/library/aa367870(VS.85).aspx
    MsiHandle hColNames;
    CHECK_WIN32_DWORD(::MsiViewGetColumnInfo(msiView, MSICOLINFO_NAMES, & hColNames),
        L"Error in MsiViewGetColumnInfo(MSICOLINFO_NAMES)");

    MsiHandle hColTypes;
    CHECK_WIN32_DWORD(::MsiViewGetColumnInfo(msiView, MSICOLINFO_TYPES, & hColTypes),
        L"Error in MsiViewGetColumnInfo(MSICOLINFO_NAMES)");

    // number of columns
    int cols = ::MsiRecordGetFieldCount(hColNames);

    for (int i = 1; i <= cols; i++)
    {
        // read the column name
        {
            std::wstring column_name;
            DWORD cbRead = 0;
            CHECK_WIN32_DWORD(::MsiRecordGetString(hColNames, i, NULL, & cbRead), 
                L"Error reading data size");
            column_name.resize(cbRead++);
            CHECK_WIN32_DWORD(::MsiRecordGetString(hColNames, i, & * column_name.begin(), & cbRead), 
                L"Error reading data size (2)");
            column_name.resize(cbRead);
            column_names.push_back(column_name);
        }

        // read the column type
        {
            std::wstring column_type;
            DWORD cbRead = 0;
            CHECK_WIN32_DWORD(::MsiRecordGetString(hColTypes, i, NULL, & cbRead), 
                L"Error reading data size");
            column_type.resize(cbRead++);
            CHECK_WIN32_DWORD(::MsiRecordGetString(hColTypes, i, & * column_type.begin(), & cbRead), 
                L"Error reading data size (2)");
            column_type.resize(cbRead);
            column_types.push_back(column_type);
        }
    }
}

std::wstring MsiInstall::GetViewData(const std::wstring& query)
{
    // xml document
    MSXML2::IXMLDOMDocumentPtr spXMLDOM;
    CHECK_HR(spXMLDOM.CreateInstance(MSXML2::CLSID_DOMDocument), 
		L"Error creating output document");
    // processing instruction
    MSXML2::IXMLDOMProcessingInstructionPtr spXMLPI = spXMLDOM->createProcessingInstruction(
        _bstr_t(L"xml"), _bstr_t(L"version=\"1.0\" encoding=\"UTF-8\""));
    CHECK_BOOL(NULL != spXMLDOM->appendChild(spXMLPI), 
		L"Error appending processing instruction");
    // root element
    MSXML2::IXMLDOMElementPtr spXMLRoot = spXMLDOM->createElement(L"Table");
    CHECK_BOOL(NULL != spXMLDOM->appendChild(spXMLRoot), 
		L"Error appending Table element node");

    std::vector<std::wstring> column_names;
    std::vector<std::wstring> column_types;

    //! \todo The view is executed twice, once to get the info, once in GetViewData
    GetViewInfo(query, column_names, column_types);

    MsiView msiView;
    MsiHandle msiDatabase = MsiGetActiveDatabase(_h);

    // fetch the row from binary table
    CHECK_WIN32_DWORD(::MsiDatabaseOpenView(msiDatabase, query.c_str(), & msiView),
        L"Error executing " << query);

    // fetch the record from the view
    MsiHandle hRow;
    CHECK_WIN32_DWORD(::MsiViewExecute(msiView, NULL),
        L"Error executing view");

    DWORD fetch_rc = ::MsiViewFetch(msiView, & hRow);
    int cols = ::MsiRecordGetFieldCount(hRow);

    while (fetch_rc == ERROR_SUCCESS)
    {
        MSXML2::IXMLDOMElementPtr spXMLRow = spXMLDOM->createElement(L"Row");
        CHECK_BOOL(NULL != spXMLRoot->appendChild(spXMLRow), L"Error appending Row node");

        for (int i = 1; i <= cols; i++)
        {
            MSXML2::IXMLDOMElementPtr spXMLData = spXMLDOM->createElement(L"Data");
            CHECK_BOOL(NULL != spXMLRow->appendChild(spXMLData), L"Error appending Data node");

            MSXML2::IXMLDOMAttributePtr spXMLDataColumn = spXMLDOM->createAttribute(L"Column");
            spXMLDataColumn->put_nodeValue(_variant_t(column_names[i - 1].c_str()));
            CHECK_BOOL(NULL != spXMLData->Getattributes()->setNamedItem(spXMLDataColumn), L"Error setting data attribute");

            // http://msdn.microsoft.com/en-us/library/aa367870(VS.85).aspx
            switch(tolower(column_types[i - 1][0]))
            {
            case L's': // string
            case L'g': // temporary string
            case L'l': // localizable string
                {
                    std::wstring data;
                    DWORD cbRead = 0;
                    CHECK_WIN32_DWORD(::MsiRecordGetString(hRow, i, NULL, & cbRead), 
                        L"Error reading data size");
					if (cbRead > 0)
					{
						data.resize(cbRead++);
						CHECK_WIN32_DWORD(::MsiRecordGetString(hRow, i, & * data.begin(), & cbRead), 
							L"Error reading data size (2)");
						data.resize(cbRead);
						std::wstring formatted_data = GetFormattedString(data);
						MSXML2::IXMLDOMNodePtr spXmlDataColumnValue = spXMLDOM->createTextNode(formatted_data.c_str());
						CHECK_BOOL(NULL != spXMLData->appendChild(spXmlDataColumnValue), L"Error setting data attribute");
					}
                }
                break;
            case L'i': // integer
            case L'j': // temporary integer
                {
                    int data = MSI_NULL_INTEGER;
                    CHECK_WIN32_BOOL(MSI_NULL_INTEGER != (data = ::MsiRecordGetInteger(hRow, i)), 
                        L"Error reading integer");
                    MSXML2::IXMLDOMNodePtr spXmlDataColumnValue = spXMLDOM->createTextNode(StringUtils::toString(data).c_str());
                    CHECK_BOOL(NULL != spXMLData->appendChild(spXmlDataColumnValue), L"Error setting data attribute");
                }
                break;
            case L'v': // stream
            default:
                CHECK_BOOL(false,
                    L"Unsupported type " << column_types[i - 1]);
            }
        }

        fetch_rc = ::MsiViewFetch(msiView, & hRow);
    }

    if (fetch_rc != ERROR_NO_MORE_ITEMS)
    {
        CHECK_WIN32_DWORD(fetch_rc,
            L"Error fetching record");
    }

    CComBSTR bstrXml;
    CHECK_HR(spXMLDOM->get_xml(& bstrXml), L"Error getting XML");
    return static_cast<LPCWSTR>(bstrXml);	
}

void MsiInstall::SetActionData(const std::wstring& action, const std::wstring& data)
{
    SetProperty(action, data);
}

std::wstring MsiInstall::GetActionData()
{
    return GetProperty(L"CustomActionData");
}

std::wstring MsiInstall::GetFormattedString(const std::wstring& s)
{
    if (s.empty())
    {
        // a NULL record with one item renderes as 1: <blank>
        return L"";
    }

	MsiHandle hRecord = ::MsiCreateRecord(1);

    CHECK_WIN32_DWORD(::MsiRecordSetString(hRecord, 0, s.c_str()),
        L"Error in MsiRecordSetString");

	DWORD cch = 0;

    DWORD rc = ::MsiFormatRecord(_h, hRecord, NULL, & cch);
    CHECK_WIN32_DWORD(rc == ERROR_MORE_DATA,
        L"Error in MsiFormatRecord");

	std::wstring result;
	if (cch != 0)
	{
		result.resize(cch++);

		CHECK_WIN32_DWORD(MsiFormatRecord(_h, hRecord, & * result.begin(), & cch),
			L"Error in MsiFormatRecord (2)");
	}

    return result;
}

bool MsiInstall::EvaluateCondition(const std::wstring& condition)
{
    MSICONDITION msiCondition = ::MsiEvaluateCondition(_h, condition.c_str());

    CHECK_BOOL(MSICONDITION_ERROR != msiCondition,
        L"Error evaluating condition \"" << condition << "\"");

    return (MSICONDITION_TRUE == msiCondition ? true : false);
}

bool MsiInstall::IsComponentInstalling(const std::wstring& component)
{
	INSTALLSTATE component_installed = INSTALLSTATE_UNKNOWN;
	INSTALLSTATE component_action = INSTALLSTATE_UNKNOWN;
	GetComponentState(component, component_installed, component_action);

	return (INSTALLSTATE_LOCAL == component_action 
		|| INSTALLSTATE_SOURCE == component_action 
		|| (INSTALLSTATE_DEFAULT == component_action 
		&& (INSTALLSTATE_LOCAL == component_installed 
		|| INSTALLSTATE_SOURCE == component_installed)));
}

bool MsiInstall::IsComponentUnInstalling(const std::wstring& component)
{
	INSTALLSTATE component_installed = INSTALLSTATE_UNKNOWN;
	INSTALLSTATE component_action = INSTALLSTATE_UNKNOWN;
	GetComponentState(component, component_installed, component_action);

	return ((INSTALLSTATE_ABSENT == component_action 
		|| INSTALLSTATE_REMOVED == component_action) 
		&& (INSTALLSTATE_LOCAL == component_installed 
		|| INSTALLSTATE_SOURCE == component_installed));
}

bool MsiInstall::IsComponentReInstalling(const std::wstring& component)
{
	INSTALLSTATE component_installed = INSTALLSTATE_UNKNOWN;
	INSTALLSTATE component_action = INSTALLSTATE_UNKNOWN;
	GetComponentState(component, component_installed, component_action);

	return ((INSTALLSTATE_LOCAL == component_action 
		|| INSTALLSTATE_SOURCE == component_action 
		|| INSTALLSTATE_DEFAULT == component_action) 
		&& (INSTALLSTATE_LOCAL == component_installed 
		|| INSTALLSTATE_SOURCE == component_installed));
}

bool MsiInstall::IsInstalling()
{
	//! \todo This has to be wrong for reinstall
	return EvaluateCondition(L"NOT Installed");
}

bool MsiInstall::IsRollback()
{
    return (TRUE == ::MsiGetMode(_h, MSIRUNMODE_ROLLBACK));
}

bool MsiInstall::IsUnInstalling()
{
	//! \todo This has to be wrong for reinstall
	return EvaluateCondition(L"Installed");
}

void MsiInstall::DoAction(const std::wstring& action)
{
    CHECK_WIN32_DWORD(::MsiDoActionW(_h, action.c_str()),
        L"Error executing action: " << action);
}

void MsiInstall::GetComponentState(const std::wstring& component, INSTALLSTATE& component_installed, INSTALLSTATE& component_action)
{
	// allows overriding any component state, unit tests cannot call ::MsiGetComponentState
	std::wstring component_installed_s = GetProperty(component + L"_Installed");
	std::wstring component_action_s = GetProperty(component + L"_Action");
	if (! component_action_s.empty() && ! component_installed_s.empty()) 
	{
		component_installed = (INSTALLSTATE) AppSecInc::StringUtils::stringToLong(component_installed_s);
		component_action = (INSTALLSTATE) AppSecInc::StringUtils::stringToLong(component_action_s);
	}
	else
	{
		CHECK_WIN32_DWORD(::MsiGetComponentState(_h, component.c_str(), & component_installed, & component_action),
			L"Error calling MsiGetComponentState for \"" << component << L"\"");
	}
}