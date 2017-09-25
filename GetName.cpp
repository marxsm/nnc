#include "Matcher.h"

char * Matcher::GetName(bool required)
{
	char * result = nullptr;

	if (!Empty() && currentTokenIsName()) {

		result = tokens->front();

		NextToken();
	}
	else
		if (required)
			Error("A name expected.");

	return result;
}