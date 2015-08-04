// CoreServicesDLL.h

#ifdef CORESERVICESSDLL_EXPORTS
#define CORESERVICESDLL_API __declspec(dllexport) 
#else
#define CORESERVICESDLL_API __declspec(dllimport) 
#endif

#include "SceneFileLoader.h"
#include "Engine.h"