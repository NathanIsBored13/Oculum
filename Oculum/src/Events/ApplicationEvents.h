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
		int GetExitCode();
	private:
		int exitCode;
	};

	class ChildCloseEvent : public WindowCloseEvent
	{
	public:
		ChildCloseEvent(int);
		~ChildCloseEvent();
		virtual Type GetType() override;
		static Type GetStaticType();
	};

	class ParentCloseEvent : public WindowCloseEvent
	{
	public:
		ParentCloseEvent(int);
		~ParentCloseEvent();
		virtual Type GetType() override;
		static Type GetStaticType();
	};

	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(int, int);
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
		WindowFocusLostEvent();
		~WindowFocusLostEvent();
		virtual const char* GetName() override;
		virtual const std::string GetString() override;
		virtual Type GetType() override;
		static Type GetStaticType();
	};

	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int, int);
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