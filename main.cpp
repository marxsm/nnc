#include "Logger.h"
#include "Compiler.h"

using namespace Logger;

bool ErrorMarked = false;

bool ShowLog = false;


int main(int args, char** argv) {

	printf("NNC Compiler - Noname compiler\nDeveloped by Chien Tran\nContact: yeulaptrinh98@gmail.com\n\n");

	char* srcFile = argv[1];

	if (!srcFile) {
		printf("\tTo compile source file 'a.nnc' please type 'nnc a.nnc'\n");
	}
	else {
		Compiler * c = new Compiler(srcFile);

		c->BuildTree();
		if (!ErrorMarked)
			c->Optimize();
		if (!ErrorMarked)
			c->CompileToAsm();
		if (!ErrorMarked)
			c->CompileToBin();
		if (!ErrorMarked) {
			Success("Compile source file %s successful", srcFile);
		}
		else
		{
			printf("Compile source file %s failed", srcFile);
		}
	}

	return 0;
}