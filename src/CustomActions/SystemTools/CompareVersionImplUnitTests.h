#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace CompareVersion
		{
			class CompareVersionImplUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CompareVersionImplUnitTests );
				CPPUNIT_TEST( Test_CompareVersions);
                CPPUNIT_TEST( Test_CompareVersion );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_CompareVersions();
                void Test_CompareVersion();
				void Test_EntryPoints();
			};
        }
	}
}
