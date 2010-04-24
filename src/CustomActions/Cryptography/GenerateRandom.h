#pragma once

/*!
\brief GenerateRandom generate a random, base-64-encoded string
\param GENERATE_RANDOM_LENGTH Length of the string to generate.
\return GENERATE_RANDOM_RESULT Randomly generated string.
*/
CA_API UINT __stdcall GenerateRandomString(MSIHANDLE hInstall);
