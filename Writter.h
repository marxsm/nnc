#pragma once

#include <fstream>
#include <iostream>

#include "Logger.h"

using namespace std;

using namespace Logger;


#define Wrinst Writter::Instance()

class Writter
{
public:
	Writter();
	~Writter();

	FILE * outFile;

	static Writter * instance;
	static Writter * Instance();

	void OpenFile(char * fileName);
	void CloseFile();

	void Writeln(const char * format, ...);

	void IncludeLibrary();
};

