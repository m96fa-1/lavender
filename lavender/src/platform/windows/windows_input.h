#pragma once

#include "Lavender/input.h"

namespace lv {

	class windows_input : public input {
	protected:
		bool is_key_down_impl(int keycode) override;

		bool is_mouse_down_impl(int button) override;
		const glm::vec2& get_mouse_position_impl() override;
		float get_mousex_impl() override;
		float get_mousey_impl() override;
	};

}