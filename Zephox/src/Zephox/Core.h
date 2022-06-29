#pragma once

#ifdef ZP_PLATFORM_WINDOWS
	#ifdef ZP_BUILD_DLL
		#define ZP_API __declspec(dllexport)
	#else
		#define ZP_API __declspec(dllimport)
	#endif
#else
	#error Zephox currently only supports windows!
#endif

#ifdef ZP_ENABLE_ASSERTS
	#define ZP_ASSERT(x, ...) { if(!(x)) { ZP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ZP_CORE_ASSERT(x, ...) { if(!(x)) { ZP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ZP_ASSERT(x, ...)
	#define ZP_CORE_ASSERT(x, ...)
#endif

#define BIT(X) (1 << x)