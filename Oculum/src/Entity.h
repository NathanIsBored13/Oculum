#pragma once

#include "IEventListener.h"

namespace Oculum
{
	class Window;
	class Entity : public IEventListener
	{
	public:
		Entity(Window*, int);
		virtual ~Entity();
		virtual void OnUpdate(float) = 0;
		virtual void OnRender() = 0;
		Window* GetWindow();
	private:
		Window* window;
	};
}