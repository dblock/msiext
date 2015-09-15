#pragma once

#include "StringUtilsImpl.h"

namespace AppSecInc
{
    //! Common string utilities
    namespace StringUtils
    {
	    /*!
	     Performs a string replace on every instance.
	     \param ss Input/Output. The string to perform the substring replace.
	     \param from Input. The substring to find.
	     \param to Input. The substring to replace.
	     \return Number of replacements made.
	     */
	    int replace(std::string& ss, const std::string& from, const std::string& to);
	    int replace(std::wstring& ss, const std::wstring& from, const std::wstring& to);

	    /*!
	     Tokenizes a given string using a multi-byte delimiter. Multi-byte delimiter can be any length
	     that will be discarded and not included with the tokens.
	     \param ss Input. The string to parse for tokens.
	     \param delims Input. The String to use as delimiter.
	     \param tokens Input/Output. The resulting tokens will be placed into a vector.
	     */
	    void tokenize(const std::string& ss, std::vector<std::string>& tokens, const std::string& delims);
	    void tokenize(const std::wstring& ss, std::vector<std::wstring>& tokens, const std::wstring& delims);

	    /*!
	     Join a given vector using a multi-byte delimiter.
	     \param tokens Input. The tokens to join.
	     \param delims Input. The String to use as delimiter.
	     \return The string result.
	     */
        std::string join(const std::vector<std::string>& tokens, const std::string& delims);
        std::wstring join(const std::vector<std::wstring>& tokens, const std::wstring& delims);
        std::string join(const std::list<std::string>& tokens, const std::string& delims);
        std::wstring join(const std::list<std::wstring>& tokens, const std::wstring& delims);

	    /*!
	     Tokenizes a given string using a delimiter.
	     that will be discarded and not included with the tokens.
	     Imp: this versoin skips contiguous delimiters. e.g. when tokenizing "X;;Y" using ";" 
	     as a delimeter, we'll skipp both semi-colons. This gives us two tokens "X" and "Y".
	     \param ss Input. The string to parse for tokens.
	     \param delim Input. The String to use as delimiter.
	     \param tokens Input/Output. The resulting tokens will be placed into a vector.
	     */
	    void tokenizeWithSkip(const std::string& ss, std::vector<std::string>& tokens, const std::string& delim = " ");
	    void tokenizeWithSkip(const std::wstring& ss, std::vector<std::wstring>& tokens, const std::wstring& delim = L" ");

	    /*!
	     Tokenizes a given string using a delimiter.
	     that will be discarded and not included with the tokens.
	     \param ss Input. The string to parse for tokens.
	     \param delims Input. String of chars to be used as delimiters.
	     \param tokens Input/Output. The resulting tokens will be placed into a vector.
	     */
	    void tokenizeOnChar(const std::string& ss, std::vector<std::string>& tokens, const std::string& delims);
	    void tokenizeOnChar(const std::wstring& ss, std::vector<std::wstring>& tokens, const std::wstring& delims);

	    /*!
	     This performs an in-place left trim.
	     \param ss Input/Output. The string to perform the trim on.
	     \param whitespaces Input. The whitespace to trim. Defaults to " " and tab characters.
	     */
	    void ltrim(std::string& ss, const std::string& whitespaces = " \t");
	    void ltrim(std::wstring& ss, const std::wstring& whitespaces = L" \t");

	    /*!
	     This performs an in-place right trim.
	     \param ss Input/Output. The string to perform the trim on.
	     \param whitespaces Input. The whitespace to trim. Defaults to " " and tab characters.
	     */
	    void rtrim(std::string& ss, const std::string& whitespaces = " \t");
	    void rtrim(std::wstring& ss, const std::wstring& whitespaces = L" \t");

	    /*!
	     This performs an in-place left and right trim.
	     \param ss Input/Output. The string to perform the trim on.
	     \param whitespaces Input. The whitespace to trim. Defaults to " " and tab characters.
	     */
	    void lrtrim(std::string& ss, const std::string& whitespaces = " \t");
	    void lrtrim(std::wstring& ss, const std::wstring& whitespaces = L" \t");

	    /*!
	     This performs an in-place left and right trim.
	     \param ss Input/Output. The string to perform the trim on.
	     \param whitespaces Input. The whitespace to trim. Defaults to " ", CRLF and tab characters.
	     */
	    void lrtrimcrlf(std::string& ss, const std::string& whitespaces = " \r\n\t");
	    void lrtrimcrlf(std::wstring& ss, const std::wstring& whitespaces = L" \r\n\t");

	    /*!
	     This transforms the string to all uppercase.
	     \param ss Input/Output. The string to perform the function on.
	     */
	    void uppercase(std::string& ss);
	    void uppercase(std::wstring& ss);

	    /*!
	     This transforms the string to all lowercase.
	     \param ss Input/Output. The string to perform the function on.
	     */
	    void lowercase(std::string& ss);
	    void lowercase(std::wstring& ss);

	    /*!
	     Case-insensitive string compare.
	     \param ss1 Input. 1st String.
	     \param ss2 Input. 2nd String.
	     \return bool true if strings are the same, false otherwise.
	     */
	    bool comparei(const std::string& ss1, const std::string& ss2);
	    bool comparei(const std::wstring& ss1, const std::wstring& ss2);

