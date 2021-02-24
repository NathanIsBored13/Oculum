#pragma once

#include "Oculum.h"

class TestEntity : public Oculum::Entity
{
public:
	TestEntity(Oculum::Window*, int);
	~TestEntity();
	void OnUpdate(float) override;
	void OnRender() override;
private:
};