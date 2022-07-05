#include "HWNDeskriptor.h"

void HWNDeskriptor::_begcreation() {
	_type = TypeHWND__window;
	_style = WS_OVERLAPPEDWINDOW;
}

void HWNDeskriptor::_endcreation() {
}

void HWNDeskriptor::create(std::wstring name, UINT coordX, UINT coordY, UINT Width, UINT Height, HMENU menu, HWND parent) {
	_begcreation();

	_hwnd = CreateWindow(
		to_wstring(_type).c_str(),
		name.c_str(),
		_style,
		coordX, coordY,
		Width, Height,
		parent, 
		menu,
		NULL, NULL);

	_endcreation();
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

void Window::prepare_to_creation(WNDPROC proccess) {
	memset(&_wcl, 0, sizeof(WNDCLASSW));

	_wcl.lpszClassName = PROJECT_NAME;
	_wcl.lpfnWndProc = proccess;

	RegisterClass(&_wcl);
}

void Window::need_show_window(bool need)
{
	ShowWindow(_hwnd, need ? SW_SHOWNORMAL : SW_HIDE);
}
