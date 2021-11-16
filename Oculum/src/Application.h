#pragma once

#include "Core.h"
#include "WindowManager.h"

namespace Oculum
{
	class Application
	{
	public:
		Application();
		Application(Application&) = delete;
		virtual ~Application();
		void Run();
		WindowManager* getManager();
	private:
		bool running;
		WindowManager manager;
	};
}