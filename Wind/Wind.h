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

interface IWind {
	void add_title(std::string titl);
};

interface HWNDesk : public IWind {
	void create(std::wstring name, UINT coordX, UINT coordY, UINT Width, UINT Height, HMENU menu, HWND parent = NULL);
	HWND get_HWND();

};

#include "Wind.cpp"
#include "HWNDeskriptor/HWNDeskriptor.h"