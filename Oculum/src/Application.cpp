#include "ocpch.h"
#include "Application.h"

#include "LayerStack.h"

#include <chrono>

namespace Oculum
{
	Application::TestListener::TestListener()
	{
		SubscribeEvent<WindowCloseEvent>(std::bind(&Application::TestListener::OnClose, this, std::placeholders::_1));
		SubscribeEvent<WindowResizedEvent>(std::bind(&Application::TestListener::OnResize, this, std::placeholders::_1));
	}

	Application::TestListener::~TestListener()
	{

	}

	bool Application::TestListener::OnClose(WindowCloseEvent* e)
	{
		OC_TRACE("%s", e->GetString().c_str());
		return true;
	}

	bool Application::TestListener::OnResize(WindowResizedEvent* e)
	{
		OC_TRACE("%s", e->GetString().c_str());
		return true;
	}

	Application::TestEntity::TestEntity(const char* name) : name(name)
	{

	}

	Application::TestEntity::~TestEntity()
	{

	}

	void Application::TestEntity::OnUpdate(float elapsedTime)
	{
		OC_TRACE("Updated %s", name);
	}

	void Application::TestEntity::OnRender()
	{

	}

	void Application::TestEntity::OnEvent(Event* e)
	{

	}

	Application::Application()
	{
		IEventListener* i = new TestListener();
		i->OnEvent(new WindowResizedEvent(0, 100, 100));
		i->OnEvent(new WindowCloseEvent(1));

		LayerStack s;
		OC_TRACE(s.ToString().c_str());
		s.PushLayer(new Layer("a"));
		s.PushLayer(new Layer("b"));
		s.PushLayer(new Layer("c"));
		OC_TRACE(s.ToString().c_str());
		Layer* lp = s.GetLayer("a");
		OC_TRACE(lp->ToString().c_str());
		lp->AddEntity(new TestEntity("a1"));
		lp->AddEntity(new TestEntity("b1"));
		lp->AddEntity(new TestEntity("c1"));
		lp = s.GetLayer("b");
		lp->AddEntity(new TestEntity("a2"));
		lp->AddEntity(new TestEntity("b2"));
		lp->AddEntity(new TestEntity("c2"));
		lp = s.GetLayer("c");
		lp->AddEntity(new TestEntity("a3"));
		lp->AddEntity(new TestEntity("b3"));
		lp->AddEntity(new TestEntity("c3"));
		OC_TRACE(s.ToString().c_str());
		s.OnUpdate(1.0f);
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