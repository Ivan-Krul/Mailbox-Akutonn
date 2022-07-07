// Mailbox Akutonn.h : включаемый файл для стандартных
//  системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include "Define/Define.h"
#include "MSBox/MSBox.h"
#include "Wnodw/Wnodw.h"

#define MenuFileMenuCreateMenuFile 1
#define MenuVisual 2
#define MenuDocumentation 3
#define MenuFileMenuExit 4

void add_menu(HWND hwnd);
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp,
	LPARAM lp);

int main();

// TODO: установите здесь ссылки на дополнительные заголовки,
//	требующиеся для программы.
