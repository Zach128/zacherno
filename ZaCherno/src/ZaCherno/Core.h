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

// Returns the value of 1 left-shifted by x number of bits
#define BIT(x) (1 << x)