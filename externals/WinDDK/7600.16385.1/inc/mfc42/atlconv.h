#if defined(USE_MFC6_WITH_ATL7)
#include "..\atlmfc\atlconv.h"
#define AFX_CRT_ERRORCHECK(expr) \
	AtlCrtErrorCheck(expr)
       
#else
#include "..\atl30\atlconv.h"
#define _ATL_NO_CONVERSIONS
#endif

