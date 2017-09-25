#include "Compiler.h"

#pragma warning(disable: 4996)

void Compiler::CompileToAsm()
{	
	char * asFile = Utils::getAsFileName(rawName);

	Wrinst->OpenFile(asFile);

	Wrinst->Writeln("format PE console");
	Wrinst->Writeln("entry main");
	Wrinst->Writeln("");
	Wrinst->Writeln("include 'win32a.inc'");
	Wrinst->Writeln("");
	Wrinst->Writeln("section '.text' code readable executable");

	for (Declaration * declare : *declares) {

		Log("Assemblying declaration %s", declare->name);

		declare->GenerateAsm(0);
	}

	Wrinst->Writeln("\tmov esp, ebp");
	Wrinst->Writeln("\tpop ebp");
	
	Wrinst->Writeln("\tcall [ExitProcess]");

	Wrinst->Writeln("");

	Wrinst->Writeln("section '.idata' import data readable");
	Wrinst->Writeln("\tlibrary kernel32, 'kernel32.dll', \\");
	Wrinst->Writeln("\tmsvcrt, 'msvcrt.dll'");
	Wrinst->Writeln("");
	Wrinst->Writeln("\timport kernel32, \\");
	Wrinst->Writeln("\tExitProcess, 'ExitProcess'");
	Wrinst->Writeln("");
	Wrinst->Writeln("\timport msvcrt, \\");
	Wrinst->Writeln("\tprintf, 'printf'"); 
	
	Wrinst->Writeln("");
	Wrinst->Writeln("section '.data' data readable writeable");

	for (Declaration * declare : *declares) {

		Log("Assemblying data in declaration %s", declare->name);

		declare->GenerateDataAsm();
	}

	Wrinst->CloseFile();
}