#pragma once
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
#include <iostream>

#define IS_SHOW_CONSOLE 1
#define PROJECT_NAME "Mailbox Akutonn"

std::string metadata(const char* file = __FILE__) {
	std::string meta = "(";
	meta += file;
	meta += ") (";
	meta += __DATE__;
	meta += " ";
	meta += __TIME__;
	meta += ")";
	return meta;
}
