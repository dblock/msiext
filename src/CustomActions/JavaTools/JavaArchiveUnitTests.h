#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace JavaTools
		{
			class JavaArchiveUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( JavaArchiveUnitTests );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST( Test_JavaArchive );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_EntryPoints();
                void Test_JavaArchive();
			};
        }
	}
}
