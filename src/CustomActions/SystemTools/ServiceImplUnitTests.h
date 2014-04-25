#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Service
		{
			class ServiceImplUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( ServiceImplUnitTests );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST( Test_Service_RenameRegistryEntry );
				CPPUNIT_TEST( Test_Service_ChangeBinaryPathName );
				CPPUNIT_TEST( Test_Service_ChangeDisplayName );
				CPPUNIT_TEST( Test_Service_ChangeDescription );
                CPPUNIT_TEST( Test_Service_Control );
				CPPUNIT_TEST( Test_Service_Delete );
				CPPUNIT_TEST( Test_Service_GetConfig );
				CPPUNIT_TEST( Test_Service_Exists );
				CPPUNIT_TEST( Test_Service_GetStatus );
				CPPUNIT_TEST_SUITE_END();
			private:
				std::wstring service_name;
			public:
				void setUp();
				void tearDown();
				void Test_EntryPoints();
				void Test_Service_RenameRegistryEntry();
				void Test_Service_ChangeBinaryPathName();
				void Test_Service_ChangeDisplayName();
				void Test_Service_ChangeDescription();
				void Test_Service_Delete();
                void Test_Service_Control();
				void Test_Service_GetConfig();
				void Test_Service_Exists();
				void Test_Service_GetStatus();
			};
		}
	}
}
