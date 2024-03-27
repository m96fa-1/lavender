#pragma once

#include "Event.h"

namespace Lv {

	class LV_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return m_button; }

		EVENT_CLASS_CATEGORY(MouseEventsCategory | InputEventsCategory)

	protected:
		MouseButtonEvent(int button)
			: m_button(button) {}

		int m_button;
	};

	class LV_API MouseDownEvent : public MouseButtonEvent {
	public:
		MouseDownEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::ostringstream oss;
			oss << "MouseDownEvent: " << m_button;
			return oss.str();
		}

		EVENT_CLASS_TYPE(MouseDown)
	};

	class LV_API MouseUpEvent : public MouseButtonEvent {
	public:
		MouseUpEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::ostringstream oss;
			oss << "MouseUpEvent: " << m_button;
			return oss.str();
		}

		EVENT_CLASS_TYPE(MouseUp)
	};

	class LV_API MouseMoveEvent : public Event {
	public:
		MouseMoveEvent(float x, float y)
			: m_mouseX(x), m_mouseY(y) {}

		inline float GetPosX() const { return m_mouseX; }
		inline float GetPosY() const { return m_mouseY; }

		std::string ToString() const override {
			std::ostringstream oss;
			oss << "MouseMoveEvent: " << m_mouseX << ", " << m_mouseY;
			return oss.str();
		}

		EVENT_CLASS_TYPE(MouseMove)
		EVENT_CLASS_CATEGORY(MouseEventsCategory | InputEventsCategory)

	private:
		float m_mouseX, m_mouseY;
	};

	class LV_API MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(float offsetX, float offsetY)
			: m_offsetX(offsetX), m_offsetY(offsetY) {}

		inline float GetOffsetX() const { return m_offsetX; }
		inline float GetOffsetY() const { return m_offsetY; }

		std::string ToString() const override {
			std::ostringstream oss;
			oss << "MouseScrollEvent: " << m_offsetX << ", " << m_offsetY;
			return oss.str();
		}

		EVENT_CLASS_TYPE(MouseMove)
		EVENT_CLASS_CATEGORY(MouseEventsCategory | InputEventsCategory)

	private:
		float m_offsetX, m_offsetY;
	};

}