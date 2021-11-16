#pragma once


#include "Core.h"
#include "Event.h"

#include <functional>
#include <unordered_map>

namespace Oculum
{
	class IEventListener
	{
	public:
		virtual ~IEventListener()
		{
			for(std::pair<Event::Type, AbstractDispatcher*> pair : dispatchers)
			{
				delete pair.second;
			}
		}

		virtual void OnEvent(Event* e)
		{
			std::unordered_map<Event::Type, AbstractDispatcher*>::iterator iterator = dispatchers.find(e->GetType());
			if (iterator != dispatchers.end())
			{
				(*iterator).second->Dispatch(e);
			}
		}

		template <class T>
		void SubscribeEvent(std::function<bool(T*)> function)
		{
			std::pair<Event::Type, AbstractDispatcher*> pair = std::pair<Event::Type, AbstractDispatcher*>(T::GetStaticType(), new Dispatcher<T>(function));
			dispatchers.insert(pair);
		}

	private:
		class AbstractDispatcher
		{
		public:
			virtual void Dispatch(Event*) = 0;
		};

		template <class T>
		class Dispatcher : public AbstractDispatcher
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
		private:
			std::function<bool(T*)> function;
		};

		std::unordered_map<Event::Type, AbstractDispatcher*> dispatchers = std::unordered_map<Event::Type, AbstractDispatcher*>();
	};
}