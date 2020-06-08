#pragma once

#include "IEventListener.h"

namespace Oculum
{
	class IEntity : public IEventListener
	{
	public:
		virtual void OnUpdate(float) = 0;
		virtual void OnRender() = 0;
	};
}