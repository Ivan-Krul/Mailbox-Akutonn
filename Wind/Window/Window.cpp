#include "Window.h"

WNDCLASS Window::_new_window(HBRUSH bg_color,
	HCURSOR cursor, HINSTANCE hinst, HICON icon,
	WNDPROC proccess) {
	WNDCLASS NWC = { 0 };

	NWC.hIcon = icon;
	NWC.hCursor = cursor;
	NWC.hInstance = hinst;
	NWC.lpszClassName = L"MainWndClass";
	NWC.hbrBackground = bg_color;
	NWC.lpfnWndProc = proccess;

	return NWC;
}

void Window::create(HBRUSH bg_color, HCURSOR cursor,
	HINSTANCE hinst, HICON icon, WNDPROC proccess) {
	_wcl = _new_window((HBRUSH)bg_color, cursor, hinst,
		icon, proccess);
	if (!RegisterClass(&_wcl)) exit(-1);
}

HWND Window::adapt(LPCWSTR name, DWORD style, UINT x,
	UINT y, HWND hwnd, HMENU hmenu, HINSTANCE hinst,
	LPVOID lparam)
{
	auto a = get_screen_resol();

	return CreateWindowW(L"MainWndClass", name, style,
		(a.x)/2 - x, (a.y)/2 - y, x, y, hwnd, hmenu,
		hinst, lparam);
}
