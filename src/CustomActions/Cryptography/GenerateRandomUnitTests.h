#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Cryptography
		{
			class GenerateRandomUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( GenerateRandomUnitTests );
				CPPUNIT_TEST( Test_GenerateRandom );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_GenerateRandom();
				void Test_EntryPoints();
			};
        }
	}
}
