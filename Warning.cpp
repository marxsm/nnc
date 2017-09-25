#include "Logger.h"

void Logger::Warning(const char* format, ...) {
	va_list args;
	fprintf(stderr, "Warning: ");
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	fprintf(stderr, "\n");
}