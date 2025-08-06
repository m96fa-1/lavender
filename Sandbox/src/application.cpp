#include <lavender.h>

class example_layer : public lv::layer {
public:
	example_layer() : layer("Example Layer") {
		
	}

	void on_update() override {

	}

	void on_event(lv::event& event) override {

	}
};

class sandbox : public lv::application {
public:
	sandbox() {
		push_layer(new example_layer());
		push_overlay(new lv::glfw_opengl_imgui_layer());
	}

	~sandbox() {

	}
};

lv::application* lv::create_application() {
	return new sandbox();
}