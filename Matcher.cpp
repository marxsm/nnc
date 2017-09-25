#include "Matcher.h"

Matcher * Matcher::instance;

Matcher * Matcher::Instance()
{
	if (instance == NULL)
		instance = new Matcher();
	return instance;
}
