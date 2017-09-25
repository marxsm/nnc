#include "Declaration.h"

#include "Expression.h"

void Declaration::GenerateAsm(BASE64 index)
{
	switch (DecType)
	{
	case 'P': {
		if (!strcmp(type, "int")) {
			Wrinst->Writeln("\tmov eax, [ebp+%u]", index);
			Wrinst->Writeln("\tmov [%s], eax", name);
		}
	}break;
	case 'F': {
		if (!strcmp(type, "int")) {
			Wrinst->Writeln("%s:", name);

			Wrinst->Writeln("\tpush ebp");
			Wrinst->Writeln("\tmov ebp, esp");
			Wrinst->Writeln("");

			Declaration * param = nullptr;

			BASE64 count = params->size() * 4 + 4;

			reverse(params->begin(), params->end());

			for (auto param : *params) {

				param->GenerateAsm(count);

				count -= 4;
			}

			reverse(params->begin(), params->end());

			Element * element = nullptr;

			for (auto element : *elements)

				element->GenerateAsm(name);
		}
	}break;
	default:
		break;
	}
	Wrinst->Writeln("");
}