#pragma once
#include "../Wind.h"

class HWNDeskriptor : public HWNDesk {
protected:
	HWND _hwnd;
	TypeHWND _type;
	DWORD _style;

	virtual void _begcreation();
	virtual void _endcreation();
public:
	void set_style(DWORD dword);
	void add_style(DWORD dword);
	void create(std::wstring name, UINT coordX, UINT coordY, UINT Width, UINT Height, HMENU menu, HWND parent = NULL);
	HWND get_HWND();
};

class Window : public HWNDeskriptor {
protected:
	WNDCLASS _wcl;

public:
	void prepare_to_creation(WNDPROC proccess);

	void need_show_window(bool need = true);
};

using Button = HWNDeskriptor;
using Edit = HWNDeskriptor;
using Static = HWNDeskriptor;
using List = HWNDeskriptor;
using Combobox = HWNDeskriptor;
using MdiClient = HWNDeskriptor;
using Scroll = HWNDeskriptor;

#include "HWNDeskriptor.cpp"