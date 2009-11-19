#include "StdAfxUnitTests.h"
#include "CryptoPPUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Crypt::CryptoPPUnitTest);

using namespace AppSecInc::UnitTests::Crypt;

void CryptoPPUnitTest::testScramble41(void)
{
    typedef struct
    {
        LPCSTR szSalt;
        LPCSTR szInput;
        LPCSTR szOutput;
    } TestData;

    TestData testdata[] =
    {
        { "", "", "5A0BED3C1BE5165CDA0428C29C4A110673DB8982" },
        { "salt", "input", "1C6B9EAF2982EF8EC5B5A637ED4C76FDBEBDF260" }
    };

    for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
    {
        BYTE pbOut[20];
        BYTE pbMidway[20];
        CryptoPP::SHA1 context1, context2, context3;
        context1.Update(reinterpret_cast<const byte *>(testdata[i].szInput), strlen(testdata[i].szInput));
        context1.Final(pbOut);
        context2.Update(pbOut, sizeof(pbOut));
        context2.Final(pbMidway);
        context3.Update(reinterpret_cast<const byte *>(testdata[i].szSalt), strlen(testdata[i].szSalt));
        context3.Update(pbMidway, sizeof(pbMidway));
        context3.Final(pbMidway);
        LPBYTE pbDest = pbOut;
        for(int j = 0; j < sizeof(pbMidway); j++)
        {
            *(pbDest++) ^= pbMidway[j];
        }

        CryptoPP::HexEncoder hexencoder;
        hexencoder.PutMessageEnd(pbOut, sizeof(pbOut));
        std::string output;
        output.resize(sizeof(pbOut) * 2);
        hexencoder.Get(reinterpret_cast<byte *>(const_cast<char *>(output.c_str())), output.size());

        CPPUNIT_ASSERT_MESSAGE(output, output == testdata[i].szOutput);
    }
}

void CryptoPPUnitTest::testSHA1(void)
{
    typedef struct
    {
        LPCSTR szSalt;
        LPCSTR szInput;
        LPCSTR szOutput;
    } TestData;

    TestData testdata[] =
    {
        { "", "", "BE1BDEC0AA74B4DCB079943E70528096CCA985F8" },
        { "salt", "input", "2FC13892909EAA8817298D32FAA908594B639D45" }
    };

    for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
    {
        BYTE pbOut[20];
        CryptoPP::SHA1 context1, context2;
        context1.Update(reinterpret_cast<const byte *>(testdata[i].szInput), strlen(testdata[i].szInput));
        context1.Final(pbOut);
        context2.Update(pbOut, sizeof(pbOut));
        context2.Final(pbOut);

        CryptoPP::HexEncoder hexencoder;
        hexencoder.PutMessageEnd(pbOut, sizeof(pbOut));
        std::string output;
        output.resize(sizeof(pbOut) * 2);
        hexencoder.Get(reinterpret_cast<byte *>(const_cast<char *>(output.c_str())), output.size());

        CPPUNIT_ASSERT(output == testdata[i].szOutput);
    }
}

void CryptoPPUnitTest::testHexEncoder(void)
{
    typedef struct
    {
        LPCSTR szInput;
        LPCSTR szOutput;
    } TestData;

    TestData testdata[] =
    {
        { "", "" },
        { "test", "74657374" }
    };

    for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
    {
        std::string input(testdata[i].szInput);

        CryptoPP::HexEncoder hexencoder;
        hexencoder.PutMessageEnd(reinterpret_cast<const byte *>(input.c_str()), input.length());

        std::string output;
        output.resize(input.length() * 2);
        hexencoder.Get(reinterpret_cast<byte *>(const_cast<char *>(output.c_str())), output.size());

        CPPUNIT_ASSERT(output == testdata[i].szOutput);
    }
}
