#include "lvpch.h"
#include "Application.h"

#include <glad/glad.h>

namespace Lv {
	
#define BIND_EVENT_FUNC(func) std::bind(&Application::func, this, std::placeholders::_1)
	
	Application* Application::s_instance = nullptr;

	Application::Application()
		: m_running(false) {
		LV_CORE_ASSERT(!s_instance, "Application already exists");
		s_instance = this;

		m_window = std::unique_ptr<Window>(Window::Create(WindowProps(680, 460)));
		m_window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));
	}

	Application::~Application() {

	}

	void Application::Run() {
		m_running = true;
		while (m_running) {
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_layerStack) {
				layer->OnUpdate();
			}

			m_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));

		for (auto it = m_layerStack.end(); it != m_layerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled()) break;
		}
	}

	void Application::PushLayer(Layer* layer) {
		m_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) {
		m_layerStack.PushLayer(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_running = false;
		return true;
	}

}