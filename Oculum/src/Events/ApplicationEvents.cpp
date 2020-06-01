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

	const std::string WindowCloseEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] was closed";
		return ss.str();
	}

	Event::Type WindowCloseEvent::GetType()
	{
		return GetStaticType();
	}

	Event::Type WindowCloseEvent::GetStaticType()
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

	const std::string WindowResizedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] was resized to [" << GetX() << ", " << GetY() << "]";
		return ss.str().c_str();
	}

	Event::Type WindowResizedEvent::GetType()
	{
		return GetStaticType();
	}

	Event::Type WindowResizedEvent::GetStaticType()
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

	const std::string WindowFocusGainedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] gained focus";
		return ss.str();
	}

	Event::Type WindowFocusGainedEvent::GetType()
	{
		return GetStaticType();
	}

	Event::Type WindowFocusGainedEvent::GetStaticType()
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

	const std::string WindowFocusLostEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] lost focus";
		return ss.str();
	}

	Event::Type WindowFocusLostEvent::GetType()
	{
		return GetStaticType();
	}

	Event::Type WindowFocusLostEvent::GetStaticType()
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

	const std::string WindowMovedEvent::GetString()
	{
		std::stringstream ss;
		ss << "Window [" << GetWindowID() << "] was moved to [" << GetX() << ", " << GetY() << "]";
		return ss.str();
	}

	Event::Type WindowMovedEvent::GetType()
	{
		return GetStaticType();
	}

	Event::Type WindowMovedEvent::GetStaticType()
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