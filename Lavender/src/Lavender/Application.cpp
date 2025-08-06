#include "lvpch.h"
#include "application.h"

#include "core.h"
#include "input.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace lv {

	application::application() : m_is_running(false) {
		LV_CORE_ASSERT(!s_instance, "Application already exists.");
		s_instance = this;

		logger::init();
		m_window = std::unique_ptr<window>(window::create(window_props()));
		m_window->set_event_callback(LV_BIND_EVENT_FUNC(application::on_event));
	}

	application::~application() {

	}

	void application::run() {
		m_is_running = true;
		while (m_is_running) {
			glClearColor(0.45f, 0.4f, 0.475f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (layer* layer : m_layer_stack) {
				layer->on_update();
			}

			m_window->on_update();
		}
	}

	void application::on_event(event& event) {
		event_dispatcher dispatcher(event);
		dispatcher.dispatch<window_close_event>(LV_BIND_EVENT_FUNC(application::on_window_close));

		for (auto it = m_layer_stack.end(); it != m_layer_stack.begin();) {
			(*--it)->on_event(event);
			if (event.handled())
				break;
		}
	}

	void application::push_layer(layer* layer) {
		m_layer_stack.push_layer(layer);
		layer->on_attach();
	}

	void application::push_overlay(layer* overlay) {
		m_layer_stack.push_layer(overlay);
		overlay->on_attach();
	}

	bool application::on_window_close(window_close_event& event) {
		m_is_running = false;
		return true;
	}

}