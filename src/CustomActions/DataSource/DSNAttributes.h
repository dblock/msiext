#pragma once

/*!
DSNAttributes collects MSI attributes and translates them onto a DSN_ATTRIBUTES string
*/
class DSNAttributes
{
private:
    MSIHANDLE _h;
    std::vector<std::wstring> _attributes;
public:
    DSNAttributes(MSIHANDLE hInstall);
    //! add the value of property_name as attribute_name to DSN_ATTRIBUTES
    void AddPropertyValue(const std::wstring& property_name, const std::wstring& attribute_name, bool blank = false);
    //! get the attributes value string
    std::wstring GetAttributes() const;
};
