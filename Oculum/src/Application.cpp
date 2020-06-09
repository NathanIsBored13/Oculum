#include "ocpch.h"
#include "Application.h"

#include "LayerStack.h"

#include <chrono>

namespace Oculum
{
	Application::Application()
	{
		wnds.RegisterWindow(new Window(L"Main Window", 400, 400));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		std::chrono::steady_clock::time_point mark = std::chrono::steady_clock::now();
		while (running)
		{
			if (wnds.ProcessMessages())
			{
				running = false;
			}
		}
	}
}