	    /*!
	     Checks if each char in ss is a number, then returns the integer value.
	     If ss is not a number, returns default_on_error.
	     \param ss Input. String to be converted to integer.
	     \param default_on_error Input. Default value to return on error.
	     \param base Same as base parameter in strtol.
         \return The resulting integer value.
	     */
	    long stringToLong(const std::string& ss, long default_on_error = 0, int base = 10);
        long stringToLong(const std::wstring& ss, long default_on_error = 0, int base = 10);
	    long stringToLong(const char * psz, long default_on_error = 0, int base = 10);
	    long stringToLong(const wchar_t * psz, long default_on_error = 0, int base = 10);

	    /*!
	     This converts a Multi-byte (ASCII) string to a Wide-character (Unicode) set string.
	     \param from Input. The Multi-byte string to convert.
	     \return The resulting Wide-character string.
	     */
	    std::wstring mb2wc(const std::string& from);
	    std::wstring mb2wc(const char * from);
	    std::wstring mb2wc(const char * from, unsigned int len);

	    /*!
	     This converts a UTF8 string to a Wide-character (Unicode) set string.
	     \param from Input. The UTF8 string to convert.
	     \return The resulting Wide-character string.
	     */
	    std::wstring utf82wc(const std::string& from);
	    std::wstring utf82wc(const char * from);
	    std::wstring utf82wc(const char * from, unsigned int len);

	    /*!
	     This converts a Wide-character (Unicode) string to a Multi-byte (ASCII) string.
	     \param from Input. The wide-char string to convert.
	     \return The resulting multi-byte string.
	     */
	    std::string wc2mb(const std::wstring& from);
	    std::string wc2mb(const wchar_t * from);
	    std::string wc2mb(const wchar_t * from, unsigned int len);

	    /*!
	     This converts a Wide-character (Unicode) string to a UTF8 string.
	     \param from Input. The wide-char string to convert.
	     \return The resulting multi-byte UTF8 string.
	     */
	    std::string wc2utf8(const std::wstring& from);
	    std::string wc2utf8(const wchar_t * from);
	    std::string wc2utf8(const wchar_t * from, unsigned int len);

	    /*!
	     This converts a BSTR to a Multi-byte (ASCII) string.
	     \param from Input. The BSTR to convert.
	     \return The resulting multi-byte string.
	     */
	    std::string bstr2mb(BSTR from);
	    std::string bstr2mb(BSTR from, int len);
	    std::string bstr2mb(const _bstr_t& from);
	    std::string bstr2mb(const CComBSTR& from);

	    /*!
	     This converts a VARIANT to a Multi-byte (ASCII) string.
	     \param from Input. The VARIANT to convert.
	     \return The resulting Multi-byte string.
	     */
	    std::string toString(VARIANT from);
	    std::string toString(const _variant_t& from);
	    std::string toString(const CComVariant& from);

	    std::wstring toWString(VARIANT from);
	    std::wstring toWString(const _variant_t& from);
	    std::wstring toWString(const CComVariant& from);

	    /*!
	     This converts an ASCII string to an EBCDIC string.
	     EBCDIC = Extended Binary Coded Decimal Interchange Code.
	     IBM's 8-bit extension of the 4-bit Binary Coded Decimal encoding of digits 0-9 (0000-1001).
	     \param ss Input/Output. The ASCII string to convert.
	     */
	    void s2ebcdic(std::string& ss);
	    void s2ebcdic(unsigned char * s, unsigned long len);

	    /*!
	     This converts an EBCDIC string to an ASCII string in-place.
	     EBCDIC = Extended Binary Coded Decimal Interchange Code.
	     IBM's 8-bit extension of the 4-bit Binary Coded Decimal encoding of digits 0-9 (0000-1001).
	     \param ss Input/Output. The EBDDIC string to convert.
	     */
	    void ebcdic2s(std::string& ss);
	    void ebcdic2s(unsigned char * s, unsigned long len);

	    /*!
	     Returns true if a string starts with (case-sensitive) another string.
	     \param ss Input. The input string.
	     \param what Input. The candidate string.
	     \return bool true if success, false otherwise.
	     */
	    bool startsWith(const std::string& ss, const std::string& what);
	    bool startsWith(const std::wstring& ss, const std::wstring& what);

	    /*!
	     Returns true if a string ends with (case-sensitive) another string.
	     \param ss Input. The input string.
	     \param what Input. The candidate string.
	     \return bool True if ss ends with what, false otherwise.
	     */
	    bool endsWith(const std::string& ss, const std::string& what);
	    bool endsWith(const std::wstring& ss, const std::wstring& what);

	    std::wstring escape(std::wstring const &s);

	    //! Convert any streamable data into a UNICODE string.
	    template<class T>
	    std::wstring toWString(const T& t)
	    {
		    std::wstringstream ss;
		    ss << t;
		    return ss.str();
	    }

	    //! Convert any streamable data into an ANSI string.
	    template<class T>
	    std::string toString(const T& t)
	    {
		    std::stringstream ss;
		    ss << t;
		    return ss.str();
	    }
    }
}