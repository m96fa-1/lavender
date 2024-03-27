#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Lv {

	class LV_API Log {
	public:
		Log() = delete;

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};

}

// Logger macros
#define LV_CORE_TRACE(...) ::Lv::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LV_CORE_INFO(...) ::Lv::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LV_CORE_DEBUG(...) ::Lv::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define LV_CORE_WARNING(...) ::Lv::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LV_CORE_ERROR(...) ::Lv::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LV_CORE_CRITICAL(...) ::Lv::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define LV_TRACE(...) ::Lv::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LV_INFO(...) ::Lv::Log::GetClientLogger()->info(__VA_ARGS__)
#define LV_DEBUG(...) ::Lv::Log::GetClientLogger()->debug(__VA_ARGS__)
#define LV_WARNING(...) ::Lv::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LV_ERROR(...) ::Lv::Log::GetClientLogger()->error(__VA_ARGS__)
#define LV_CRITICAL(...) ::Lv::Log::GetClientLogger()->critical(__VA_ARGS__)