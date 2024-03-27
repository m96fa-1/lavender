#include <Lavender.h>

class ExampleLayer : public Lv::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnEvent(Lv::Event& e) override {
		LV_TRACE(e);
	}
};

class Sandbox : public Lv::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Lv::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Lv::Application* Lv::CreateApplication() {
	return new Sandbox();
}