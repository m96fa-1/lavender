#pragma once
#include "event.h"

namespace lv {

	class LV_API mouse_button_event : public event {
	public:
		[[nodiscard]] inline int get_mouse_button() const noexcept { return m_button; }

		EVENT_CLASS_CATEGORY(mouse_events_category | input_events_category)

	protected:
		mouse_button_event(int button)
			: m_button(button) {}

		int m_button;
	};

	class LV_API mouse_down_event : public mouse_button_event {
	public:
		mouse_down_event(int button)
			: mouse_button_event(button) {
		
		}

		std::string to_string() const noexcept override {
			return std::format("mouse_down_event: {}", m_button);
		}

		EVENT_CLASS_TYPE(mouse_down)
	};

	class LV_API mouse_up_event : public mouse_button_event {
	public:
		mouse_up_event(int button)
			: mouse_button_event(button) {
		
		}

		std::string to_string() const noexcept override {
			return std::format("mouse_up_event: {}", m_button);
		}

		EVENT_CLASS_TYPE(mouse_up)
	};

	class LV_API mouse_move_event : public event {
	public:
		mouse_move_event(float x, float y)
			: m_mousex(x), m_mousey(y) {
		
		}

		[[nodiscard]] inline float get_posx() const noexcept { return m_mousex; }
		[[nodiscard]] inline float get_posy() const noexcept { return m_mousey; }

		std::string to_string() const noexcept override {
			return std::format("mouse_move_event: {}, {}", m_mousex, m_mousey);
		}

		EVENT_CLASS_TYPE(mouse_move)
		EVENT_CLASS_CATEGORY(mouse_events_category | input_events_category)

	private:
		float m_mousex, m_mousey;
	};

	class LV_API mouse_scroll_event : public event {
	public:
		mouse_scroll_event(float offsetx, float offsety)
			: m_offsetx(offsetx), m_offsety(offsety) {
		
		}

		[[nodiscard]] inline float get_offsetx() const noexcept { return m_offsetx; }
		[[nodiscard]] inline float get_offsety() const noexcept { return m_offsety; }

		std::string to_string() const noexcept override {
			return std::format("mouse_scroll_event: {}, {}", m_offsetx, m_offsety);
		}

		EVENT_CLASS_TYPE(mouse_move)
		EVENT_CLASS_CATEGORY(mouse_events_category | input_events_category)

	private:
		float m_offsetx, m_offsety;
	};

}