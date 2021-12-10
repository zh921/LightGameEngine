#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace MiniGameEngine
{
	class MGE_API Log
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

// Core log macros
#define MGE_CORE_TRACE(...)		::MiniGameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MGE_CORE_INFO(...)		::MiniGameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MGE_CORE_WARN(...)		::MiniGameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MGE_CORE_ERROR(...)		::MiniGameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MGE_CORE_FATAL(...)		::MiniGameEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MGE_TRACE(...)		::MiniGameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MGE_INFO(...)		::MiniGameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define MGE_WARN(...)		::MiniGameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MGE_ERROR(...)		::MiniGameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define MGE_FATAL(...)		::MiniGameEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
