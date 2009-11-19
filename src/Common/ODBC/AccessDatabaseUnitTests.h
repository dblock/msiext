#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace Access
			{
				class AccessDatabaseUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( AccessDatabaseUnitTests );
					CPPUNIT_TEST(testConstructorDestructor);
					CPPUNIT_TEST(testCreate);
                    CPPUNIT_TEST(testLoadSave);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testConstructorDestructor();
					void testCreate();
                    void testLoadSave();
				};
			}
		}
	}
}
