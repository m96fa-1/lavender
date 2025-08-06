#pragma once
#include "event.h"

namespace lv {

	class LV_API key_event : public event {
	public:
		[[nodiscard]] inline int get_key_code() const noexcept { return m_keycode; }

		EVENT_CLASS_CATEGORY(keyboard_events_category | input_events_category)

	protected:
		key_event(int keycode)
			: m_keycode(keycode) {}

		int m_keycode;
	};

	class LV_API key_down_event : public key_event {
	public:
		key_down_event(int keycode)
			: key_event(keycode) {
		
		}

		std::string to_string() const noexcept override {
			return std::format("key_down_event: {}", m_keycode);
		}

		EVENT_CLASS_TYPE(key_down)
	};

	class LV_API key_up_event : public key_event {
	public:
		key_up_event(int keycode)
			: key_event(keycode) {
		
		}

		std::string to_string() const noexcept override {
			return std::format("key_up_event: {}", m_keycode);
		}

		EVENT_CLASS_TYPE(key_up)
	};

	class LV_API key_repeat_event : public key_event {
	public:
		key_repeat_event(int keycode, int repeat_count)
			: key_event(keycode), m_repeat_count(repeat_count) {
		
		}

		[[nodiscard]] inline int get_repeat_count() const noexcept { return m_repeat_count; }

		std::string to_string() const noexcept override {
			return std::format("key_down_event: {}, {}", m_keycode, m_repeat_count);
		}

		EVENT_CLASS_TYPE(key_repeat)

	private:
		int m_repeat_count;
	};

	class LV_API key_type_event : public key_event {
	public:
		key_type_event(int keycode)
			: key_event(keycode) {
		
		}

		std::string to_string() const noexcept override {
			return std::format("key_type_event: {}", m_keycode);
		}

		EVENT_CLASS_TYPE(key_type)
	};

}