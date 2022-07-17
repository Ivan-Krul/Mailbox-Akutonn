// Mailbox Akutonn.cpp: определяет точку входа для приложения.
//

#include "Main.h"

int main() {
	try {
		auto wnd = Wnodw();
		wnd.create(WndProc);
		wnd.adapt("Wnd", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 500, 250);

		MSG msg = { 0 };
		while (GetMessage(&msg, NULL, NULL, NULL)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		return 0;
	}
	catch (std::exception& exept) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4f);
		std::cout << "Error: " << exept.what()<<'\n';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);
		return -1;
	}
}

//---------------------------------------------------------//

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	static Menu menu;
	static WEdit edit;
	static WStatic stati;
	static WButton butt;

	if (msg == WM_CREATE) {
		std::cout << "create\n";
		//Indexer_.fillfromfile("Stand.txt");
		add_menu(hwnd, menu);
		add_widgets(hwnd);
	}
	else if (msg == WM_COMMAND) {
		std::cout << "command\n";

		if (wp == Indexer_["Empty file"]) {
			std::cout << "\t" << Indexer_[wp] << "\n";
		}
		else if(wp == Indexer_["Visual"]) {
			std::cout << "\t" << Indexer_[wp] << "\n";
		}
		else if (wp == Indexer_["Documentation"]) {
			std::cout << "\t" << Indexer_[wp] << "\n";
		}
		else if (wp == Indexer_["Exit"]) {
			std::cout << "\t" << Indexer_[wp] << "\n";
			std::cout << "destroy\n";
			PostQuitMessage(0);
		}
		else if (wp == Indexer_["click"]) {
			std::cout << "\t"<<Indexer_[wp]<<"\n";
			SetWindowText(hEdit5, "clicked!");
		}
	}
	else if (msg == WM_DESTROY) {
		std::wcout << "destroy\n";
		PostQuitMessage(0);
	}
	return DefWindowProc(hwnd, msg, wp, lp);
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
	Indexer_.append("click");


	CreateWindow("static", "Hello static widget!", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 460, 20, hwnd, NULL, NULL, NULL);
	hEdit5 = CreateWindow("edit", "Hello edit widget!", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 30, 460, 100, hwnd, NULL, NULL, NULL);
	CreateWindow("button", "Hello button widget!", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 130, 460, 20, hwnd, (HMENU)Indexer_["click"], NULL, NULL);
}

