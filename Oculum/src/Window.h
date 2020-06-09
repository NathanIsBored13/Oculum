#pragma once

#include "LayerStack.h"

namespace Oculum
{
	class Window
	{
	public:
		Window(const wchar_t*, int, int);
		~Window();
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
		const wchar_t* name;
		int width, height;
	};
}