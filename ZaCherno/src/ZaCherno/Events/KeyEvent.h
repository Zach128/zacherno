#pragma once

#include "Event.h"

namespace ZaCherno
{

	// Base class for Key-related events
	class ZACHERNO_API KeyEvent : public Event
	{

	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keyCode)
			: m_KeyCode(keyCode) {}

		int m_KeyCode;

	};

	class ZACHERNO_API KeyPressedEvent : public KeyEvent
	{
		
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class ZACHERNO_API KeyReleasedEvent : public KeyEvent
	{

	public:
		KeyReleasedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
		}

		EVENT_CLASS_TYPE(KeyReleased)
	private:
		int m_RepeatCount;
	};

}