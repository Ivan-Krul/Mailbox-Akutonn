#include "Button.h"
#include "Button.h"
#include "Button.h"

void WButton::adapt(LPCSTR text, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd, HMENU hmenu, HINSTANCE hinst, LPVOID lparam) {
	_create_widget("button", text, style, px, py, x, y, hwnd, hmenu, hinst, lparam);
}
