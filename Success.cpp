#include "Logger.h"

void Logger::Success(const char* format, ...) {
	va_list args;
	fprintf(stderr, "Success: ");
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	fprintf(stderr, "\n");
}