#pragma once

#include "Core.h"

#include <string>

namespace Oculum
{
	class Event
	{
	public:
		enum class Type
		{
			ParentClose, ChildClose, WindowResize, WindowFocusGained, WindowFocusLost, WindowMoved,
			KeyPressed, KeyReleased,
			MouseMoved, MouseButtonPressed, MouseButtonReleased, MouseScrolled
		};

		Event();
		virtual ~Event();
		virtual const char* GetName() = 0;
		virtual const std::string GetString() = 0;
		virtual Type GetType() = 0;
		void Handled();
		bool IsHandled();
	private:
		bool handled = false;
	};
}