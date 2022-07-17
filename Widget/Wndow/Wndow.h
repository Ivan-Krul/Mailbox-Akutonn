#pragma once
#include "../Widget.h"

interface IWCreate {
	void create(WNDPROC proccess, HBRUSH bg_color = (HBRUSH)COLOR_WINDOW, HCURSOR cursor = LoadCursor(NULL, IDC_ARROW), HINSTANCE hinst = NULL, HICON icon = NULL);
};

static POINT get_screen_resol();

class Wndow : public Widget, public IWCreate {
protected:
	WNDCLASS _wcl;

	WNDCLASS _new_window(HBRUSH bg_color, HCURSOR cursor, HINSTANCE hinst, HICON icon, WNDPROC proccess);
public:
	void create(WNDPROC proccess, HBRUSH bg_color = (HBRUSH)COLOR_WINDOW, HCURSOR cursor = LoadCursor(NULL, IDC_ARROW), HINSTANCE hinst = NULL, HICON icon = NULL);

	HWND adapt(LPCSTR name, DWORD style, UINT x, UINT y, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);
	virtual widgets intedeficate();

	WNDCLASS operator() ();
};

#include "Wndow.cpp"