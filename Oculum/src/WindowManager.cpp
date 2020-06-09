#include "ocpch.h"
#include "WindowManager.h"

namespace Oculum
{
	WindowManager::WindowManager()
	{

	}

	WindowManager::~WindowManager()
	{
		for (Window* wnd : wnds)
		{
			delete wnd;
		}
	}

	std::optional<WPARAM> WindowManager::ProcessMessages()
	{
		std::optional<WPARAM> ret;
		MSG msg;
		while (!ret && PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				ret = msg.wParam;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		return ret;
	}

	void WindowManager::RegisterWindow(Window* wnd)
	{
		wnds.push_back(wnd);
	}
}