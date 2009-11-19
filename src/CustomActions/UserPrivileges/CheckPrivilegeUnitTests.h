#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace UserPrivileges
		{
			class CheckPrivilegeUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CheckPrivilegeUnitTests );
				CPPUNIT_TEST( Test_CheckPrivilege );
				CPPUNIT_TEST( Test_CheckPrivilege_Domain );
				CPPUNIT_TEST( Test_CheckPrivilege_LogonUser );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                virtual void setUp();
                virtual void tearDown();
                void Test_CheckPrivilege();
				void Test_CheckPrivilege_Domain();
				void Test_CheckPrivilege_LogonUser();
				void Test_EntryPoints();
			};
        }
	}
}
