#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Registry
		{
			class RegistryImplUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( RegistryImplUnitTests );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST( Test_Registry_CopyDeleteBranch );
				CPPUNIT_TEST( Test_Registry_MoveBranch );
				CPPUNIT_TEST( Test_Registry_CreateKey );
				CPPUNIT_TEST( Test_Registry_SetStringValue );
				CPPUNIT_TEST( Test_Registry_KeyExists );
				CPPUNIT_TEST( Test_Registry_Copy );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_EntryPoints();
				void Test_Registry_CopyDeleteBranch();
				void Test_Registry_MoveBranch();
				void Test_Registry_CreateKey();
				void Test_Registry_SetStringValue();
				void Test_Registry_KeyExists();
				void Test_Registry_Copy();
			};
		}
	}
}
