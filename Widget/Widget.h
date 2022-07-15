#pragma once
#include "../Define/Define.h"

interface IAdapt {
	HWND adapt(LPCWSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);
};

interface IWidget : IAdapt {
	HWND operator() ();
};

class Widget : public IWidget {
	HWND _hwnd;

public:
	void adapt(LPCWSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);

	set_text

	HWND operator() ();
};
