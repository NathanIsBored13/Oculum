#include "MainWindow.h"
#include "TestEntity.h"
#include "ChildWindow.h"

MainWindow::MainWindow(Oculum::WindowManager* manager) : Oculum::Window(L"MainWindow", 400, 400, nullptr, manager)
{
	SubscribeEvent<Oculum::ChildCloseEvent>([&](Oculum::ChildCloseEvent* e)
		{
			OC_INFO("Child closed with exit code %i", e->GetExitCode());
			return true;
		});

	new ChildWindow(this, GetManager());
	new ChildWindow(this, GetManager());
	new ChildWindow(this, GetManager());
}

MainWindow::~MainWindow()
{

}

void MainWindow::OnUpdateClient(float)
{

}

void MainWindow::OnClose()
{
	if (MessageBox(GetHwnd(), L"Are you sure you want to exit?", L"Quit", MB_YESNO) == IDYES)
	{
		CloseWindow(Oculum::Window::ExitCode::Normal);
	}
}