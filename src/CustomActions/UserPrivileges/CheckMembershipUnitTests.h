#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace UserPrivileges
		{
			class CheckMembershipUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CheckMembershipUnitTests );
				CPPUNIT_TEST( Test_CheckMembership );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                void setUp();
                void tearDown();
				void Test_CheckMembership();
				void Test_EntryPoints();
			};
        }
	}
}
