#pragma once

#include "Event.h"

namespace Lv {

	class LV_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_keycode; }

		EVENT_CLASS_CATEGORY(KeyboardEventsCategory | InputEventsCategory)

	protected:
		KeyEvent(int keycode)
			: m_keycode(keycode) {}

		int m_keycode;
	};

	class LV_API KeyDownEvent : public KeyEvent {
	public:
		KeyDownEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_repeatCount; }

		std::string ToString() const override {
			std::ostringstream oss;
			oss << "KeyDownEvent: " << m_keycode << " keycode, " << m_repeatCount << " repeat";
			return oss.str();
		}

		EVENT_CLASS_TYPE(KeyDown)

	private:
		int m_repeatCount;
	};

	class LV_API KeyUpEvent : public KeyEvent {
	public:
		KeyUpEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override {
			std::ostringstream oss;
			oss << "KeyUpEvent: " << m_keycode << " keycode";
			return oss.str();
		}

		EVENT_CLASS_TYPE(KeyUp)
	};

}