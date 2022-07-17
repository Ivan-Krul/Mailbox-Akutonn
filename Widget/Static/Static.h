#pragma once
#include "../Widget.h"

class WStatic : public Widget {
public:
	virtual void adapt(LPCSTR text, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);
	virtual widgets intedeficate();

};
