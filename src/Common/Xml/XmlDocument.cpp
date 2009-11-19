#include "StdAfx.h"
#include "XmlDocument.h"

using namespace AppSecInc::Xml;

XmlDocument::XmlDocument()
{
	
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
        MSXML2::IXMLDOMParseErrorPtr error;        
        _document->get_parseError(& error);
		std::wstringstream error_s;
		error_s << L"Error loading " << filename;
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
    CHECK_BOOL(! xpath.empty(),
        L"Missing xpath");

	CHECK_BOOL(_loaded,
        L"Document not loaded");

    MSXML2::IXMLDOMNodePtr node;

    node = (NULL != parent) 
        ? parent->selectSingleNode(_bstr_t(xpath.c_str())) 
        : _document->selectSingleNode(_bstr_t(xpath.c_str()));

    CHECK_BOOL(node != NULL,
		L"Invalid xpath: " << xpath);

    return node.Detach();
}

MSXML2::IXMLDOMNodeListPtr XmlDocument::SelectNodes(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
	MSXML2::IXMLDOMNode * pnode = NULL;

    CHECK_BOOL(! xpath.empty(),
        L"Missing xpath");

	CHECK_BOOL(_loaded,
        L"Document not loaded");

    MSXML2::IXMLDOMNodeListPtr nodes;

    nodes = (NULL != parent) 
        ? parent->selectNodes(_bstr_t(xpath.c_str())) 
        : _document->selectNodes(_bstr_t(xpath.c_str()));

    CHECK_BOOL(nodes != NULL,
		L"Invalid xpath: " << xpath);

    return nodes.Detach();
}

bool XmlDocument::HasNode(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
    CHECK_BOOL(! xpath.empty(),
        L"Missing xpath");

    CHECK_BOOL(_loaded,
        L"Document not loaded");

    MSXML2::IXMLDOMNodePtr node;

    node = (NULL != parent) 
        ? parent->selectSingleNode(_bstr_t(xpath.c_str())) 
        : _document->selectSingleNode(_bstr_t(xpath.c_str()));

    return (node != NULL);
}

bool XmlDocument::SelectNodeBoolValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
    std::wstring value = SelectNodeValue(xpath, parent);
    std::wstring l_value = value;
    AppSecInc::StringUtils::lowercase(l_value);
    bool result = false;
    if (l_value == L"true" || l_value == L"1") result = true;
    else if (l_value == L"false" || l_value == L"0") result = false;
	else { THROW(L"invalid boolean value: " << value); }
    return result;
}

std::wstring XmlDocument::SelectNodeValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent, const std::wstring& defaultvalue) const
{
    if (HasNode(xpath, parent))
        return SelectNodeValue(xpath, parent);

    return defaultvalue;
}

bool XmlDocument::SelectNodeBoolValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent, bool defaultvalue) const
{
    if (HasNode(xpath, parent))
        return SelectNodeBoolValue(xpath, parent);

    return defaultvalue;
}

std::wstring XmlDocument::SelectNodeValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
    CHECK_BOOL(! xpath.empty(),
        L"Missing xpath");

    CComBSTR result;
    MSXML2::IXMLDOMNodePtr node;

	node = SelectNode(xpath, parent);

	CHECK_HR(node->get_text(& result),
        L"Error getting node text.");

	return static_cast<LPCWSTR>(result);
}

std::wstring XmlDocument::SelectNodeXml(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent) const
{
    CHECK_BOOL(! xpath.empty(),
        L"Missing xpath");

    CComBSTR result;
    MSXML2::IXMLDOMNodePtr node;

    node = SelectNode(xpath, parent);

    CHECK_HR(node->get_xml(& result),
        L"Error getting node text.");

	return static_cast<LPCWSTR>(result);
}

std::wstring XmlDocument::GetXml() const
{
	CHECK_BOOL(_loaded,
        L"Document not loaded");

    CComBSTR result;

    CHECK_HR(_document->get_xml(& result),
        L"Error getting node text.");

	return static_cast<LPCWSTR>(result);
}

