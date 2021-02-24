#pragma once

#include "Oculum.h"

class MainWindow : public Oculum::Window
{
public:
	MainWindow(Oculum::WindowManager*);
	~MainWindow();
	void OnUpdateClient(float) override;
	bool OnClose() override;
};