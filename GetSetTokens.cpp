#include "Matcher.h"

void Matcher::SetTokens(deque<char*>* newTokens)
{
	tokens = newTokens;
}

deque<char*>* Matcher::GetTokens()
{
	return tokens;
}