#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace File
		{
			class ProcessUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( ProcessUnitTests );
                CPPUNIT_TEST( testExecute );
                CPPUNIT_TEST( testExecuteWithOutput );
                CPPUNIT_TEST( testExecuteWithOutputLines );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testExecute();
                void testExecuteWithOutput();
                void testExecuteWithOutputLines();
			};
		}
	}
}
