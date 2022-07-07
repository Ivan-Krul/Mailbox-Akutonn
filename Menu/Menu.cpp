#include "Menu.h"

Menu::Menu() {
	_menu = CreateMenu();
}

Menu::Menu(std::vector<std::wstring> indexer) {
	_indexer = indexer; 
	for (size_t i = 0;i < indexer.size();i++) {
		append(indexer[i]);
	}
}

void Menu::append(std::wstring what) {

}

void Menu::append(HMENU menu) {
}

void Menu::separatorend() {
}

void Menu::append(IMenu menu) {
}

size_t Menu::index(std::wstring name) {
	return size_t();
}
