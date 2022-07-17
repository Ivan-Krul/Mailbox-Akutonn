#pragma once
#include "../Widget.h"

interface IWnodw : IWidget {
	void create(HBRUSH bg_color, HCURSOR cursor, HINSTANCE hinst, HICON icon, WNDPROC proccess);

	HWND adapt(LPCWSTR name, DWORD style, UINT x, UINT y, UINT px = NULL, UINT py = NULL, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);

	WNDCLASS modify();
};

static POINT get_screen_resol();

class Wnodw : IWnodw {
protected:
	WNDCLASS _wcl;

	WNDCLASS _new_window(HBRUSH bg_color, HCURSOR cursor, HINSTANCE hinst, HICON icon, WNDPROC proccess);
public:
	void create(WNDPROC proccess, HBRUSH bg_color = (HBRUSH)COLOR_WINDOW, HCURSOR cursor = LoadCursor(NULL, IDC_ARROW), HINSTANCE hinst = NULL, HICON icon = NULL);

	HWND adapt(LPCSTR name, DWORD style, UINT x, UINT y, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);
	
	WNDCLASS operator() ();
};

#include "Wndow.cpp"