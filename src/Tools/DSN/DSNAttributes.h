#pragma once

//! DSNAttributes collects MSI attributes and translates them onto an attribute string
class DSNAttributes
{
private:
    std::vector<std::wstring> _attributes;
public:
    DSNAttributes();
    //! add a value of format name=value
    void Add(const std::wstring& namevaluepair);
    //! add an array of values of format name=value
    void AddRange(const std::vector<std::wstring>& namevaluepairs);
    //! get the attributes value string
    std::wstring GetAttributes() const;
};
