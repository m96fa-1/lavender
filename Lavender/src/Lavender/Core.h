#pragma once

#ifdef LV_PLATFORM_WINDOWS
	#ifdef LV_BUILD_DLL
		#define LV_API __declspec(dllexport)
	#else
		#define LV_API __declspec(dllimport)
	#endif
#else
	#error Lavender only supports Windows for now.
#endif

#include "Log.h"

#ifdef LV_ENABLE_ASSERT
	#define LV_CORE_ASSERT(x, ...) { if(!(x)) { LV_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LV_ASSERT(x, ...) { if(!(x)) { LV_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	// Set them as nothing (will be ignored/deleted by the compiler)
	#define LV_CORE_ASSERT(x, ...)
	#define LV_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)