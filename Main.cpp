// Mailbox Akutonn.cpp: определяет точку входа для приложения.
//

#define _WIN32_WINNT 0x0A00
#include "Main.h"

LRESULT WndProc (
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam);

HWND bt_strout;

int main()
{
	HWND hwn = GetConsoleWindow();
	ShowWindow(hwn, SHOW_CONSOLE);



	WNDCLASSW wcl;
	HWND hwnd;

	memset(&wcl, 0, sizeof(WNDCLASSW));

	wcl.lpszClassName = PROJECT_NAME;
	wcl.lpfnWndProc = WndProc;

	RegisterClassW(&wcl);
	int X = 640;
	int Y = 480;
	srand(time(NULL));
	hwnd = CreateWindow(L"Wind", L"Wind name", WS_OVERLAPPEDWINDOW,
		100, 100, X, Y, NULL, NULL, NULL, NULL);

	ShowWindow(hwnd, SW_SHOWNORMAL);

	HWND bt_quit;
	bt_quit = CreateWindow(L"button", L"Quit", WS_VISIBLE |WS_CHILD,
		10, 10, 100, 50, hwnd, (HMENU)1, NULL, NULL);

	HWND bt_ok;
	bt_ok = CreateWindow(L"button", L"Ok", WS_VISIBLE | WS_CHILD,
		120, 10, 100, 50, hwnd, (HMENU)2, NULL, NULL);

	HWND bt_strin;
	bt_ok = CreateWindow(L"edit", L"0", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_RIGHT |ES_NUMBER,
		230, 10, 200, 25, hwnd, (HMENU)3, NULL, NULL);


	bt_strout = CreateWindow(L"static", L"hello", WS_VISIBLE | WS_CHILD,
		10, 70, 100, 50, hwnd, (HMENU)4, NULL, NULL);

	HWND bt_list;

	bt_list = CreateWindow(L"combobox", L"world", WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
		120, 70, 100, 250, hwnd, (HMENU)5, NULL, NULL);

	SendMessage(bt_list, CB_ADDSTRING, 0, (LPARAM)L"aaaaa");
	SendMessage(bt_list, CB_ADDSTRING, 0, (LPARAM)L"asdasd");
	SendMessage(bt_list, CB_ADDSTRING, 0, (LPARAM)L"mfjgh");
	SendMessage(bt_list, CB_SETCURSEL, 1, (LPARAM)0);

	MSG msg;
	while (GetMessage(&msg,NULL,0,0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT WINAPI WndProc(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam) {
	if (Msg == WM_DESTROY) {
		std::cout << "Window is closed\n";
		PostQuitMessage(0);
	}
	else if (Msg == WM_KEYDOWN)
		std::wcout << wParam << '\n';
	else if (Msg == WM_CHAR)
		std::wcout << (wchar_t)wParam << '\n';
	else if (Msg == WM_MOUSEMOVE) {
		int mox = LOWORD(lParam);
		int moy = HIWORD(lParam);
		std::wcout << "mouse [" << mox << "," << moy << "]\n";
	}
	else if (Msg == WM_LBUTTONDOWN)
		std::wcout << "click LB\n";
	else if (Msg == WM_RBUTTONDOWN)
		std::wcout << "click RB\n";
	else if (Msg == WM_COMMAND) {
		std::wcout << "Command\n";
		if (LOWORD(wParam) == 1) {
			std::cout << "Button : \"Quit\"\n";
			std::cout << "Window is closed\n";
			PostQuitMessage(0);
		}
		else if (LOWORD(wParam) == 2) {
			std::cout << "Button : \"Ok\"\n";
		}
		else if (LOWORD(wParam) == 3) {
			int nc = HIWORD(wParam);
			std::wstring str;
			str.resize(100);
			GetWindowText((HWND)lParam, (LPWSTR)str.c_str(), 100);
			if (nc == EN_UPDATE) {
				std::wcout << "Input Update\t" << str << "\n";
				SetWindowText(bt_strout, (LPWSTR)str.c_str());
			}
			if (nc == EN_CHANGE)
				std::cout << "Input Change\n";
		}
		else if (LOWORD(wParam) == 5) {
			if (HIWORD(wParam) == CBN_SELCHANGE) {
				int id = SendMessage((HWND)lParam,CB_GETCURSEL,0,0);
				std::wstring str;
				str.resize(100);
				GetWindowText((HWND)lParam, (LPWSTR)str.c_str(), 100);
				std::wcout << "Selected " << id << " is old " << str << '\n';
				SendMessage((HWND)lParam,CB_GETLBTEXT, id, (LPARAM)str.c_str());
				std::wcout << "Selected " << id<< " is new "<<str << '\n';
			}
		}
	}
	return DefWindowProc(hWnd,Msg,wParam,lParam);
}
