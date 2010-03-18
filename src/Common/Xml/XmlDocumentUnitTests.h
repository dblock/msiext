#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Xml
		{
			class XmlDocumentUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( XmlDocumentUnitTests );
				CPPUNIT_TEST( testConstructorDestructor );
				CPPUNIT_TEST( testSelectNodeValue );
				CPPUNIT_TEST( testSelectNodeBoolValue );
				CPPUNIT_TEST( testXslTransform );
				CPPUNIT_TEST( testSelectNodeAttributeValue );
                CPPUNIT_TEST( testGetXml );
				CPPUNIT_TEST( testSelectNodes );
				CPPUNIT_TEST( testCreate );
                CPPUNIT_TEST( testAppendChild );
                CPPUNIT_TEST( testSetAttribute );
				CPPUNIT_TEST( testSelectAttributeValue );
				CPPUNIT_TEST( testSelectAttributeBoolValue );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testConstructorDestructor();
				void testSelectNodeValue();
				void testSelectNodeBoolValue();
				void testXslTransform();
				void testSelectNodeAttributeValue();
                void testGetXml();
                void testSelectNodes();
                void testCreate();
                void testAppendChild();
                void testSetAttribute();
				void testSelectAttributeValue();
				void testSelectAttributeBoolValue();
			};
		}
	}
}


