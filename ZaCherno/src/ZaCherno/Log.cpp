#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace ZaCherno
{

	// Declare two loggers for the engine and application using shared pointers for reference
	std::shared_ptr < spdlog::logger > Log::s_CoreLogger;
	std::shared_ptr < spdlog::logger > Log::s_ClientLogger;

	void Log::Init()
	{

		// Define the logging message template consisting of time, class name, and message
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		// Initialise the Core logger for the engine
		s_CoreLogger = spdlog::stdout_color_mt("ZACHERNO");
		s_CoreLogger->set_level(spdlog::level::trace);

		//Initialise the Application logger for the main application
		s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ClientLogger->set_level(spdlog::level::trace);

	}

}