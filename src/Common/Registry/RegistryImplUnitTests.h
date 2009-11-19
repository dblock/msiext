#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Registry
		{
			class RegistryUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( RegistryUnitTests );
                CPPUNIT_TEST( testKeyExists );
				CPPUNIT_TEST( testGetStringValue );
				CPPUNIT_TEST( testCopyDeleteBranch );
				CPPUNIT_TEST( testCreateKey );
				CPPUNIT_TEST( testSetStringValue );
				CPPUNIT_TEST_SUITE_END();
			public:
                void testKeyExists();
				void testGetStringValue();
				void testCopyDeleteBranch();
				void testCreateKey();
				void testSetStringValue();

			};
		}
	}
}
