#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace File
		{
			class VersionUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( VersionUnitTests );
                CPPUNIT_TEST( testIsWithinBounds );
                CPPUNIT_TEST( testCompare );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testCompare();
                void testIsWithinBounds();
			};
		}
	}
}
