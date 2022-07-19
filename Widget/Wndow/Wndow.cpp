#include "Wndow.h"

static POINT get_screen_resol() {
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	POINT p = { desktop.right,desktop.bottom };
	return p;
}

WNDCLASS Wndow::_new_window(HBRUSH bg_color,
	HCURSOR cursor, HINSTANCE hinst, HICON icon,
	WNDPROC proccess) {
	WNDCLASS NWC = { 0 };

	NWC.hIcon = icon;
	NWC.hCursor = cursor;
	NWC.hInstance = hinst;
	NWC.lpszClassName = "MainWndClass";
	NWC.hbrBackground = bg_color;
	NWC.lpfnWndProc = proccess;

	return NWC;
}

void Wndow::create(WNDPROC proccess, HBRUSH bg_color,
	HCURSOR cursor, HINSTANCE hinst, HICON icon) {
	_wcl = _new_window((HBRUSH)bg_color, cursor, hinst,
		icon, proccess);
	if (!RegisterClass(&_wcl)) exit(-1);
}

void Wndow::adapt(LPCSTR name, DWORD style, UINT x,
	UINT y, UINT px,UINT py, HWND hwnd, HMENU hmenu, HINSTANCE hinst,
	LPVOID lparam)
{
	auto a = get_screen_resol();

	int posX, posY;
#if (WINDOW_POS_INDEX == CENTER)
	posX = (a.x - x) / 2;
	posY = (a.y - y) / 2;
#elif (WINDOW_POS_INDEX == DIAGONAL)
	posX = (x + y) / 4;
	posY = (x + y) / 4;
#elif (WINDOW_POS_INDEX == RANDOM)
	srand(time(NULL));
	posX = rand() % ((a.x - x) / 2);
	posY = rand() % ((a.y - y) / 2);
#else
	posX = 0;
	posY = 0;
#endif

	CreateWindow("MainWndClass", name, style,
		posX, posY, x, y, hwnd, hmenu,
		hinst, lparam);
}
