#include "ocpch.h"
#include "WindowManager.h"

namespace Oculum
{
	WindowManager::WindowManager()
	{

	}

	WindowManager::~WindowManager()
	{

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
				Window* window = reinterpret_cast<Window*>(msg.lParam);
				UnregisterWindow(window);
				delete window;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		return ret;
	}

	void WindowManager::OnUpdate(float fElapsed)
	{
		for (Window* wnd : wnds)
		{
			wnd->OnUpdate(fElapsed);
		}
	}

	void WindowManager::RegisterWindow(Window* wnd)
	{
		wnds.push_back(wnd);
	}

	void WindowManager::UnregisterWindow(Window* wnd)
	{
		for (size_t i = 0; i < wnds.size(); i++)
		{
			if (wnds[i] == wnd)
			{
				wnds.erase(wnds.begin() + i);
			}
		}
	}

	size_t WindowManager::CountRunningWindows()
	{
		return wnds.size();
	}
}