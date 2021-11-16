#pragma once

#include "LayerStack.h"
#include "Win32.h"

#include <unordered_set>

namespace Oculum
{
	class WindowManager;
	class Window : public IEventListener
	{
	public:
		enum ExitCode
		{
			Normal, Closed_Due_To_Parent
		};
		Window(const wchar_t*, int, int, Window*, WindowManager* manager);
		Window(Window&) = delete;
		virtual ~Window();
		virtual void OnUpdate(float);
		void OnEvent(Event* e);
		virtual void OnUpdateClient(float) = 0;
		virtual void OnClose() = 0;
		void CloseWindow(int);
		bool IsClosing();
		LayerStack* GetStack();
		HWND GetHwnd();
		WindowManager* GetManager();
		Window* GetParent();
		std::unordered_set<Window*>& GetChildren();
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
			static constexpr const wchar_t* wndClassName = L"DX3DEngine";
			static WindowTemplate wndClass;
			HINSTANCE hInst;
		};
		static LRESULT CALLBACK HandleMsgSetup(HWND, UINT, WPARAM, LPARAM) noexcept;
		static LRESULT CALLBACK HandleMsgThunk(HWND, UINT, WPARAM, LPARAM) noexcept;
		LRESULT HandleMsg(HWND, UINT, WPARAM, LPARAM) noexcept;
		HWND hWnd;
		LayerStack stack;
		WindowManager* manager;
		Window* parent;
		std::unordered_set<Window*> children;
		const wchar_t* name;
		int width, height;
		bool closing;
	};
}