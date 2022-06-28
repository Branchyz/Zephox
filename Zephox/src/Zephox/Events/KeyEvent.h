#pragma once

#include "Event.h"

namespace Zephox {
	class ZP_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
	protected:
		KeyEvent(int key) : m_KeyCode(key) {}

		int m_KeyCode;
	};


	class ZP_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int key, bool isRepeat = false)
			: KeyEvent(key), m_IsRepeat(isRepeat) {}

		bool IsRepeat() const { return m_IsRepeat; }

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_IsRepeat;
	};


	class ZP_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const int key)
			: KeyEvent(key) {}

		EVENT_CLASS_TYPE(KeyReleased)
	};


	class ZP_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(const int key) : KeyEvent(key) {}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}
