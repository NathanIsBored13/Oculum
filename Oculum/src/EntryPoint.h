#pragma once

namespace Oculum
{
	extern Application* CreateApplication();
}

int CALLBACK WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	Oculum::Application* app = Oculum::CreateApplication();
	OC_INFO("Engine initialised");
	app->Run();
	delete app;
	return 0;
}