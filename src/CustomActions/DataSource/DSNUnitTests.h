#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace DataSource
		{
			class DSNUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( DSNUnitTests );
				CPPUNIT_TEST( Test_CreateRemoveDSN );
				CPPUNIT_TEST( Test_CreateRemoveDSN_Access );
				CPPUNIT_TEST( Test_CreateRemoveDSN_SQLServer );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
				std::wstring GetUniqueName();
                void Test_CreateRemoveDSN();
                void Test_CreateRemoveDSN_Access();
                void Test_CreateRemoveDSN_SQLServer();
				void Test_EntryPoints();
			};
        }
	}
}
