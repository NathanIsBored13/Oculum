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
				for (size_t i = 0; i < wnds.size(); i++)
				{
					if (wnds[i] == reinterpret_cast<Window*>(msg.lParam))
					{
						wnds.erase(wnds.begin() + i);
					}
				}
				delete reinterpret_cast<Window*>(msg.lParam);
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

	size_t WindowManager::GetRunningWindows()
	{
		return wnds.size();
	}
}