#include "ocpch.h"
#include "Application.h"

#include <chrono>

namespace Oculum
{
	Application::TestEntity::TestEntity()
	{
		SubscribeEvent<WindowCloseEvent>(std::bind(&Application::TestEntity::OnClose, this, std::placeholders::_1));
		SubscribeEvent<WindowResizedEvent>(std::bind(&Application::TestEntity::OnResize, this, std::placeholders::_1));
	}

	Application::TestEntity::~TestEntity()
	{

	}

	bool Application::TestEntity::OnClose(WindowCloseEvent* e)
	{
		OC_TRACE("%s", e->GetString().c_str());
		return true;
	}

	bool Application::TestEntity::OnResize(WindowResizedEvent* e)
	{
		OC_TRACE("%s", e->GetString().c_str());
		return true;
	}

	Application::Application()
	{
		IEventListener* i = new TestEntity();
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