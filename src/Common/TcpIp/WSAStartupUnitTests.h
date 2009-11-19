#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace TcpIp
		{
			class WSAStartupUnitTest :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE(WSAStartupUnitTest);
				CPPUNIT_TEST(basicTest);
				CPPUNIT_TEST(simpleVersionTests);
				CPPUNIT_TEST(testNegotiation);
				CPPUNIT_TEST(testUnloadedDriver);
				CPPUNIT_TEST_SUITE_END();
			public:
				const static WORD vdefault = AppSecInc::TcpIp::CWSAStartup::default_version;
				const static WORD v10 = MAKEWORD(1, 0);
				const static WORD v11 = MAKEWORD(1, 1);
				const static WORD v21 = MAKEWORD(2, 1);
				const static WORD v22 = MAKEWORD(2, 2);
				const static WORD v33 = MAKEWORD(3, 3);
				void basicTest();
				void simpleVersionTests();
				void testNegotiation();
				void testUnloadedDriver();
			private:
				WORD negotiateVersion(WORD version);
				WORD highestSupportedVersion();
				bool supportsWinsock2(WORD version);
			};
		}
	}
}