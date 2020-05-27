#pragma once

extern Oculum::Application* Oculum::CreateApplication();

int CALLBACK WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	Oculum::Application* app = Oculum::CreateApplication();
	OC_INFO("Engine initialised");
	app->Run();
	delete app;
	return 0;
}