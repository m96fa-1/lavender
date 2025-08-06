#pragma once
#include <print>
#include <functional>

namespace lv {

	enum class event_type {
		none = 0,
		window_close, window_resize, window_move, window_focus, window_focus_lose,
		key_down, key_up, key_repeat, key_type,
		mouse_down, mouse_up, mouse_move, mouse_scroll
	};

	enum event_category {
		none = 0,
		window_events_category		= 1 << 0,
		input_events_category		= 1 << 1,
		keyboard_events_category	= 1 << 2,
		mouse_events_category		= 1 << 3
	};

#define EVENT_CLASS_TYPE(type) static event_type get_static_type() noexcept { return event_type::##type; }\
			   				   event_type get_event_type() const noexcept override { return get_static_type(); }\
							   const char* get_name() const noexcept override { return #type; }

#define EVENT_CLASS_CATEGORY(category) int get_category_flags() const noexcept override { return category; }

	class LV_API event {
		friend class event_dispatcher;

	public:
		[[nodiscard]] virtual event_type get_event_type() const noexcept = 0;
		[[nodiscard]] virtual const char* get_name() const noexcept = 0;
		[[nodiscard]] virtual int get_category_flags() const noexcept = 0;
		[[nodiscard]] virtual std::string to_string() const noexcept { return get_name(); }
		
		[[nodiscard]] inline bool is_in_category(event_category category) const noexcept { return get_category_flags() & category; }
		[[nodiscard]] inline bool handled() const noexcept { return m_handled; }

	protected:
		bool m_handled;
	};

	class event_dispatcher {
		template<typename T>
		using event_func = std::function<bool(T&)>;
		
	public:
		event_dispatcher(event& event)
			: m_event(event) {}

		template<typename T>
		bool dispatch(event_func<T> func) {
			if (m_event.get_event_type() == T::get_static_type()) {
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}

	private:
		event& m_event;
	};

}