#pragma once
#include "../Define/Define.h"
#include <vector>

interface IIndexer {
	void append(std::string ind);
	void appbeg(std::string ind);
	size_t operator[] (std::string);
};

class Indexer : public IIndexer {
	static std::vector<std::string> _indexer;
public:
	void append(std::string ind);
	void appbeg(std::string ind);
	size_t operator[] (std::string what);
};

#include "Indexer.cpp"