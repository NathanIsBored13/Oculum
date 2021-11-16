#include "ocpch.h"
#include "WindowManager.h"

#include "Events/ApplicationEvents.h"

namespace Oculum
{
	WindowManager::WindowManager() : wnds(std::unordered_set<Window*>())
	{

	}

	WindowManager::~WindowManager()
	{

	}

	std::optional<WPARAM> WindowManager::ProcessMessages()
	{
		std::optional<WPARAM> ret;
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) && !ret)
		{
			if (msg.message == WM_QUIT)
			{
				ret = msg.wParam;
				Window* window = reinterpret_cast<Window*>(msg.lParam);
				wnds.erase(window);
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
		wnds.insert(wnd);
	}

	size_t WindowManager::CountRunningWindows()
	{
		return wnds.size();
	}
}