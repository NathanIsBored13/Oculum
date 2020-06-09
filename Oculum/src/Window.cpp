#include "ocpch.h"
#include "Window.h"

namespace Oculum
{
	Window::WindowTemplate Window::WindowTemplate::wndClass;

	Window::WindowTemplate::WindowTemplate() noexcept : hInst(GetModuleHandle(nullptr))
	{
		WNDCLASSEX wnd =
		{
			sizeof(wnd),
			CS_OWNDC,
			HandleMsgSetup,
			0,
			0,
			GetInstance(),
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			GetName(),
			nullptr
		};
		RegisterClassEx(&wnd);
	}

	Window::WindowTemplate::~WindowTemplate()
	{
		UnregisterClass(wndClassName, GetInstance());
	}

	const wchar_t* Window::WindowTemplate::GetName() noexcept
	{
		return wndClassName;
	}

	HINSTANCE Window::WindowTemplate::GetInstance() noexcept
	{
		return wndClass.hInst;
	}

	Window::Window(const wchar_t* name, int width, int height) : width(width), height(height), name(name)
	{
		RECT wr
		{
			100,
			100,
			width + 100,
			height + 100
		};
		AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);
		hWnd = CreateWindowEx(0, WindowTemplate::GetName(), name, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top, nullptr, nullptr, WindowTemplate::GetInstance(), this);
		ShowWindow(hWnd, SW_SHOWDEFAULT);
	}

	Window::~Window()
	{
	}

	LRESULT CALLBACK Window::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)  noexcept
	{
		LRESULT ret;
		if (msg == WM_NCCREATE)
		{
			const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
			Window* const pWnd = static_cast<Window*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Window::HandleMsgThunk));
			ret = pWnd->HandleMsg(hWnd, msg, wParam, lParam);
		}
		else
		{
			ret = DefWindowProc(hWnd, msg, wParam, lParam);
		}
		return ret;
	}

	LRESULT CALLBACK Window::HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)  noexcept
	{
		return reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA))->HandleMsg(hWnd, msg, wParam, lParam);
	}

	LRESULT Window::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

}