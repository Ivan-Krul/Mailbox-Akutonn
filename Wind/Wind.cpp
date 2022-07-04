#include "Wind.h"

std::wstring to_wstring(TypeHWND tphwn) {
	switch (tphwn)
	{
	case TypeHWND__window:
		return L"WINDOW";
	case TypeHWND__button:
		return L"BUTTON";
	case TypeHWND__edit:
		return L"EDIT";
	case TypeHWND__static:
		return L"STATIC";
	case TypeHWND__list:
		return L"LISTBOX";
	case TypeHWND__combobox:
		return L"COMBOBOX";
	case TypeHWND__mdiclient:
		return L"MDICLIENT";
	case TypeHWND__scroll:
		return L"SCROLLBAR";
	}
}

POINT get_screen_resol() {
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	POINT p = { desktop.right,desktop.bottom };
	return p;
}
