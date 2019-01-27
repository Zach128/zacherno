#pragma once

#include "zcpch.h"
#include "ZaCherno/Core.h"

namespace ZaCherno
{

	// Events in ZaCherno are blocking/interrupting, meaning they interrupt program flow and must be dealt with then and there.
	// In the ideal future, they will be dealt with in a separate stage of the programs cycle in an 'event' stage.

	// Used to denote the type of event pertaining to a particular peripheral, software event, or state
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// Denotes the possible categories under which EventTypes can be categorised
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

// Implements a number of common Event-related methods which override the base implementation by returning the provided EventType
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

// Implements a constant getter function for returning the categories associated with an Event
// Takes an integer containing all EventCategory flags which fall under the Event
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	//Base class for event-type classes to inherit and for dealing with application event-related logic
	class ZACHERNO_API Event
	{
		// Defined a class EventDispatcher
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;

	};

	// Sub-class of Event for dealing with dispatching of tpye-like events
	class EventDispatcher
	{
		// Following lines define support for callback methods - with name EventFn - for this class only

		template<typename T>
		// A standard function with a bool return-type that takes any EventType as a parameter
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>

		// Following function defines a class
		bool Dispatch(EventFn<T> func)
		{
			// If the type of the given func matches the type of the Event that you're trying to dispatch,
			// call the function and mark the event as handles
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	// Defines a string concatenation operator for Event classes
	// which appends the Events toString output to the existing outputstream
	inline std::ostream& operator <<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}