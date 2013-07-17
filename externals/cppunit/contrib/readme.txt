What's in those files:

bc5/:
	* bc5-makefile.zip: makefile for CppUnit with Borland C++ 5.5 free compiler.
	  contributed by 'cuppa' project team (http://sourceforge.jp/projects/cuppa/).
	  See instruction  'readme_en.txt' in the zip.

msvc/:

	* CppUnit.WWTpl: a template Workspace Whiz! which create a new class 
and add the new files to the project. You can specify that the class is a 
CppUnit testcase and all the macro will be defined to register the test case
and declare the test suite. Workspace Whiz! is an add-ins for VC++. It can
be found at: http://www.workspacewhiz.com/.

	* AddingUnitTestMethod.dsm: a set of VC++ macro to add unit test
using helper macros.

xml-xsl/:

	* report.xsl: a xml style sheet contributed by 'cuppa' project team 
(http://sourceforge.jp/projects/cuppa/)  to transform  CppUnit XML output into 
HTML. Windows user can test it by running tests.xml (require Internet Explorer 
5.0+).

    * cppunit2junit.xsl: XSLT for compatibility with Ant junit xml formatter
	  (patch #1112053 contributed by BARBOSA Norbert. 
	   See cppunit2junit.txt for details).