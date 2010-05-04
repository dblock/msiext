#include "StdAfx.h"
#include "XmlDocument.h"

using namespace AppSecInc::Xml;

XmlDocument::XmlDocument()
{
	
}

std::wstring XmlDocument::GetParseError() const
{
    MSXML2::IXMLDOMParseErrorPtr error;        
    _document->get_parseError(& error);
	std::wstringstream error_s;
    if (error != NULL)
    {
        CComBSTR bstrReason;
        long errorCode = 0;
        long lineNumber = 0;
        long linePosition = 0;
        error->get_errorCode(& errorCode);
        error->get_reason(& bstrReason);
        error->get_line(& lineNumber);
        error->get_linepos(& linePosition);
        error_s << L"error " << errorCode << L" at " << lineNumber << L":" << linePosition 
			<< L" - " << (bstrReason == NULL ? L"unknown error" : static_cast<LPCWSTR>(bstrReason));            
    }

	return error_s.str();
}

void XmlDocument::Create(const CLSID clsid)
{
    if (NULL != _document)
    {
        _document.Release();
        _loaded = false;
    }

    CHECK_HR(_document.CreateInstance(clsid),
	    L"Error creating XML document object");

	CHECK_HR(_document->put_async(VARIANT_FALSE),
        L"Error in XMLDOMDocument->put_async");

    _loaded = true;
}

void XmlDocument::Load(const std::wstring& filename, const CLSID clsid)
{
    if (NULL != _document)
    {
        _document.Release();
        _loaded = false;
    }

    CHECK_BOOL(! filename.empty(),
        L"Missing filename");

    CHECK_HR(_document.CreateInstance(clsid),
	    L"Error creating XML document object");

	CHECK_HR(_document->put_async(VARIANT_FALSE),
        L"Error in XMLDOMDocument->put_async");

    CHECK_HR(_document->put_validateOnParse(VARIANT_FALSE),
	    L"Error in XMLDOMDocument->put_validateOnParse");

    CHECK_HR(_document->put_resolveExternals(VARIANT_FALSE),
        L"Error in XMLDOMDocument->put_resolveExternals");
    
    VARIANT_BOOL xmldoc_loaded = _document->load(CComVariant(filename.c_str()));
    
    if (xmldoc_loaded == VARIANT_FALSE)
    {
		std::wstringstream error_s;
		error_s << L"Error loading " << filename << L": " << GetParseError();
        THROW(error_s.str());
    }

    _loaded = true;
}

void XmlDocument::LoadXml(const std::wstring& xml, const CLSID clsid)
{
    if (NULL != _document)
    {
        _document.Release();
        _loaded = false;
    }

    CHECK_BOOL(! xml.empty(),
        L"Missing xml");

    CHECK_HR(_document.CreateInstance(clsid),
        L"Error creating XML document object");

    CHECK_HR(_document->put_async(VARIANT_FALSE),
        L"Error in XMLDOMDocument->put_async");

    CHECK_HR(_document->put_validateOnParse(VARIANT_FALSE),
        L"Error in XMLDOMDocument->put_validateOnParse");

    CHECK_HR(_document->put_resolveExternals(VARIANT_FALSE),
        L"Error in XMLDOMDocument->put_resolveExternals");
    
    VARIANT_BOOL xmldoc_loaded = _document->loadXML(_bstr_t(xml.c_str()));
    
    if (xmldoc_loaded == VARIANT_FALSE)
    {
        MSXML2::IXMLDOMParseErrorPtr error;        
        _document->get_parseError(& error);
		std::wstringstream error_s;
		error_s << L"Error loading xml";
        if (error != NULL)
        {
            CComBSTR bstrReason;
            long errorCode = 0;
            long lineNumber = 0;
            long linePosition = 0;
            error->get_errorCode(& errorCode);
            error->get_reason(& bstrReason);
            error->get_line(& lineNumber);
            error->get_linepos(& linePosition);
            error_s << L", error " << errorCode << L" at " << lineNumber << L":" << linePosition 
                << L" - " << static_cast<LPCWSTR>(bstrReason);            
        }

        THROW(error_s.str());
    }

    _loaded = true;
}

MSXML2::IXMLDOMNodePtr XmlDocument::SelectNode(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
	MSXML2::IXMLDOMNodePtr node = FindNode(xpath, parent);

    CHECK_BOOL(node != NULL,
		L"Invalid xpath: " << xpath);

    return node.Detach();
}

MSXML2::IXMLDOMNodeListPtr XmlDocument::SelectNodes(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
	MSXML2::IXMLDOMNodeListPtr nodes = FindNodes(xpath, parent);

    CHECK_BOOL(nodes != NULL,
		L"Invalid xpath: " << xpath);

	return nodes.Detach();
}

