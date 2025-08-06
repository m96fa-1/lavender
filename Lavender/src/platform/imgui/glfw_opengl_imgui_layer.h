#pragma once
#include "lavender/imgui/imgui_layer.h"

namespace lv {

	class LV_API glfw_opengl_imgui_layer : public imgui_layer {
	public:
		glfw_opengl_imgui_layer();
		virtual ~glfw_opengl_imgui_layer();

		void on_attach() override;
		void on_detach() override;

		// can be overrided again if we wanted to
		virtual void on_update() override;
		virtual void on_event(event& event) override;
	};

}