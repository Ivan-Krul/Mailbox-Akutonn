#pragma once
#include <vector>
#include <list>
#include "../Wind.h"

template<typename T,class S>
class hash_map {
	std::list<std::pair<T, S>> map;
public:
	void push_back(T& a, S& b);
	void push_front(T& a, S& b);

	void resize(size_t size);
	size_t size();
	S& operator[](T& what);

	void pop_back();
	void pop_front();
};

class Menu {
	std::vector<HMENU> cataloh;
};

#include "Menu.cpp"