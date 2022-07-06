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
	Window wnd;
	wnd.create((HBRUSH)COLOR_WINDOW,
		LoadCursor(NULL, IDC_ARROW),NULL,
		LoadIcon(NULL, IDI_QUESTION), WndProc);
	wnd.adapt(L"Wnd", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 500,
		250);

	MSG msg = {0};
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

WNDCLASS new_window(HBRUSH bg_color, HCURSOR cursor, HINSTANCE hinst, HICON icon, LPCWSTR name, WNDPROC proccess) {
	WNDCLASS NWC = { 0 };

	NWC.hIcon = icon;
	NWC.hCursor = cursor;
	NWC.hInstance = hinst;
	NWC.lpszClassName = name;
	NWC.hbrBackground = bg_color;
	NWC.lpfnWndProc = proccess;

	return NWC;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg)
	{
	case WM_CREATE:
		std::wcout << "create\n";
		add_menu(hwnd);
		break;

	case WM_COMMAND:
		std::wcout << "command";
		switch (wp) {
		case MenuFileMenuCreateMenuFile: {
			std::wcout << "\tmenu:file/create/empty file\n";
			MSBoxInf inf(hwnd);
			inf.title(L"info");
			inf.text(L"menu:file/create/empty file is clicked");
			inf.property(MSBox_prop__ok);
			inf.trig();}
			break;

		case MenuVisual: {
			std::wcout << "\tmenu:visual\n";
			MSBoxInf inf(hwnd);
			inf.title(L"info");
			inf.text(L"visual is clicked");
			inf.property(MSBox_prop__ok);
			inf.trig();}
			break;

		case MenuDocumentation: {
			std::wcout << "\tmenu:documentation\n";
			MSBoxInf inf(hwnd);
			inf.title(L"info");
			inf.text(L"documentation is clicked");
			inf.property(MSBox_prop__ok);
			inf.trig();}
			break;

		case MenuFileMenuExit:
			std::wcout << "\tmenu:file/exit\n";
			std::wcout << "destroy\n";
			PostQuitMessage(0);

			break;
		}
		break;
	case WM_DESTROY:
		std::wcout << "destroy\n";
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, msg, wp, lp);
	}

}

void add_menu(HWND hwnd) {
	HMENU root = CreateMenu();
	HMENU root_file = CreateMenu();
	HMENU root_file_create = CreateMenu();

	AppendMenu(root, MF_POPUP, (UINT_PTR)root_file, L"File");
	AppendMenu(root, MF_STRING, MenuVisual, L"Visual");
	AppendMenu(root, MF_STRING, MenuDocumentation, L"Documentation");
	AppendMenu(root_file, MF_POPUP, (UINT_PTR)root_file_create, L"Create");
	AppendMenu(root_file, MF_SEPARATOR, NULL, NULL);
	AppendMenu(root_file, MF_STRING, MenuFileMenuExit, L"Exit");
	AppendMenu(root_file_create, MF_STRING, MenuFileMenuCreateMenuFile, L"Empty file");


	SetMenu(hwnd, root);
}
