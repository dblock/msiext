#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace StringTools
		{
			class StringToolsImplUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( StringToolsImplUnitTests );
				CPPUNIT_TEST( Test_StringReplace );
				CPPUNIT_TEST( Test_StringTrim );
				CPPUNIT_TEST( Test_RegexMatch );
				CPPUNIT_TEST( Test_RegexReplace );
				CPPUNIT_TEST( Test_StringToLower );
				CPPUNIT_TEST( Test_StringToUpper );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
				void Test_EntryPoints();
                void Test_StringReplace();
                void Test_StringTrim();
                void Test_RegexMatch();
                void Test_RegexReplace();
                void Test_StringToLower();
                void Test_StringToUpper();
			};
        }
	}
}
