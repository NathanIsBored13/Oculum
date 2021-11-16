#pragma once

#include "Oculum.h"

class MainWindow : public Oculum::Window
{
public:
	MainWindow(Oculum::WindowManager* manager);
	~MainWindow();
	void OnUpdateClient(float) override;
	void OnClose() override;
};