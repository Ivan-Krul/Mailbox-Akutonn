// Mailbox Akutonn.cpp: определяет точку входа для приложения.
//

#include "Main.h"

static WButton but;
static WEdit edi;
static WStatic sta;
static Menu menu;

int main() {
	try {
		std::cout << "["<<PROJECT_NAME<<"]\n";
		Wndow wnd;

		wnd.create(WndProc);
		wnd.adapt("Wnd", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 500, 250);

		MSG msg = { 0 };
		while (GetMessage(&msg, NULL, NULL, NULL)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (GetAsyncKeyState(VK_ESCAPE)) {
				std::cout << "emergency stop!\n";
				throw std::exception();
			}
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
		else if (wp == but.henu()) {
			std::cout << "\t"<<Indexer_[wp]<<"\n";	
			edi.text("clicked!");
		}
		else if (wp == edi.henu()) {
			std::cout << "\t" << Indexer_[wp] << "\n";
		}
		else if (wp == sta.henu()) {
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
	Indexer_.append("Wbutton");
	Indexer_.append("Wstatic");
	Indexer_.append("Wedit");
	but.adapt("hello, button", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 135, 130, 40, hwnd, (HMENU)Indexer_["Wbutton"]);
	sta.adapt("Hello static widget!", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 460, 20, hwnd, (HMENU)Indexer_["Wstatic"]);
	edi.adapt("Hello edit widget!", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 30, 460, 100, hwnd, (HMENU)Indexer_["Wedit"]);
}

