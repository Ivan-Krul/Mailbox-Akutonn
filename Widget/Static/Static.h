#pragma once
#include "../Widget.h"

class WStatic : public Widget {
public:
	void adapt(LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL) override;
};
#include "Static.cpp"