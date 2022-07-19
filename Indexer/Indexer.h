#pragma once
#include "../Define/Define.h"
#include <vector>
#include <string>
#include <fstream>

__interface IIndexer {
	size_t size();
	void append(std::string ind);
	size_t appgetend(std::string ind);
};

class Indexer : public IIndexer {
	static std::vector<std::string> _indexer;
public:
	size_t size();
	void append(std::string ind);

	size_t appgetend(std::string ind);

	size_t operator[] (std::string what);
	std::string operator[] (size_t what);
} Indexer_;

std::vector<std::string> Indexer::_indexer;
#include "Indexer.cpp"