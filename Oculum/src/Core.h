#pragma once

#ifdef OC_BUILD_DLL
	#define OC_API __declspec(dllexport)
#else
	#define OC_API __declspec(dllimport)
#endif