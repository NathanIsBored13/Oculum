#pragma once

#include "Oculum.h"

class ChildWindow : public Oculum::Window
{
public:
	ChildWindow(Oculum::Window*, Oculum::WindowManager* manager);
	~ChildWindow();
	void OnUpdateClient(float) override;
	void OnClose() override;
};