#pragma once
#include "../Define/Define.h"

interface IWnodw {
	void create(HBRUSH bg_color, HCURSOR cursor, HINSTANCE hinst, HICON icon, WNDPROC proccess);

	HWND adapt(LPCWSTR name, DWORD style, UINT x, UINT y, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);

	WNDCLASS modify();
};

static POINT get_screen_resol();

class Wnodw {
	WNDCLASS _wcl;

	WNDCLASS _new_window(HBRUSH bg_color, HCURSOR cursor, HINSTANCE hinst, HICON icon, WNDPROC proccess);
public:
	void create(WNDPROC proccess, HBRUSH bg_color = (HBRUSH)COLOR_WINDOW, HCURSOR cursor = LoadCursor(NULL, IDC_ARROW), HINSTANCE hinst = NULL, HICON icon = NULL);

	HWND adapt(LPCSTR name, DWORD style, UINT x, UINT y, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);
	
	WNDCLASS operator() ();
};

#include "Wnodw.cpp"