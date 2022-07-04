#include "HWNDeskriptor.h"

void HWNDeskriptor::_equal_type() {
	_type = TypeHWND__window;
	_style = WS_OVERLAPPEDWINDOW;
}

void HWNDeskriptor::create(std::wstring name, UINT coordX, UINT coordY, UINT Width, UINT Height, HMENU menu, HWND parent) {
	_equal_type();

	_hwnd = CreateWindow(
		to_wstring(_type).c_str(),
		name.c_str(),
		_style,
		coordX, coordY,
		Width, Height,
		parent, 
		menu,
		NULL, NULL);
}

void HWNDeskriptor::create(std::wstring name, UINT Width, UINT Height, HMENU menu, HWND parent) {
	_equal_type();

	_hwnd = CreateWindow(
		to_wstring(_type).c_str(),
		name.c_str(),
		_style,
		WINDOW_POS_X, WINDOW_POS_Y,
		Width, Height,
		parent,
		menu,
		NULL, NULL);
}

HWND HWNDeskriptor::get_HWND() {
	return _hwnd;
}

void HWNDeskriptor::add_style(DWORD dword) {
	_style |= dword;
}

void HWNDeskriptor::set_style(DWORD dword) {
	_style = dword;
}
