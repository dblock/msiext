#pragma once

template<class T>
class StringUtilsImpl
{
public:

	static int replace(std::basic_string<T>& s, const std::basic_string<T>& from, const std::basic_string<T>& to) 
	{
		int ii = 0;
		int result = 0;
		
		if (s.length() != 0 && from.length() != 0)
		{
			while ((ii = s.find(from, ii)) != s.npos) 
			{
				s.replace(ii, from.length(), to);
				ii += (abs((int)(to.length() - from.length())) + 1);
				result ++;
			}
		}
		return result;
	}

	static void tokenize(const std::basic_string<T>& ss, std::vector<std::basic_string<T>>& tokens, const std::basic_string<T>& delim) 
	{
		tokens.clear();
		int begin = 0, end = 0;
		std::basic_string<T> temp;

		temp = ss;

		while ( (end = temp.find(delim)) != std::basic_string<T>::npos )
		{
			tokens.push_back( temp.substr(0, end) );
			begin = end + delim.length();
			temp = temp.substr(begin, temp.length() - begin);
		}

		tokens.push_back(temp.substr(0, temp.length()));
	}

	static std::basic_string<T> join(const std::vector<std::basic_string<T>>& tokens, const std::basic_string<T>& delim) 
	{
        std::basic_string<T> ss;
				
		for (unsigned int i = 0; i < tokens.size(); i++)
		{
			if (i > 0) ss.append(delim);
			ss.append(tokens[i]);
		}

        return ss;
	}

	static std::basic_string<T> join(const std::list<std::basic_string<T>>& tokens, const std::basic_string<T>& delim) 
	{
        std::basic_string<T> ss;
        
        int i = 0;
		for each (const std::basic_string<T>& token in tokens)
		{
			if (i > 0) ss.append(delim);
			ss.append(token);
            i++;
		}

        return ss;
	}

	static void tokenizeWithSkip(const std::basic_string<T>& ss, std::vector<std::basic_string<T>>& tokens, const std::basic_string<T>& delims)
	{
		// Skip delims at beginning.
		std::basic_string<T>::size_type lastpos = ss.find_first_not_of(delims, 0);
		// Find first "non-delimiter".
		std::basic_string<T>::size_type pos     = ss.find_first_of(delims, lastpos);

		while (std::string::npos != pos || std::string::npos != lastpos)
		{
			// Found a token, add it to the vector.
			tokens.push_back(ss.substr(lastpos, pos - lastpos));
			// Skip delims.  Note the "not_of"
			lastpos = ss.find_first_not_of(delims, pos);
			// Find next "non-delimiter"
			pos = ss.find_first_of(delims, lastpos);
		}
	}

	// Each character in the delim string is treated as a delimeter.
	static void tokenizeOnChar(const std::basic_string<T>& ss, std::vector<std::basic_string<T>>& tokens, const std::basic_string<T>& delims) 
	{
		tokens.clear();
		int begin = 0, end = 0;

		for( unsigned int i = 0; i < ss.length(); i++)
		{	
			if ( delims.find(ss.substr(i, 1), 0) == std::basic_string<T>::npos )
			{
				end++;
			} 
			else 
			{
				tokens.push_back(ss.substr(begin, (end - begin)));
				begin = ++end;
			}
		}
		tokens.push_back(ss.substr(begin, (end - begin)));
	}

	static void ltrim(std::basic_string<T>& ss, const std::basic_string<T>& whitespaces) 
	{
		ss.erase(0, ss.find_first_not_of(whitespaces));
	}

	static void rtrim(std::basic_string<T>& ss, const std::basic_string<T>& whitespaces) 
	{
		ss.erase(ss.find_last_not_of(whitespaces) + 1);
	}

	static void lrtrim(std::basic_string<T>& ss, const std::basic_string<T>& whitespaces) 
	{
		ltrim(ss, whitespaces);
		rtrim(ss, whitespaces);
	}

	static void lrtrimcrlf(std::basic_string<T>& ss, const std::basic_string<T>& whitespaces) 
	{
		ltrim(ss, whitespaces);
		rtrim(ss, whitespaces);
	}

	static void uppercase(std::basic_string<T>& ss) 
	{
		std::transform(ss.begin(), ss.end(), ss.begin(), (int(*)(int)) toupper);
	}

	static void lowercase(std::basic_string<T>& ss) 
	{
		std::transform(ss.begin(), ss.end(), ss.begin(), (int(*)(int)) tolower);
	}

	static bool comparei(const std::basic_string<T>& ss1, const std::basic_string<T>& ss2) 
	{
		std::basic_string<T> s1, s2;
		s1 = ss1; s2 = ss2;
		lowercase(s1);
		lowercase(s2);
		return (s1 == s2);
	}

	static bool isNumber(const std::basic_string<T>& ss) 
	{
		unsigned int i = 0;

		if( ss.length() > 1 && ss[0] == '-') i = 1;
		if( ss.length() == i ) return false;

		for( ; i < ss.length(); i++ )
		{
			if(! isdigit(ss[i])) 
			{
				return false;
			}
		}

		return true;
	}

	static bool startsWith(const std::basic_string<T>& what, const std::basic_string<T>& with) 
	{
		if (what.length() < with.length())
			return false;
		if (what.substr(0, with.length()) == with)
			return true;
		return false;
	}
   
	static bool endsWith(const std::basic_string<T>& what, const std::basic_string<T>& with) 
	{
		if (what.length() < with.length())
			return false;
		if (what.substr(what.length() - with.length(), what.length()) == with)
			return true;
		return false;
	}
};
