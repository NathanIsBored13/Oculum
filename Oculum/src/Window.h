#pragma once

#include "LayerStack.h"

namespace Oculum
{
	class WindowManager;

	class Window
	{
	public:
		enum ExitCode
		{
			Normal, Closed_Due_To_Parent
		};
		Window(const wchar_t*, int, int, Window*, WindowManager*);
		virtual ~Window();
		virtual void OnUpdate(float);
		virtual void OnUpdateClient(float) = 0;
		virtual bool OnClose() = 0;
		void AddChild(Window*);
		void RemoveChild(Window*);
		void CloseWindow(int);
		WindowManager* GetWindowManager();
		LayerStack* GetStack();
		HWND GetHwnd();
	private:
		class WindowTemplate
		{
		public:
			static const wchar_t* GetName() noexcept;
			static HINSTANCE GetInstance() noexcept;
		private:
			WindowTemplate() noexcept;
			~WindowTemplate();
			WindowTemplate(const WindowTemplate&) = delete;
			WindowTemplate& operator=(const WindowTemplate&) = delete;
			static constexpr const wchar_t* wndClassName = L"DX3DEngin";
			static WindowTemplate wndClass;
			HINSTANCE hInst;
		};
		static LRESULT CALLBACK HandleMsgSetup(HWND, UINT, WPARAM, LPARAM) noexcept;
		static LRESULT CALLBACK HandleMsgThunk(HWND, UINT, WPARAM, LPARAM) noexcept;
		LRESULT HandleMsg(HWND, UINT, WPARAM, LPARAM) noexcept;
		WindowManager* windowManager;
		HWND hWnd;
		LayerStack stack;
		Window* parent;
		std::vector<Window*> children;
		const wchar_t* name;
		int width, height;
	};
}