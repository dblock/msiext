#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace UserPrivileges
		{
			class LocalGroupMembersUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( LocalGroupMembersUnitTests );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST( Test_LocalGroupMembers );
                CPPUNIT_TEST_SUITE_END();
			public:
				void Test_EntryPoints();
                void Test_LocalGroupMembers();
			};
        }
	}
}
