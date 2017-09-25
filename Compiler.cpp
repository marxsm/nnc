#include "Compiler.h"


Compiler::Compiler() {
}

Compiler::Compiler(char* srcFile)
{
	this->srcFile = srcFile;

	rawName = Utils::getRawFileName(srcFile);
}


Compiler::~Compiler()
{
}
