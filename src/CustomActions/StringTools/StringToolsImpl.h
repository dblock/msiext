#pragma once

/*! 

\brief Replace a string

Replaces the value in STRING_REPLACE_FROM by the value in STRING_REPLACE_TO in a string specified by 
STRING_VALUE_FROM and puts the result in STRING_VALUE_TO along with the number of occurences replaced
in STRING_REPLACE_COUNT. This function doesn't do anything special about empty strings and behaves like
a regular string replacement.

\param STRING_VALUE_FROM string to replace
\param STRING_REPLACE_FROM source string to find in STRING_VALUE
\param STRING_REPLACE_TO target string to replace occurences of STRING_REPLACE_FROM with
\return STRING_REPLACE_COUNT number of occurrences replaced
\return STRING_VALUE_TO replacement result

*/
CA_API UINT __stdcall String_Replace(MSIHANDLE hInstall);

/*! 

\brief Trim a string

This performs left and right trim.

\param STRING_TRIM_INPUT string to trim
\param STRING_TRIM_WHITESPACES the whitespace to trim. Defaults to " " and tab characters
\param STRING_TRIM_RESULT the resulting string

*/
CA_API UINT __stdcall String_Trim(MSIHANDLE hInstall);

/*! 

\brief Trim a string from left

This performs left trim. For example leading zeros in a string.

\param STRING_LTRIM_INPUT string to trim
\param STRING_LTRIM_WHITESPACES the whitespace to trim. Defaults to " " and tab characters
\param STRING_LTRIM_RESULT the resulting string

*/
CA_API UINT __stdcall String_LTrim(MSIHANDLE hInstall);

/*! 

\brief Trim a string from right

This performs right trim. 

\param STRING_RTRIM_INPUT string to trim
\param STRING_RTRIM_WHITESPACES the whitespace to trim. Defaults to " " and tab characters
\param STRING_RTRIM_RESULT the resulting string

*/
CA_API UINT __stdcall String_RTrim(MSIHANDLE hInstall);

/*! 

\brief Regex_Match

Returns 1 if the specified regular expression REGEX_MATCH_EXPRESSION
matches the whole of the input specified in REGEX_MATCH_INPUT_STRING.

\param REGEX_MATCH_INPUT_STRING input string
\param REGEX_MATCH_EXPRESSION regular expression to use in the match
\return REGEX_MATCH_RESULT 1 if it matched, 0 otherwise

*/
CA_API UINT __stdcall Regex_Match(MSIHANDLE hInstall);


/*! 

\brief Regex_Replace

Searches through the string REGEX_REPLACE_INPUT_STRING finding all the matches
to the regular expression specified in REGEX_REPLACE_EXPRESSION.
For each match it format the string using REGEX_REPLACE_FORMAT

\param REGEX_REPLACE_INPUT_STRING input string
\param REGEX_REPLACE_EXPRESSION regular expression to use in the replace
\param REGEX_REPLACE_FORMAT replacement format string
\return REGEX_MATCH_RESULT replacement result

*/
CA_API UINT __stdcall Regex_Replace(MSIHANDLE hInstall);


/*! 

\brief Converts string to lower case

Converts STRING_TOLOWER_INPUT string to lower case, output goes into STRING_TOLOWER_RESULT.

\param  STRING_TOLOWER_INPUT   input string
\return STRING_TOLOWER_RESULT conversion result, lowercase

*/
CA_API UINT __stdcall String_ToLower(MSIHANDLE hInstall);


/*! 

\brief Converts string to upper case

Converts STRING_TOUPPER_INPUT string to upper case, output goes into STRING_TOUPPER_RESULT.

\param  STRING_TOUPPER_INPUT   input string
\return STRING_TOUPPER_RESULT conversion result, uppercase

*/
CA_API UINT __stdcall String_ToUpper(MSIHANDLE hInstall);
