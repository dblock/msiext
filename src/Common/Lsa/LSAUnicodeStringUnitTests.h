#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class LSAUnicodeStringUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( LSAUnicodeStringUnitTests );
				CPPUNIT_TEST( testConstructorDestructor );
                CPPUNIT_TEST( testProperties );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testConstructorDestructor();
                void testProperties();
			};
		}
	}
}
