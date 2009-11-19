#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace DataSource
		{
			class DataFileUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( DataFileUnitTests );
				CPPUNIT_TEST( Test_DataFile_SQLServer );
                CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_DataFile();
                void Test_EntryPoints();
				void Test_DataFile_SQLServer();
			};
        }
	}
}
