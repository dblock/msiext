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
				CPPUNIT_TEST( testConstructorDestructor );
				CPPUNIT_TEST( testCreate );
				CPPUNIT_TEST( testLoad );
				CPPUNIT_TEST( testLoadXml );
				CPPUNIT_TEST( testGetXml );
				CPPUNIT_TEST( testAppendChild );
				CPPUNIT_TEST( testXslTransform );
				CPPUNIT_TEST( testFindNode );
				CPPUNIT_TEST( testHasNode );
				CPPUNIT_TEST( testSelectNode );
				CPPUNIT_TEST( testHasNodes );
				CPPUNIT_TEST( testSelectNodes );
				CPPUNIT_TEST( testFindNodes );
				CPPUNIT_TEST( testGetNodeXml );
				CPPUNIT_TEST( testGetNodeValue );
				CPPUNIT_TEST( testGetNodeBoolValue );
				CPPUNIT_TEST( testFindAttribute );
				CPPUNIT_TEST( testGetAttributeValue );
				CPPUNIT_TEST( testGetAttributeValueXPath );
				CPPUNIT_TEST( testGetAttributeBoolValue );
				CPPUNIT_TEST( testSetAttribute );
				CPPUNIT_TEST( testSelectAttribute );
				CPPUNIT_TEST( testHasAttribute );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testConstructorDestructor();
				void testCreate();
				void testLoad();
				void testLoadXml();
				void testGetXml();
				void testAppendChild();
				void testXslTransform();
				// node
				void testFindNode();
				void testHasNode();
				void testSelectNode();
				// nodes
				void testHasNodes();
				void testSelectNodes();
				void testFindNodes();
				// node value
				void testGetNodeXml();
				void testGetNodeValue();
				void testGetNodeBoolValue();
				// attributes
				void testFindAttribute();
				void testGetAttributeValue();
				void testGetAttributeValueXPath();
				void testGetAttributeBoolValue();
				void testSetAttribute();
				void testSelectAttribute();
				void testHasAttribute();
			};
		}
	}
}


