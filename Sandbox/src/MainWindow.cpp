#include "MainWindow.h"

MainWindow::MainWindow() : Oculum::Window(L"MainWindow", 400, 400, nullptr)
{

}

MainWindow::~MainWindow()
{

}

void MainWindow::OnUpdateClient(float)
{

}

bool MainWindow::OnClose()
{
	return true;
}