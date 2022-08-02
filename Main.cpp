// Mailbox Akutonn.cpp: определяет точку входа для приложения.
//

#include "Main.h"
#include "Logger/Logger.h"

static WButton but;
static WEdit edi;
static WStatic sta;
static Menu menu;

static logger logg;
extern auto beg = std::chrono::system_clock::now();

int main() {
	try {
		Wndow wnd;

		wnd.create(WndProc, (HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), NULL, LoadIcon(NULL, MAKEINTRESOURCE(NULL)));
		wnd.adapt("Wnd", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 500, 250);

		MSG msg = { 0 };
		while (GetMessage(&msg, NULL, NULL, NULL)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (GetAsyncKeyState(VK_ESCAPE)) {
				logg.log("emergency stop!");
				throw std::exception();
			}
		}

		return 0;
	}
	catch (std::exception& exept) {
		logg.log("Error: "+(std::string)exept.what());
		return -1;
	}
}

//---------------------------------------------------------//

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {


	if (msg == WM_CREATE) {
		logg.log("create");
		add_menu(hwnd, menu);
		add_widgets(hwnd);
	}
	else if (msg == WM_COMMAND) {
		logg.log("command");
		

		if (wp == Indexer_["Exit"]) {
			logg.log("\t"+Indexer_[wp]);
			logg.log("destroy");
			PostQuitMessage(0);
		}
		else if (wp == but.henu()) {
			logg.log("\t"+Indexer_[wp]);
			edi.text("clicked!");
		}
		
	}
	else if (msg == WM_DESTROY) {
		logg.log("destroy");
		PostQuitMessage(0);
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

std::string si(float val) {
	int stepin = 0;

	while (!(1000.0f > val) && stepin != 24) {
		val /= 1000.0f;
		stepin += 3;
	}
	while (!(val > 1.0f) && stepin != -24) {
		val *= 1000.0f;
		stepin -= 3;
	}
	char su;

	if (stepin == -24) su = 'y';
	else if (stepin == -21) su = 'z';
	else if (stepin == -18) su = 'a';
	else if (stepin == -15) su = 'f';
	else if (stepin == -12) su = 'p';
	else if (stepin == -9) su = 'n';
	else if (stepin == -6) su = 'u';
	else if (stepin == -3) su = 'm';
	else if (stepin == 0) su = '\0';
	else if (stepin == 3) su = 'k';
	else if (stepin == 6) su = 'M';
	else if (stepin == 9) su = 'G';
	else if (stepin == 12) su = 'T';
	else if (stepin == 15) su = 'P';
	else if (stepin == 18) su = 'E';
	else if (stepin == 21) su = 'Z';
	else su = 'Y';

	std::string num = std::to_string(val) + " ";
	num.insert(num.end(), su);
	return num;
}

void add_menu(HWND hwnd, Menu& menu) {
	auto men1 = Menu();
	auto men2 = Menu();

	menu.append(men1(), "File");
	menu.append("Visual");
	menu.append("Documentation");
	men1.append(men2(), "Create");
	men1.separatorend();
	men1.append("Exit");
	men2.append("Empty file");

	menu.set_as_main(hwnd);


}

void add_widgets(HWND hwnd) {
	but.adapt("hello, button", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 135, 130, 40, hwnd, (HMENU)Indexer_.appgetend("Wbutton"));
	sta.adapt("Hello static widget!", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 460, 20, hwnd, (HMENU)Indexer_.appgetend("Wstatic"));
	edi.adapt("Hello edit widget!", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 30, 460, 100, hwnd, (HMENU)Indexer_.appgetend("Wedit"));
}
