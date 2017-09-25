#include "Matcher.h"

void Matcher::PrevToken(char * token)
{
	tokens->push_front(token);
}