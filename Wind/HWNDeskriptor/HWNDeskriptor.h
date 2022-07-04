#pragma once
#include "../Wind.h"

class HWNDeskriptor : public HWNDesk {
protected:
	HWND _hwnd;
	TypeHWND _type;
	DWORD _style;

	virtual void _equal_type();
public:
	void set_style(DWORD dword);
	void add_style(DWORD dword);
	void create(std::wstring name, UINT coordX, UINT coordY, UINT Width, UINT Height, HMENU menu, HWND parent = NULL);
	void create(std::wstring name, UINT Width, UINT Height, HMENU menu = NULL, HWND parent = NULL);
	HWND get_HWND();
};

class Window : public HWNDeskriptor {
protected:
	WNDCLASS _wcl;

public:
	void create();
};

#include "HWNDeskriptor.cpp"