#pragma once

#if defined(LV_WINDOWS)
	#ifdef LV_BUILD_DLL
		#define LV_API __declspec(dllexport)
	#else
		#define LV_API __declspec(dllimport)
	#endif

#elif defined(LV_MACOSX)
	#ifdef LV_BUILD_DLL
		#define LV_API 
	#else
		#define LV_API 
	#endif

#elif defined(LV_LINUX)
	#ifdef LV_BUILD_DLL
		#define LV_API __attribute__((visibility("default")))
	#else
		#define LV_API 
	#endif

#else
	#error What on earth is the platform you are using?
#endif

#ifndef LV_DIST
	#define LV_ENABLE_ASSERT
	#define LV_ENABLE_LOGGING
#endif

#ifdef LV_ENABLE_ASSERT
	#define LV_CORE_ASSERT(x, ...) if(!(x)) { LV_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); }
	#define LV_ASSERT(x, ...) if(!(x)) { LV_LOG_ERROR("Assertion failed: {0}", __VA_ARGS__); }

#else
	#define LV_CORE_ASSERT(x, ...)
	#define LV_ASSERT(x, ...)
#endif

#define LV_BIND_EVENT_FUNC(func) std::bind(&func, this, std::placeholders::_1)