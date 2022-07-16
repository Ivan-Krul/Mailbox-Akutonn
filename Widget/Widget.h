#pragma once
#include "../Define/Define.h"

interface IAdapt {
	HWND adapt(LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);
};

interface IWidget : IAdapt {
	HWND operator() ();
};

class Widget : public IWidget {
	HWND _hwnd;

	void create_widget(LPCSTR type,LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);
public:
	virtual void adapt(LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL)
		: create_widget("Window", name, style, px, py, x, y, hwnd, hmenu, hinst, lparam);

	virtual void text(std::string str);
	virtual std::string text();

	HWND operator() ();
};
#include "Widget.cpp"
#include "Wndow/Wndow.h"