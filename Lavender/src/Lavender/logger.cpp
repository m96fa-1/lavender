#include "lvpch.h"
#include "logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace lv {

	void logger::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_core_logger = spdlog::stdout_color_mt("LAVENDER");
		s_core_logger->set_level(spdlog::level::trace);
		s_client_logger = spdlog::stdout_color_mt("CLIENT");
		s_client_logger->set_level(spdlog::level::trace);
	}

}