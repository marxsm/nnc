#include "Declaration.h"

#include "Expression.h"

void Declaration::GenerateDataAsm()
{
	switch (DecType)
	{
	case 'P': {

		if (!strcmp(type, "int")) {

			Wrinst->Writeln("\t%s dd %u", name, 0);
		}
	}break;
	case 'V': {
		if (!strcmp(type, "int")) {

			Wrinst->Writeln("\t%s dd %u", name, 0);
		}
	}
	case 'F': {

		if (params) {

			Declaration * param = nullptr;

			for (auto param : *params)

				param->GenerateDataAsm();
		}

		if (elements) {

			Element * element = nullptr;

			for (auto element : *elements)

				element->GenerateDataAsm();
		}
	}break;
	default:
		break;
	}
}