#pragma once
#include "IMSBox.h"

class MSBox : public IMSBox {
protected:
	std::wstring _title;
	std::wstring _text;

	UINT _icon;
	UINT _property;
	MSBox_res _id;

	HWND _win;
public:
	MSBox(HWND& hwnd);

	void add_title(std::wstring titl);
	void add_text(std::wstring txt);
	void add_property(MSBox_prop prop);
	void trig();
	MSBox_res resultmsg();
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