#pragma once

#include "../Common.h"
#include <memory>
#include <spdlog\spdlog.h>

#ifdef EU_DEBUG

#ifdef EU_ENGINE
#define EU_LOG_TRACE(...) Eunoia::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define EU_LOG_INFO(...) Eunoia::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define EU_LOG_WARN(...) Eunoia::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define EU_LOG_ERROR(...) Eunoia::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define EU_LOG_FATAL(...) Eunoia::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#else
#define EU_LOG_TRACE(...) Eunoia::Logger::GetAppLogger()->trace(__VA_ARGS__)
#define EU_LOG_INFO(...) Eunoia::Logger::GetAppLogger()->trace(__VA_ARGS__)
#define EU_LOG_WARN(...) Eunoia::Logger::GetAppLogger()->trace(__VA_ARGS__)
#define EU_LOG_ERROR(...) Eunoia::Logger::GetAppLogger()->trace(__VA_ARGS__)
#define EU_LOG_FATAL(...) Eunoia::Logger::GetAppLogger()->trace(__VA_ARGS__)
#endif
#define EU_LOG_TRACE
#define EU_LOG_INFO
#define EU_LOG_WARN
#define EU_LOG_ERROR
#define EU_LOG_FATAL
#endif

namespace Eunoia {

	class EU_API Logger
	{
	public:
		static void Init();

		static inline std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		static inline std::shared_ptr<spdlog::logger>& GetAppLogger() { return s_AppLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_AppLogger;
	};

}
