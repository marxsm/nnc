#include "Writter.h"

#pragma warning(disable: 4996)

void Writter::OpenFile(char * fileName)
{
	outFile = fopen(fileName, "w");

	if (!outFile) Error("Error opening file");
}

void Writter::CloseFile()
{
	fclose(outFile);
}