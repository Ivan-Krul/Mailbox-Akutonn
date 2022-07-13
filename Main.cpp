// Mailbox Akutonn.cpp: определяет точку входа для приложения.
//

#include "Main.h"

int main() {
	Wnodw wnd;
	wnd.create(WndProc);
	wnd.adapt("Wnd", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 500, 250);

	MSG msg = {0};
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

//---------------------------------------------------------//

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	static Menu menu;

	if (msg == WM_CREATE) {
		std::wcout << "create\n";
		add_menu(hwnd, menu);
	}
	else if (msg == WM_COMMAND) {
		std::wcout << "command";

		if (wp == menu["Empty file"]) {
			std::wcout << "\tmenu:file/create/empty file\n";
			MSBoxInf inf(hwnd);
			inf.title("info");
			inf.text(
				"menu:file/create/empty file is clicked");
			inf.property(MSBox_prop::ok);
			inf.trig();
		}
		else if(wp == menu["Visual"]) {
			std::wcout << "\tmenu:visual\n";
			MSBoxInf inf(hwnd);
			inf.title("info");
			inf.text("visual is clicked");
			inf.property(MSBox_prop::ok);
			inf.trig();
		}
		else if (wp == menu["Documentation"]) {
			std::wcout << "\tmenu:documentation\n";
			MSBoxInf inf(hwnd);
			inf.title("info");
			inf.text("documentation is clicked");
			inf.property(MSBox_prop::ok);
			inf.trig();
		}
		else if (wp == menu["Exit"]) {
			std::wcout << "\tmenu:file/exit\n";
			std::wcout << "destroy\n";
			PostQuitMessage(0);
		}
	}
	else if (msg == WM_DESTROY) {
		std::wcout << "destroy\n";
		PostQuitMessage(0);
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

void add_menu(HWND hwnd, Menu& menu) {
	Menu men1;
	Menu men2;

	menu.append(men1(), "File");
	menu.append("Visual");
	menu.append("Documentation");
	men1.append(men2(), "Create");
	men1.separatorend();
	men1.append("Exit");
	men2.append("Empty file");

	menu.set_as_main(hwnd);
}
