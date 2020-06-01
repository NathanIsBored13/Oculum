#include "ocpch.h"
#include "Event.h"


namespace Oculum
{
	Event::Event(int windowID) : windowID(windowID)
	{

	}

	Event::~Event()
	{

	}

	int Event::GetWindowID() noexcept
	{
		return windowID;
	}

	void Event::Handled()
	{
		handled = true;
	}

	bool Event::IsHandled()
	{
		return handled;
	}
}