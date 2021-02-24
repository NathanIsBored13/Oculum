#pragma once

#include "Window.h"

#include <Vector>
#include <optional>

namespace Oculum
{
	class WindowManager
	{
	public:
		WindowManager();
		~WindowManager();
		std::optional<WPARAM> ProcessMessages();
		void OnUpdate(float);
		void RegisterWindow(Window* wnd);
		void UnregisterWindow(Window* wnd);
		size_t CountRunningWindows();
	private:
		std::vector<Window*> wnds;
	};
}