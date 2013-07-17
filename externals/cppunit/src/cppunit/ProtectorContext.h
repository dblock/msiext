#ifndef CPPUNIT_PROTECTORCONTEXT_H
#define CPPUNIT_PROTECTORCONTEXT_H

#include <cppunit/Portability.h>
#include <string>

#if CPPUNIT_NEED_DLL_DECL
#pragma warning( push )
#pragma warning( disable: 4251 )  // X needs to have dll-interface to be used by clients of class Z
#endif 

CPPUNIT_NS_BEGIN

class Test;
class TestResult;


/*! \brief Protector context (Implementation).
 * Implementation detail.
 * \internal Context use to report failure in Protector.
 */
class CPPUNIT_API ProtectorContext
{
public:
  ProtectorContext( Test *test,
                    TestResult *result,
                    const std::string &shortDescription )
      : m_test( test )
      , m_result( result )
      , m_shortDescription( shortDescription )
  {
  }

  Test *m_test;
  TestResult *m_result;
  std::string m_shortDescription;
};


CPPUNIT_NS_END

#if CPPUNIT_NEED_DLL_DECL
#pragma warning( pop )
#endif

#endif // CPPUNIT_PROTECTORCONTEXT_H

