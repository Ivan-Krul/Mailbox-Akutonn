#pragma once
#include "../Define/Define.h"
#include <vector>

interface IMenu {
	void append(std::string);
	void append(HMENU menu);
	void separatorend();
	void append(IMenu menu);

	HMENU get_menu();

	size_t operator[] (std::string name);
};


class Menu : public IMenu {
	HMENU _menu;
	static std::vector<std::string> _indexer;

public:
	Menu();
	Menu(std::vector<std::string> indexer) : Menu();

	void append(std::string what);
	void append(HMENU menu, std::string name);
	void separatorend();
	void append(IMenu menu, std::string name);

	HMENU get_menu();

	size_t operator[] (std::string name);
};
#include "Menu.cpp"