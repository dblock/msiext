#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Crypt
		{
			class MicrosoftCryptProviderUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( MicrosoftCryptProviderUnitTests );
				CPPUNIT_TEST( testInitialize );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testInitialize();				
			};
		}
	}
}