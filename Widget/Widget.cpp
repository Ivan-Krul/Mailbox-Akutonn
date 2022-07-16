#include "Widget.h"

void Widget::create_widget(LPCSTR type, LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd, HMENU hmenu, HINSTANCE hinst, LPVOID lparam)
{
	_hwnd = CreateWindow(type, name, style, px, py, x, y, hwnd, hmenu, hinst, lparam);
}

void Widget::adapt(LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd, HMENU hmenu, HINSTANCE hinst, LPVOID lparam) {
	
}

void Widget::text(std::string str) {
	SetWindowText(_hwnd, str.c_str());
}

std::string Widget::text() {
	return std::string();
}

HWND Widget::operator() () {
	return HWND();
}
