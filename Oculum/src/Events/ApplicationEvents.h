#pragma once

#include "src/Event.h"

namespace Oculum
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent(int);
		~WindowCloseEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
	};

	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(int, int, int);
		~WindowResizedEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
		int GetX();
		int GetY();
	private:
		int x, y;
	};

	class WindowFocusGainedEvent : public Event
	{
	public:
		WindowFocusGainedEvent(int);
		~WindowFocusGainedEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
	};

	class WindowFocusLostEvent : public Event
	{
	public:
		WindowFocusLostEvent(int);
		~WindowFocusLostEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
	};

	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int, int, int);
		~WindowMovedEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
		int GetX();
		int GetY();
	private:
		int x, y;
	};
}