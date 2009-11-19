#pragma once

namespace AppSecInc {
namespace UnitTests {
namespace Msi 
{
    class MsiDatabaseUnitTests :  public CPPUNIT_NS::TestFixture
    {
	    CPPUNIT_TEST_SUITE(MsiDatabaseUnitTests);
        CPPUNIT_TEST(testConstructorDestructor);
        CPPUNIT_TEST(testCreateDatabase);
        CPPUNIT_TEST(testImport);
	    CPPUNIT_TEST_SUITE_END();
    public:
        void testConstructorDestructor();
        void testCreateDatabase();
        void testImport();
    };
}}}
