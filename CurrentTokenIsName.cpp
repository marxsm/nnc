#include "Matcher.h"

bool Matcher::currentTokenIsName()
{
	char * token = tokens->front();

	if (getCharTypeAdvanced(*token) != CT_ALPHA)
		return false;

	for (char * c = token; *c; c++)

		if (getCharTypeAdvanced(*c) != CT_ALPHA && getCharTypeAdvanced(*c) != CT_NUM)
			return false;

	return true;
}