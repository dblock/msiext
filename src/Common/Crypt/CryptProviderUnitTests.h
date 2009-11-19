#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Crypt
		{
			class CryptProviderUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CryptProviderUnitTests );				
				CPPUNIT_TEST( testAllProvidersProtectUnprotect );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testAllProvidersProtectUnprotect();			
				void testSpecificProviderProtectUnprotect(AppSecInc::Crypt::CryptProvider * p);
			};
		}
	}
}