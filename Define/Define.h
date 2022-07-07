#pragma once
#define UNICODE

#define CENTER 'cent'
#define DIAGONAL 'diag'
#define RANDOM 'rand'
#define WINDOW_POS_INDEX CENTER

#define DEBUG
#ifndef DEBUG
#define NDEBUG
#endif

#include <cassert>
#include <Windows.h>

#define SHOW_CONSOLE 1
#define PROJECT_NAME L"Mailbox Akutonn"

#ifdef SHOW_CONSOLE
#include <iostream>
#endif

