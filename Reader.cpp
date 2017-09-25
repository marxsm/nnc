#include "Reader.h"

Reader::Reader(char * srcFile)
{
	rawData = readFile(srcFile);
}