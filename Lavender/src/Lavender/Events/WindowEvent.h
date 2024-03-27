#pragma once

#include "Event.h"

namespace Lv {
	
	class LV_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(WindowEventsCategory)
	};

	class LV_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_width(width), m_height(height) {}

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override {
			std::ostringstream oss;
			oss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return oss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(WindowEventsCategory)

	private:
		unsigned int m_width, m_height;
	};

	class LV_API WindowMoveEvent : public Event {
	public:
		WindowMoveEvent() = default;

		EVENT_CLASS_TYPE(WindowMove)
		EVENT_CLASS_CATEGORY(WindowEventsCategory)
	};

	class LV_API WindowFocusEvent : public Event {
	public:
		WindowFocusEvent() = default;

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(WindowEventsCategory)
	};

	class LV_API WindowFocusLoseEvent : public Event {
	public:
		WindowFocusLoseEvent() = default;

		EVENT_CLASS_TYPE(WindowFocusLose)
		EVENT_CLASS_CATEGORY(WindowEventsCategory)
	};

}