#include "lvpch.h"
#include "windows_window.h"

#include "lavender/events/window_event.h"
#include "lavender/events/key_event.h"
#include "lavender/events/mouse_event.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace lv {

	static bool s_glfw_initialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		LV_CORE_ERROR("[GLFW Error]: ({}), {}", error, description);
	}

	window* window::create(const window_props& props /*= window_props()*/) {
		return new windows_window(props);
	}

	windows_window::windows_window(const window_props& props) {
		init(props);
	}

	windows_window::~windows_window() {
		shutdown();
	}

	void windows_window::on_update() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void windows_window::set_event_callback(const event_callback_func& callback) {
		m_data.event_callback = callback;
	}

	void windows_window::init(const window_props& props) {
		m_data.width = props.width;
		m_data.height = props.height;
		m_data.title = props.title;
		m_data.vsync = props.vsync;

		LV_CORE_INFO("Creating window \"{}\" ({}, {})", m_data.title, m_data.width, m_data.height);
		
		if (!s_glfw_initialized) {
			int success = glfwInit();
			LV_CORE_ASSERT(success, "Failed to initialize GLFW");
			LV_CORE_INFO("GLFW initialization succeed");
			s_glfw_initialized = true;
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LV_CORE_ASSERT(success, "Failed to initialize GLAD");
		LV_CORE_INFO("GLAD initialization succeed");
		glfwSetWindowUserPointer(m_window, &m_data);
		if (m_data.vsync)
			glfwSwapInterval(GLFW_TRUE);

		if (props.center_window) {
			const GLFWvidmode& fullscreen = *glfwGetVideoMode(glfwGetPrimaryMonitor());
			glfwSetWindowPos(m_window, (fullscreen.width - m_data.width) / 2, (fullscreen.height - m_data.height) / 2);
		}

		// glfw callbacks
		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			window_data& data = *(window_data*)glfwGetWindowUserPointer(window);

			window_close_event event;
			data.event_callback(event);
		});

		glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		});

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			window_resize_event event(width, height);
			data.event_callback(event);
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
			
			switch (action) {
				case GLFW_PRESS:
				{
					key_down_event event(key);
					data.event_callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					key_up_event event(key);
					data.event_callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					key_repeat_event event(key, 1);
					data.event_callback(event);
					break;
				}
			}
		});

		glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode) {
			window_data& data = *(window_data*)glfwGetWindowUserPointer(window);

			key_type_event event(keycode);
			data.event_callback(event);
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
			window_data& data = *(window_data*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS:
				{
					mouse_down_event event(button);
					data.event_callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					mouse_up_event event(button);
					data.event_callback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double offsetx, double offsety) {
			window_data& data = *(window_data*)glfwGetWindowUserPointer(window);

			mouse_scroll_event event((float)offsetx, (float)offsety);
			data.event_callback(event);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double posx, double posy) {
			window_data& data = *(window_data*)glfwGetWindowUserPointer(window);

			mouse_move_event event((float)posx, (float)posy);
			data.event_callback(event);
		});
	}

	void windows_window::shutdown() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

}