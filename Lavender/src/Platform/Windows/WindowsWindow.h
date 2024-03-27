#pragma once

#include "Lavender/Window.h"

#include <GLFW/glfw3.h>

namespace Lv {

	class LV_API WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_data.width; }
		unsigned int GetHeight() const override { return m_data.height; }
		bool IsVsync() const override { return m_data.vsync; }

		void SetEventCallback(const EventCallbackFunc& callback) override;
		void SetVsync(bool enabled) override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_window;

		struct WindowData {
			unsigned int width, height;
			std::string title;
			bool vsync;
			EventCallbackFunc eventCallback;
		};

		WindowData m_data;
	};

}