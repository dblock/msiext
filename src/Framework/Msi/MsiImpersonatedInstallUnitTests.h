#pragma once

namespace AppSecInc {
namespace UnitTests {
namespace Msi 
{
    class MsiImpersonatedInstallUnitTests : public CPPUNIT_NS::TestFixture
    {
	    CPPUNIT_TEST_SUITE(MsiImpersonatedInstallUnitTests);
        CPPUNIT_TEST(testImpersonated);
	    CPPUNIT_TEST_SUITE_END();
    public:
        virtual void setUp();
        virtual void tearDown();
        void testImpersonated();
    };

}}}
