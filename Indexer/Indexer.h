#pragma once
#include "../Define/Define.h"
#include <vector>
#include <string>
#include <fstream>

interface IIndexer {
	void append(std::string ind);
	void appbeg(std::string ind);
	size_t operator[] (std::string);
};

class Indexer : public IIndexer {
	static std::vector<std::string> _indexer;
public:
	size_t size();
	void append(std::string ind);
	void appbeg(std::string ind);

	size_t operator[] (std::string what);
	std::string operator[] (size_t what);
} Indexer_;

std::vector<std::string> Indexer::_indexer;
#include "Indexer.cpp"