#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Xml
		{
			class XmlToolsGetUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( XmlToolsGetUnitTests );
				CPPUNIT_TEST( Test_SelectNodeValue );
                CPPUNIT_TEST( Test_SelectNodeAttributeValue );
				CPPUNIT_TEST( Test_XslTranform );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST( Test_DeleteNodes );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_SelectNodeValue();
                void Test_XslTranform();
                void Test_SelectNodeAttributeValue();
				void Test_EntryPoints();
				void Test_DeleteNodes();
			};
        }
	}
}
