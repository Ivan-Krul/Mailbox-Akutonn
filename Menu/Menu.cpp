#include "Menu.h"

Menu::Menu() {
	_menu = CreateMenu();
}

Menu::Menu(std::vector<std::string> indexer) {
	for (size_t i = 0;i < indexer.size();i++) {
		append(indexer[i]);
	}
}

void Menu::append(std::string what) {
	AppendMenu(_menu, MF_STRING, _indexer.size(), what.c_str());
	_indexer.push_back(what);
}

void Menu::append(HMENU menu, std::string name) {
	AppendMenu(_menu, MF_POPUP, (UINT_PTR)menu, name.c_str());
}

void Menu::separatorend() {
	AppendMenu(_menu, MF_SEPARATOR, NULL, NULL);
}

void Menu::append(IMenu menu, std::string name) {
	append(menu.get_menu(), name);
}

HMENU Menu::get_menu() {
	return _menu;
}

size_t Menu::operator[](std::string name) {
	for (auto i = 0;i < _indexer.size();i++) {
		if (_indexer[i] == name)
			return i;
	}
	throw std::invalid_argument("menu is not found it");
}
