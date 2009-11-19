#pragma once

template<class T>
class FormatterImpl
{
public:

    // \todo add flags to change behavior of mapping variables that don't exist, currently they are left untouched
    static int FormatTemplate(std::basic_string<T>& s, const std::map<std::basic_string<T>, std::basic_string<T>>& variables, const std::basic_string<T>& left, const std::basic_string<T>& right) 
	{
        if (left.empty() || right.empty())
        {
            throw std::exception("Missing l/r delimiter(s)");
        }

        if (s.empty())
        {
            return 0;
        }

		int ii = 0;
		int result = 0;
		
		while ((ii = s.find(left, ii)) != s.npos) 
		{
            int jj = s.find(right, ii + left.length());
            if (jj == s.npos)
                break;

            int replace_length = jj - ii + right.length();
            int variable_length = jj - ii - left.length();

            std::basic_string<T> variable = s.substr(ii + left.length(), variable_length);
            std::map<std::basic_string<T>, std::basic_string<T>>::const_iterator iter = variables.find(variable);
            if (iter != variables.end())
            {
                std::basic_string<T> variable_value = iter->second;
			    s.replace(ii, replace_length, variable_value);
			    ii += variable_value.length();
            }
            else
            {
                ii += replace_length;
            }

			result ++;
		}

		return result;
	}
};
