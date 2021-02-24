#pragma once

#include "Entity.h"

#include <vector>

namespace Oculum
{
	class Layer : public IEventListener
	{
		friend class LayerStack;
	public:
		Layer(const char*);
		~Layer();
		Layer* GetChild();
		const char* GetName();
		void OnUpdate(float);
		void OnRender();
		void AddEntity(Entity*);
		void Push(Layer*);
		std::string ToString();
		void OnEvent(Event*) override;
	private:
		const char* name;
		Layer* child = nullptr;
		std::vector<Entity*> elements;
	};
}