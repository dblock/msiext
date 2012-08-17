#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace TcpIp
		{
			namespace NetBIOS
			{
				class NetBIOSUnitTests : public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE(NetBIOSUnitTests);
					CPPUNIT_TEST(testGetComputerName);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testGetComputerName();
				};
			}
		}
	}
}