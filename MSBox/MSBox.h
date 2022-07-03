#pragma once
#include "IMSBox.h"

class MSBox : public IMSBox {
protected:
	std::string _title;
	std::string _text;

	UINT _icon;
	UINT _property;
	int _id;

public:
	void add_title(std::string titl);
};

class MSboxErr : public MSBox {
};
class MSboxQue : public MSBox {
};
class MSboxWrn : public MSBox {
};
class MSboxInf : public MSBox {
};

#include "MSBox.cpp"