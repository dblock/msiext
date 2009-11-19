#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Cryptography
		{
			class DESEDE3UnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( DESEDE3UnitTests );
				CPPUNIT_TEST( Test_DESEDE3 );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_DESEDE3();
				void Test_EntryPoints();
			};
        }
	}
}
