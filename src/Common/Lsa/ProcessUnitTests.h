#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class ProcessUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( ProcessUnitTests );
				CPPUNIT_TEST( testConstructorDestructor );
                CPPUNIT_TEST( testOpenClose );
                CPPUNIT_TEST( testOpenCloseByName );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testConstructorDestructor();
                void testOpenClose();
                void testOpenCloseByName();
			};
		}
	}
}
