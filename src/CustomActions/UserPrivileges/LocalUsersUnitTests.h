#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace UserPrivileges
		{
			class LocalUsersUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( LocalUsersUnitTests );
                CPPUNIT_TEST( Test_LocalUsers );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
				void Test_EntryPoints();
                void Test_LocalUsers();
			};
        }
	}
}
