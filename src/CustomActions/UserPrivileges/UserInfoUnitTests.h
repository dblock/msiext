#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace UserPrivileges
		{
			class UserInfoUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( UserInfoUnitTests );
				CPPUNIT_TEST( Test_GetUserInfo );
				CPPUNIT_TEST( Test_GetUserNameFormatted );
				CPPUNIT_TEST( Test_GetUserNameFormattedDomain );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST( Test_GetAccountSid );
				CPPUNIT_TEST( Test_GetAccountSid_DefaultParam );
				CPPUNIT_TEST( Test_TranslateNameFormatted );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_GetUserInfo();
				void Test_EntryPoints();
				void Test_GetUserNameFormatted();
				void Test_GetUserNameFormattedDomain();
				void Test_GetAccountSid();
				void Test_GetAccountSid_DefaultParam();
				void Test_TranslateNameFormatted();
			};
        }
	}
}
