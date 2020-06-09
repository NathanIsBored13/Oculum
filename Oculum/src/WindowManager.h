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
		void RegisterWindow(Window* wnd);
	private:
		std::vector<Window*> wnds;
	};
}