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