// Mailbox Akutonn.h : включаемый файл для стандартных
//  системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include "Define/Define.h"
#include "MSBox/MSBox.h"
#include "Widget/Static/Static.h"
#include "Widget/Edit/Edit.h"
#include "Widget/Button/Button.h"
#include "Widget/Wndow/Wndow.h"
#include "Menu/Menu.h"

#include <chrono>

void add_menu(HWND hwnd, Menu& menu);
void add_widgets(HWND hwnd);
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

void ext();

int main();

// TODO: установите здесь ссылки на дополнительные заголовки,
//	требующиеся для программы.
