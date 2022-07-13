#pragma once
#include "../Define/Define.h"
#include <vector>

interface IMenu {
	~IMenu() {};
	void append(std::string);
	void append(HMENU menu);
	void separatorend();
	void append(IMenu menu);

	void set_as_main(HWND hwnd = NULL);
	HMENU get_menu();

	size_t operator[] (std::string name);
};


class Menu : public IMenu {
	HMENU _menu;
	static std::vector<std::string> _indexer;

public:
	Menu();
	Menu(std::vector<std::string> indexer);

	HMENU operator() ();

	void append(std::string what);
	void append(HMENU menu, std::string name);
	void separatorend();
	void append(IMenu menu, std::string name);

	HMENU get_menu();
	void set_as_main(HWND hwnd = NULL);

	size_t operator[] (std::string name);
};

std::vector<std::string> Menu::_indexer;
#include "Menu.cpp"