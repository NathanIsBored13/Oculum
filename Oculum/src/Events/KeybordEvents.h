#pragma once

#include "src/Event.h"

namespace Oculum
{
	class KeyEvent : public Event
	{
	public:
		KeyEvent(int);
		~KeyEvent();
		int GetKey();
	private:
		int keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int, bool);
		~KeyPressedEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
		bool IsRepeat();
	private:
		bool isRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int);
		~KeyReleasedEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
	};
}