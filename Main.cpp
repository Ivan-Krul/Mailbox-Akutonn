// Mailbox Akutonn.cpp: определяет точку входа для приложения.
//

#include "Main.h"

static WButton
static Menu menu;

int main() {
	try {
		Wndow wnd;

		wdgt[0] = new WButton();
		wdgt[1] = new WEdit();
		wdgt[2] = new WStatic();

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
		else if (wp == Indexer_["Wbutton"]) {
			std::cout << "\t"<<Indexer_[wp]<<"\n";			
		}
		else if (wp == Indexer_["Wedit"]) {
			std::cout << "\t" << Indexer_[wp] << "\n";
		}
		else if (wp == Indexer_["Wstatic"]) {
			std::cout << "\t" << Indexer_[wp] << "\n";
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
	for (size_t i = 0; i < std::size(wdgt);i++) {
		if (wdgt[i]->intedeficate() == widgets::button) {
			wdgt[i]->adapt("hello, button", WS_VISIBLE | WS_CHILD | ES_CENTER, 400, 40, 5, 130+i*40, hwnd, (Indexer_.append("Wbutton"), (HMENU)Indexer_["Wbutton"]), NULL, NULL);
		}
		else if (wdgt[i]->intedeficate() == widgets::edit) {
			wdgt[i]->adapt("Hello edit widget!", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 30, 460, 100, hwnd, (Indexer_.append("Wedit"), (HMENU)Indexer_["W" + std::to_string(i) + "edit"]), NULL, NULL);
		}
		else if (wdgt[i]->intedeficate() == widgets::static_) {
			wdgt[i]->adapt("Hello static widget!", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 460, 20, hwnd, (Indexer_.append("Wstatic"), (HMENU)Indexer_["W" + std::to_string(i) + "static"]), NULL, NULL);
		}
	}
}