MSXML2::IXMLDOMNodePtr XmlDocument::FindNode(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
    CHECK_BOOL(! xpath.empty(),
        L"Missing xpath");

    CHECK_BOOL(_loaded,
        L"Document not loaded");

    MSXML2::IXMLDOMNodePtr node = (NULL != parent) 
        ? parent->selectSingleNode(_bstr_t(xpath.c_str())) 
        : _document->selectSingleNode(_bstr_t(xpath.c_str()));

	return (node == NULL) ? NULL : node.Detach();
}

MSXML2::IXMLDOMNodeListPtr XmlDocument::FindNodes(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
	MSXML2::IXMLDOMNode * pnode = NULL;

    CHECK_BOOL(! xpath.empty(),
        L"Missing xpath");

	CHECK_BOOL(_loaded,
        L"Document not loaded");

    MSXML2::IXMLDOMNodeListPtr nodes;

	if (parent != NULL)
	{
		MSXML2::IXMLDOMNodeListPtr nodes;
		HRESULT hr = parent->raw_selectNodes(_bstr_t(xpath.c_str()), & nodes);
		return SUCCEEDED(hr) ? nodes.Detach() : NULL;
	}
	else
	{
		MSXML2::IXMLDOMNodeListPtr nodes;
		HRESULT hr = _document->raw_selectNodes(_bstr_t(xpath.c_str()), & nodes);
		return SUCCEEDED(hr) ? nodes.Detach() : NULL;
	}
}

bool XmlDocument::HasNode(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
	return (NULL != FindNode(xpath, parent));
}

bool XmlDocument::HasNodes(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
	return (NULL != FindNodes(xpath, parent));
}

bool XmlDocument::GetNodeBoolValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
	return GetNodeBoolValue(SelectNode(xpath, parent));
}

std::wstring XmlDocument::GetNodeValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent, const std::wstring& defaultvalue) const
{
	MSXML2::IXMLDOMNodePtr node = FindNode(xpath, parent);
	return NULL != node ? GetNodeValue(node) : defaultvalue;
}

bool XmlDocument::GetNodeBoolValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent, bool defaultvalue) const
{
	MSXML2::IXMLDOMNodePtr node = FindNode(xpath, parent);
	return NULL != node ? GetNodeBoolValue(node) : defaultvalue;
}

std::wstring XmlDocument::GetNodeValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
	return GetNodeValue(SelectNode(xpath, parent));
}

std::wstring XmlDocument::GetNodeXml(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
	return GetNodeXml(SelectNode(xpath, parent));
}

std::wstring XmlDocument::GetNodeXml(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent, const std::wstring& defaultvalue) const
{
	MSXML2::IXMLDOMNodePtr node = FindNode(xpath, parent);
	return NULL != node ? GetNodeXml(node) : defaultvalue;
}

std::wstring XmlDocument::GetXml() const
{
	CHECK_BOOL(_loaded,
        L"Document not loaded");

    CComBSTR result;

    CHECK_HR(_document->get_xml(& result),
        L"Error getting node xml");

	return static_cast<LPCWSTR>(result);
}

std::wstring XmlDocument::GetAttributeValue(const std::wstring& xpath, const std::wstring& attributename, MSXML2::IXMLDOMNode * parent) const
{
    CHECK_BOOL(! attributename.empty(),
        L"Missing attribute name");

    MSXML2::IXMLDOMNodePtr node = SelectNode(xpath, parent);
	MSXML2::IXMLDOMAttributePtr attribute = SelectAttribute(attributename, node);
	return GetAttributeValue(attribute);
}

std::wstring XmlDocument::XslTransform(const std::wstring xslt_filename)
{
    XmlDocument xslt;
    xslt.Load(xslt_filename, MSXML2::CLSID_FreeThreadedDOMDocument);

	CComBSTR bstrOut;

	CHECK_HR(_document->raw_transformNode(xslt._document, & bstrOut),
		L"Error transforming document: " << xslt.GetParseError());

	return (LPCWSTR) bstrOut;
}

MSXML2::IXMLDOMNodePtr XmlDocument::AppendChild(const std::wstring& name, MSXML2::IXMLDOMNode * parent, const _variant_t & type, const LPCWSTR pszNamespaceUri)
{
	CHECK_BOOL(_loaded,
        L"Document not loaded");

    MSXML2::IXMLDOMNodePtr node = _document->createNode(
        type, _bstr_t(name.c_str()), _bstr_t(pszNamespaceUri));

    CHECK_BOOL(NULL != node,
        L"Error creating node \"" << name << "\"");

    return (parent != NULL) 
        ? parent->appendChild(node) 
        : _document->appendChild(node);
}

