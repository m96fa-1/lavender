#pragma once

#include "window.h"
#include "layer_stack.h"
#include "events.h"

namespace lv {
	
	class LV_API application {
	public:
		application();
		virtual ~application();

		void run();

		void on_event(event& event);

		void push_layer(layer* layer);
		void push_overlay(layer* overlay);

		[[nodiscard]] inline static application& get() { return *s_instance; }
		[[nodiscard]] inline window& get_window() { return *m_window; }

	private:
		[[nodiscard]] bool on_window_close(window_close_event& event);

	private:
		bool m_is_running;
		std::unique_ptr<window> m_window;
		layer_stack m_layer_stack;

		inline static application* s_instance = nullptr;
	};

	// Must be defined inside client applications
	application* create_application();

}