#pragma once
#include "../Wind.h"

class Window : public IWindow {
	WNDCLASS _wcl;


	WNDCLASS _new_window(HBRUSH bg_color, HCURSOR cursor,
		HINSTANCE hinst, HICON icon, WNDPROC proccess);
public:
	void create(HBRUSH bg_color, HCURSOR cursor,
		HINSTANCE hinst, HICON icon, WNDPROC proccess);

	HWND adapt(LPCWSTR name, DWORD style, UINT x, UINT y,
		HWND hwnd = NULL, HMENU hmenu = NULL,
		HINSTANCE hinst = NULL, LPVOID lparam = NULL);
};

#include "Window.cpp"