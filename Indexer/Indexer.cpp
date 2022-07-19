#include "Indexer.h"

void Indexer::append(std::string ind) {
	_indexer.push_back(ind);
}

size_t Indexer::size() {
	return _indexer.size();
}

size_t Indexer::appgetend(std::string ind) {
	_indexer.insert(_indexer.begin(), ind);
	return _indexer.size() - 1;
}



size_t Indexer::operator[](std::string what) {
	for (auto i = 0;i < _indexer.size();i++) {
		if (_indexer[i] == what)
			return i;
	}

	std::string errmeta = metadata(__FILE__) + " -> element is not found it : " + what;
	throw std::invalid_argument(errmeta.c_str());
}

std::string Indexer::operator[](size_t what) {
	if(what< _indexer.size())
		return _indexer[what];

	std::string errmeta = metadata(__FILE__) + " -> address is out of the range : " + std::to_string(what);
	throw std::out_of_range(errmeta.c_str());
}

