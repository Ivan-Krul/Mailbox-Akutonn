#pragma once
#include "../Define/Define.h"

__interface IWidget {
	void adapt(LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd, HMENU hmenu, HINSTANCE hinst, LPVOID lparam);

	void text(std::string str);
	std::string text(UINT size);
	size_t henu();
};

class Widget : public IWidget {
protected:
	HWND _hwnd;
	size_t _henu;

	void _create_widget(LPCSTR type, LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd, HMENU hmenu, HINSTANCE hinst, LPVOID lparam);
public:
	virtual void adapt(LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL) = 0;

	void text(std::string str);
	std::string text(UINT size);
	size_t henu();

	HWND operator() ();
};
#include "Widget.cpp"