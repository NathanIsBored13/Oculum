#pragma once

#include "src/Event.h"

namespace Oculum
{
	class MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(int, bool);
		~MouseButtonEvent();
		bool GetButton();
	private:
		bool button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int, bool);
		~MouseButtonPressedEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int, bool);
		~MouseButtonReleasedEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
	};
}