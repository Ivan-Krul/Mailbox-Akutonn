#pragma once
#include "../Widget.h"

class WEdit : public Widget {
public:
	void adapt(LPCSTR text, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL) override;

};
#include "Edit.cpp"