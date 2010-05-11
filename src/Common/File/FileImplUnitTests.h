#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace File
		{
			class FileUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( FileUnitTests );
				CPPUNIT_TEST( testGetTemporaryFileName );
				CPPUNIT_TEST( testGetTemporaryDirectory );
				CPPUNIT_TEST( testGetModuleDirectory );
				CPPUNIT_TEST( testFileDirectoryExists );
				CPPUNIT_TEST( testDelete );
                CPPUNIT_TEST( testDirectoryCombine );
                CPPUNIT_TEST( testGetFileSize );
                CPPUNIT_TEST( testGetFilesRecursive );
                CPPUNIT_TEST( testReadToEnd );
                CPPUNIT_TEST( testFileWrite );
                CPPUNIT_TEST( testFileCreate );
				CPPUNIT_TEST( testDirectoryCreate );
				CPPUNIT_TEST( testDirectoryDelete );
                CPPUNIT_TEST( testSizeToString );
				CPPUNIT_TEST( testGetCurrentDirectory );
				CPPUNIT_TEST( testGetFilesWithInvalidWildcard );
				CPPUNIT_TEST( testGetFilesWithWildcard );
				CPPUNIT_TEST( testGetFilesWithNoWildcard );
				CPPUNIT_TEST( testGetParentDirectory );
				CPPUNIT_TEST( testGetSpecialFolderPath );
				CPPUNIT_TEST( testIsAbsolutePath );
				CPPUNIT_TEST( testReadAndConvertToEnd );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testGetTemporaryFileName();
                void testGetTemporaryDirectory();
				void testGetModuleDirectory();
				void testFileDirectoryExists();
				void testDelete();
                void testDirectoryCombine();
                void testGetFileSize();
                void testGetFilesRecursive();
				void testGetFilesWithWildcard();
				void testGetFilesWithNoWildcard();
				void testGetFilesWithInvalidWildcard();
                void testReadToEnd();
                void testFileWrite();
                void testFileCreate();
				void testDirectoryCreate();
				void testDirectoryDelete();
                void testSizeToString();
				void testGetCurrentDirectory();
				void testGetParentDirectory();
				void testGetSpecialFolderPath();
				void testIsAbsolutePath();
				void testReadAndConvertToEnd();
			};
		}
	}
}
