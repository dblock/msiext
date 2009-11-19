
/****************************************************************************** 
 * 
 *  file:  DocBookOutput.h
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

#ifndef TCLAP_DOCBOOKOUTPUT_H
#define TCLAP_DOCBOOKOUTPUT_H

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
 * A class that generates DocBook output for usage() method for the 
 * given CmdLine and its Args.
 */
class DocBookOutput : public CmdLineOutput
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
		 * Substitutes the char r for wstring x in wstring s.
		 * \param s - The wstring to operate on. 
		 * \param r - The char to replace. 
		 * \param x - What to replace r with. 
		 */
		void substituteSpecialChars( std::wstring& s, char r, std::wstring& x );
		void removeChar( std::wstring& s, char r);

		void printShortArg(Arg* it);
		void printLongArg(Arg* it);
};


inline void DocBookOutput::version(CmdLineInterface& _cmd) 
{ 
	std::wcout << _cmd.getVersion() << std::endl;
}

inline void DocBookOutput::usage(CmdLineInterface& _cmd ) 
{
	std::list<Arg*> argList = _cmd.getArgList();
	std::wstring progName = _cmd.getProgramName();
	std::wstring version = _cmd.getVersion();
	XorHandler xorHandler = _cmd.getXorHandler();
	std::vector< std::vector<Arg*> > xorList = xorHandler.getXorList();


	std::wcout << "<?xml version='1.0'?>" << std::endl;
	std::wcout << "<!DOCTYPE book PUBLIC \"-//Norman Walsh//DTD DocBk XML V4.2//EN\"" << std::endl;
	std::wcout << "\t\"http://www.oasis-open.org/docbook/xml/4.2/docbookx.dtd\">" << std::endl << std::endl;

	std::wcout << "<book>" << std::endl;
	std::wcout << "<refentry>" << std::endl;

	std::wcout << "<refmeta>" << std::endl;
	std::wcout << "<refentrytitle>" << std::endl;
	std::wcout << progName << std::endl; 
	std::wcout << "</refentrytitle>" << std::endl;
	std::wcout << "<manvolnum>1</manvolnum>" << std::endl;
	std::wcout << "</refmeta>" << std::endl;

	std::wcout << "<refnamediv>" << std::endl;
	std::wcout << "<refname>" << std::endl;
	std::wcout << progName << std::endl; 
	std::wcout << "</refname>" << std::endl;
	std::wcout << "</refnamediv>" << std::endl;

	std::wcout << "<cmdsynopsis>" << std::endl;

	std::wcout << "<command>" << progName << "</command>" << std::endl;

	// xor
	for ( int i = 0; (unsigned int)i < xorList.size(); i++ )
	{
		std::wcout << "<group choice='req'>" << std::endl;
		for ( ArgVectorIterator it = xorList[i].begin(); 
						it != xorList[i].end(); it++ )
			printShortArg((*it));

		std::wcout << "</group>" << std::endl;
	}
	
	// rest of args
	for (ArgListIterator it = argList.begin(); it != argList.end(); it++)
		if ( !xorHandler.contains( (*it) ) )
			printShortArg((*it));

 	std::wcout << "</cmdsynopsis>" << std::endl;

	std::wcout << "<refsect1>" << std::endl;
	std::wcout << "<title>Description</title>" << std::endl;
	std::wcout << "<para>" << std::endl;
	std::wcout << _cmd.getMessage() << std::endl; 
	std::wcout << "</para>" << std::endl;
	std::wcout << "</refsect1>" << std::endl;

	std::wcout << "<refsect1>" << std::endl;
	std::wcout << "<title>Options</title>" << std::endl;
	std::wcout << "<para>" << std::endl;
	std::wcout << "<itemizedlist>" << std::endl;
	// xor
	for ( int i = 0; (unsigned int)i < xorList.size(); i++ )
	{
		std::wcout << "<itemizedlist>" << std::endl;
		size_t xlen = xorList.size() - 1;
		size_t xcount = 0; 
		for ( ArgVectorIterator it = xorList[i].begin(); 
						it != xorList[i].end(); it++, xcount++ )
		{
			printLongArg((*it));
			if ( xcount < xlen )
				std::wcout << "<listitem>OR</listitem>" << std::endl;
		}

		std::wcout << "</itemizedlist>" << std::endl;
	}
	
	// rest of args
	for (ArgListIterator it = argList.begin(); it != argList.end(); it++)
		if ( !xorHandler.contains( (*it) ) )
			printLongArg((*it));

	std::wcout << "</itemizedlist>" << std::endl;
	std::wcout << "</para>" << std::endl;
	std::wcout << "</refsect1>" << std::endl;

	std::wcout << "<refsect1>" << std::endl;
	std::wcout << "<title>Version</title>" << std::endl;
	std::wcout << "<para>" << std::endl;
	std::wcout << version << std::endl; 
	std::wcout << "</para>" << std::endl;
	std::wcout << "</refsect1>" << std::endl;
	
	std::wcout << "</refentry>" << std::endl;
 	std::wcout << "</book>" << std::endl;

}

inline void DocBookOutput::failure( CmdLineInterface& _cmd,
				                ArgException& e ) 
{ 
		std::wcout << e.what() << std::endl;
}

inline void DocBookOutput::substituteSpecialChars( std::wstring& s,
				                                   char r,
												   std::wstring& x )
{
	size_t p;
	while ( (p = s.find_first_of(r)) != std::wstring::npos )
	{
		s.erase(p,1);
		s.insert(p,x);
	}
}

inline void DocBookOutput::removeChar( std::wstring& s, char r)
{
	size_t p;
	while ( (p = s.find_first_of(r)) != std::wstring::npos )
	{
		s.erase(p,1);
	}
}

inline void DocBookOutput::printShortArg(Arg* a)
{
	std::wstring lt = "&lt;"; 
	std::wstring gt = "&gt;"; 

	std::wstring id = a->shortID();
	substituteSpecialChars(id,'<',lt);
	substituteSpecialChars(id,'>',gt);
	removeChar(id,'[');
	removeChar(id,']');
	
	std::wstring choice = "opt";
	if ( a->isRequired() )
		choice = "req";

	std::wstring repeat = "norepeat";
	if ( a->acceptsMultipleValues() )
		repeat = "repeat";

		
				
	std::wcout << "<arg choice='" << choice 
			  << "' repeat='" << repeat << "'>" 
			  << id << "</arg>" << std::endl; 

}

inline void DocBookOutput::printLongArg(Arg* a)
{
	std::wstring lt = "&lt;"; 
	std::wstring gt = "&gt;"; 

	std::wstring id = a->longID();
	substituteSpecialChars(id,'<',lt);
	substituteSpecialChars(id,'>',gt);
	removeChar(id,'[');
	removeChar(id,']');

	std::wstring desc = a->getDescription();
	substituteSpecialChars(desc,'<',lt);
	substituteSpecialChars(desc,'>',gt);

	std::wcout << "<simplelist>" << std::endl;

	std::wcout << "<member>" << std::endl;
	std::wcout << id << std::endl;
	std::wcout << "</member>" << std::endl;

	std::wcout << "<member>" << std::endl;
	std::wcout << desc << std::endl;
	std::wcout << "</member>" << std::endl;

	std::wcout << "</simplelist>" << std::endl;
}

} //namespace TCLAP
#endif 
