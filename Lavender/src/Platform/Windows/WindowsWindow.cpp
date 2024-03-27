#include "lvpch.h"
#include "WindowsWindow.h"

#include "Lavender/Events/WindowEvent.h"
#include "Lavender/Events/KeyEvent.h"
#include "Lavender/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Lv {

	static bool s_GLFWinitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		LV_CORE_ERROR("[GLFW Error]: ({0}), {1}", error, description);
	}

	Window* Window::Create(const WindowProps& props /*= WindowProps()*/) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFunc& callback) {
		m_data.eventCallback = callback;
	}

	void WindowsWindow::SetVsync(bool enabled) {
		enabled ? glfwSwapInterval(GLFW_TRUE) : glfwSwapInterval(GLFW_FALSE);
		m_data.vsync = enabled;
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_data.width = props.width;
		m_data.height = props.height;
		m_data.title = props.title;

		LV_CORE_INFO("Creating window \"{0}\" ({1}, {2})", props.title, props.width, props.height);
		
		if (!s_GLFWinitialized) {
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			LV_CORE_ASSERT(success, "Failed to initialize GLFW");
			LV_CORE_INFO("GLFW initialization succeeded");
			s_GLFWinitialized = true;
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		m_window = glfwCreateWindow((int)m_data.width, (int)m_data.height, m_data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LV_CORE_ASSERT(success, "Failed to initialize GLAD");
		LV_CORE_INFO("GLAD initialization succeeded");
		glfwSetWindowUserPointer(m_window, &m_data);
		SetVsync(true);

		// Set GLFW callbacks
		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.eventCallback(event);
		});

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.eventCallback(event);
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action) {
				case GLFW_PRESS:
				{
					KeyDownEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyUpEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyDownEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS:
				{
					MouseDownEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseUpEvent event(button);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double offsetX, double offsetY) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrollEvent event((float)offsetX, (float)offsetY);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double posX, double posY) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMoveEvent event((float)posX, (float)posY);
			data.eventCallback(event);
		});
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_window);
	}

}