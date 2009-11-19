
/****************************************************************************** 
 * 
 *  file:  StdOutput.h
 * 
 *  Copyright (c) 2004, Michael E. Smoot
 *  All rights reverved.
 * 
 *  See the file COPYING in the top directory of this distribution for
 *  more information.
 *  
 *  THE SOFTWARE IS PROVIDED _AS IS_, WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 *  DEALINGS IN THE SOFTWARE.  
 *  
 *****************************************************************************/ 

#ifndef TCLAP_STDCMDLINEOUTPUT_H
#define TCLAP_STDCMDLINEOUTPUT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

#include <tclap/CmdLineInterface.h>
#include <tclap/CmdLineOutput.h>
#include <tclap/XorHandler.h>
#include <tclap/Arg.h>

namespace TCLAP {

/**
 * A class that isolates any output from the CmdLine object so that it
 * may be easily modified.
 */
class StdOutput : public CmdLineOutput
{

	public:

		/**
		 * Prints the usage to stdout.  Can be overridden to 
		 * produce alternative behavior.
		 * \param c - The CmdLine object the output is generated for. 
		 */
		virtual void usage(CmdLineInterface& c);

		/**
		 * Prints the version to stdout. Can be overridden 
		 * to produce alternative behavior.
		 * \param c - The CmdLine object the output is generated for. 
		 */
		virtual void version(CmdLineInterface& c);

		/**
		 * Prints (to stderr) an error message, short usage 
		 * Can be overridden to produce alternative behavior.
		 * \param c - The CmdLine object the output is generated for. 
		 * \param e - The ArgException that caused the failure. 
		 */
		virtual void failure(CmdLineInterface& c, 
						     ArgException& e );

	protected:

        /**
         * Writes a brief usage message with short args.
		 * \param c - The CmdLine object the output is generated for. 
         * \param os - The stream to write the message to.
         */
        void _shortUsage( CmdLineInterface& c, std::wostream& os ) const;

        /**
		 * Writes a longer usage message with long and short args, 
		 * provides descriptions and prints message.
		 * \param c - The CmdLine object the output is generated for. 
		 * \param os - The stream to write the message to.
		 */
		void _longUsage( CmdLineInterface& c, std::wostream& os ) const;

