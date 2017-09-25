#include "Matcher.h"


char * Matcher::GetOperator(bool required)
{
	char * result = nullptr;

	if (!Empty() && currentTokenIsOperator()) {

		result = tokens->front();

		NextToken();
	}
	else
		if (required)
			Error("An operator is expected.");

	return result;
}