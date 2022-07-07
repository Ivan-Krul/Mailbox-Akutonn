#pragma once
#include "../Define/Define.h"
#include <vector>

interface IMenu {
	void append(std::wstring);
	void append(HMENU menu);
	void separatorend();
	void append(IMenu menu);

	size_t index(std::wstring name);
};

class Menu : public IMenu {
	HMENU _menu;
	std::vector<std::wstring> _indexer;
	size_t _flag;

	static size_t _hudeflag;

public:
	Menu();
	Menu(std::vector<std::wstring> indexer) : Menu();

	void append(std::wstring what);
	void append(HMENU menu);
	void separatorend();
	void append(IMenu menu);

	size_t index(std::wstring name);
};
#include "Menu.cpp"
size_t Menu::_hudeflag = 0;