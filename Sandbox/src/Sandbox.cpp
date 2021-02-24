#include "Sandbox.h"

Sandbox::Sandbox() : Oculum::Application()
{
	GetManager()->RegisterWindow(new MainWindow(GetManager()));
}

Sandbox::~Sandbox()
{

}