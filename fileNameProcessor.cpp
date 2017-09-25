#include "Utils.h"

#pragma warning(disable : 4996)

char * Utils::getRawFileName(char * fileName)
{
	int i = strlen(fileName);

	while (i && fileName[i - 1] != '.') i--;

	char * result = new char[i+1];

	memcpy(result, fileName, i);

	result[i] = 0;

	return result;
}

char * Utils::getAsFileName(char * fileName)
{
	char * raw = getRawFileName(fileName);

	char * fn = new char[strlen(raw) + 3];

	strcpy(fn, raw);
	strcat(fn, "as");

	return fn;
}

char * Utils::getExeFileName(char * fileName)
{
	char * raw = getRawFileName(fileName);

	char * fn = new char[strlen(raw) + 4];

	strcpy(fn, raw);
	strcat(fn, "exe");

	return fn;
}