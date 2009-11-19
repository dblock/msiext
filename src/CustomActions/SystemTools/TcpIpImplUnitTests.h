#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace TcpIp
		{
			class TcpIpImplUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( TcpIpImplUnitTests );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST( Test_TcpIp_ListAddresses );
				CPPUNIT_TEST( Test_TcpIp_BindSocket );
				CPPUNIT_TEST( Test_TcpIp_Connect );
				CPPUNIT_TEST( Test_TcpIp_BindSocket_Local );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_EntryPoints();
				void Test_TcpIp_BindSocket();
				void Test_TcpIp_Connect();
				void Test_TcpIp_BindSocket_Local();
				void Test_TcpIp_ListAddresses();
			};
		}
	}
}