MSXML2::IXMLDOMAttributePtr XmlDocument::SetAttribute(const std::wstring& name, const std::wstring& value, MSXML2::IXMLDOMNode * node)
{
	CHECK_BOOL(_loaded,
        L"Document not loaded");

	CHECK_BOOL(node != NULL,
        L"Missing node");

    MSXML2::IXMLDOMAttributePtr attribute = _document->createAttribute(_bstr_t(name.c_str()));
    CHECK_HR(attribute->put_text(_bstr_t(value.c_str())),
        L"Error setting attribute value");

    return node->attributes->setNamedItem(attribute);
}

MSXML2::IXMLDOMAttributePtr XmlDocument::FindAttribute(const std::wstring& name, MSXML2::IXMLDOMNode * node) const
{
    CHECK_BOOL(! name.empty(),
        L"Missing name");

	CHECK_BOOL(_loaded,
        L"Document not loaded");

    MSXML2::IXMLDOMNodePtr attribute;

	CHECK_HR(node->attributes->raw_getNamedItem(_bstr_t(name.c_str()), & attribute),
		L"Error getting attribute: " << name);

	return attribute != NULL ? attribute.Detach() : NULL;
}

MSXML2::IXMLDOMAttributePtr XmlDocument::SelectAttribute(const std::wstring& name, MSXML2::IXMLDOMNode * node) const
{
    MSXML2::IXMLDOMNodePtr attribute = FindAttribute(name, node);

    CHECK_BOOL(attribute != NULL,
		L"Invalid attribute name: " << name);

    return attribute.Detach();
}


bool XmlDocument::HasAttribute(const std::wstring& name, MSXML2::IXMLDOMNode * node) const
{
	return (NULL != FindAttribute(name, node));
}

bool XmlDocument::GetAttributeBoolValue(const std::wstring& name, MSXML2::IXMLDOMNode * node) const
{
    std::wstring value = GetAttributeValue(name, node);
    std::wstring l_value = value;
    AppSecInc::StringUtils::lowercase(l_value);
    bool result = false;
    if (l_value == L"true" || l_value == L"1") result = true;
    else if (l_value == L"false" || l_value == L"0") result = false;
	else { THROW(L"invalid boolean value: " << value); }
    return result;
}

std::wstring XmlDocument::GetAttributeValue(const std::wstring& name, MSXML2::IXMLDOMNode * node, const std::wstring& defaultvalue) const
{
	MSXML2::IXMLDOMAttributePtr attribute = FindAttribute(name, node);
	
	return attribute != NULL 
		? GetAttributeValue(attribute) 
		: defaultvalue;
}

bool XmlDocument::GetAttributeBoolValue(const std::wstring& name, MSXML2::IXMLDOMNode * node, bool defaultvalue) const
{
	MSXML2::IXMLDOMAttributePtr attribute = FindAttribute(name, node);
	
	return attribute != NULL 
		? GetAttributeBoolValue(attribute) 
		: defaultvalue;
}

std::wstring XmlDocument::GetAttributeValue(const std::wstring& name, MSXML2::IXMLDOMNode * node) const
{
	return GetAttributeValue(SelectAttribute(name, node));	
}

std::wstring XmlDocument::GetAttributeValue(MSXML2::IXMLDOMAttribute * attribute) const
{
	CHECK_BOOL(attribute != NULL,
		L"Missing attribute");

	CComBSTR result;
	CHECK_HR(attribute->get_text(& result),
        L"Error getting node text");

	return static_cast<LPCWSTR>(result);
}

std::wstring XmlDocument::GetNodeXml(MSXML2::IXMLDOMNode * node) const
{
	CHECK_BOOL(node != NULL,
		L"Missing node");

	CComBSTR result;
    CHECK_HR(node->get_xml(& result),
        L"Error getting node XML");

	return static_cast<LPCWSTR>(result);
}

std::wstring XmlDocument::GetNodeValue(MSXML2::IXMLDOMNode * node) const
{
	CHECK_BOOL(node != NULL,
		L"Missing node");

	CComBSTR result;
	CHECK_HR(node->get_text(& result),
		L"Error getting node text");
	return static_cast<LPCWSTR>(result);
}

bool XmlDocument::GetNodeBoolValue(MSXML2::IXMLDOMNode * node) const
{
	return wstring2bool(GetNodeValue(node));
}

bool XmlDocument::GetAttributeBoolValue(MSXML2::IXMLDOMAttribute * attribute) const
{
	return wstring2bool(GetAttributeValue(attribute));
}

bool XmlDocument::wstring2bool(const std::wstring& value)
{
	std::wstring l_value = value;
    AppSecInc::StringUtils::lowercase(l_value);
    bool result = false;
    if (l_value == L"true" || l_value == L"1") result = true;
    else if (l_value == L"false" || l_value == L"0") result = false;
	else 
	{ 
		THROW(L"invalid boolean value: " << value); 
	}
    return result;
}
