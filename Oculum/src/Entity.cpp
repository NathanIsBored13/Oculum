#include "ocpch.h"

#include "Entity.h"
#include "Window.h"

namespace Oculum
{
	Entity::Entity(Window* window, int layer) : window(window)
	{
		window->GetStack()->GetLayer(layer)->AddEntity(this);
	}

	Entity::~Entity()
	{

	}

	Window* Entity::GetWindow()
	{
		return window;
	}
}