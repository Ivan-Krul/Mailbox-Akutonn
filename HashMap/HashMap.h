#pragma once
#include <list>

template<typename T, class S>
class hash_map {
	std::list<std::pair<T, S>> map;
public:
	void push_back(T& a, S& b);
	void push_front(T& a, S& b);

	void resize(size_t size);
	size_t size();
	S& operator[](T& what);
	T& operator[](S& what);

	void pop_back();
	void pop_front();
};
#include "HashMap.cpp"