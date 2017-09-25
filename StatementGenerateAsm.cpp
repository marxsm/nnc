#include "Statement.h"

#include "Expression.h"

void Statement::GenerateAsm(char * decName)
{
	switch (DecType)
	{
	case 'R': {
		exp->GenerateAsm(decName);

		if (!strcmp(decName, "main")) {
		}
		else {
			Wrinst->Writeln("\tpop eax");
			Wrinst->Writeln("\tmov esp, ebp");
			Wrinst->Writeln("\tpop ebp");

			Wrinst->Writeln("\tret");
		}

	}break;
	default:
		break;
	}
}