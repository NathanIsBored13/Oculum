#include "ocpch.h"
#include "Application.h"

#include <chrono>

namespace Oculum
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		std::chrono::steady_clock::time_point clk = std::chrono::steady_clock::now();
		while (running)
		{
			if (std::optional<WPARAM> ret = windows.ProcessMessages())
			{
				OC_INFO("window closed with exit code %i", *ret);
				if (windows.CountRunningWindows() == 0)
				{
					OC_INFO("all windows are closed");
				}
			}
			else if (float fElapsed = std::chrono::duration<float>(std::chrono::steady_clock::now() - clk).count() > 5)
			{
				clk = std::chrono::steady_clock::now();
				windows.OnUpdate(fElapsed);
			}
		}
	}

	WindowManager* Application::GetManager()
	{
		return &windows;
	}
}