#pragma once

#include <stdarg.h>
#include <stdio.h>


namespace Logger {

	void Log(const char * format, ...);
	void Error(const char * format, ...);
	void Success(const char * format, ...);
	void Warning(const char * format, ...);
};

