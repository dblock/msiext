#include "StdAfx.h"

CA_API UINT __stdcall JavaArchive_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	// process java archives
    std::wstring xml = msiInstall.GetActionData();
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);
	
	std::wstring jarexe = L"jar.exe";
	// attempt to construct a default path for jar.exe
	wchar_t java_home[MAX_PATH] = { 0 };
	::GetEnvironmentVariableW(L"JAVA_HOME", java_home, sizeof(java_home));
	if (wcslen(java_home))
	{
		msiInstall.LogInfo(L"JavaArchive_Deferred - JAVA_HOME", java_home);
		jarexe.insert(0, L"\\bin\\");
		jarexe.insert(0, java_home);
	}

	// process jars
    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"/JavaArchives/JavaArchive");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
		// optional path to jar.exe
		std::wstring toolpath = xmlDocument.GetAttributeValue(L"toolpath", row, L"");
		if (! toolpath.empty())
		{
			msiInstall.LogInfo(L"JavaArchive_Deferred - ToolPath", toolpath);
		}

		if (toolpath.empty()) toolpath = jarexe;
		else if (AppSecInc::File::DirectoryExists(toolpath)) toolpath.append(L"\\jar.exe");

		// run the command
		if (! AppSecInc::File::FileExists(toolpath))
		{
			THROW(toolpath << L" does not exist");
		}
		
		std::wstringstream command;
		command << L"\"" << toolpath << L"\"";

		std::wstring id = xmlDocument.GetAttributeValue(L"id", row); // jar file affected			
		std::wstring operation = xmlDocument.GetAttributeValue(L"operation", row); // operation performed, combination of flags, eg. "cvf" or "cvfm"			
		std::wstring jarfile = xmlDocument.GetAttributeValue(L"jarfile", row); // jar file affected
		std::wstring directory = xmlDocument.GetAttributeValue(L"directory", row); // jar file affected
		std::wstring manifestfile = xmlDocument.GetAttributeValue(L"manifestfile", row, L""); // manifest file
		std::wstring condition = xmlDocument.GetAttributeValue(L"condition", row, L"1"); // manifest file

		command << L" " << operation << L" \"" << jarfile << "\"";
		if (! manifestfile.empty()) command << L" " << manifestfile;

		if (! condition.empty() && condition != L"1")
		{
			std::wstringstream status;
			status << L"Skipping " << id << L" (" << jarfile << L"), condition = " << condition;
			msiInstall.LogInfo(L"JavaArchive_Deferred", status.str());
			continue;
		}
		
		// get the list of files
		MSXML2::IXMLDOMNodeListPtr files = xmlDocument.SelectNodes(L"JavaArchiveFiles/JavaArchiveFile", row);
		MSXML2::IXMLDOMNodePtr file = NULL;
		while (NULL != (file = files->nextNode()))
		{
			// filename
			std::wstring fileid = xmlDocument.GetAttributeValue(L"id", file);
			std::wstring filename = xmlDocument.GetAttributeValue(L"name", file);
			std::wstring filedirectory = xmlDocument.GetAttributeValue(L"directory", file, L"");
			std::wstring filecondition = xmlDocument.GetAttributeValue(L"condition", file, L"1");

			if (! filecondition.empty() && filecondition != L"1")
			{
				std::wstringstream status;
				status << L"Skipping " << fileid << L" (" << filename << L") in " << jarfile << L", condition = " << condition;
				msiInstall.LogInfo(L"JavaArchive_Deferred", status.str());
				continue;
			}

			if (! filedirectory.empty()) 
			{
				// jar.exe doesn't like paths that end with a backslash
				AppSecInc::StringUtils::rtrim(filedirectory, L"\\");
				command << L" -C \"" << filedirectory << L"\"";
			}

			command << L" \"" << filename << L"\"";
		}

		msiInstall.LogInfo(L"JavaArchive_Deferred", command.str());

        AppSecInc::File::Process p;
        p.CreateWithRedirectedOutput(command.str(), directory);
        bool finished = false;
        while (! finished)
        {
            msiInstall.LogInfo(_T(__FUNCTION__), AppSecInc::StringUtils::mb2wc(p.ReadLine(finished)));
        }
        
        p.Wait();

		DWORD dwExitCode = p.GetExitCode();

		// this has a consequence of leaving jar.exe on the system on purpose,
		// it lets you rerun the failed command from the log output
		CHECK_BOOL(dwExitCode == 0,
			L"Error executing \"" << command.str() << L"\", non-zero error code returned: " << dwExitCode);
    }

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall JavaArchive_Immediate(MSIHANDLE hInstall)
{
    // immediate custom action, evaluate conditions and update the custom action table data
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	/* 
		This produces an xml like this, and adds it as JavaArchive_Deferred property:

		 <JavaArchives jarexe="">
		  <JavaArchive jarfile="Something.jar" toolpath="" condition="1" operation="xvf" manifestFile="">
		   <JavaArchiveFiles /> 
		  </JavaArchive>
		  <JavaArchive jarfile="Something.jar" toolpath="" condition="" operation="cvf" manifestfile="">
		   <JavaArchiveFiles>
			<JavaArchiveFile id="*" name="file" directory="directory" condition="1" /> 
			<JavaArchiveFile id="*" name="file" directory="" condition="0" /> 
		   </JavaArchiveFiles>
		  </JavaArchive>
		 </JavaArchives>

	*/

	// combined xml document
	AppSecInc::Xml::XmlDocument combined_xml_document;
	combined_xml_document.Create();
	MSXML2::IXMLDOMNodePtr combined_xml_root = combined_xml_document.AppendChild(L"JavaArchives");

	// java archive
    AppSecInc::Xml::XmlDocument javaarchive_xml_document;
    javaarchive_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `JavaArchive`"));

	// java archive files
    AppSecInc::Xml::XmlDocument javaarchivefile_xml_document;
    javaarchivefile_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `JavaArchiveFile`"));

    MSXML2::IXMLDOMNodeListPtr javaarchive_rows = javaarchive_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr javaarchive_row = NULL;
    while (NULL != (javaarchive_row = javaarchive_rows->nextNode()))
    {
        // evaluate condition that can be specified that says whether to process the jar
        MSXML2::IXMLDOMNodePtr condition_node = javaarchive_row->selectSingleNode(L"Data[@Column=\"Condition\"]");
        if (condition_node != NULL)
        {
            std::wstring condition = condition_node->text;
            if (! condition.empty())
            {
                MSICONDITION msiCondition = ::MsiEvaluateCondition(hInstall, condition.c_str());

                CHECK_BOOL(MSICONDITION_ERROR != msiCondition,
                    L"Error evaluating condition \"" << condition << "\"");

                condition_node->put_text(_bstr_t(AppSecInc::StringUtils::toString(msiCondition).c_str()));
            }
        }			

		std::wstring javaarchive_id = javaarchive_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", javaarchive_row);
		MSXML2::IXMLDOMNodePtr javaarchive_node = combined_xml_document.AppendChild(L"JavaArchive", combined_xml_root);
		combined_xml_document.SetAttribute(L"id", javaarchive_id, javaarchive_node);
		combined_xml_document.SetAttribute(L"jarfile", javaarchive_xml_document.GetNodeValue(L"Data[@Column=\"JarFile\"]", javaarchive_row), javaarchive_node);
		combined_xml_document.SetAttribute(L"toolpath", javaarchive_xml_document.GetNodeValue(L"Data[@Column=\"ToolPath\"]", javaarchive_row), javaarchive_node);
		combined_xml_document.SetAttribute(L"directory", javaarchive_xml_document.GetNodeValue(L"Data[@Column=\"Directory\"]", javaarchive_row), javaarchive_node);
		combined_xml_document.SetAttribute(L"condition", javaarchive_xml_document.GetNodeValue(L"Data[@Column=\"Condition\"]", javaarchive_row), javaarchive_node);
		combined_xml_document.SetAttribute(L"operation", javaarchive_xml_document.GetNodeValue(L"Data[@Column=\"Operation\"]", javaarchive_row), javaarchive_node);
		combined_xml_document.SetAttribute(L"manifestfile", javaarchive_xml_document.GetNodeValue(L"Data[@Column=\"ManifestFile\"]", javaarchive_row), javaarchive_node);

		// append the files xml to the jar node
		MSXML2::IXMLDOMNodePtr javaarchivefiles_node = combined_xml_document.AppendChild(L"JavaArchiveFiles", javaarchive_node);

		// find all JavaArchiveFiles which belong to this JavaArchive, add to the xml
		MSXML2::IXMLDOMNodeListPtr javaarchivefile_rows = javaarchivefile_xml_document.SelectNodes(L"//Row");
		MSXML2::IXMLDOMNodePtr javaarchivefile_row = NULL;
		while (NULL != (javaarchivefile_row = javaarchivefile_rows->nextNode()))
		{
			// \todo Change XPATH to fetch only rows that match ID
			std::wstring javaarchivefile_id = javaarchivefile_xml_document.GetNodeValue(L"Data[@Column=\"JavaArchiveId\"]", javaarchivefile_row);
			if (javaarchivefile_id != javaarchive_id)
				continue;

			// evaluate condition that can be specified that says whether to evalute the jar file
			MSXML2::IXMLDOMNodePtr javaarchivefile_condition_node = javaarchivefile_row->selectSingleNode(L"Data[@Column=\"Condition\"]");
			if (javaarchivefile_condition_node != NULL)
			{
				std::wstring condition = javaarchivefile_condition_node->text;
				if (! condition.empty())
				{
					MSICONDITION msiCondition = ::MsiEvaluateCondition(hInstall, condition.c_str());

					CHECK_BOOL(MSICONDITION_ERROR != msiCondition,
						L"Error evaluating condition \"" << condition << "\"");

					javaarchivefile_condition_node->put_text(_bstr_t(AppSecInc::StringUtils::toString(msiCondition).c_str()));
				}
			}

			// append the file xml to the jar node
			MSXML2::IXMLDOMNodePtr javaarchivefile_node = combined_xml_document.AppendChild(L"JavaArchiveFile", javaarchivefiles_node);
			combined_xml_document.SetAttribute(L"id", javaarchivefile_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", javaarchivefile_row), javaarchivefile_node);
			combined_xml_document.SetAttribute(L"name", javaarchivefile_xml_document.GetNodeValue(L"Data[@Column=\"Name\"]", javaarchivefile_row), javaarchivefile_node);
			combined_xml_document.SetAttribute(L"directory", javaarchivefile_xml_document.GetNodeValue(L"Data[@Column=\"Directory\"]", javaarchivefile_row), javaarchivefile_node);
			combined_xml_document.SetAttribute(L"condition", javaarchivefile_xml_document.GetNodeValue(L"Data[@Column=\"Condition\"]", javaarchivefile_row), javaarchivefile_node);
		}
    }

    msiInstall.SetActionData(L"JavaArchive_Deferred", combined_xml_document.GetXml());

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
