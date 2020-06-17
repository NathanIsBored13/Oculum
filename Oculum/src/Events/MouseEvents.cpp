#include "ocpch.h"
#include "MouseEvents.h"

#include <ostream>

namespace Oculum
{
	MouseMovedEvent::MouseMovedEvent(int WindowID, int x, int y) : Event(WindowID), x(x), y(y)
	{

	}

	MouseMovedEvent::~MouseMovedEvent()
	{

	}

	const char* MouseMovedEvent::GetName()
	{
		return "MouseMovedEvent";
	}

	const std::string MouseMovedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] had mouse moved to position [" << x << ", " << y << "]";
		return ss.str();
	}

	Event::Type MouseMovedEvent::GetType()
	{
		return GetStaticType();
	}

	Event::Type MouseMovedEvent::GetStaticType()
	{
		return Event::Type::MouseMoved;
	}

	int MouseMovedEvent::GetX()
	{
		return x;
	}

	int MouseMovedEvent::GetY()
	{
		return y;
	}

	MouseButtonEvent::MouseButtonEvent(int windowID, bool button) : Event(windowID), button(button)
	{

	}

	MouseButtonEvent::~MouseButtonEvent()
	{

	}

	bool MouseButtonEvent::GetButton()
	{
		return button;
	}

	MouseButtonPressedEvent::MouseButtonPressedEvent(int windowID, bool button) : MouseButtonEvent(windowID, button)
	{

	}

	MouseButtonPressedEvent::~MouseButtonPressedEvent()
	{

	}

	const char* MouseButtonPressedEvent::GetName()
	{
		return "MouseButtonPressedEvent";
	}

	const std::string MouseButtonPressedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] had mouse button " << GetButton() << " pressed";
		return ss.str();
	}

	Event::Type MouseButtonPressedEvent::GetType()
	{
		return Event::Type::MouseButtonPressed;
	}

	Event::Type MouseButtonPressedEvent::GetStaticType()
	{
		return Event::Type::MouseButtonPressed;
	}

	MouseButtonReleasedEvent::MouseButtonReleasedEvent(int windowID, bool button) : MouseButtonEvent(windowID, button)
	{

	}

	MouseButtonReleasedEvent::~MouseButtonReleasedEvent()
	{

	}

	const char* MouseButtonReleasedEvent::GetName()
	{
		return "MouseButtonReleasedEvent";
	}

	const std::string MouseButtonReleasedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] had mouse button " << GetButton() << " released";
		return ss.str();
	}

	Event::Type MouseButtonReleasedEvent::GetType()
	{
		return GetStaticType();
	}

	Event::Type MouseButtonReleasedEvent::GetStaticType()
	{
		return Event::Type::MouseButtonReleased;
	}
}