// Mailbox Akutonn.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include "Define/Define.h"
#include "MSBox/MSBox.h"
#include "Wind/Window/Window.h"

#define MenuFileMenuCreateMenuFile 1
#define MenuVisual 2
#define MenuDocumentation 3
#define MenuFileMenuExit 4

void add_menu(HWND hwnd);
WNDCLASS new_window(HBRUSH bg_color, HCURSOR cursor, HINSTANCE hinst, HICON icon, LPCWSTR name, WNDPROC proccess);
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

int main();

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
