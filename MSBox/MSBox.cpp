#include "MSBox.h"

MSBox::MSBox(HWND hwnd) {
	_win = hwnd;

	_title = "[title]";
	_text = "[text]";
	_id = MSBox_res::ok;
	_icon = MB_ICONINFORMATION;
	_property = 0u;
}

void MSBox::title(std::string titl) {
	_title = titl;
}

void MSBox::text(std::string txt) {
	_text = txt;
}

void MSBox::property(MSBox_prop prop) {
	_property |= (UINT)prop;
}

void MSBox::trig() {
	int id = MessageBox(_win, _text.c_str(), _title.c_str(),
		_property | _icon);
	_id = (MSBox_res)id;
}

MSBox_res MSBox::resultmsg() {
	return _id;
}
