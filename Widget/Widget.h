#pragma once
#include "../Define/Define.h"

enum class widgets : int {
	def_widget = 'defa',
	window = 'wind',
	button = 'butt',
	static_ = 'stat',
	edit = 'edit'
};

interface IWidget {
	HWND adapt(LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);
	void text(std::string str);
	std::string text(UINT size);
	size_t henu();
	virtual widgets intedeficate();
	HWND operator() ();
};

class Widget : public IWidget {
protected:
	HWND _hwnd;
	size_t _henu;

	void _create_widget(LPCSTR type,LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);
public:
	virtual void adapt(LPCSTR name, DWORD style, UINT x, UINT y, UINT px, UINT py, HWND hwnd = NULL, HMENU hmenu = NULL, HINSTANCE hinst = NULL, LPVOID lparam = NULL);

	void text(std::string str);
	std::string text(UINT size);
	size_t henu();
	virtual widgets intedeficate();

	HWND operator() ();
};
#include "Widget.cpp"
#include "Wndow/Wndow.h"
#include "Static/Static.h"
#include "Edit/Edit.h"
#include "Button/Button.h"