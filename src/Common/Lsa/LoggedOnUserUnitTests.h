#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class LoggedOnUserUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( LoggedOnUserUnitTests );
                CPPUNIT_TEST( testLogonLogout );
                CPPUNIT_TEST( testLogonSyntax );
				CPPUNIT_TEST( testLogonGetSid );
				CPPUNIT_TEST( testLogonGetPrivileges );
				CPPUNIT_TEST( testLogonGetGroups );
				CPPUNIT_TEST_SUITE_END();
			public:
                virtual void setUp();
                virtual void tearDown();
                void testLogonLogout();
                void testLogonSyntax();
				void testLogonGetSid();
				void testLogonGetPrivileges();
				void testLogonGetGroups();
			};
		}
	}
}
