#include "Matcher.h"

bool Matcher::Match(char * st)
{
	if (Equal(st)) {
		NextToken();
		return true;
	}
	else
		return false;
}