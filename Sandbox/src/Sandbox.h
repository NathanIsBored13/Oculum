#pragma once

#include "Oculum.h"
#include "src/EntryPoint.h"
#include "MainWindow.h"

class Sandbox : public Oculum::Application
{
public:
	Sandbox();
	~Sandbox();
};

Oculum::Application* Oculum::CreateApplication()
{
    return new Sandbox();
}