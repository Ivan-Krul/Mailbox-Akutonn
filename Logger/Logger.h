#pragma once
#include <fstream>
#include <chrono>
#include "../Define/Define.h"

class logger 
{
protected:
	const std::string _cType = ".log";
	std::chrono::system_clock::time_point _start,_last;
	std::ofstream _ofs;

	float _delay_ms(std::chrono::system_clock::time_point beg_, std::chrono::system_clock::time_point end_);
	void _createFile(std::string dir_);
	void _closeFile();
public:
	logger() { _createFile(PROJECT_NAME); }
	logger(std::string dir_) { _createFile(dir_); }

	void log(std::string str_);

	~logger() { _closeFile(); }
};

inline float logger::_delay_ms(std::chrono::system_clock::time_point beg_, std::chrono::system_clock::time_point end_)
{
	return (float)std::chrono::duration_cast<std::chrono::nanoseconds>(end_ - beg_).count() / 1000000.0f;
}

inline void logger::_createFile(std::string dir_)
{
	_start = std::chrono::system_clock::now();
	_last = _start;
	_ofs.open(dir_ + _cType);
}

inline void logger::_closeFile()
{
	_ofs << "time elapsed - " << _delay_ms(_start,std::chrono::system_clock::now())<<" ms\n" <<"date: "<<__DATE__<<"\ttime: "<<__TIME__;
	_ofs.close();
}

inline void logger::log(std::string str_)
{
	_ofs <<'[' << std::setw(6) << _delay_ms(_last, std::chrono::system_clock::now()) << " \tms] " << str_ << '\n';
	_last = std::chrono::system_clock::now();
}
