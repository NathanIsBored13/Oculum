#include "Sandbox.h"

Sandbox::Sandbox() : Oculum::Application()
{
	Oculum::Application::GetManager()->RegisterWindow(new MainWindow());
}

Sandbox::~Sandbox()
{

}