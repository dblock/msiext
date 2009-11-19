#pragma once

namespace AppSecInc {
namespace UnitTests {
namespace Msi 
{
    class MsiFlagUnitTest :  public CPPUNIT_NS::TestFixture
    {
	    CPPUNIT_TEST_SUITE(MsiFlagUnitTest);
        CPPUNIT_TEST(MsiFlag_GetFlagValue_Test);
		CPPUNIT_TEST(MsiFlag_GetFlagName_Test);
        CPPUNIT_TEST(MsiFlag_GetStringFlagsValue_Test);
	    CPPUNIT_TEST_SUITE_END();
    public:
        void MsiFlag_GetFlagValue_Test();
		void MsiFlag_GetFlagName_Test();
        void MsiFlag_GetStringFlagsValue_Test();
    };
}}}
