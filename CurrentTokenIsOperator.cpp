#include "Matcher.h"

bool Matcher::currentTokenIsOperator()
{
	char* token = tokens->front();

	for (char* c = token; *c; c++)

		if (getCharTypeAdvanced(*c) != CT_OPERATOR)
			return false;

	return true;
}