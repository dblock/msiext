#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Win32
		{
			class ComImplUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( ComImplUnitTests );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST( Test_Win32_GenerateGuidString );
				CPPUNIT_TEST( Test_Win32_IsValidGuid );
                CPPUNIT_TEST_SUITE_END();
			public:
				void Test_EntryPoints();
                void Test_Win32_GenerateGuidString();
				void Test_Win32_IsValidGuid();
			};
        }
	}
}
