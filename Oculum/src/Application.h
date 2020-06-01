#pragma once

#include "ocpch.h"
#include "Core.h"
#include "IEventListener.h"
#include "Log.h"
#include "Events/ApplicationEvents.h"

namespace Oculum
{
	class OC_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		bool running = true;
	};
	Application* CreateApplication();
}