#pragma once

#include "src/Event.h"

namespace Oculum
{
	class OC_API KeyEvent : public Event
	{
	public:
		KeyEvent(int, int);
		~KeyEvent();
		int GetKey();
	private:
		int keyCode;
	};

	class OC_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int, int, bool);
		~KeyPressedEvent();
		virtual const char* GetName() override;
		virtual const char* GetString() override;
		virtual Type GetType() override;
		bool IsRepeat();
	private:
		bool isRepeat;
	};

	class OC_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int, int);
		~KeyReleasedEvent();
		virtual const char* GetName() override;
		virtual const char* GetString() override;
		virtual Type GetType() override;
	};
}