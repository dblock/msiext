#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Crypt
		{
			class DPAPICryptProviderUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( DPAPICryptProviderUnitTests );
				CPPUNIT_TEST( testProtectUnprotect );				
				CPPUNIT_TEST_SUITE_END();
			public:
				void testProtectUnprotect(void);
			};
		}
	}
}