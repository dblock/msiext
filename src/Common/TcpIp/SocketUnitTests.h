#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace TcpIp
		{
			class SocketUnitTest : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE(SocketUnitTest);
				CPPUNIT_TEST(testConstructorDestructor);
				CPPUNIT_TEST(testOptions);
				CPPUNIT_TEST(testError);
				CPPUNIT_TEST(testReconnect);
				CPPUNIT_TEST(testConnectDisconnectValidHost);
				CPPUNIT_TEST(testConnectDisconnectInvalidHost);
				CPPUNIT_TEST(testBind);
				CPPUNIT_TEST_SUITE_END();
			public:
				void testConstructorDestructor();
				void testOptions();
				void testError();
				void testReconnect();
				void testConnectDisconnectValidHost();
				void testConnectDisconnectInvalidHost();
				void testBind();
			};
		}
	}
}