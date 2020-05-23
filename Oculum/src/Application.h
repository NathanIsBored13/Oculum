#pragma once

#include "ocpch.h"
#include "Core.h"

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