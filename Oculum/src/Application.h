#pragma once

#include "ocpch.h"

#include "Core.h"
#include "IEventListener.h"
#include "Log.h"
#include "Events/ApplicationEvents.h"

namespace Oculum
{
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		class TestEntity : public IEventListener
		{
		public:
			TestEntity();
			~TestEntity();
		private:
			bool OnClose(WindowCloseEvent*);
			bool OnResize(WindowResizedEvent*);
		};
		bool running = true;
	};
	Application* CreateApplication();
}