#pragma once
#include "event.h"

namespace lv {
	
	class LV_API window_close_event : public event {
	public:
		EVENT_CLASS_TYPE(window_close)
		EVENT_CLASS_CATEGORY(window_events_category)
	};

	class LV_API window_resize_event : public event {
	public:
		window_resize_event(int width, int height)
			: m_width(width), m_height(height) {
		
		}

		[[nodiscard]] inline int get_width() const noexcept { return m_width; }
		[[nodiscard]] inline int get_height() const noexcept { return m_height; }

		std::string to_string() const noexcept override {
			return std::format("window_resize_event: {}, {}", m_width, m_height);
		}

		EVENT_CLASS_TYPE(window_resize)
		EVENT_CLASS_CATEGORY(window_events_category)

	private:
		int m_width, m_height;
	};

	class LV_API window_move_event : public event {
	public:
		EVENT_CLASS_TYPE(window_move)
		EVENT_CLASS_CATEGORY(window_events_category)
	};

	class LV_API window_focus_event : public event {
	public:
		EVENT_CLASS_TYPE(window_focus)
		EVENT_CLASS_CATEGORY(window_events_category)
	};

	class LV_API window_focus_lose_event : public event {
	public:
		window_focus_lose_event() = default;

		EVENT_CLASS_TYPE(window_focus_lose)
		EVENT_CLASS_CATEGORY(window_events_category)
	};

}