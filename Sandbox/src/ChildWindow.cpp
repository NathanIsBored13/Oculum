#include "ChildWindow.h"
#include "TestEntity.h"

ChildWindow::ChildWindow(Oculum::Window* parent, Oculum::WindowManager* manager) : Oculum::Window(L"Child", 200, 200, parent, manager)
{
	SubscribeEvent<Oculum::ParentCloseEvent>([&](Oculum::ParentCloseEvent* e)
		{
			CloseWindow(Oculum::Window::ExitCode::Closed_Due_To_Parent);
			return true;
		});
}

ChildWindow::~ChildWindow()
{

}

void ChildWindow::OnUpdateClient(float)
{

}

void ChildWindow::OnClose()
{
	CloseWindow(Oculum::Window::ExitCode::Normal);
}