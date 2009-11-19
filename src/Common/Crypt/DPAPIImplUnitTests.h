#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Crypt
		{
			class DPAPIImplUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( DPAPIImplUnitTests );
				CPPUNIT_TEST( testProtectUnprotect );				
				CPPUNIT_TEST_SUITE_END();
			public:
				void testProtectUnprotect(void);
			};
		}
	}
}