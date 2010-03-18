#pragma once

namespace AppSecInc
{
    namespace Xml
    {
        //! An MSXML document
        class XmlDocument
        {
        private:
            bool _loaded;
            MSXML2::IXMLDOMDocumentPtr _document;
        public:
            XmlDocument();
            //! create an empty xml document
            void Create(const CLSID clsid = MSXML2::CLSID_DOMDocument);
	        //! load an xml document
            void Load(const std::wstring& filename, const CLSID clsid = MSXML2::CLSID_DOMDocument);
	        //! load an xml buffer
            void LoadXml(const std::wstring& xml, const CLSID clsid = MSXML2::CLSID_DOMDocument);
	        //! has node
            bool HasNode(const std::wstring& xpath, MSXML2::IXMLDOMNode * = NULL) const;
	        //! select node
            MSXML2::IXMLDOMNodePtr SelectNode(const std::wstring& xpath, MSXML2::IXMLDOMNode * = NULL) const;
            //! select nodes
            MSXML2::IXMLDOMNodeListPtr SelectNodes(const std::wstring& xpath, MSXML2::IXMLDOMNode * = NULL) const;
	        //! select a node and return its boolean value
	        bool SelectNodeBoolValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * = NULL) const;
	        //! select a node and return its boolean value
	        bool SelectNodeBoolValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * parent, bool defaultvalue) const;
	        //! select a node and return its value
	        std::wstring SelectNodeValue(const std::wstring& xpath, MSXML2::IXMLDOMNode * = NULL) const;
	        //! select a node and return its value with a default
            std::wstring SelectNodeValue(const std::wstring& xpath, MSXML2::IXMLDOMNode *, const std::wstring& defaultvalue) const;
	        //! select a node and return its inner xml
	        std::wstring SelectNodeXml(const std::wstring& xpath, MSXML2::IXMLDOMNode * = NULL) const;
            //! get outer xml
            std::wstring GetXml() const;
	        //! select a node, fetch an attribute and return its value
	        std::wstring SelectNodeAttributeValue(const std::wstring& xpath, const std::wstring& attributename, MSXML2::IXMLDOMNode * = NULL) const;
            //! append a new node
            MSXML2::IXMLDOMNodePtr AppendChild(const std::wstring& name, MSXML2::IXMLDOMNode * parent = NULL, const _variant_t & type = VT_NULL, LPCWSTR pszNamespaceUri = NULL);
            //! append a new node
            MSXML2::IXMLDOMAttributePtr SetAttribute(const std::wstring& name, const std::wstring& value, MSXML2::IXMLDOMNode * node);
	        //! select attribute node
            MSXML2::IXMLDOMAttributePtr SelectAttribute(const std::wstring& name, MSXML2::IXMLDOMNode *) const;
	        //! has attribute
            bool HasAttribute(const std::wstring& name, MSXML2::IXMLDOMNode *) const;
	        //! select an attribute and return its boolean value
	        bool SelectAttributeBoolValue(const std::wstring& name, MSXML2::IXMLDOMNode *) const;
	        //! select an attribute and return its boolean value
	        bool SelectAttributeBoolValue(const std::wstring& name, MSXML2::IXMLDOMNode *, bool defaultvalue) const;
	        //! select an attribute and return its value
	        std::wstring SelectAttributeValue(const std::wstring& name, MSXML2::IXMLDOMNode *) const;
	        //! select an attribute and return its value with a default
            std::wstring SelectAttributeValue(const std::wstring& name, MSXML2::IXMLDOMNode *, const std::wstring& defaultvalue) const;
			//! transform an xml with xslt
			std::wstring XslTransform(const std::wstring xslt_filename);
            //! IXMLDOMDocument
            MSXML2::IXMLDOMDocument * operator->() const throw() { return _document.operator->(); }
			//! error
			std::wstring GetParseError() const;
        };
    }
}
