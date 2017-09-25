#include "Compiler.h"

void Compiler::BuildTree()
{
	Log("Reading source file %s", srcFile);

	Reader * reader = new Reader(srcFile);

	Minst->SetTokens(reader->getTokens());

	Log("Building tree for source file %s", srcFile);

	declares = new deque<Declaration*>();

	Declaration * tmp = nullptr;

	while (tmp = Declaration::getDeclaration())
		declares->push_back(tmp);
}