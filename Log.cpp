#include "Logger.h"

extern bool ShowLog;

void Logger::Log(const char * format, ...)
{
	if (!ShowLog) return;
	va_list args;
	fprintf(stdout, "Log: ");
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
	fprintf(stdout, "\n");
}