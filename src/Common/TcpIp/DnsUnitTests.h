#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace TcpIp
		{
			namespace DNS
			{
				class DnsUnitTests : public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE(DnsUnitTests);
					CPPUNIT_TEST(testGetHostByAddress);
					CPPUNIT_TEST(testGetHostByInvalidAddress);
					CPPUNIT_TEST(testGetHostInfo);
					CPPUNIT_TEST(testGetHostByName);
					CPPUNIT_TEST(testGetHostIpAddresses);
					CPPUNIT_TEST(testGetLocal);
                    CPPUNIT_TEST(testGetHostName);
					CPPUNIT_TEST(testIsIpAddress);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testGetHostByAddress();
					void testGetHostByInvalidAddress();
					void testGetHostInfo();
					void testGetHostByName();
					void testGetHostIpAddresses();
					void testGetLocal();
                    void testGetHostName();
					void testIsIpAddress();
				};
			}
		}
	}
}