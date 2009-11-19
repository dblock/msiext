#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class AccountUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( AccountUnitTests );
                CPPUNIT_TEST( testLookupAccount );
				CPPUNIT_TEST( testLookupSid );
                CPPUNIT_TEST( testGetAddRemoveUserRights );
                // CPPUNIT_TEST( testGetAddRemoveUserRights_Domain );
                CPPUNIT_TEST( testGetCurrentUserName );
                CPPUNIT_TEST( testGetCurrentUserNameFormat );
				CPPUNIT_TEST( testGetCurrentUserNameFormatDomain );
				CPPUNIT_TEST( testGetFQN );
                CPPUNIT_TEST( testCreate );
                CPPUNIT_TEST( testDelete );
                CPPUNIT_TEST( testExists );
				CPPUNIT_TEST( testTranslateDomain );
				CPPUNIT_TEST_SUITE_END();
			public:
                virtual void setUp();
                virtual void tearDown();
                void testLookupAccount();
				void testLookupSid();
                void testGetAddRemoveUserRights();
				void testGetAddRemoveUserRights_Domain();
                void testGetCurrentUserName();
				void testGetCurrentUserNameFormat();
				void testGetCurrentUserNameFormatDomain();
                void testCreate();
                void testDelete();
                void testExists();
				void testGetFQN();
				void testTranslateDomain();
			};
		}
	}
}
