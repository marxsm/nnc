#include "Matcher.h"


bool Matcher::currentTokenIsNumber()
{
	char * token = tokens->front();

	for (char * c = token; *c; c++)

		if (getCharTypeAdvanced(*c) != CT_NUM)
			return false;

	return true;
}