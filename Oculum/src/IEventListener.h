#pragma once

#include "ocpch.h"

#include "Core.h"
#include "Event.h"

namespace Oculum
{
	class IEventListener
	{
	public:
		virtual void OnEvent(Event* e)
		{
			for (DispatcherTypeless* dispatcher : dispatchers)
			{
				if (e->GetType() == dispatcher->GetType())
				{
					dispatcher->Dispatch(e);
				}
			}
		}

		template <class T>
		void SubscribeEvent(std::function<bool(T*)> function)
		{
			dispatchers.push_back(new Dispatcher<T>(function));
		}

	private:
		class DispatcherTypeless
		{
		public:
			virtual void Dispatch(Event*) = 0;
			virtual Event::Type GetType() = 0;
		};

		template <class T>
		class Dispatcher : public DispatcherTypeless
		{
		public:
			Dispatcher(std::function<bool(T*)> function) : function(function)
			{

			}

			virtual void Dispatch(Event* e) override
			{
				if (function(static_cast<T*>(e)))
				{
					e->Handled();
				}
			}

			virtual Event::Type GetType() override
			{
				return T::GetStaticType();
			}
		private:
			std::function<bool(T*)> function;
		};

		std::vector<DispatcherTypeless*> dispatchers;
	};
}