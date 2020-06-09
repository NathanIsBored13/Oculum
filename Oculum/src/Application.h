#pragma once

#include "ocpch.h"

#include "Core.h"
#include "WindowManager.h"
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
		bool running = true;
		WindowManager wnds;
	};
	Application* CreateApplication();
}