#include "Reader.h"

deque<char*> * Reader::getTokens()
{
	deque<char*>* tokens = new deque<char*>();

	char * token;

	while (token = getToken())
		tokens->push_back(token);

	return tokens;
}