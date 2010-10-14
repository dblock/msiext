#pragma once

/*!
\brief Select the text value of an xml node in a document.
\param XML_FILENAME XML file
\param XML_XPATH XPATH to select, if more than one node matches the first one only is used
\param XML_NODEVALUE MSI property that contains the result after execution

\par Example:

Suppose that we're upgrading an existing product (OLDERVERSIONBEINGUPGRADED is defined somewhere in the MSI
sequence), which has a configuration file called config\\Config.xml. This file contains a \b Configuration 
node with \b Host and \b Port. 

The following code declares the custom actions that will prepare the configuration parameters for the
Xml_SelectNodeValue custom action. Each action must be named individually.

\code
 <!-- set the filename to config\Config.xml -->
 <CustomAction Id="Xml_SetFileName" Property="XML_FILENAME" Value="[INSTALLDIR]\config\Config.xml" Execute="immediate" />
 <!-- select /Configuration/Host into the HOST property -->
 <CustomAction Id="Xml_SelectNodeValue_Host_XPath" Property="XML_XPATH" Value="/Configuration/Host" Execute="immediate" />
 <CustomAction Id="Xml_SelectNodeValue_Host" BinaryKey="XmlTools" DllEntry="Xml_SelectNodeValue" Execute="immediate" Return="check" />
 <CustomAction Id="Xml_GetNodeValue_Host" Property="HOST" Value="[XML_NODEVALUE]" Execute="immediate" />
 <!-- select /Configuration/Port into the PORT property -->
 <CustomAction Id="Xml_SelectNodeValue_Port_XPath" Property="XML_XPATH" Value="/Configuration/Port" Execute="immediate" />
 <CustomAction Id="Xml_SelectNodeValue_Port" BinaryKey="XmlTools" DllEntry="Xml_SelectNodeValue" Execute="immediate" Return="check" />
 <CustomAction Id="Xml_GetNodeValue_Port" Property="PORT" Value="[XML_NODEVALUE]" Execute="immediate" />
 <!-- custom action binary -->
 <Binary Id="XmlTools" SourceFile="$(var.BinDir)\XmlTools.dll" />
\endcode

These custom actions are then inserted into InstallExecuteSequence. Once they are executed, two properties
\b HOST and \b PORT are defined.

\code
<InstallExecuteSequence>
 <Custom Action="Xml_SetFileName" After="FindRelatedProducts">OLDERVERSIONBEINGUPGRADED</Custom>      
 <!-- get /Configuration/Host -->
 <Custom Action="Xml_SelectNodeValue_Host_XPath" After="Xml_SetFileName">OLDERVERSIONBEINGUPGRADED</Custom>
 <Custom Action="Xml_SelectNodeValue_Host" After="Xml_SelectNodeValue_Host_XPath">OLDERVERSIONBEINGUPGRADED</Custom>
 <Custom Action="Xml_GetNodeValue_Port" After="Xml_SelectNodeValue_Host">OLDERVERSIONBEINGUPGRADED</Custom>
 <!-- get /Configuration/Port -->
 <Custom Action="Xml_SelectNodeValue_Port_XPath" After="Xml_GetNodeValue_Port">OLDERVERSIONBEINGUPGRADED</Custom>
 <Custom Action="Xml_SelectNodeValue_Port" After="Xml_SelectNodeValue_Port_XPath">OLDERVERSIONBEINGUPGRADED</Custom>
 <Custom Action="Xml_GetNodeValue_Port" After="Xml_SelectNodeValue_Port">OLDERVERSIONBEINGUPGRADED</Custom>
 ...
</InstallExecuteSequence>
\endcode
*/
CA_API UINT __stdcall Xml_SelectNodeValue(MSIHANDLE hInstall);

/*!
\brief Select the XML value of a node in a document.
\param XML_FILENAME XML file
\param XML_XPATH XPATH to select, if more than one node matches the first one only is used
\param XML_NODEXML MSI property that contains the result after execution
*/
CA_API UINT __stdcall Xml_SelectNodeXml(MSIHANDLE hInstall);

/*!
\brief Select the text value of an xml node attribute.
\param XML_FILENAME XML file
\param XML_XPATH XPATH to select, if more than one node matches the first one only is used
\param XML_ATTRIBUTENAME attribute name
\param XML_ATTRIBUTEVALUE MSI property that contains the result after execution
*/
CA_API UINT __stdcall Xml_SelectNodeAttributeValue(MSIHANDLE hInstall);

/*!
\brief Transform an XML document with XSLT into a new XML document.
\param XML_FILENAME XML file to transform
\param XSLT_FILENAME XSLT file to use for the transform
\param XSLT_RESULT_FILENAME file that will contain the transformed output
*/
CA_API UINT __stdcall Xml_XslTransform(MSIHANDLE hInstall);