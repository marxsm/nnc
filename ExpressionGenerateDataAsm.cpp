#include "Expression.h"


void Expression::GenerateDataAsm()
{
	switch (DecType)
	{
	case 'S': {
		Log("Registering string %s", str);

		Wrinst->Writeln("\t%s db %s, 0", name, str);
	}break;
	default: {
	}
	}

	if (exps) {

		Expression * expression = nullptr;

		for (auto expression : *exps)

			expression->GenerateDataAsm();
	}
}