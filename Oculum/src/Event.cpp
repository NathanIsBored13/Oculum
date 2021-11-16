#include "ocpch.h"
#include "Event.h"


namespace Oculum
{
	Event::Event()
	{

	}

	Event::~Event()
	{

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