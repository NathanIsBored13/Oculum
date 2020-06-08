#include "ocpch.h"
#include "LayerStack.h"

namespace Oculum
{
	LayerStack::LayerStack()
	{

	}

	LayerStack::~LayerStack()
	{
		delete head;
	}

	void LayerStack::OnUpdate(float elapsedTime)
	{
		if (head != nullptr)
		{
			head->OnUpdate(elapsedTime);
		}
	}

	void LayerStack::OnRender()
	{
		if (head != nullptr)
		{
			head->OnRender();
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		if (tail == nullptr)
		{
			head = layer;
		}
		else
		{
			tail->Push(layer);
		}
		tail = layer;
		size++;
	}

	Layer* LayerStack::GetLayer(int depth)
	{
		Layer* ret = nullptr;
		if (depth < size)
		{
			ret = head;
			while (depth > 0)
			{
				ret = ret->GetChild();
				depth--;
			}
		}
		return ret;
	}

	Layer* LayerStack::GetLayer(const char* name)
	{
		Layer* ret = nullptr;
		if (head != nullptr)
		{
			ret = head;
			while (ret != nullptr && std::strcmp(name, ret->GetName()) != 0)
			{
				ret = ret->GetChild();
			}
		}
		return ret;
	}

	std::string LayerStack::ToString()
	{
		std::stringstream ss;
		if (size != 0)
		{
			ss << "LayerStack contains [" << size << "] elements\n";
			Layer* ptr = head;

			do
			{
				ss << "\t" << ptr->ToString() << "\n";
				ptr = ptr->GetChild();
			} while (ptr != nullptr);
		}
		else
		{
			ss << "LayerStack is empty";
		}
		return ss.str();
	}

	void LayerStack::OnEvent(Event* e)
	{
		if (head != nullptr)
		{
			head->OnEvent(e);
		}
	}
}