#pragma once

namespace AppSecInc {
namespace UnitTests {
namespace Msi 
{
    class MsiInstallUnitTests : public CPPUNIT_NS::TestFixture
    {
	    CPPUNIT_TEST_SUITE(MsiInstallUnitTests);
        CPPUNIT_TEST(testGetSetProperty);
        CPPUNIT_TEST(testPrologEpilog);
        CPPUNIT_TEST(testGetBinaryData);
        CPPUNIT_TEST(testGetViewData);
        CPPUNIT_TEST(testGetViewInfo);
        CPPUNIT_TEST(testActionData);
        CPPUNIT_TEST(testGetFormattedString);
	    CPPUNIT_TEST_SUITE_END();
    public:
        void testGetSetProperty();
        void testGetBinaryData();
        void testPrologEpilog();
        void testGetViewData();
        void testGetViewInfo();
        void testGetFormattedString();
        void testActionData();
    private:
        int testPrologEpilogImpl_CaError(MSIHANDLE h);
        int testPrologEpilogImpl_StdException(MSIHANDLE h);
        int testPrologEpilogImpl_CppException(MSIHANDLE h);
        int testPrologEpilogImpl_ComException(MSIHANDLE h);
    };

}}}
