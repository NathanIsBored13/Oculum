#pragma once

#include "Core.h"

namespace Oculum
{
	class OC_API Event
	{
	public:
		enum class Type
		{
			WindowClose, WindowResize, WindowFocusGained, WindowFocusLost, WindowMoved,
			KeyPressed, KeyReleased,
			MouseMoved, MouseButtonPressed, MouseButtonReleased, MouseScrolled
		};

		Event(int);
		virtual ~Event();
		int GetWindowID() noexcept;
		virtual const char* GetName() = 0;
		virtual const std::string GetString() = 0;
		virtual Type GetType() = 0;
		void Handled();
		bool IsHandled();
	private:
		bool handled = false;
		int windowID;
	};
}