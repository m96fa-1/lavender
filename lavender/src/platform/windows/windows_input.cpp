#include "lvpch.h"
#include "windows_input.h"

#include "lavender/application.h"

#include <GLFW/glfw3.h>

namespace lv {

	input* input::s_instance = new windows_input();

	bool windows_input::is_key_down_impl(int keycode) {
		GLFWwindow* window = static_cast<GLFWwindow*>(application::get().get_window().get_native_window());
		int state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool windows_input::is_mouse_down_impl(int button) {
		GLFWwindow* window = static_cast<GLFWwindow*>(application::get().get_window().get_native_window());
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	const glm::vec2& windows_input::get_mouse_position_impl() {
		GLFWwindow* window = static_cast<GLFWwindow*>(application::get().get_window().get_native_window());
		double posx, posy;
		glfwGetCursorPos(window, &posx, &posy);
		return glm::vec2((float)posx, (float)posy);
	}

	float windows_input::get_mousex_impl() {
		return get_mouse_position_impl().x;
	}

	float windows_input::get_mousey_impl() {
		return get_mouse_position_impl().y;
	}

}