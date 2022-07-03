#pragma once
#include "../Define/Define.h"
#include <string>

__interface IMessagebox {
	void add_title(std::string titl);
	void add_text(std::string txt);
	void add_button();
	void trig();
	int resultmsg();
};
