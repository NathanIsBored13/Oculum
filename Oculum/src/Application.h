#pragma once

#include "ocpch.h"

#include "Core.h"
#include "IEntity.h"
#include "Log.h"
#include "Events/ApplicationEvents.h"

namespace Oculum
{
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		class TestListener : public IEventListener
		{
		public:
			TestListener();
			~TestListener();
		private:
			bool OnClose(WindowCloseEvent*);
			bool OnResize(WindowResizedEvent*);
		};

		class TestEntity : public IEntity
		{
		public:
			TestEntity(const char*);
			~TestEntity();
			void OnUpdate(float) override;
			void OnRender() override;
			void OnEvent(Event* e) override;
		private:
			const char* name;
		};
		bool running = true;
	};
	Application* CreateApplication();
}