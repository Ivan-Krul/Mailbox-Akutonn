#pragma once
#include "../Define/Define.h"
#include <string>

enum TypeHWND {
	TypeHWND__window,
	TypeHWND__button,
	TypeHWND__edit,
	TypeHWND__static,
	TypeHWND__list,
	TypeHWND__combobox,
	TypeHWND__mdiclient,
	TypeHWND__scroll
};

std::wstring to_wstring(TypeHWND tphwn);
POINT get_screen_resol();

interface ITitle {
	void title(std::string titl);
};

interface IWindow {
	void create(HBRUSH bg_color, HCURSOR cursor, HINSTANCE hinst, HICON icon, LPCWSTR name, WNDPROC proccess);
};

#include "Wind.cpp"