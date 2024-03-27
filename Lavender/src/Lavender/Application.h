#pragma once

#include "lvpch.h"

#include "Window.h"
#include "LayerStack.h"
#include "Events/WindowEvent.h"

namespace Lv {
	
	class LV_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_instance; }
		inline Window& GetWindow() { return *m_window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		bool m_running;
		std::unique_ptr<Window> m_window;
		LayerStack m_layerStack;

	private:
		static Application* s_instance;
	};

	// Must be defined inside client applications
	Application* CreateApplication();

}