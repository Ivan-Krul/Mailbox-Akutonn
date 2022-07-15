#pragma once
#include "../Define/Define.h"
#include "../Indexer/Indexer.h"
#include <vector>

interface IMenu {
	~IMenu() {};
	void append(std::string);
	void append(HMENU menu);
	void separatorend();
	void append(IMenu menu);

	void set_as_main(HWND hwnd = NULL);
	HMENU get_menu();
};


class Menu : public IMenu {
	HMENU _menu;

public:
	Menu();
	Menu(std::vector<std::string> indexer);

	HMENU operator() ();

	void append(std::string what);
	void append(HMENU menu, std::string name);
	void separatorend();

	HMENU get_menu();
	void set_as_main(HWND hwnd = NULL);
};

#include "Menu.cpp"