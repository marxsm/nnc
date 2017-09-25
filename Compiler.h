#pragma once

#include <string>

#include "Logger.h"
#include "Reader.h"
#include "Matcher.h"
#include "Declaration.h"
#include "Writter.h"
#include "Utils.h"

using namespace std;
using namespace Logger;


class Compiler
{
public:
	Compiler();
	Compiler(char* srcFile);
	~Compiler();

	deque<Declaration*> * declares;

	char* srcFile;

	char* rawName;

	void BuildTree();

	void Optimize();

	void CompileToAsm();

	void CompileToBin();
};

