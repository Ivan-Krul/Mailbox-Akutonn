// Mailbox Akutonn.cpp: определяет точку входа для приложения.
//

#include "Main.h"

int main()
{
	HWND hwnd = GetConsoleWindow();

	MSBox ms;

	MoveWindow(hwnd, 500, 500, 400, 300, true);
	MessageBox(hwnd, TEXT("Text"), TEXT("Text"), MB_SERVICE_NOTIFICATION);

	std::wcout << "Hello CMake.\n";
	return 0;
}
