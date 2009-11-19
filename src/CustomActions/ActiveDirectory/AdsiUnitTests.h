#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace ActiveDirectory
		{
			class AdsiUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( AdsiUnitTests );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST( Test_ADSI_GetPropertyValue_RootDSE );
				CPPUNIT_TEST( Test_ADSI_GetAttributeValue );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_EntryPoints();
				void Test_ADSI_GetPropertyValue_RootDSE();
				void Test_ADSI_GetAttributeValue();
			};
        }
	}
}
