#include "Button.h"
#include "Button.h"

void WButton::adapt(LPCSTR text, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd, HMENU hmenu, HINSTANCE hinst, LPVOID lparam) {
	_create_widget("edit", text, style, px, py, x, y, hwnd, hmenu, hinst, lparam);
}

widgets WButton::intedeficate()
{
	return widgets::button;
}
