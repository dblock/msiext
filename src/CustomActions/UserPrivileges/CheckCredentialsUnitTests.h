#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace UserPrivileges
		{
			class CheckCredentialsUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CheckCredentialsUnitTests );
				CPPUNIT_TEST( Test_CheckCredentials );
                CPPUNIT_TEST( Test_CheckCredentials_Invalid );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                virtual void setUp();
                virtual void tearDown();
                void Test_CheckCredentials();
                void Test_CheckCredentials_Invalid();
				void Test_EntryPoints();
			};
        }
	}
}
