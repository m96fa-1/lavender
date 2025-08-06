#pragma once

#include "lavender/layer.h"
#include "lavender/events.h"

namespace lv {

	class LV_API imgui_layer : public layer {
	public:
		imgui_layer(const char* name = "ImGui Layer") : layer(name), m_time(0.0) {}

		virtual void on_attach() override = 0;
		virtual void on_detach() override = 0;
		virtual void on_update() override = 0;
		virtual void on_event(event& event) override = 0;

	protected:
		double m_time;
	};

}