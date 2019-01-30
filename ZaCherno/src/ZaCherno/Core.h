#pragma once

// Handles dll export/import based on definitions.
#ifdef ZC_PLATFORM_WINDOWS
	#ifdef ZC_BUILD_DLL
		#define ZACHERNO_API __declspec(dllexport)
	#else
		#define ZACHERNO_API __declspec(dllimport)
	#endif
#else
	#error zaCherno only supports 64-bit Windows.
#endif

// Set of debug macros which assert that a provided value(s) are equal to true
// If not, log an error and instruct any attached debugger to break on the line
#ifdef ZC_ENABLE_ASSERTS
	#define ZC_ASSERT(x, ...) { if(!(x)) { ZC_ERROR("Assertation failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ZC_CORE_ASSERT(x, ...) { if(!(x)) { ZC_CORE_ERROR("Assertation failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ZC_ASSERT(x, ...)
	#define ZC_CORE_ASSERT(x, ...)
#endif

// Returns the value of 1 left-shifted by x number of bits
#define BIT(x) (1 << x)