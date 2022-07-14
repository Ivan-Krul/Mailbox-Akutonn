#include "Indexer.h"

void Indexer::append(std::string ind) {
	_indexer.push_back(ind);
}

void Indexer::appbeg(std::string ind) {
	_indexer.insert(_indexer.begin(), ind);
}

size_t Indexer::operator[](std::string what) {
	for (auto i = 0;i < _indexer.size();i++) {
		if (_indexer[i] == name)
			return i;
	}
	std::string errmeta;
	errmeta += metadata(__FILE__) +
		" -> menu is not found it : " + name;

	throw std::invalid_argument(errmeta);
}
