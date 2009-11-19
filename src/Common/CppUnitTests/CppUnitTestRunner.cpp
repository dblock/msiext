#include "StdAfx.h"
#include "CppUnitTests.h"

std::string CppUnitTestRunner::s_XmlPath;

CppUnitTestRunner::CppUnitTestRunner(void)
{
	char moduleFileName[MAX_PATH];
    CPPUNIT_ASSERT(::GetModuleFileNameA(NULL, moduleFileName, MAX_PATH) != 0);

	std::string smoduleFileName = moduleFileName;
    int backslashPos = smoduleFileName.rfind('\\', smoduleFileName.length());
    CPPUNIT_ASSERT(backslashPos != smoduleFileName.npos);

    s_XmlPath = smoduleFileName.substr(0, backslashPos);
    m_TestSuiteName = smoduleFileName.substr(backslashPos + 1, 
        smoduleFileName.length() - backslashPos - ARRAYSIZE(".exe"));
}

CppUnitTestRunner::~CppUnitTestRunner(void)
{
}

std::string CppUnitTestRunner::Help()
{
    return Help(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
}

std::string CppUnitTestRunner::Help(CPPUNIT_NS::Test * test, int level)
{
    std::stringstream s;
    for (int i = 0; i < test->getChildTestCount(); i++)
    {
        s << std::endl;
		if (0 < level)
		{
			std::string spaces(level, ' ');
			s << spaces;
		}
		CPPUNIT_NS::Test * child = test->getChildTestAt(i);
		s << child->getName();
		s << Help(child, level + 1);
    }
    return s.str();
}

int CppUnitTestRunner::Run(int argc, char* argv[])
{
    std::vector<CPPUNIT_NS::Test *> tests;
    CPPUNIT_NS::Test * root = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
    for (int i = 1; i < argc; i++)
    {
        if (! strcmp(argv[i], "/?") || ! strcmp(argv[i], "-?") || ! strcmp(argv[i], "--help"))
        {
            std::cout << "usage: " << argv[0] << " <test-suite|test> [<test-suite1|test1> ... ]";
            std::cout << std::endl << Help();
            return 0;
        }
        else
        {
            try
            {
                CPPUNIT_NS::Test * test = NULL;
                test = root->findTest(argv[i]);
                tests.push_back(test);
            }
            catch(std::invalid_argument&) 
            { 
                std::cout << "invalid test: " << argv[i];
                std::cout << std::endl << Help();
                return -1;
            }
        }
    }

    return tests.size() ? Run(tests) : Run();
}

int CppUnitTestRunner::Run()
{
    std::vector<CPPUNIT_NS::Test *> tests;
    tests.push_back(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    return Run(tests);
}

int CppUnitTestRunner::Run(std::vector<CPPUNIT_NS::Test *>& tests)
{
    CPPUNIT_NS::TestRunner					runner;
    CPPUNIT_NS::TestResult					controller;
    CPPUNIT_NS::TestResultCollector			result;
    CPPUNIT_NS::BriefTestProgressListener	progress;
    CPPUNIT_NS::CompilerOutputter			outputter( &result, std::cerr );
    std::string								xmlFileName   = (s_XmlPath=="" ? "" : s_XmlPath + "\\") + m_TestSuiteName + ".xml";
    std::ofstream							output_file( xmlFileName.c_str() , std::ios::out );
    CPPUNIT_NS::XmlOutputter                 xmloutputter( &result, output_file );

    controller.addListener( &result );        
    controller.addListener( &progress );      

    for each (CPPUNIT_NS::Test * test in tests)
        runner.addTest(test);

    runner.run( controller );

    outputter.write();
    xmloutputter.write();

    return result.wasSuccessful() ? EXIT_SUCCESS : EXIT_FAILURE;
}
