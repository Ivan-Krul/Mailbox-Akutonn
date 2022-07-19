#include "Menu.h"

Menu::Menu() {
	_menu = CreateMenu();
}

Menu::Menu(std::vector<std::string> indexer) : Menu::Menu() {
	for (size_t i = 0;i < indexer.size();i++) {
		append(indexer[i]);
	}
}

void Menu::append(std::string what) {
	AppendMenu(_menu, MF_STRING, Indexer_.size(), what.c_str());
	Indexer_.append(what);
}

void Menu::append(HMENU menu, std::string name) {
	AppendMenu(_menu, MF_POPUP, (UINT_PTR)menu, name.c_str());
}

void Menu::separatorend() {
	AppendMenu(_menu, MF_SEPARATOR, NULL, NULL);
}

HMENU Menu::get_menu() {
	return _menu;
}

void Menu::set_as_main(HWND hwnd) {
	SetMenu(hwnd, _menu);
}

HMENU Menu::operator() () {
	return _menu;
}
