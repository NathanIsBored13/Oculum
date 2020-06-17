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
		size_t GetRunningWindows();
	private:
		std::vector<Window*> wnds;
	};
}