#pragma once

// disable warning C4995: 'function': name was marked as #pragma deprecated
// atlbase.h brings in deprecated functions
#pragma warning(disable: 4995) 

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

#ifndef STRICT
#define STRICT
#endif

#define WIN32_LEAN_AND_MEAN

#include <atlbase.h>
#include <comdef.h>
#include <strsafe.h>
#include <windows.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <map>
#include <list>
