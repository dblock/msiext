#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace Access
			{
				class AccessConnectionInfoUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( AccessConnectionInfoUnitTests );
					CPPUNIT_TEST(testConstructorDestructor);
					CPPUNIT_TEST(testCopyAndAssignment);
					CPPUNIT_TEST(testGetConnectionString);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testConstructorDestructor();
					void testCopyAndAssignment();
					void testGetConnectionString();
				};
			}
		}
	}
}
