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

#define BIT(X) (1 << x)