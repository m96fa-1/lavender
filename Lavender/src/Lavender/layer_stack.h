#pragma once

#include "core.h"
#include "layer.h"

#include <vector>

namespace lv {

	class LV_API layer_stack {
	public:
		layer_stack();
		~layer_stack();
		
		void push_layer(layer* layer);
		void push_overlay(layer* overlay);
		void pop_layer(layer* layer);
		void pop_overlay(layer* overlay);

		[[nodiscard]] inline constexpr std::vector<layer*>::iterator begin() noexcept { return m_layers.begin(); }
		[[nodiscard]] inline constexpr std::vector<layer*>::iterator end() noexcept { return m_layers.end(); }

	private:
		std::vector<layer*> m_layers;
		std::vector<layer*>::iterator m_layer_insert;
	};

}