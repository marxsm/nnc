#include "Logger.h"

#include "Matcher.h"

extern bool ErrorMarked;

void Logger::Error(const char* format, ...) {
	va_list args;
	fprintf(stdout, "Error: ");
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
	fprintf(stdout, "\n");

	ErrorMarked = true;

	deque<char*>* t = Minst->GetTokens();

	char * tok = nullptr;

	printf("At position :\n\t");

	int i = 0;
	for (auto tok : *t) {
		i++;
		printf(" %s", tok);
		if (i == 3) break;
	}
	printf("\n");

}