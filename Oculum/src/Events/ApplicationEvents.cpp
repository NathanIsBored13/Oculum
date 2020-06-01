#include "ocpch.h"
#include "ApplicationEvents.h"

#include <ostream>

namespace Oculum
{
	WindowCloseEvent::WindowCloseEvent(int windowID) : Event(windowID)
	{

	}

	WindowCloseEvent::~WindowCloseEvent()
	{

	}

	const char* WindowCloseEvent::GetName()
	{
		return "WindowCloseEvent";
	}

	const char* WindowCloseEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] was closed";
		return ss.str().c_str();
	}

	Event::Type WindowCloseEvent::GetType()
	{
		return Event::Type::WindowClose;
	}

	WindowResizedEvent::WindowResizedEvent(int windowID, int x, int y) : Event(windowID), x(x), y(y)
	{

	}

	WindowResizedEvent::~WindowResizedEvent()
	{

	}

	const char* WindowResizedEvent::GetName()
	{
		return "WindowResizedEvent";
	}

	const char* WindowResizedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] was resized to [" << GetX() << ", " << GetY() << "]";
		return ss.str().c_str();
	}

	Event::Type WindowResizedEvent::GetType()
	{
		return Event::Type::WindowResize;
	}

	int WindowResizedEvent::GetX()
	{
		return x;
	}

	int WindowResizedEvent::GetY()
	{
		return y;
	}

	WindowFocusGainedEvent::WindowFocusGainedEvent(int windowID) : Event(windowID)
	{

	}

	WindowFocusGainedEvent::~WindowFocusGainedEvent()
	{

	}

	const char* WindowFocusGainedEvent::GetName()
	{
		return "WindowFocusGainedEvent";
	}

	const char* WindowFocusGainedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] gained focus";
		return ss.str().c_str();
	}

	Event::Type WindowFocusGainedEvent::GetType()
	{
		return Event::Type::WindowFocusGained;
	}

	WindowFocusLostEvent::WindowFocusLostEvent(int windowID) : Event(windowID)
	{

	}

	WindowFocusLostEvent::~WindowFocusLostEvent()
	{

	}

	const char* WindowFocusLostEvent::GetName()
	{
		return "WindowFocusLostEvent";
	}

	const char* WindowFocusLostEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] lost focus";
		return ss.str().c_str();
	}

	Event::Type WindowFocusLostEvent::GetType()
	{
		return Event::Type::WindowFocusLost;
	}

	WindowMovedEvent::WindowMovedEvent(int windowID, int x, int y) : Event(windowID), x(x), y(y)
	{

	}

	WindowMovedEvent::~WindowMovedEvent()
	{

	}

	const char* WindowMovedEvent::GetName()
	{
		return "WindowMovedEvent";
	}

	const char* WindowMovedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] was moved to [" << GetX() << ", " << GetY() << "]";
		return ss.str().c_str();
	}

	Event::Type WindowMovedEvent::GetType()
	{
		return Event::Type::WindowMoved;
	}

	int WindowMovedEvent::GetX()
	{
		return x;
	}

	int WindowMovedEvent::GetY()
	{
		return y;
	}
}