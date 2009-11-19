#pragma once

namespace AppSecInc {
namespace UnitTests {
namespace Msi 
{
    class MsiPackageUnitTests :  public CPPUNIT_NS::TestFixture
    {
	    CPPUNIT_TEST_SUITE(MsiPackageUnitTests);
        CPPUNIT_TEST(testConstructorDestructor);
        CPPUNIT_TEST(testOpenPackage);
	    CPPUNIT_TEST_SUITE_END();
    public:
        void testConstructorDestructor();
        void testOpenPackage();
    };
}}}