		/**
		 * This function inserts line breaks and indents long strings 
		 * according the  params input. It will only break lines at spaces, 
		 * commas and pipes.
		 * \param os - The stream to be printed to.
		 * \param s - The wstring to be printed.
		 * \param maxWidth - The maxWidth allowed for the output line. 
		 * \param indentSpaces - The number of spaces to indent the first line. 
		 * \param secondLineOffset - The number of spaces to indent the second
		 * and all subsequent lines in addition to indentSpaces.
		 */
		void spacePrint( std::wostream& os, 
						 const std::wstring& s, 
						 int maxWidth, 
						 int indentSpaces, 
						 int secondLineOffset ) const;

};


inline void StdOutput::version(CmdLineInterface& _cmd) 
{
	std::wstring progName = _cmd.getProgramName();
	std::wstring version = _cmd.getVersion();

	std::wcout << std::endl << progName << _T("  version: ") 
			  << version << std::endl << std::endl;
}

inline void StdOutput::usage( CmdLineInterface& _cmd ) 
{
	std::wcout << std::endl << _T("USAGE: ") << std::endl << std::endl; 

	_shortUsage( _cmd, std::wcout );

	std::wcout << std::endl << std::endl << _T("Where: ") << std::endl << std::endl;

	_longUsage( _cmd, std::wcout );

	std::wcout << std::endl; 

}

inline void StdOutput::failure( CmdLineInterface& _cmd,
				                ArgException& e ) 
{
	std::wstring progName = _cmd.getProgramName();

	std::wcerr << _T("PARSE ERROR: ") << e.argId() << std::endl
		      << _T("             ") << e.error() << std::endl << std::endl;

	if ( _cmd.hasHelpAndVersion() )
	{
		std::wcerr << _T("Brief USAGE: ") << std::endl;

		_shortUsage( _cmd, std::wcerr );	

		std::wcerr << std::endl << _T("For complete USAGE and HELP type: ") 
			      << std::endl << _T("   ") << progName << _T(" --help") 
				  << std::endl << std::endl;
	}
	else
		usage(_cmd);

}

inline void StdOutput::_shortUsage( CmdLineInterface& _cmd, 
				                    std::wostream& wos ) const
{
	std::list<Arg*> argList = _cmd.getArgList();
	std::wstring progName = _cmd.getProgramName();
	XorHandler xorHandler = _cmd.getXorHandler();
	std::vector< std::vector<Arg*> > xorList = xorHandler.getXorList();

	std::wstring s = progName + _T(" ");

	// first the xor
	for ( int i = 0; static_cast<unsigned int>(i) < xorList.size(); i++ )
	{
		s += _T(" {");
		for ( ArgVectorIterator it = xorList[i].begin(); 
						it != xorList[i].end(); it++ )
			s += (*it)->shortID() + _T("|");

		s[s.length()-1] = L'}';
	}

	// then the rest
	for (ArgListIterator it = argList.begin(); it != argList.end(); it++)
		if ( !xorHandler.contains( (*it) ) )
			s += _T(" ") + (*it)->shortID();

	// if the program name is too long, then adjust the second line offset 
	int secondLineOffset = static_cast<int>(progName.length()) + 2;
	if ( secondLineOffset > 75/2 )
			secondLineOffset = static_cast<int>(75/2);

	spacePrint( std::wcout, s, 75, 3, secondLineOffset );
}

inline void StdOutput::_longUsage( CmdLineInterface& _cmd, 
			                       std::wostream& wos ) const
{
	std::list<Arg*> argList = _cmd.getArgList();
	std::wstring message = _cmd.getMessage();
	XorHandler xorHandler = _cmd.getXorHandler();
	std::vector< std::vector<Arg*> > xorList = xorHandler.getXorList();

	// first the xor 
	for ( int i = 0; static_cast<unsigned int>(i) < xorList.size(); i++ )
	{
		for ( ArgVectorIterator it = xorList[i].begin(); 
			  it != xorList[i].end(); 
			  it++ )
		{
			spacePrint( wos, (*it)->longID(), 75, 3, 3 );
			spacePrint( wos, (*it)->getDescription(), 75, 5, 0 );

			if ( it+1 != xorList[i].end() )
				spacePrint(wos, _T("-- OR --"), 75, 9, 0);
		}
		wos << std::endl << std::endl;
	}

	// then the rest
	for (ArgListIterator it = argList.begin(); it != argList.end(); it++)
		if ( !xorHandler.contains( (*it) ) )
		{
			spacePrint( wos, (*it)->longID(), 75, 3, 3 ); 
			spacePrint( wos, (*it)->getDescription(), 75, 5, 0 ); 
			wos << std::endl;
		}

	wos << std::endl;

	spacePrint( wos, message, 75, 3, 0 );
}

inline void StdOutput::spacePrint( std::wostream& wos, 
						           const std::wstring& s, 
						           int maxWidth, 
						           int indentSpaces, 
						           int secondLineOffset ) const
{
	int len = static_cast<int>(s.length());

	if ( (len + indentSpaces > maxWidth) && maxWidth > 0 )
	{
		int allowedLen = maxWidth - indentSpaces;
		int start = 0;
		while ( start < len )
		{
			// find the substring length
			int stringLen = std::min( len - start, allowedLen );
			
			//replace with this line and comment the above if windows has the min macro defined and it complains about std::min
			//int stringLen = min( len - start, allowedLen );

			// trim the length so it doesn't end in middle of a word
			if ( stringLen == allowedLen )
				while ( s[stringLen+start] != _T(' ') && 
			   	        s[stringLen+start] != _T(',') &&
			   	        s[stringLen+start] != _T('|') &&
						stringLen >= 0 )
					stringLen--;
	
			// ok, the word is longer than the line, so just split 
			// wherever the line ends
			if ( stringLen <= 0 )
				stringLen = allowedLen;

			// check for newlines
			for ( int i = 0; i < stringLen; i++ )
				if ( s[start+i] == _T('\n') )
					stringLen = i+1;

			// print the indent	
			for ( int i = 0; i < indentSpaces; i++ )
				wos << _T(" ");

			if ( start == 0 )
			{
				// handle second line offsets
				indentSpaces += secondLineOffset;

				// adjust allowed len
				allowedLen -= secondLineOffset;
			}

			wos << s.substr(start,stringLen) << std::endl;

			// so we don't start a line with a space
			while ( s[stringLen+start] == _T(' ') && start < len )
				start++;
			
			start += stringLen;
		}
	}
	else
	{
		for ( int i = 0; i < indentSpaces; i++ )
				wos << _T(" ");
		wos << s << std::endl;
	}
}

} //namespace TCLAP
#endif 
