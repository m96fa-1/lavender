#pragma once
#include "core.h"
#include "events/event.h"

namespace lv {

	class LV_API layer {
	public:
		layer(const char* name = "Layer");
		virtual ~layer();

		virtual void on_attach() {}
		virtual void on_detach() {}
		virtual void on_update() {}
		virtual void on_event(event& event) {}
		
		inline const std::string& get_name() const { return m_debug_name; }

	protected:
		std::string m_debug_name;
	};

}