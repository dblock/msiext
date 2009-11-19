#pragma once

namespace AppSecInc {
namespace UnitTests {
namespace MsiShim {

/*! \class MsiShimUnitTest
	\brief Unit test for a custom action fake environment
*/
class MsiShimUnitTest :  public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( MsiShimUnitTest );
	CPPUNIT_TEST(RecordTest);
	CPPUNIT_TEST(PropertiesTest);
    CPPUNIT_TEST(TwoInstallationsTest);
	CPPUNIT_TEST_SUITE_END();
public:
	void RecordTest();
	void PropertiesTest();
    void TwoInstallationsTest();
};

} // namespace MsiShim {
} // namespace UnitTests {
} // namespace AppSecInc {

