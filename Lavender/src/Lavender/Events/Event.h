#pragma once

#include "lvpch.h"

namespace Lv {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowMove, WindowFocus, WindowFocusLose,
		KeyDown, KeyUp,
		MouseDown, MouseUp, MouseMove, MouseScroll
	};

	enum EventCategory {
		None = 0,
		WindowEventsCategory		= BIT(0),
		InputEventsCategory			= BIT(1),
		KeyboardEventsCategory		= BIT(2),
		MouseEventsCategory			= BIT(3)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
			   				   virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class LV_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
		
		inline bool IsInCategory(EventCategory category) const {
			return GetCategoryFlags() & category;
		}
		inline bool Handled() const { return m_handled; }

	protected:
		bool m_handled;
	};

	class EventDispatcher {
		template<typename T>
		using EventFunc = std::function<bool(T&)>;
		
	public:
		EventDispatcher(Event& event)
			: m_event(event) {}

		template<typename T>
		bool Dispatch(EventFunc<T> func) {
			if (m_event.GetEventType() == T::GetStaticType()) {
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}

	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}

}