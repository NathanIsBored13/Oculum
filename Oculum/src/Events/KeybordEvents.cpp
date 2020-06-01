#include "ocpch.h"
#include "KeybordEvents.h"

#include <ostream>

namespace Oculum
{
	KeyEvent::KeyEvent(int windowID, int keyCode) : Event(windowID), keyCode(keyCode)
	{

	}

	KeyEvent::~KeyEvent()
	{

	}

	int KeyEvent::GetKey()
	{
		return keyCode;
	}

	KeyPressedEvent::KeyPressedEvent(int windowID, int keyCode, bool isRepeat) : KeyEvent(windowID, keyCode), isRepeat(isRepeat)
	{

	}

	KeyPressedEvent::~KeyPressedEvent()
	{

	}

	const char* KeyPressedEvent::GetName()
	{
		return "KeyPressedEvent";
	}

	const char* KeyPressedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] had key " << GetKey() << " pressed";
		return ss.str().c_str();
	}

	Event::Type KeyPressedEvent::GetType()
	{
		return Event::Type::KeyPressed;
	}

	bool KeyPressedEvent::IsRepeat()
	{
		return isRepeat;
	}

	KeyReleasedEvent::KeyReleasedEvent(int windowID, int keyCode) : KeyEvent(windowID, keyCode)
	{

	}

	KeyReleasedEvent::~KeyReleasedEvent()
	{

	}

	const char* KeyReleasedEvent::GetName()
	{
		return "KeyReleasedEvent";
	}

	const char* KeyReleasedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] had key " << GetKey() << " released";
		return ss.str().c_str();
	}

	Event::Type KeyReleasedEvent::GetType()
	{
		return Event::Type::KeyReleased;
	}
}