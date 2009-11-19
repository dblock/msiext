#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace TemplateFiles
		{
			class TemplateFilesUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( TemplateFilesUnitTests );
				CPPUNIT_TEST( Test_TemplateFiles);
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_TemplateFiles();
                void Test_EntryPoints();
			};
        }
	}
}
