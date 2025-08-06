#pragma once

#include "core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace lv {

	class LV_API logger {
	public:
		logger() = delete;

		static void init();

		inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return s_core_logger; }
		inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return s_client_logger; }

	private:
		inline static std::shared_ptr<spdlog::logger> s_core_logger;
		inline static std::shared_ptr<spdlog::logger> s_client_logger;
	};

}

#ifdef LV_ENABLE_LOGGING

	#define LV_CORE_TRACE(...)		::lv::logger::get_core_logger()->trace(__VA_ARGS__)
	#define LV_CORE_INFO(...)		::lv::logger::get_core_logger()->info(__VA_ARGS__)
	#define LV_CORE_DEBUG(...)		::lv::logger::get_core_logger()->debug(__VA_ARGS__)
	#define LV_CORE_WARNING(...)	::lv::logger::get_core_logger()->warn(__VA_ARGS__)
	#define LV_CORE_ERROR(...)		::lv::logger::get_core_logger()->error(__VA_ARGS__); __debugbreak()
	#define LV_CORE_CRITICAL(...)	::lv::logger::get_core_logger()->critical(__VA_ARGS__); __debugbreak()

	#define LV_LOG_TRACE(...)		::lv::logger::get_client_logger()->trace(__VA_ARGS__)
	#define LV_LOG_INFO(...)		::lv::logger::get_client_logger()->info(__VA_ARGS__)
	#define LV_LOG_DEBUG(...)		::lv::logger::get_client_logger()->debug(__VA_ARGS__)
	#define LV_LOG_WARNING(...)		::lv::logger::get_client_logger()->warn(__VA_ARGS__)
	#define LV_LOG_ERROR(...)		::lv::logger::get_client_logger()->error(__VA_ARGS__); __debugbreak()
	#define LV_LOG_CRITICAL(...)	::lv::logger::get_client_logger()->critical(__VA_ARGS__); __debugbreak()

#else

	#define LV_CORE_TRACE(...)
	#define LV_CORE_INFO(...)
	#define LV_CORE_DEBUG(...)
	#define LV_CORE_WARNING(...)
	#define LV_CORE_ERROR(...)
	#define LV_CORE_CRITICAL(...)

	#define LV_LOG_TRACE(...)
	#define LV_LOG_INFO(...)
	#define LV_LOG_DEBUG(...)
	#define LV_LOG_WARNING(...)
	#define LV_LOG_ERROR(...)
	#define LV_LOG_CRITICAL(...)

#endif