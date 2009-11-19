#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace UserPrivileges
		{
			class LocalGroupsUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( LocalGroupsUnitTests );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST( Test_LocalGroups );
                CPPUNIT_TEST_SUITE_END();
			public:
				void Test_EntryPoints();
                void Test_LocalGroups();
			};
        }
	}
}
