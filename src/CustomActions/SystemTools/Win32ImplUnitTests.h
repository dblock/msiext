#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Win32
		{
			class Win32ImplUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( Win32ImplUnitTests );
				CPPUNIT_TEST( Test_Win32_CopyMoveFile );
				CPPUNIT_TEST( Test_Win32_DeleteFile );
                CPPUNIT_TEST( Test_Win32_CopyFileOverwrite );
				CPPUNIT_TEST( Test_Win32_CopyFiles );
				CPPUNIT_TEST( Test_Win32_MoveFiles );
				CPPUNIT_TEST( Test_Win32_DeleteFiles );
				CPPUNIT_TEST( Test_Win32_Execute );
				CPPUNIT_TEST( Test_Win32_ScheduledExecute );
				CPPUNIT_TEST( Test_Win32_ConditionalExecute );
				CPPUNIT_TEST( Test_Win32_CreateDirectory );
				CPPUNIT_TEST( Test_Win32_DeleteDirectory );
				CPPUNIT_TEST( Test_Win32_GetParentDirectory );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST( Test_Win32_GetFileSize );
				CPPUNIT_TEST( Test_Win32_FileExists );
				CPPUNIT_TEST( Test_Win32_WriteFile );
				CPPUNIT_TEST( Test_Win32_ReadFile );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_Win32_CopyFileOverwrite();
                void Test_Win32_CopyMoveFile();
                void Test_Win32_DeleteFile();
				void Test_EntryPoints();
                void Test_Win32_CopyFiles();
				void Test_Win32_MoveFiles();
                void Test_Win32_DeleteFiles();
                void Test_Win32_Execute();
                void Test_Win32_ConditionalExecute();
                void Test_Win32_ScheduledExecute();
				void Test_Win32_CreateDirectory();
				void Test_Win32_DeleteDirectory();
				void Test_Win32_GetParentDirectory();
                void Test_Win32_GetFileSize();
                void Test_Win32_FileExists();
				void Test_Win32_WriteFile();
				void Test_Win32_ReadFile();
			};
        }
	}
}
