#ifndef CPPUNIT_TESTCOMPSITE_H    // -*- C++ -*-
#define CPPUNIT_TESTCOMPSITE_H

#include <cppunit/Test.h>
#include <string>

#if CPPUNIT_NEED_DLL_DECL
#pragma warning( push )
#pragma warning( disable: 4251 )  // X needs to have dll-interface to be used by clients of class Z
#endif 

CPPUNIT_NS_BEGIN


/*! \brief A Composite of Tests.
 *
 * Base class for all test composites. Subclass this class if you need to implement
 * a custom TestSuite.
 * 
 * \see Test, TestSuite.
 */
class CPPUNIT_API TestComposite : public Test
{
public:
  TestComposite( const std::string &name = "" );

  ~TestComposite();

  void run( TestResult *result );

  int countTestCases() const;
  
  std::string getName() const;

private:
  TestComposite( const TestComposite &other );
  TestComposite &operator =( const TestComposite &other ); 

  virtual void doStartSuite( TestResult *controller );
  virtual void doRunChildTests( TestResult *controller );
  virtual void doEndSuite( TestResult *controller );

private:
  const std::string m_name;
};


CPPUNIT_NS_END

#if CPPUNIT_NEED_DLL_DECL
#pragma warning( pop )
#endif

#endif // CPPUNIT_TESTCOMPSITE_H
