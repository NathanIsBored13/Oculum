#pragma once

#include "LayerStack.h"

namespace Oculum
{
	class Window
	{
	public:
		Window(const wchar_t*, int, int, Window*);
		virtual ~Window();
		virtual void OnUpdate(float);
		virtual void OnUpdateClient(float) = 0;
		virtual bool OnClose() = 0;
		void AddChild(Window*);
		void RemoveChild(Window*);
		void CloseWindow(int);
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
		HWND hWnd;
		LayerStack stack;
		Window* parent;
		std::vector<Window*> children;
		const wchar_t* name;
		int width, height;
	};
}