#include "Logger.h"
#include <spdlog\sinks\stdout_color_sinks.h>

namespace Eunoia {

	std::shared_ptr<spdlog::logger> Logger::s_EngineLogger;
	std::shared_ptr<spdlog::logger> Logger::s_AppLogger;

	void Logger::Init()
	{
#ifdef EU_DEBUG
		spdlog::set_pattern("%^[T] %n: %v%&");

		s_EngineLogger = spdlog::stdout_color_mt("EUNOIA");
		s_AppLogger = spdlog::stdout_color_mt("APPLICATION");
		s_EngineLogger->set_level(spdlog::level::trace);
		s_AppLogger->set_level(spdlog::level::trace);
		
		EU_LOG_INFO("Initialized Loggers");
#endif
	}

}
