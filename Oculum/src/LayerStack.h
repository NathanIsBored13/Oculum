#pragma once

#include "IEventListener.h"
#include "Layer.h"

#include <vector>

namespace Oculum
{
	class LayerStack : public IEventListener
	{
	public:
		LayerStack();
		~LayerStack();
		void OnUpdate(float);
		void OnRender();
		void PushLayer(Layer*);
		Layer* GetLayer(int depth);
		Layer* GetLayer(const char* name);
		std::string ToString();
		void OnEvent(Event*) override;
	private:
		Layer *head = nullptr, *tail = nullptr;
		int size = 0;
	};
}