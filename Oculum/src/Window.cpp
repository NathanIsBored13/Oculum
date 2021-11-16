#include "ocpch.h"
#include "Window.h"

#include "Events/Events.h"
#include "WindowManager.h"

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

	Window::Window(const wchar_t* name, int width, int height, Window* parent, WindowManager* manager) : width(width), height(height), name(name), parent(parent), children(std::unordered_set<Window*>()), closing(false), manager(manager)
	{
		if (parent != nullptr)
		{
			parent->children.insert(this);
		}

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
		stack = LayerStack();

		manager->RegisterWindow(this);
	}

	Window::~Window()
	{

	}

	void Window::OnUpdate(float fElapsed)
	{
		stack.OnUpdate(fElapsed);
		OnUpdateClient(fElapsed);
	}

	void Window::OnEvent(Event* e)
	{
		IEventListener::OnEvent(e);

		if (!e->IsHandled())
		{
			stack.OnEvent(e);
		}
	}

	void Window::CloseWindow(int exitCode)
	{
		closing = true;

		if (parent != nullptr)
		{
			parent->OnEvent(new ChildCloseEvent(exitCode));
			if (!parent->IsClosing())
			{
				parent->children.erase(this);
			}
		}

		for (Window* wnd : children)
		{
			wnd->OnEvent(new ParentCloseEvent(exitCode));
			wnd->parent = nullptr;
		}

		DestroyWindow(hWnd);
		PostMessage(nullptr, WM_QUIT, exitCode, reinterpret_cast<LPARAM>(this));
	}

	bool Window::IsClosing()
	{
		return closing;
	}

	LayerStack* Window::GetStack()
	{
		return &stack;
	}

	HWND Window::GetHwnd()
	{
		return hWnd;
	}

	WindowManager* Window::GetManager()
	{
		return manager;
	}

	Window* Window::GetParent()
	{
		return parent;
	}

	std::unordered_set<Window*>& Window::GetChildren()
	{
		return children;
	}

	LRESULT CALLBACK Window::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)  noexcept
	{
		if (msg == WM_NCCREATE)
		{
			const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
			Window* const pWnd = static_cast<Window*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Window::HandleMsgThunk));
			return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
		}
		else
		{
			return  DefWindowProc(hWnd, msg, wParam, lParam);
		}
	}

	LRESULT CALLBACK Window::HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)  noexcept
	{
		return reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA))->HandleMsg(hWnd, msg, wParam, lParam);
	}

	LRESULT Window::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		switch (msg)
		{
		case WM_CLOSE:
			OnClose();
			return 0;
			break;
		case WM_MOUSEMOVE:
			OnEvent(new MouseMovedEvent((int)LOWORD(lParam), (int)HIWORD(lParam)));
			break;
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}