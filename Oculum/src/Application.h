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
		WindowManager* GetManager();
	private:
		bool running = true;
		WindowManager windows;
	};
	Application* CreateApplication();
}