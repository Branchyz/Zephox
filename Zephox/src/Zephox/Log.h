#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Zephox {
	class ZP_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core macros
#define ZP_CORE_TRACE(...)   ::Zephox::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZP_CORE_INFO(...)    ::Zephox::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZP_CORE_WARN(...)    ::Zephox::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZP_CORE_ERROR(...)   ::Zephox::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZP_CORE_FATAL(...)   ::Zephox::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client macros
#define ZP_TRACE(...)   ::Zephox::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZP_INFO(...)    ::Zephox::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZP_WARN(...)    ::Zephox::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZP_ERROR(...)   ::Zephox::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZP_FATAL(...)   ::Zephox::Log::GetClientLogger()->critical(__VA_ARGS__)