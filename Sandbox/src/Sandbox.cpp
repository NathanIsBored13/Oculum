#include "Sandbox.h"

Sandbox::Sandbox() : Oculum::Application()
{
	new MainWindow(getManager());
}

Sandbox::~Sandbox()
{

}