#pragma once

#include "Lavender/Core.h"
#include "Lavender/Events/Event.h"

namespace Lv {

	struct WindowProps {
		unsigned int width;
		unsigned int height;
		std::string title;

		WindowProps(
			unsigned int width = 1280U,
			unsigned int height = 720U,
			const std::string& title = "Lavender Engine")
			: width(width), height(height), title(title) {}
	};

	class LV_API Window {
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual bool IsVsync() const = 0;
		
		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVsync(bool enabled) = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}