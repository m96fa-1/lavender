#pragma once
#include "core.h"

#include <glm/glm.hpp>

namespace lv {

	class LV_API input {
	public:
		[[nodiscard]] inline static bool is_key_down(int keycode) { return s_instance->is_key_down_impl(keycode); }
		[[nodiscard]] inline static bool is_mouse_down(int button) { return s_instance->is_mouse_down_impl(button); }
		[[nodiscard]] inline static const glm::vec2& get_mouse_position() { return s_instance->get_mouse_position_impl(); }
		[[nodiscard]] inline static float get_mousex() { return s_instance->get_mousex_impl(); }
		[[nodiscard]] inline static float get_mousey() { return s_instance->get_mousey_impl(); }

	protected:
		[[nodiscard]] virtual bool is_key_down_impl(int keycode) = 0;
		[[nodiscard]] virtual bool is_mouse_down_impl(int button) = 0;
		[[nodiscard]] virtual const glm::vec2& get_mouse_position_impl() = 0;
		[[nodiscard]] virtual float get_mousex_impl() = 0;
		[[nodiscard]] virtual float get_mousey_impl() = 0;

	private:
		static input* s_instance;
	};

}