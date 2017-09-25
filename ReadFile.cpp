#include "Reader.h"

char * Reader::readFile(char * srcFile)
{
	std::ifstream in("template.nnc");
	std::string contents((std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>());

	const char * data = contents.c_str();

	char * result = new char[strlen(data) + 1];

	memcpy(result, data, strlen(data));

	result[strlen(data)] = 0;

	return result;
}