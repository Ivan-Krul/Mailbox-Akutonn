#include "HashMap.h"

template<typename T, class S>
void hash_map<T, S>::push_back(T& a, S& b) {
	std::pair<T, S> a = {a,b};
	map.push_back(a);
}

template<typename T, class S>
void hash_map<T, S>::push_front(T& a, S& b) {
	std::pair<T, S> a = { a,b };
	map.push_front(a);
}

template<typename T, class S>
void hash_map<T, S>::resize(size_t size) {
	 map.resize(size);
}

template<typename T, class S>
size_t hash_map<T, S>::size() {
	return map.size();
}

template<typename T, class S>
S& hash_map<T, S>::operator[](T& what)
{
	// TODO: вставьте здесь оператор return
}

template<typename T, class S>
T& hash_map<T, S>::operator[](S& what)
{
	// TODO: вставьте здесь оператор return
}

template<typename T, class S>
void hash_map<T, S>::pop_back()
{
}

template<typename T, class S>
void hash_map<T, S>::pop_front()
{
}