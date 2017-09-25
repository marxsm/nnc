#include "Matcher.h"

char * Matcher::GetStringConstant(bool required)
{
	char * result = nullptr;

	if (!Empty()) {

		char * token = tokens->front();

		if (*token == '\"' && token[strlen(token)-1] == '\"') {

			Minst->NextToken();

			result = token;
		}
	}
	else
		if (required)
			Error("An string constant is expected.");

	return result;
}