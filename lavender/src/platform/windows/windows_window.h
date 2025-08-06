#pragma once
#include "lavender/window.h"

struct GLFWwindow;

namespace lv {

	class LV_API windows_window : public window {
	public:
		windows_window(const window_props& props);
		virtual ~windows_window();

		void on_update() override;

		inline int get_width() const noexcept override { return m_data.width; }
		inline int get_height() const noexcept override { return m_data.height; }
		inline bool is_vsync() const noexcept override { return m_data.vsync; }

		void set_event_callback(const event_callback_func& callback) override;

		inline void* get_native_window() const override { return m_window; }

	private:
		virtual void init(const window_props& props);
		virtual void shutdown();

	private:
		GLFWwindow* m_window;

		struct window_data {
			int width, height;
			std::string title;
			bool vsync;
			event_callback_func event_callback;
		};

		window_data m_data;
	};

}