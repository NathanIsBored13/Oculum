#pragma once

#include "Window.h"

#include <optional>
#include <unordered_set>

namespace Oculum
{
	class WindowManager
	{
	public:
		WindowManager();
		~WindowManager();
		WindowManager(WindowManager&) = delete;
		std::optional<WPARAM> ProcessMessages();
		void OnUpdate(float);
		void RegisterWindow(Window*);
		size_t CountRunningWindows();
	private:
		std::unordered_set<Window*> wnds;
	};
}