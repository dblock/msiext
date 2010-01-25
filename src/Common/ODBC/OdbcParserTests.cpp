#include "StdAfxUnitTests.h"
#include "OdbcParserTests.h"
#include "OdbcParserImpl.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::UnitTests::Databases::ODBC;

CPPUNIT_TEST_SUITE_REGISTRATION(OdbcParserUnitTests);

void OdbcParserUnitTests::testCommandSetSqlServer()
{
	CPPUNIT_ASSERT_NO_THROW(CommandSet::getForFlavour(L"sqlserver"));
	CPPUNIT_ASSERT_NO_THROW(CommandSet::getForFlavour(L"SqlServer"));
	CPPUNIT_ASSERT_NO_THROW(CommandSet::getForFlavour(L"MSSQL"));
	CPPUNIT_ASSERT_NO_THROW(CommandSet::getForFlavour(L"tsql"));
	CPPUNIT_ASSERT_NO_THROW(CommandSet::getForFlavour(L"osql"));

	CPPUNIT_ASSERT_THROW(CommandSet::getForFlavour(L"MSWINSQL"), std::logic_error);
	
	CommandSet* cs = CommandSet::getForFlavour(L"sqlserver");
	CommandSet* cs1 = CommandSet::getForFlavour(L"mssql");
	CommandSet* cs2 = CommandSet::getForFlavour(L"tsql");
	// should be the same sets:
	CPPUNIT_ASSERT(cs == cs1);
	CPPUNIT_ASSERT(cs == cs2);
}

void OdbcParserUnitTests::testCommandSetDelimiters()
{
	std::vector<const std::wstring> delims;
	delims.push_back(L"go");
	CommandSet* cs  = CommandSet::getForDelimiters(delims);
	
	std::vector<const std::wstring> delims1;
	delims1.push_back(L"go");
	CommandSet* cs1 = CommandSet::getForDelimiters(delims1);

	// should be the same set:
	CPPUNIT_ASSERT(cs == cs1);
}

void OdbcParserUnitTests::testCommandSetFindCommand()
{
	CommandSet* cs = CommandSet::getForFlavour(L"sqlserver");
	CPPUNIT_ASSERT( 0 != cs->findCommand(L"go") );
	CPPUNIT_ASSERT( 0 != cs->findCommand(L"go \r") );
	CPPUNIT_ASSERT( 0 != cs->findCommand(L"Go") );
	
	CPPUNIT_ASSERT( 0 != cs->findCommand(L":r myfile.sql") );
	
	//invalid commands
	CPPUNIT_ASSERT( 0 == cs->findCommand(L":j myfile.sql") );
	CPPUNIT_ASSERT( 0 == cs->findCommand(L" go") );
	CPPUNIT_ASSERT( 0 == cs->findCommand(L"go -- comment") );
}

void OdbcParserUnitTests::testCommandSetFindCommandForDelimiters()
{
	std::vector<const std::wstring> delims;
	delims.push_back(L"Go");
	CommandSet* cs  = CommandSet::getForDelimiters(delims);
	CPPUNIT_ASSERT( 0 != cs->findCommand(L"GO") );
	CPPUNIT_ASSERT( 0 != cs->findCommand(L"go") );
}

void OdbcParserUnitTests::testOdbcParserSplitting()
{
	std::wstring input = L"  Line 1\r\nLINE 2\r\ngo\r\nLine 3\r\nGO\r\n";
	OdbcParser parser;
	parser.setSqlFlavour(L"SqlServer");
	parser.setInput( input );
	
	std::wstring stmt;
	CPPUNIT_ASSERT(parser.hasMore());
	stmt = parser.getNextBatch();
	CPPUNIT_ASSERT(L"Line 1\r\nLINE 2" == stmt);
	stmt = parser.getNextBatch();
	CPPUNIT_ASSERT(L"Line 3" == stmt);
	CPPUNIT_ASSERT(!parser.hasMore());
}


class MockNameResolver: public PathResolver {
	std::wstring content;
  public:
	MockNameResolver(std::wstring content): content(content) {}
	
	virtual std::wstring readContent(const std::wstring& path) {
		return content;
	}
};

void OdbcParserUnitTests::testOdbcParserInsert()
{
	std::wstring input = L"Line 1\r\ngo\r\n:r A.sql\r\nLINE 2";
	OdbcParser parser;
	parser.setSqlFlavour(L"SqlServer");
	parser.setInput( input );
	MockNameResolver resolver(L"Inserted A\r\nGO");
	parser.setPathResolver( &resolver );
	
	CPPUNIT_ASSERT(L"Line 1" == parser.getNextBatch());
	CPPUNIT_ASSERT(L"Inserted A" == parser.getNextBatch());
	CPPUNIT_ASSERT(L"LINE 2" == parser.getNextBatch());
	CPPUNIT_ASSERT(!parser.hasMore());
}

void OdbcParserUnitTests::testOdbcParserInsertNotTerminating()
{
	std::wstring input = L"Line 1\r\ngo\r\n:r B.sql\r\nLINE 2";
	OdbcParser parser;
	parser.setSqlFlavour(L"SqlServer");
	parser.setInput( input );
	MockNameResolver resolver(L"Inserted B\r\n");
	parser.setPathResolver( &resolver );
	
	CPPUNIT_ASSERT(L"Line 1" == parser.getNextBatch());
	CPPUNIT_ASSERT(L"Inserted B\r\nLINE 2" == parser.getNextBatch());
	CPPUNIT_ASSERT(!parser.hasMore());
}


void OdbcParserUnitTests::testOdbcParserNoDelims()
{
	std::wstring input = L"Line 1\r\ngo\r\n:r B.sql\r\nLINE 2";
	OdbcParser parser;
	parser.setInput( input );
	CPPUNIT_ASSERT(input == parser.getNextBatch());
	CPPUNIT_ASSERT(!parser.hasMore());
}
