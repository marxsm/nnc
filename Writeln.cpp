#include "Writter.h"


void Writter::Writeln(const char * format, ...) {
	va_list args;
	va_start(args, format);
	vfprintf(outFile, format, args);
	va_end(args);
	fprintf(outFile, "\n");
}