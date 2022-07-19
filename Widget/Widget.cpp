#include "Widget.h"

void Widget::_create_widget(LPCSTR type, LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd, HMENU hmenu, HINSTANCE hinst, LPVOID lparam) {
	_hwnd = CreateWindow(type, name, style, px, py, x, y, hwnd, hmenu, hinst, lparam);
	_henu = (size_t)hmenu;
}

void Widget::text(std::string str) {
	SetWindowText(_hwnd, str.c_str());
}

std::string Widget::text(UINT size) {
	std::string str;
	str.resize(size);
	GetWindowText(_hwnd, (char*)str.c_str(), size);

	return str;
}

size_t Widget::henu() {
	return _henu;
}


HWND Widget::operator() () {
	return _hwnd;
}
