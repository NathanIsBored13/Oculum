#pragma once

#include "IEntity.h"

#include <vector>

namespace Oculum
{
	class Layer : public IEntity
	{
		friend class LayerStack;
	public:
		Layer(const char*);
		~Layer();
		Layer* GetChild();
		const char* GetName();
		void OnUpdate(float) override;
		void OnRender() override;
		void AddEntity(IEntity*);
		void Push(Layer*);
		std::string ToString();
		void OnEvent(Event*) override;
	private:
		const char* name;
		Layer* child = nullptr;
		std::vector<IEntity*> elements;
	};
}