#include "Edit.h"

void WEdit::adapt(LPCSTR text, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd, HMENU hmenu, HINSTANCE hinst, LPVOID lparam) {
	_create_widget("edit", text, style, px, py, x, y, hwnd, hmenu, hinst, lparam);
}
