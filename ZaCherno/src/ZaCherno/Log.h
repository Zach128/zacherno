#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace ZaCherno
{

	class ZACHERNO_API Log
	{
	public:
		static void Init();

		// declare accessors for s_CoreLogger and s_ClientLogger

		inline static std::shared_ptr < spdlog::logger > & GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr < spdlog::logger > & GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr < spdlog::logger > s_CoreLogger;
		static std::shared_ptr < spdlog::logger > s_ClientLogger;

	};

}

// Core log methods
#define ZC_CORE_ERROR(...)  ::ZaCherno::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZC_CORE_WARN(...)   ::ZaCherno::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZC_CORE_INFO(...)   ::ZaCherno::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZC_CORE_TRACE(...)  ::ZaCherno::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZC_CORE_FATAL(...)  ::ZaCherno::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log methods
#define ZC_ERROR(...)       ::ZaCherno::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZC_WARN(...)        ::ZaCherno::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZC_INFO(...)        ::ZaCherno::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZC_TRACE(...)       ::ZaCherno::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZC_FATAL(...)       ::ZaCherno::Log::GetClientLogger()->fatal(__VA_ARGS__)