#include "ocpch.h"
#include "KeybordEvents.h"

#include <ostream>

namespace Oculum
{
	KeyEvent::KeyEvent(int keyCode) : Event(), keyCode(keyCode)
	{

	}

	KeyEvent::~KeyEvent()
	{

	}

	int KeyEvent::GetKey()
	{
		return keyCode;
	}

	KeyPressedEvent::KeyPressedEvent(int keyCode, bool isRepeat) : KeyEvent(keyCode), isRepeat(isRepeat)
	{

	}

	KeyPressedEvent::~KeyPressedEvent()
	{

	}

	const char* KeyPressedEvent::GetName()
	{
		return "KeyPressedEvent";
	}

	const std::string KeyPressedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window had key " << GetKey() << " pressed";
		return ss.str();
	}

	Event::Type KeyPressedEvent::GetType()
	{
		return GetStaticType();
	}

	Event::Type KeyPressedEvent::GetStaticType()
	{
		return Event::Type::KeyPressed;
	}

	bool KeyPressedEvent::IsRepeat()
	{
		return isRepeat;
	}

	KeyReleasedEvent::KeyReleasedEvent(int keyCode) : KeyEvent(keyCode)
	{

	}

	KeyReleasedEvent::~KeyReleasedEvent()
	{

	}

	const char* KeyReleasedEvent::GetName()
	{
		return "KeyReleasedEvent";
	}

	const std::string KeyReleasedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window had key " << GetKey() << " released";
		return ss.str();
	}

	Event::Type KeyReleasedEvent::GetType()
	{
		return GetStaticType();
	}

	Event::Type KeyReleasedEvent::GetStaticType()
	{
		return Event::Type::KeyReleased;
	}
}