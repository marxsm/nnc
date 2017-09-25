#include "Matcher.h"

bool Matcher::Equal(char * st)
{
	if (!strcmp(st, tokens->front()))
		return true;
	else
		return false;
}