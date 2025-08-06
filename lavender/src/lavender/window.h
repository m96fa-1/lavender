#pragma once

#include "lavender/core.h"
#include "lavender/events/event.h"

namespace lv {

	struct window_props {
		int width, height;
		std::string title;
		bool vsync;
		bool center_window;

		window_props(int width = 1280, int height = 720, const char* title = "Lavender Engine", bool vsync = true, bool center_window = true)
			: width(width), height(height), title(title), center_window(center_window) {
			
		}
	};

	class LV_API window {
	public:
		using event_callback_func = std::function<void(event&)>;

		virtual ~window() {
		
		}

		virtual void on_update() = 0;

		[[nodiscard]] virtual inline int get_width() const noexcept = 0;
		[[nodiscard]] virtual inline int get_height() const noexcept = 0;
		[[nodiscard]] virtual inline bool is_vsync() const noexcept = 0;
		
		virtual void set_event_callback(const event_callback_func& callback) = 0;

		virtual void* get_native_window() const = 0;

		static window* create(const window_props& props = window_props());
	};

}