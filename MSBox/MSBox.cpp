#include "MSBox.h"

MSBox::MSBox(HWND& hwnd) {
	_win = hwnd;

	_title = L"[title]";
	_text = L"[text]";
	_id = MSBox_res__ok;
	_icon = MB_ICONINFORMATION;
	_property = 0u;
}

void MSBox::add_title(std::wstring titl) {
	_title = titl;
}

void MSBox::add_text(std::wstring txt) {
	_text = txt;
}

void MSBox::add_property(MSBox_prop prop) {
	_property |= prop;
}

void MSBox::trig() {
	int id = MessageBox(_win, _text.c_str(), _title.c_str(), _property | );
	_id = (MSBox_res)id;
}

MSBox_res MSBox::resultmsg() {
	return _id;
}
