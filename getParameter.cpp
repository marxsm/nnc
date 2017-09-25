#include "Declaration.h"

#pragma warning(disable : 4996)

Declaration * Declaration::getParameter(char * parentName)
{
	Declaration * result = nullptr;

	char *var1, *var2, *var3;

	if (var1 = Minst->GetName(false)) {

		var2 = Minst->GetName(true);

		var3 = new char[strlen(var2) + strlen(parentName) + 2];
		strcpy(var3, parentName);
		strcat(var3, "_");
		strcat(var3, var2);

		result = new Declaration(var1, var2, var3);
	}

	return result;
}