#include "ocpch.h"
#include "Application.h"

#include <chrono>

namespace Oculum
{
	Application::Application()
	{
		TestEntity e = TestEntity();
		IEventListener* i = &e;
		i->OnEvent(new WindowResizedEvent(0, 100, 100));
		i->OnEvent(new WindowCloseEvent(1));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		std::chrono::steady_clock::time_point mark = std::chrono::steady_clock::now();
		while (running)
		{
			if (long delta_t = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - mark).count() >= 5)
			{
				OC_TRACE("mark");
				mark = std::chrono::steady_clock::now();
			}
		}
	}
}