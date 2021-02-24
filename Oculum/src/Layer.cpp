#include "ocpch.h"
#include "Layer.h"

namespace Oculum
{
	Layer::Layer(const char* name = "Unamed") : name(name)
	{

	}

	Layer::~Layer()
	{
		for (Entity* entity : elements)
		{
			delete entity;
		}
		if (child != nullptr)
		{
			delete child;
		}
	}

	Layer* Layer::GetChild()
	{
		return child;
	}

	const char* Layer::GetName()
	{
		return name;
	}

	void Layer::OnUpdate(float elapsedTime)
	{
		for (Entity* entity : elements)
		{
			entity->OnUpdate(elapsedTime);
		}
		if (child != nullptr)
		{
			child->OnUpdate(elapsedTime);
		}
	}

	void Layer::OnRender()
	{
		if (child != nullptr)
		{
			child->OnRender();
		}
		for (Entity* entity : elements)
		{
			entity->OnRender();
		}
	}

	void Layer::AddEntity(Entity* e)
	{
		elements.push_back(e);
	}

	void Layer::Push(Layer* layer)
	{
		child = layer;
	}

	std::string Layer::ToString()
	{
		std::stringstream ss;
		ss << "Layer \"" << name << "\" contains [" << elements.size() << "] elements";
		return ss.str();
	}

	void Layer::OnEvent(Event* e)
	{
		for (Entity* entity : elements)
		{
			entity->OnEvent(e);
		}
		if (e->IsHandled() || child == nullptr)
		{
			delete e;
		}
		else
		{
			child->OnEvent(e);
		}
	}
}