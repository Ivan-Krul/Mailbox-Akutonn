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
	MSBox(HWND hwnd);

	void title(std::wstring titl);
	void text(std::wstring txt);
	void property(MSBox_prop prop);
	void trig();
	MSBox_res resultmsg();
};

class MSBoxErr : public MSBox {
public:
	MSBoxErr(HWND hwnd) : MSBox(hwnd) {
		_icon = MB_ICONERROR;
	}
};
class MSBoxQue : public MSBox {
public:
	MSBoxQue(HWND hwnd) : MSBox(hwnd) {
		_icon = MB_ICONQUESTION;
	}
};
class MSBoxWrn : public MSBox {
public:
	MSBoxWrn(HWND hwnd) : MSBox(hwnd) {
		_icon = MB_ICONWARNING;
	}
};
class MSBoxInf : public MSBox {
public:
	MSBoxInf(HWND hwnd) : MSBox(hwnd) {
		_icon = MB_ICONINFORMATION;
	}
};

#include "MSBox.cpp"