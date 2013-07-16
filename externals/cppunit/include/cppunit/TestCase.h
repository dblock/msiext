#ifndef CPPUNIT_TESTCASE_H
#define CPPUNIT_TESTCASE_H

#include <cppunit/Portability.h>
#include <cppunit/TestLeaf.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <string>

#if CPPUNIT_NEED_DLL_DECL
#pragma warning( push )
#pragma warning( disable: 4251 )  // X needs to have dll-interface to be used by clients of class Z
#endif 

CPPUNIT_NS_BEGIN


class TestResult;


/*! \brief A single test object.
 *
 * This class is used to implement a simple test case: define a subclass
 * that overrides the runTest method.
 *
 * You don't usually need to use that class, but TestFixture and TestCaller instead.
 *
 * You are expected to subclass TestCase is you need to write a class similiar
 * to TestCaller.
 */
class CPPUNIT_API TestCase : public TestLeaf,
                             public TestFixture
{
public:

    TestCase( const std::string &name );

    TestCase();

    ~TestCase();
    
    virtual void run(TestResult *result);

    std::string getName() const;

    //! FIXME: this should probably be pure virtual.
    virtual void runTest();
    
private:
    TestCase( const TestCase &other ); 
    TestCase &operator=( const TestCase &other ); 
    
private:
    const std::string m_name;
};

CPPUNIT_NS_END

#if CPPUNIT_NEED_DLL_DECL
#pragma warning( pop )
#endif

#endif // CPPUNIT_TESTCASE_H 