std::wstring XmlDocument::SelectNodeAttributeValue(const std::wstring& xpath, const std::wstring& attributename, MSXML2::IXMLDOMNode * parent) const
{
    CHECK_BOOL(! attributename.empty(),
        L"Missing attribute name");

    MSXML2::IXMLDOMNodePtr node = SelectNode(xpath, parent);

    MSXML2::IXMLDOMNamedNodeMapPtr attributes;
    CHECK_HR(node->get_attributes(& attributes),
        L"Error getting node attributes.");

    MSXML2::IXMLDOMNodePtr attribute(attributes->getNamedItem(_bstr_t(attributename.c_str())));

    CComBSTR result;

    if (attribute != NULL)
    {
		CHECK_HR(attribute->get_text(& result),
            L"Error getting value of " << attributename);
    }

	return result != NULL ? static_cast<LPCWSTR>(result) : L"";
}

void XmlDocument::XslTransform(const std::wstring& xslt_filename, const std::wstring& target_filename)
{
    CHECK_BOOL(! xslt_filename.empty(),
        L"Missing xslt filename");

    CHECK_BOOL(! target_filename.empty(),
        L"Missing target filename");

    XmlDocument xslt;
    xslt.Load(xslt_filename, MSXML2::CLSID_FreeThreadedDOMDocument);

    MSXML2::IXMLDOMDocumentPtr output;
    CHECK_HR(output.CreateInstance(MSXML2::CLSID_DOMDocument),
        L"Error creating output document");

    CComPtr<IDispatch> pdispatch;
    CHECK_HR(output->QueryInterface(IID_IDispatch, (void **) & pdispatch),
        L"Error getting IDispatch interface from output document");

    VARIANT var;
    var.vt = VT_DISPATCH;
    var.pdispVal = pdispatch;

    CHECK_HR(_document->transformNodeToObject(xslt._document, var),
        L"Error transforming document");

    CHECK_HR(output->save(CComVariant(target_filename.c_str())),
        L"Error saving " << target_filename);
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


MSXML2::IXMLDOMAttributePtr XmlDocument::SelectAttribute(const std::wstring& name, MSXML2::IXMLDOMNode * node) const
{
    CHECK_BOOL(! name.empty(),
        L"Missing name");

	CHECK_BOOL(_loaded,
        L"Document not loaded");

    MSXML2::IXMLDOMNodePtr attribute;

	CHECK_HR(node->attributes->raw_getNamedItem(_bstr_t(name.c_str()), & attribute),
		L"Error getting attribute: " << name);

    CHECK_BOOL(attribute != NULL,
		L"Invalid attribute name: " << name);

    return attribute.Detach();
}


bool XmlDocument::HasAttribute(const std::wstring& name, MSXML2::IXMLDOMNode * node) const
{
	CHECK_BOOL(! name.empty(),
        L"Missing name");

	CHECK_BOOL(_loaded,
        L"Document not loaded");

    MSXML2::IXMLDOMNodePtr attribute;

	CHECK_HR(node->attributes->raw_getNamedItem(_bstr_t(name.c_str()), & attribute),
		L"Error getting attribute: " << name);

	return (attribute != NULL);
}

bool XmlDocument::SelectAttributeBoolValue(const std::wstring& name, MSXML2::IXMLDOMNode * node) const
{
    std::wstring value = SelectAttributeValue(name, node);
    std::wstring l_value = value;
    AppSecInc::StringUtils::lowercase(l_value);
    bool result = false;
    if (l_value == L"true" || l_value == L"1") result = true;
    else if (l_value == L"false" || l_value == L"0") result = false;
	else { THROW(L"invalid boolean value: " << value); }
    return result;
}

std::wstring XmlDocument::SelectAttributeValue(const std::wstring& name, MSXML2::IXMLDOMNode * node, const std::wstring& defaultvalue) const
{
    if (HasAttribute(name, node))
        return SelectAttributeValue(name, node);

    return defaultvalue;
}

bool XmlDocument::SelectAttributeBoolValue(const std::wstring& name, MSXML2::IXMLDOMNode * node, bool defaultvalue) const
{
    if (HasNode(name, node))
        return SelectAttributeBoolValue(name, node);

    return defaultvalue;
}

std::wstring XmlDocument::SelectAttributeValue(const std::wstring& name, MSXML2::IXMLDOMNode * node) const
{
    CHECK_BOOL(! name.empty(),
        L"Missing name");

    CComBSTR result;
    MSXML2::IXMLDOMAttributePtr attribute;

	attribute = SelectAttribute(name, node);

	CHECK_HR(attribute->get_text(& result),
        L"Error getting node text.");

	return static_cast<LPCWSTR>(result);
}