#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace ActiveDirectory
		{
			class DirectoryObjectPickerUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( DirectoryObjectPickerUnitTests );
				// these cannot be enabled in build, they popup a dialog that requires user action
				// CPPUNIT_TEST( Test_DirectoryObjectPicker_Raw );
				// CPPUNIT_TEST( Test_DirectoryObjectPicker_Users );
				// CPPUNIT_TEST( Test_DirectoryObjectPicker_Computers );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_DirectoryObjectPicker_Users();
				void Test_DirectoryObjectPicker_Computers();
				void Test_DirectoryObjectPicker_Raw();
				void Test_EntryPoints();
			};
        }
	}
}
