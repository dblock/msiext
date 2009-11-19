#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace MsiTools
		{
			class MsiBinaryUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( MsiBinaryUnitTests );
				CPPUNIT_TEST( Test_BinaryWrite );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_BinaryWrite();
			};
        }
	}
}
