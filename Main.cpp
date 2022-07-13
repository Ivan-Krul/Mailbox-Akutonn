// Mailbox Akutonn.cpp: определяет точку входа для приложения.
//

#define _WIN32_WINNT 0x0A00
#include "Main.h"

int main() {
	//Message at start
	/*
	{
		MSBoxInf ms(NULL);
		ms.title(PROJECT_NAME);
		ms.text(L"Program is run");
		ms.property(MSBox_prop__ok_cancel);
		ms.trig();
		if (ms.resultmsg() == MSBox_res__cancel) return 1;
	}
*/
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
	if (msg == WM_CREATE) {
		std::wcout << "create\n";
		add_menu(hwnd);
	}
	else if (msg == WM_COMMAND) {
		std::wcout << "command";

		if (wp == MenuFileMenuCreateMenuFile) {
			std::wcout << "\tmenu:file/create/empty file\n";
			MSBoxInf inf(hwnd);
			inf.title("info");
			inf.text(
				"menu:file/create/empty file is clicked");
			inf.property(MSBox_prop::ok);
			inf.trig();
		}
		else if(wp == MenuVisual) {
			std::wcout << "\tmenu:visual\n";
			MSBoxInf inf(hwnd);
			inf.title("info");
			inf.text("visual is clicked");
			inf.property(MSBox_prop::ok);
			inf.trig();
		}
		else if (wp == MenuDocumentation) {
			std::wcout << "\tmenu:documentation\n";
			MSBoxInf inf(hwnd);
			inf.title("info");
			inf.text("documentation is clicked");
			inf.property(MSBox_prop::ok);
			inf.trig();
		}
		else if (wp == MenuFileMenuExit) {
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

void add_menu(HWND hwnd) {
	HMENU root = CreateMenu();
	HMENU root_file = CreateMenu();
	HMENU root_file_create = CreateMenu();

	AppendMenu(root, MF_POPUP, (UINT_PTR)root_file, "File");
	AppendMenu(root, MF_STRING, MenuVisual, "Visual");
	AppendMenu(root, MF_STRING, MenuDocumentation, "Documentation");
	AppendMenu(root_file, MF_POPUP, (UINT_PTR)root_file_create, "Create");
	AppendMenu(root_file, MF_SEPARATOR, NULL, NULL);
	AppendMenu(root_file, MF_STRING, MenuFileMenuExit, "Exit");
	AppendMenu(root_file_create, MF_STRING, MenuFileMenuCreateMenuFile, "Empty file");


	SetMenu(hwnd, root);
}
